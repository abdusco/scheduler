#ifndef SCHEDULER_SCHEDULER_H
#define SCHEDULER_SCHEDULER_H

#include <queue>

#include "ProcessList.h"
#include "EventLog.h"

/**
 * \brief Controls which process gets executed out of a list of processes in Round-Robin fashion.
 *
 * Processes with higher priorities are run first.
 * Those with equal priorities are processed in first-come-first-served basis
 *
 * */
class Scheduler {
    const ProcessList& processes;
    EventLog& eventLogger;
    std::deque<Process*> readyQueue;
    std::queue<Process*> newQueue;

    unsigned long clock = 0;
    Process* current = nullptr;

    void logQueue();

    void checkForNewProcess();

    bool moreImportantProcessAvailable() const;

    void popReadyQueue();

    void pushReadyQueue(Process* first);
public:
    explicit Scheduler(const ProcessList& processes, EventLog& eventLogger);

    void run();
};


#endif //SCHEDULER_SCHEDULER_H
