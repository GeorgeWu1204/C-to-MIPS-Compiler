#include "AST/Arithmetic/ast_Mod_MIPS.hpp"

Mod_MIPS::Mod_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void Mod_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
     generate_left(dst, context, 3, branch[0], make_name);
    generate_right(dst, context, 4, branch[1], make_name);
    dst << "div " << "$3" << ", " << "$4" << std::endl;
    dst << "mfhi " << destReg << std::endl;
    // SOS why we only consider mflo here？
    //  here we consider the remainder
}

// void Binary_Mul::PrettyPrint(std::ostream &dst){
//     dst << "Identifier: " << identifier_id <<std::endl;
// }
