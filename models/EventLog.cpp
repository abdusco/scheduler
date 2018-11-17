#include "EventLog.h"

void EventLog::log(std::string entry) {
    logs.push_back(entry);
}

std::ostream& operator<<(std::ostream& os, const EventLog& log) {
    for (const std::string& entry : log.logs) {
        os << entry << std::endl;
    }
    return os;
}
