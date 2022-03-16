#include "AST/Type/ast_Enumerator_Mips.hpp"

Enumerator_Mips::Enumerator_Mips(const std::string &input, NodePtr Constant_expression)
{
    enumerator_name = input;
    branch.push_back(Constant_expression);
}
Enumerator_Mips::Enumerator_Mips(const std::string &input)
{
    enumerator_name = input;
    branch.push_back(new Node());
}


void Enumerator_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
}

int Enumerator_Mips::get_Val() const
{
    return branch[0]->get_Val();
}
std::string Enumerator_Mips::get_Id() const
{
  return enumerator_name;
}

bool Enumerator_Mips::is_Enum() const
{
  return true;
}