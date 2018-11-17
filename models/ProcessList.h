#ifndef SCHEDULER_PROCESSLIST_H
#define SCHEDULER_PROCESSLIST_H

#include "Process.h"

/**
 * \brief Keeps a list of Process pointers and allows iteration.
 * */
class ProcessList {
    std::vector<Process*> processes;

    void sortByArrivalTime();

    static bool processArrivedEarlier(const Process* process, const Process* other);

public:
    explicit ProcessList(std::vector<Process*> processes);

    ~ProcessList();


    std::vector<Process*>::iterator begin();

    std::vector<Process*>::const_iterator begin() const;

    std::vector<Process*>::iterator end();

    std::vector<Process*>::const_iterator end() const;

    Process* operator[] (unsigned int index) const;
};


#endif //SCHEDULER_PROCESSLIST_H
