#include <utility>
#include <assert.h>

#include "ProcessList.h"

ProcessList::ProcessList(std::vector<Process*> processes)
        : processes(std::move(processes)) {}

ProcessList::~ProcessList() {
    for (Process* process : processes) {
        delete process;
    }
}

std::vector<Process*>::iterator ProcessList::begin() { return processes.begin(); }

std::vector<Process*>::const_iterator ProcessList::begin() const { return processes.begin(); }

std::vector<Process*>::iterator ProcessList::end() { return processes.end(); }

std::vector<Process*>::const_iterator ProcessList::end() const { return processes.end(); }
