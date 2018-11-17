#include "Instruction.h"

Instruction::Instruction(InstructionType type, unsigned int time) : time(time), type(type) {}

bool Instruction::isLast() {
    return type == EXIT;
}

unsigned int Instruction::getDuration() {
    return time;
}
