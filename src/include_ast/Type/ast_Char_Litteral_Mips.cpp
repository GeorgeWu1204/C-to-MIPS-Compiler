#include "AST/Type/ast_Char_Litteral_Mips.hpp"

Char_Litteral_Mips::Char_Litteral_Mips(int value)
    
{
    char_litteral = value;
}

Char_Litteral_Mips::Char_Litteral_Mips()
    : char_litteral(0)
{
}

void Char_Litteral_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    dst << "li "
        << "$" << destReg << "," << char_litteral << std::endl;
    // assign the val to a register? allocate register
}

int Char_Litteral_Mips::get_Val() const
{
  return char_litteral;
}
