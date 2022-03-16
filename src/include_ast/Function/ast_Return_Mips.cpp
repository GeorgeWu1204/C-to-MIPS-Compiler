#include "AST/Function/ast_Return_Mips.hpp"

Return_Mips::Return_Mips(NodePtr Expression)
{
    branch.push_back(Expression);
}
Return_Mips::Return_Mips()
{
    Return_Mips(new Node());
}

void Return_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{

    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
}

std::string Return_Mips::get_Id() const
{
    return branch[0]->get_Id();
}

bool Return_Mips::is_Function_inside() const{
    return branch[0]->is_Function_inside();
}

bool Return_Mips::is_Jump_statement() const{
    return true;
}


