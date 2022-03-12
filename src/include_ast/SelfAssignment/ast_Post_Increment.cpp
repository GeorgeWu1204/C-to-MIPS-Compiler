#include "AST/SelfAssignment/ast_Post_Increment_MIPS.hpp"

// #include "ast_Node.hpp"
// #include "ast.hpp"

Post_Increment_MIPS::Post_Increment_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void Post_Increment_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{


    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    
    dst << "nop" << std::endl;
    dst << "addiu"
        << "$" << 3 << ", "
        << "$" << destReg 
        << " 1"<< std::endl;
    
    dst << "sw" << "$" <<3 <<" " 
    << context.find_local(branch[0]->get_Id()).offset 
    << "(" << "$30" << ")" << std::endl;

   
}
