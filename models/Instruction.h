#ifndef SCHEDULER_INSTRUCTION_H
#define SCHEDULER_INSTRUCTION_H

enum InstructionType {
    EXIT,
    NORMAL
};

/**
 * \brief Describes an instruction.
 *
 * */
class Instruction {
public:
    unsigned int time;
    InstructionType type;

    Instruction(InstructionType type, unsigned int time);
};


#endif //SCHEDULER_INSTRUCTION_H
