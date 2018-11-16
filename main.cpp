#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include "utils/InputParser.h"

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

    for (Process* proc : ps) {
        std::cout << *proc << std::endl;
    }

    return 0;
}