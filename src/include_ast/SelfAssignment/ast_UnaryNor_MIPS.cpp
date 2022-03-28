#include "AST/SelfAssignment/ast_UnaryNor_MIPS.hpp"

// #include "ast_Node.hpp"
// #include "ast.hpp"


UnaryNor_MIPS::UnaryNor_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void UnaryNor_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{


    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    
    dst << "nop" << std::endl;
    dst << "nor "
        << "$" << destReg << ","
        << "$0,"  
        << "$" << destReg << std::endl;
        
}

std::string UnaryNor_MIPS::get_Id() const{
    return branch[0]->get_Id();
}


bool UnaryNor_MIPS::is_Function_inside() const
{
    return branch[0]->is_Function_inside();
}

std::string UnaryNor_MIPS::get_cloest_Id() const
{
    return branch[0]->get_cloest_Id();
}

std::string UnaryNor_MIPS::return_expression_type(Context context)
{
    return branch[0]->return_expression_type(context);
}