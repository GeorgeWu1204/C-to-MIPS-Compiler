#include "AST/Arithmetic/ast_Equal_MIPS.hpp"


Equal_MIPS::Equal_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void Equal_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    generate_left(dst, context, 3, branch[0], make_name);
    generate_right(dst, context, 4, branch[1], make_name);
    // equal = $3 - $4 = 0;
    dst << "subu " << destReg << ", " << "$3" << ", " << "$4" << std::endl;
    
}
