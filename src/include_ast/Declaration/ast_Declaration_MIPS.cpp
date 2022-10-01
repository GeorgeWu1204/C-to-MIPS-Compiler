
#include "AST/Declaration/ast_Declaration_MIPS.hpp"

Declaration_Mips::Declaration_Mips(const NodePtr specifier, const std::vector<NodePtr> declarator_list)
{
    branch.push_back(specifier);
    Node(declarator_list);
}
// Declaration_Mips::Declaration_Mips(const std::string specifier, const NodePtr declarator)
// {
//     Declaration_Mips(new Type_Mips(specifier), declarator);
// }

void Declaration_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // int a(){} new Function definition( new Declaration(), compo)
    // int f(){ int g = 0;} new function
    // int a()
    for(int i = 1; i < branch.size(); i++){
        if (branch[i]->is_Function())
        {
            dst << branch[i]->get_Id() << " :" << std::endl;
            // expect rewriting content for params
        }
        else
        {
            // expect a variable declaration
            std::string type = branch[0]->get_type();

            if (branch[i]->is_init())
            {

                branch[i]->generateMips(dst, context, destReg, make_name, dynamic_offset); // check
            }
            else
            {

                // do nothing for generate mips
            }
        }
    }
}
std::string Declaration_Mips::get_type() const
{
    return branch[0]->get_type();
}

// SOS
// std::string Declaration_Mips::get_Id() const
// {
//     return branch[1]->get_Id();
// }

bool Declaration_Mips::is_Declaration() const
{
    return true;
}

// bool Declaration_Mips::is_Function() const
// {
//     return branch[1]->is_Function();
// }
// bool Declaration_Mips::is_init() const
// {
//     return branch[1]->is_init();
// }
