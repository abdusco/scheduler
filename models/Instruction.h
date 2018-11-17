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
    const unsigned int time;
    const InstructionType type;

    Instruction(InstructionType type, unsigned int time);
    bool isLast();
    unsigned int getDuration();
};


#endif //SCHEDULER_INSTRUCTION_H
