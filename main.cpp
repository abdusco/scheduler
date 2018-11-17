#include <iostream>
#include <fstream>
#include "utils/InputParser.h"
#include "models/Scheduler.h"
#include "models/EventLog.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Syntax: ./project3 <input_file> <output_file> [verbose]" << std::endl;
        std::cout << "(add any character to the end to output results to the console)" << std::endl;
        return 1;
    }
    bool verbose = argc > 3;
    std::string inputDir = std::string(argv[1]);

    InputParser p(inputDir);
    auto ps = p.getProcesses();

    EventLog events;
    Scheduler scheduler(ps, events);
    scheduler.run();

    std::cout << events << std::endl;

    return 0;
}