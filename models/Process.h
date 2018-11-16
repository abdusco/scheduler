#ifndef SCHEDULER_PROCESS_H
#define SCHEDULER_PROCESS_H

#include <string>
#include <ostream>

#include "Program.h"

enum ProcessStatus {
    // process is being created
            NEW,
    // instructions are being executed
            RUNNING,
    // process is waiting for an event to occur
            WAITING,
    // process is waiting to be assigned to CPU
            READY,
    // process has finished execution
            TERMINATED
};

class Process {
    Program program;
    const std::string name;
    const unsigned int priority;
    const unsigned int arrivalTime;
    std::size_t programCounter = 0;
    ProcessStatus status;
    unsigned int waitingTime = 0;
    unsigned int finishedTime;
public:
    Process(std::string name, unsigned int priority, const Program& program, unsigned int arrivalTime);

    friend std::ostream& operator<<(std::ostream& os, const Process& process);
};


#endif //SCHEDULER_PROCESS_H
