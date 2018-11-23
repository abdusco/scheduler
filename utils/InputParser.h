#ifndef SCHEDULER_INPUTPARSER_H
#define SCHEDULER_INPUTPARSER_H


#include <string>
#include "../models/Process.h"
#include "../models/ProcessList.h"

/**
 * \brief Reads definition and code input files into Process objects
 * */
class InputParser {
#if defined _WIN32 || defined __CYGWIN__
    const std::string PATH_SEPARATOR = "\\";
#else
    const std::string PATH_SEPARATOR("/");
#endif
    const std::string inputDir;
    std::vector<Process*> processes;

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
    void readDefinition(std::string definitionPath);

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
    Program readProgram(std::string codePath);

public:

    /**
     * \brief Combines given directory path with filename. Adds slashes as needed
     * \returns relative or absolute path depending on the argument dir
     * \param dir path to directory. Relative or absolute
     * \param file path to file starting from dir
     * */
    std::string combinePath(std::string dir, std::string file);
    /**
     * \brief ProcessReader constructor
     * \param inputDir Path to directory that contains definition.txt and code files for processes.
     *
     * */
    explicit InputParser(const std::string& definitionsPath);

    /**
     * \brief Parsed processes
     * \returns parsed processes
     *
     * Returns processed parsed using definition and code files
     * */
    ProcessList getProcesses();
};


#endif //SCHEDULER_INPUTPARSER_H
