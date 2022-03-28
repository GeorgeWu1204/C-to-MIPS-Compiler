#include "AST/Declaration/ast_Declare_Array_MIPS.hpp"

Declare_Array_Mips::Declare_Array_Mips(const NodePtr header)
{
    branch.push_back(header);
}

Declare_Array_Mips::Declare_Array_Mips(const NodePtr header, const NodePtr size)
{
    branch.push_back(header);
    branch.push_back(size);
}

// int g[3] = {3,4 ,5,}; init_declaration -> done in assignment
// int g[3] = {};        init_declaration -> done in assignment
// int g[3];             ignored
// void Declare_Array_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset){

// }
bool Declare_Array_Mips::is_Array() const
{
    return true;
}

std::string Declare_Array_Mips::get_type() const
{
    return branch[0]->get_type();
}


std::string Declare_Array_Mips::get_Id() const
{
    return branch[0]->get_Id();
}

int Declare_Array_Mips::get_arithmetic_const_val()
{
    return branch[1]->get_arithmetic_const_val();
}


