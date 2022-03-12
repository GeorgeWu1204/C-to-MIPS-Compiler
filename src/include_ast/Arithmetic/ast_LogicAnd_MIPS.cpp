#include "AST/Arithmetic/ast_LogicAnd_MIPS.hpp"

LogicAnd_MIPS::LogicAnd_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void LogicAnd_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    generate_left(dst, context, 3, branch[0], make_name);
    generate_right(dst, context, 4, branch[1], make_name);
    // greater than
    dst << "and " << destReg << ", "
        << "$3"
        << ", "
        << "$4" << std::endl;
}
