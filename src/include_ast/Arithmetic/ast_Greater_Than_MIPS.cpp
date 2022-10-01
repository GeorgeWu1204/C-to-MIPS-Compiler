#include "AST/Arithmetic/ast_Greater_Than_MIPS.hpp"

Greater_Than_MIPS::Greater_Than_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void Greater_Than_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    generate_left(dst, context, 3, branch[0], make_name);
    generate_right(dst, context, 4, branch[1], make_name);
    // greater than
    // a > b = b < a = 1

    dst << " slt $" << destReg << ", "
        << "$4 "
        << ", "
        << "$3 " << std::endl;
    // a < b + 1

}
