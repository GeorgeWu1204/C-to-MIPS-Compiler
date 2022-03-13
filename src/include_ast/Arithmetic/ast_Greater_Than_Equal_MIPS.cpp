#include "AST/Arithmetic/ast_Greater_Than_Equal_MIPS.hpp"

Greater_Than_Equal_MIPS::Greater_Than_Equal_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

//SOS Not done yet
void Greater_Than_Equal_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::cout << "Greater THAMN" << std::endl;
    generate_left(dst, context, 3, branch[0], make_name);
    generate_right(dst, context, 4, branch[1], make_name);
    // less than, if $3 < $4
    dst << "slt " << destReg << ", "
        << "$3"
        << ", "
        << "$4" << std::endl;
    dst << "xori " << destReg << ", " << destReg  << ", " << "0x1" << std::endl;
    dst << "andi " << destReg << ", " << destReg << ", " << "0x00ff" << std::endl;
}
