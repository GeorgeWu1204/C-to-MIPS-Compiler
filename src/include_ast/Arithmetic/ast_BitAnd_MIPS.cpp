#include "AST/Arithmetic/ast_BitAnd_MIPS.hpp"

BitAnd_MIPS::BitAnd_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void BitAnd_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
     generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);
    generate_right(dst, context, 4, branch[1], make_name, dynamic_offset);
    // greater than
    dst << "and " << destReg << ", " << "$3 " << ", " << "$4" << std::endl;
}
