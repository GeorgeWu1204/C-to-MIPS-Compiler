#include "AST/ast_Root_MIPS.hpp"

Root_Mips::Root_Mips(std::vector<NodePtr> root_input)
    : Node(root_input)
{
    build_global_context();
}

void Root_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    context.replace_global_var(Global_context);
    //context.print_global();
    for (int i = 0; i < branch.size(); i++)
    {
        branch[i]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        
    }
}

void Root_Mips::build_global_context(){
    for (int i = 0; i < branch.size(); i++){
        if(branch[i]->is_Function() == false){
            // that means this branch node is a global declaration
            for(int g = 0; g < branch[i]->get_size(); g++){
                //std::cout<<"inside global " << i << std::endl;

                NodePtr tmp = branch[i]->get_branch(g);
                //std::cout << "property    " <<  tmp->get_type()<< " | "<< branch[i]->array_size() << std::endl;
                Global_var var(tmp->get_type(), branch[i]->array_size());
                Global_context.insert(std::make_pair(tmp->get_Id(), var));
            }

        }
    }
}
