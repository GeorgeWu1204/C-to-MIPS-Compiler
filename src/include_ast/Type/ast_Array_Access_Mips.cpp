#include "AST/Type/ast_Array_Access_Mips.hpp"



Array_Access_Mips::Array_Access_Mips(NodePtr Postfix_expression, NodePtr Expression)
{
    branch.push_back(Postfix_expression);
    branch.push_back(Expression);
}

void Array_Access_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::string id = branch[0]->get_Id();
    branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
}