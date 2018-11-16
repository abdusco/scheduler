#include <utility>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "InputParser.h"
#include "../models/ProcessList.h"

InputParser::InputParser(const std::string& inputDir) : inputDir(inputDir) {
    readDefinition(combinePath(inputDir, "definition.txt"));
}

void InputParser::readDefinition(std::string definitionPath) {
    std::ifstream input(definitionPath);

    std::string line;
    while (std::getline(input, line)) {
        std::string name, codeFilename;
        size_t priority, arrivalTime;

        std::istringstream processProps(line);
        processProps >> name >> priority >> codeFilename >> arrivalTime;

        auto prog = readProgram(combinePath(inputDir, codeFilename + ".txt"));

        auto parsedProcess = new Process(prog, name, priority, arrivalTime);
        processes.push_back(parsedProcess);
    }
}


std::string InputParser::combinePath(std::string dir, std::string file) {
    bool needsSlash = dir.rfind(PATH_SEPARATOR) != dir.size() - 1;
    return dir + (needsSlash ? PATH_SEPARATOR : "") + file;
}


Program InputParser::readProgram(std::string codePath) {
    std::ifstream input(codePath);
    std::string line;

    auto p = Program();
    while (std::getline(input, line)) {
        std::string type;
        size_t duration;

        std::istringstream instProps(line);
        instProps >> type >> duration;

        p.emplace_back(
                type == "exit" ? EXIT : NORMAL,
                duration
        );
    }
    return p;
}

ProcessList InputParser::getProcesses() {
    return ProcessList(processes);
}


