#include "AST/ast_Assignment_Expression_Mips.hpp"

Assignment_Expression_Mips::Assignment_Expression_Mips(const NodePtr Unary_expression, NodePtr Assignment_expression)
{
    branch.push_back(Unary_expression);
    branch.push_back(Assignment_expression);
}
Assignment_Expression_Mips::Assignment_Expression_Mips(const NodePtr ConditionalExpression)
{
    branch.push_back(ConditionalExpression);
}

std::string Assignment_Expression_Mips::get_Id() const
{
    return branch[0]->get_Id();
}
//right hand side
// 
// int Assignment_Expression_Mips::get_Val() const
// {
//     return branch[1]->get_Val();
// }

void Assignment_Expression_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    if(branch.size() == 0){
        //condition expression
        branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    }
    else{
        // unary expression assignment expression
        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset); // check
        if (branch[0]->is_Identifier() && context.is_Local(branch[0]->get_Id()))
        {
            dst << "sw"
                << " $" << destReg << ", " << context.find_local(branch[0]->get_Id()).offset << "("
                << "$30"
                << ")" << std::endl;
        }

    }
};