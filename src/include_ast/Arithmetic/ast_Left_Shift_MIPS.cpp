#include "AST/Arithmetic/ast_Left_Shift_MIPS.hpp"

Left_Shift_MIPS::Left_Shift_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void Left_Shift_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);
    generate_right(dst, context, 4, branch[1], make_name, dynamic_offset);
    // need to decide whether shift left logical or shift left logical variable?
    // assume only use registers for all instructions
    dst << "sll" << destReg << ", "
        << "$3"
        << ", "
        << "$4" << std::endl;
}
