#ifndef SCHEDULER_INPUTPARSER_H
#define SCHEDULER_INPUTPARSER_H


#include <string>
#include "../models/Process.h"

class InputParser {
#if defined _WIN32 || defined __CYGWIN__
    const std::string PATH_SEPARATOR = "\\";
#else
    const std::string PATH_SEPARATOR("/");
#endif
    const std::string inputDir;
    std::vector<Process> processes;

    void readDefinition(std::string definitionPath);

    std::string combinePath(std::string dir, std::string file);

    Program readProgram(std::string codePath);

public:
    InputParser(const std::string& definitionsPath);
    std::vector<Process> getProcesses();
};


#endif //SCHEDULER_INPUTPARSER_H
