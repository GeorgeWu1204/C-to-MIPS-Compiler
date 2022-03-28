#include "AST/SelfAssignment/ast_UnaryNot_MIPS.hpp"

// #include "ast_Node.hpp"
// #include "ast.hpp"


UnaryNot_MIPS::UnaryNot_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void UnaryNot_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{


    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    
    dst << "nop" << std::endl;
        dst << "sltu "
        << "$" << destReg << ","
        << "$" << destReg << ","
        << 1 << std::endl;
    dst << "andi "
        << "$" << destReg << ","
        << "$" << destReg << ","
        << "0x00ff" << std::endl;
}

std::string UnaryNot_MIPS::get_Id() const{
    return branch[0]->get_Id();
}

bool UnaryNot_MIPS::is_Function_inside() const
{
    return branch[0]->is_Function_inside();
}


std::string UnaryNot_MIPS::get_cloest_Id() const
{
    return branch[0]->get_cloest_Id();
}
std::string UnaryNot_MIPS::return_expression_type(Context context)
{
    return branch[0]->return_expression_type(context);
}