#include "AST/SelfAssignment/ast_UnarySub_MIPS.hpp"

// #include "ast_Node.hpp"
// #include "ast.hpp"


UnarySub_MIPS::UnarySub_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void UnarySub_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    
    dst << "nop" << std::endl;
        dst << " subu "
        << "$" << destReg << ","
        << "$" << 0 << ","
        << "$" << destReg << std::endl;
}

std::string UnarySub_MIPS::get_Id() const{
    return branch[0]->get_Id();
}


bool UnarySub_MIPS::is_Function_inside() const
{
    return branch[0]->is_Function_inside();
}
std::string UnarySub_MIPS::get_cloest_Id() const
{
    return branch[0]->get_cloest_Id();
}