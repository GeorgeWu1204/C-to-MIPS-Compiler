
#include "AST/Declaration/ast_Global_Declaration_MIPS.hpp"

Global_Declaration_Mips::Global_Declaration_Mips(const NodePtr specifier)
{
    branch.push_back(specifier);
}

void Global_Declaration_Mips::generateMips (std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset){
    std::vector<int> var = branch[0]->return_assigned_val();
    // only shows the arrays that has been assigned.
    dst<< branch[0]->get_Id() << ":" << std::endl;
    for (int i = 0; i < var.size(); i++){
        dst <<"      " << ".word" << "    " << var[i] << std::endl;
    }
}

int Global_Declaration_Mips::array_size() const{
    return branch[0]->array_size();
}

std::string Global_Declaration_Mips::get_Id() const{
    return branch[0]->get_Id();
}

std::string Global_Declaration_Mips::get_type() const{
    return branch[0]->get_type();
}

