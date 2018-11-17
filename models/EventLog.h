#ifndef SCHEDULER_EVENTLOG_H
#define SCHEDULER_EVENTLOG_H


#include <string>
#include <vector>
#include <ostream>

class EventLog {
public:
    std::vector<std::string> logs;

    void log(std::string entry);

    friend std::ostream& operator<<(std::ostream& os, const EventLog& log);
};


#endif //SCHEDULER_EVENTLOG_H
