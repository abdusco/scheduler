#ifndef SCHEDULER_PROCESSLIST_H
#define SCHEDULER_PROCESSLIST_H


#include "Process.h"

class ProcessList {
    std::vector<Process*> processes;
public:
    explicit ProcessList(std::vector<Process*> processes);

    ~ProcessList();

    std::vector<Process*>::iterator begin();

    std::vector<Process*>::const_iterator begin() const;

    std::vector<Process*>::iterator end();

    std::vector<Process*>::const_iterator end() const;
};


#endif //SCHEDULER_PROCESSLIST_H
