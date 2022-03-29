#include "AST/Pointer/ast_PointerDeclarator_MIPS.hpp"

PointerDeclarator_MIPS::PointerDeclarator_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void PointerDeclarator_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{ }

bool PointerDeclarator_MIPS::is_Pointer() const
{
    return true;
}
std::string PointerDeclarator_MIPS::get_Id() const
{
    return branch[0]->get_Id();
}
int PointerDeclarator_MIPS::get_argument_size()
{
    return branch[0]->get_argument_size();
}

std::vector<std::pair<std::string, std::string> > PointerDeclarator_MIPS::get_argument_map(){
    return branch[0]->get_argument_map();
}

bool PointerDeclarator_MIPS::is_Function() const
{
    return branch[0]->is_Function();
}
