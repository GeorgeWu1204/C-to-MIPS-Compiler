#include "AST/Iteration/ast_While_MIPS.hpp"

While_Mips::While_Mips(NodePtr Expression_term, NodePtr Statement_term)
{
    branch.push_back(Expression_term);
    branch.push_back(Statement_term);
}

void While_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::string Condition_Label = make_name.makeName("L");
    std::string Evaluate_Label = make_name.makeName("L");
    
    dst<< "b " <<  Condition_Label << std::endl;

    dst<<std::endl;
    dst << std::endl;
    dst << Evaluate_Label << ":" << std::endl;
    branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    
    dst << std::endl;
    dst << std::endl;
    dst << Condition_Label << ": " << std::endl;
    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    // if equal to zero, jump to the top of the loop;
    // else jump out of the loop
    dst << "beq " << "$" <<destReg << " 0 " << Evaluate_Label << std::endl;
    dst << "nop" << std::endl;
    dst << std::endl;
    dst << std::endl;
   
}

bool While_Mips::is_Compound_statement() const{
    return true;
}

int While_Mips::get_context_local_size(){
    return branch[1]->get_context_local_size();
}

std::vector<std::string> While_Mips::return_waiting_to_declared_list(){
    return branch[1]->return_waiting_to_declared_list();
}
