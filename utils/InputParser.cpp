#include <utility>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "InputParser.h"
#include "../models/ProcessList.h"

/**
 * \brief ProcessReader constructor
 * \param inputDir Path to directory that contains definition.txt and code files for processes.
 *
 * */
InputParser::InputParser(const std::string& inputDir) : inputDir(inputDir) {
    readDefinition(combinePath(inputDir, "definition.txt"));
}

/**
 * \brief Reads definition file and constructs processes.
 * \param definitionPath Path to the definition file
 *
 * A definition file is a TSV file that contains details to construct a process.
 * Columns are process name, priority, name of the code file, and arrival time.
 *
 * \code
 * P1   4   code1   40
 * P2   3   code2   120
 * P3   6   code1   250
 * P4   2   code3   470
 * \endcode
 * */
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

/**
 * \brief Combines given directory path with filename. Adds slashes as needed
 * \returns relative or absolute path depending on the argument dir
 * \param dir path to directory. Relative or absolute
 * \param file path to file starting from dir
 * */
std::string InputParser::combinePath(std::string dir, std::string file) {
    bool needsSlash = dir.rfind(PATH_SEPARATOR) != dir.size() - 1;
    return dir + (needsSlash ? PATH_SEPARATOR : "") + file;
}

/**
 * \brief Read a code file into a list of instructions
 * \param codePath the path to code file
 * \returns list of instructions
 *
 * A code file is a TSV file with a number instructions.
 * Columns denode instruction type and the CPU time needed to execute it.
 *
 * \code
 * instr1   20
 * instr2   30
 * instr3   10
 * instr4   30
 * instr5   50
 * instr6   20
 * instr7   10
 * exit 10
 * \endcode
 * */
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

/**
 * \brief Parsed processes
 * \returns parsed processes
 *
 * Returns processed parsed using definition and code files
 * */
ProcessList InputParser::getProcesses() {
    return ProcessList(processes);
}


