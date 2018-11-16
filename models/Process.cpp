#include <utility>

#include "Process.h"

Process::Process(std::string name, unsigned int priority, const Program& program, unsigned int arrivalTime)
        : name(std::move(name)),
          program(program),
          priority(priority),
          arrivalTime(arrivalTime) {
    finishedTime = 0;
    status = READY;
}

std::ostream& operator<<(std::ostream& os, const Process& process) {
    os << "name: " << process.name
       << "\tprogram: " << process.program.size() << " INST"
       << "\tPC: " << process.programCounter
       << "\tpriority: " << process.priority
       << "\tarrival: " << process.arrivalTime
       << "\twaiting: " << process.waitingTime
       << "\tfinished: " << process.finishedTime
       << "\tstatus: " << process.status;
    return os;
}
