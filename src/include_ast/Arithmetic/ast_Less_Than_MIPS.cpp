#include "AST/Arithmetic/ast_Less_Than_MIPS.hpp"

Less_Than_MIPS::Less_Than_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void Less_Than_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::cout << "LESS THAMN" << std::endl;
    generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);
    generate_right(dst, context, 4, branch[1], make_name, dynamic_offset);
    // less than, if $3 < $4
    dst << "slt " << destReg << ", "
        << "$3"
        << ", "
        << "$4" << std::endl;
}
