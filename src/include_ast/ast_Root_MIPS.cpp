#include "AST/ast_Root_MIPS.hpp"

Root_Mips::Root_Mips(std::vector<NodePtr> root_input)
    : Node(root_input)
{
}

void Root_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    context.replace_global_var(Global_context);
    for (int i = 0; i < branch.size(); i++)
    {
        branch[i]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        
    }
}

void Root_Mips::build_global_context(){
    for (int i = 0; i < branch.size(); i++){
        if(branch[i]->is_Function() == false){
            // that means this branch node is a global declaration
            Global_var var(branch[i]->get_type(), branch[i]->array_size());
            Global_context.insert(make_pair(branch[i]->get_Id(), var));
        }
    }
}
