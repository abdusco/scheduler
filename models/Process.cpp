#include <utility>
#include <iostream>

#include "Process.h"

Process::Process(const Program& program, std::string name, unsigned int priority, unsigned int arrivalTime)
        : name(std::move(name)),
          program(program),
          priority(priority),
          arrivalTime(arrivalTime) {}

unsigned long Process::getTurnaround() {
    return finishTime - processTime;
}

/**
 * \brief Runs the next instruction of the program associated with the process.
 * Also sets process status depending on which instruction is being executed
 * \returns CPU time needed for the instruction
 * */
unsigned int Process::stepForward(unsigned long clock) {
    if (state == TERMINATED) return 0;
    if (program.empty()) return 0;

    if (programCounter == 0) {
        setStatus(RUNNING, clock);
    }

    Instruction& instruction = program.at(programCounter++);
    if (instruction.isLast()) {
        setStatus(TERMINATED, clock);
    }

    return instruction.getDuration();
}

std::ostream& operator<<(std::ostream& os, const Process& process) {
    os << process.name
       << "[" << process.programCounter + 1 << "]";
    return os;
}

bool Process::isFinished() {
    return state == TERMINATED;
}

bool Process::canStart(unsigned long clock) {
    return clock >= arrivalTime;
}


/**
 * \brief Returns waited time.
 *
 * Waiting time is the sum of all times
 * that the process spends in the ready queue without being processed
 * */
unsigned long Process::getWait() {
    return finishTime - readyTime - arrivalTime;
}

/**
 * \brief Sets process status and logs when what happened
 * */
void Process::setStatus(ProcessState status, unsigned long clock) {
    switch (status) {
        case READY:
            readyTime = clock;
            break;
        case TERMINATED:
            finishTime = clock;
            break;
        case RUNNING:
            processTime = clock;
        default:
            break;
    }
    this->state = status;
}

/**
 * \brief Process comparison
 * Checks if one process is more important than the other.
 *
 * Lower priorities are more important.
 *
 * */
bool Process::operator<(const Process& other) const {
    // default to first-come-first-served
    if (priority == other.priority) {
        return arrivalTime > other.arrivalTime;
    }
    return priority > other.priority;
}

bool Process::operator>(const Process& rhs) const {
    return rhs < *this;
}

bool Process::operator<=(const Process& rhs) const {
    return !(rhs < *this);
}

bool Process::operator>=(const Process& rhs) const {
    return !(*this < rhs);
}
