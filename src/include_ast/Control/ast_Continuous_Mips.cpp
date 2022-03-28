#include "AST/Control/ast_Continuous_Mips.hpp"

void Continuous_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
}
bool Continuous_Mips::is_Continue() const
{
    return true;
}
