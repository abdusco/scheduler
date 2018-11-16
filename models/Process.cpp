#include <utility>
#include <iostream>

#include "Process.h"

Process::Process(const Program& program, std::string name, unsigned int priority, unsigned int arrivalTime)
        : name(std::move(name)),
          program(program),
          priority(priority),
          arrivalTime(arrivalTime) {
    finishedTime = 0;
    status = READY;
}

void Process::begin(unsigned int clock) {
    waitingTime = clock - arrivalTime;
}

void Process::complete(unsigned int clock) {
    finishedTime = clock;
}

unsigned int Process::getTurnaround() {
    return finishedTime;
}

void Process::updateStatus(ProcessStatus status) {
    this->status = status;
}

void Process::runNextInstruction() {
    if (status == TERMINATED) return;
    if (program.empty()) return;

    Instruction& inst = program.at(programCounter++);
    if (inst.type == EXIT) {
        status = TERMINATED;
    }
}

bool Process::isTerminated() {
    return status == TERMINATED;
}

std::ostream& operator<<(std::ostream& os, const Process& process) {
    os << "name: " << process.name
       << "\tProgram: " << process.program.size() << " inst"
       << "\t[PC: " << process.programCounter
       << " Priority: " << process.priority
       << " Arrive: " << process.arrivalTime
       << " Wait: " << process.waitingTime
       << " Finish: " << process.finishedTime
       << " Status: " << process.status
       << "]";
    return os;
}
