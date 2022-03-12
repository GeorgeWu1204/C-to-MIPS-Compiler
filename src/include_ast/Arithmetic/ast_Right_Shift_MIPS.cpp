#include "AST/Arithmetic/ast_Right_Shift.hpp"

Right_Shift_MIPS::Right_Shift_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void Right_Shift_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
     generate_left(dst, context, 3, branch[0], make_name);
    generate_right(dst, context, 4, branch[1], make_name);
    // need to decide whether shift left logical or shift left logical variable?
    // assume only use registers for all instructions
    dst << "srl" << destReg << ", " << "$3" << ", " << "$4" << std::endl;
    // decide whether to use srav?
}
