#include "AST/Arithmetic/ast_Division_MIPS.hpp"

Division_MIPS::Division_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void Division_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);
    generate_right(dst, context, 4, branch[1], make_name, dynamic_offset);
    dst << "div " << "$3" << ", " << "$4" << std::endl;
    dst << "mflo " << destReg << std::endl;
    // SOS why we only consider mflo here？
    //  take the quotient
}

// void Binary_Mul::PrettyPrint(std::ostream &dst){
//     dst << "Identifier: " << identifier_id <<std::endl;
// }
