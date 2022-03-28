#include "AST/Selection/ast_Case_Mips.hpp"
Case_Mips::Case_Mips(NodePtr constantExpression, NodePtr statement)
{
    branch.push_back(constantExpression);
    branch.push_back(statement);
}

bool Case_Mips::is_Case() const
{
    return true;
}

bool Case_Mips::is_Compound_statement() const
{
    return branch[1]->is_Compound_statement();
}

int Case_Mips::get_case_index()
{
    return branch[0]->get_Val();
}

void Case_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
}

std::vector<std::string> Case_Mips::return_waiting_to_declared_list()
{
    return branch[1]->return_waiting_to_declared_list();
}

int Case_Mips::get_context_local_size()
{
    return branch[1]->get_context_local_size();
}