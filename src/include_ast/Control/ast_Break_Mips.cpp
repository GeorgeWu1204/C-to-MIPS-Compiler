#include "AST/Control/ast_Break_Mips.hpp"

void Break_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
}
bool Break_Mips::is_Break() const
{
    return true;
}
