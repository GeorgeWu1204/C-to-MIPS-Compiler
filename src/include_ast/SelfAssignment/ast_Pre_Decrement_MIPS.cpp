#include "AST/SelfAssignment/ast_Pre_Decrement_MIPS.hpp"

// #include "ast_Node.hpp"
// #include "ast.hpp"


Pre_Decrement_MIPS::Pre_Decrement_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void Pre_Decrement_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{


    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    
    dst << "nop" << std::endl;
        dst << "addiu"
        << "$" << destReg << ", "
        << "$" << destReg 
        << " -1"<< std::endl;
        
    dst << "sw" << "$" <<destReg <<" " 
    << context.find_local(branch[0]->get_Id()).offset 
    << "(" << "$30" << ")" << std::endl;
}
