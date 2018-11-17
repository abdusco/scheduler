#ifndef SCHEDULER_PROCESS_H
#define SCHEDULER_PROCESS_H

#include <string>
#include <ostream>

#include "Program.h"

enum ProcessState {
    NEW = 1 << 0, /** Process is being created */
    READY = 1 << 1, /** Process is waiting to be assigned to CPU */
    RUNNING = 1 << 2, /** Process is waiting for an event to occur */
    WAITING = 1 << 3, /** Process has finished execution */
    TERMINATED = 1 << 4,/** Process has finished execution */
};

/**
 * \brief Represents a Process Control Block
 * */
class Process {
    Program program;
    /** Index of the next instruction to be executed */
    std::size_t programCounter = 0;
    ProcessState state = NEW;
    /** Timestamp for when the process was added to ready queue */
    unsigned int readyTime = 0;
    /** Timestamp for when the process first gets processed */
    unsigned int processTime = 0;
    /** Timestamp for when the process terminates */
    unsigned int finishTime = 0;
    /** Process priority. Lower values are more important */
    const unsigned int priority;
    const std::string name;
public:
    /** Timestamp for when the process was created */
    const unsigned int arrivalTime;

    Process(const Program& program, std::string name, unsigned int priority, unsigned int arrivalTime);

    unsigned long getTurnaround();

    unsigned long getWait();

    unsigned int stepForward(unsigned long clock);

    friend std::ostream& operator<<(std::ostream& os, const Process& process);

    bool isFinished();

    bool operator<(const Process& rhs) const;

    bool operator>(const Process& rhs) const;

    bool operator<=(const Process& rhs) const;

    bool operator>=(const Process& rhs) const;

    bool canStart(unsigned long clock);

    void setStatus(ProcessState status, unsigned long clock);
};


#endif //SCHEDULER_PROCESS_H
