#include "AST/Arithmetic/ast_LogicOr_MIPS.hpp"

LogicOr_MIPS::LogicOr_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void LogicOr_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    generate_left(dst, context, 3, branch[0], make_name);
    generate_right(dst, context, 4, branch[1], make_name);
    // greater than
    dst << "or " << destReg << ", " << "$3" << ", " << "$4" << std::endl;
}
