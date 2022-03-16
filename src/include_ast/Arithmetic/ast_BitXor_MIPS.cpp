#include "AST/Arithmetic/ast_BitXor_MIPS.hpp"

BitXor_MIPS::BitXor_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}


void BitXor_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);
    generate_right(dst, context, 4, branch[1], make_name, dynamic_offset);
    // greater than
    dst << "xor " << destReg << ", " << "$3" << ", " << "$4" << std::endl;
}
