cmake_minimum_required(VERSION 3.12)
project(scheduler)

set(CMAKE_CXX_STANDARD 17)

add_executable(scheduler main.cpp utils/InputParser.cpp utils/InputParser.h models/Process.cpp models/Process.h models/Program.cpp models/Program.h models/Instruction.cpp models/Instruction.h)