#include <utility>
#include <assert.h>
#include <algorithm>

#include "ProcessList.h"

ProcessList::ProcessList(std::vector<Process*> processes)
        : processes(std::move(processes)) {
    sortByArrivalTime();
}

ProcessList::~ProcessList() {
    for (Process* process : processes) {
        delete process;
    }
}

void ProcessList::sortByArrivalTime() {
    std::sort(
            processes.begin(),
            processes.end(),
            processArrivedEarlier
    );
}

bool ProcessList::processArrivedEarlier(const Process* process, const Process* other) {
    return process->arrivalTime < other->arrivalTime;
}

std::vector<Process*>::iterator ProcessList::begin() { return processes.begin(); }

std::vector<Process*>::const_iterator ProcessList::begin() const { return processes.begin(); }

std::vector<Process*>::iterator ProcessList::end() { return processes.end(); }

std::vector<Process*>::const_iterator ProcessList::end() const { return processes.end(); }

Process* ProcessList::operator[](unsigned int index) const {
    return processes.at(index);
}
