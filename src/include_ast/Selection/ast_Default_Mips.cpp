#include "AST/Selection/ast_Default_Mips.hpp"

Default_Mips::Default_Mips(NodePtr statement)
{
    branch.push_back(statement);
}

bool Default_Mips::is_Default() const
{
    return true;
}

bool Default_Mips::is_Compound_statement() const
{
    return branch[0]->is_Compound_statement();
}

int Default_Mips::get_case_index()
{
    // std::cerr << "#"
    //           << "No index for default" << std::endl;
}

void Default_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
}

std::vector<std::string> Default_Mips::return_waiting_to_declared_list()
{
    return branch[0]->return_waiting_to_declared_list();
}

int Default_Mips::get_context_local_size()
{
    return branch[1]->get_context_local_size();
}
