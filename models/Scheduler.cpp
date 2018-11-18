#include <iostream>
#include <sstream>
#include "Scheduler.h"
#include "EventLog.h"


Scheduler::Scheduler(const ProcessList& processes, EventLog& eventLogger)
        : processes(processes),
          eventLogger(eventLogger) {
    for (Process* process : processes) {
        newQueue.push(process);
    }
}

void Scheduler::run() {
    logQueue();
    checkForNewProcess();

    while (!readyQueue.empty()) {
        current = readyQueue.front();

        while (!moreImportantProcessAvailable()) {
            clock += current->stepForward(clock);
            checkForNewProcess();

            if (current->isFinished()) {
                popReadyQueue();
                break;
            }
        }

        checkForNewProcess();
    }
}

void Scheduler::popReadyQueue() {
    readyQueue.pop_front();
    logQueue();
}

bool Scheduler::moreImportantProcessAvailable() const {
    bool ans = *current < *readyQueue.front();
    return ans;
}

void Scheduler::checkForNewProcess() {
    if (newQueue.empty()) return;
    Process* process = newQueue.front();

    if (readyQueue.empty()) {
        clock = process->arrivalTime;
        pushReadyQueue(process);
        newQueue.pop();
        return;
    }

    if (!process->canStart(clock)) return;

    newQueue.pop();
    pushReadyQueue(process);
}

void Scheduler::pushReadyQueue(Process* process) {
    process->setStatus(READY, clock);
    if (readyQueue.empty()) {
        readyQueue.push_front(process);
        logQueue();
        return;
    }

    // check if it's more important than some
    for (auto queued = readyQueue.begin(); queued != readyQueue.end(); queued++) {
        if (*process < (**queued)) continue;
        readyQueue.insert(queued, process);
        logQueue();
        return;
    }

    // least important
    readyQueue.push_back(process);
    logQueue();
}

void Scheduler::logQueue() {
    std::ostringstream entry;

    entry << clock << ":";
    entry << "HEAD";
    for (Process* process : readyQueue) {
        entry << "-" << *process;
    }
    entry << "-TAIL";

    eventLogger.log(entry.str());
}




