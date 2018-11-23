#include <iostream>
#include <fstream>
#include "utils/InputParser.h"
#include "models/Scheduler.h"
#include "models/EventLog.h"

int main(int argc, char* argv[]) {
    std::string inputDir = argc < 2 ?
                           "." : // default to cwd
                           std::string(argv[1]); // use given directory

    InputParser p(inputDir);
    auto ps = p.getProcesses();

    EventLog events;
    Scheduler scheduler(ps, events);
    scheduler.run();

    std::ofstream output(p.combinePath(inputDir, "output.txt"));
    output << events << std::endl;

    std::cout << events << std::endl;
    return 0;
}