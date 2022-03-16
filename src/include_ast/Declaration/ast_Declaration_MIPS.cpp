#include "AST/Declaration/ast_Declaration_MIPS.hpp"

Declaration_Mips::Declaration_Mips(const NodePtr specifier, const std::vector<NodePtr> declarator_list)
{
    branch.push_back(specifier);
    for( int i = 0; i < declarator_list.size(); i++){
        branch.push_back(declarator_list[i]);
    }
    std::cout << "done" << std::endl;
}
Declaration_Mips::Declaration_Mips(const NodePtr specifier, const NodePtr declarator)
{
    //std::cout << "constructing Declaaration Mips" << std::endl;
    branch.push_back(specifier);
    branch.push_back(declarator);
    //std::cout << "Passing it to Vector" << branch.size() <<std::endl;
}

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
std::string Declaration_Mips::get_Id() const
{
    //int f();
    return branch[1]->get_Id();
        // std::string Declaration_Mips_ID(branch[1]->get_Id());
        // for(int i = 1; i < branch.size() ; i++){
        //     Declaration_Mips_ID.insert(Declaration_Mips_ID.end(),branch[i]->get_Id().begin(),branch[i]->get_Id().end());
        // }
        // return Declaration_Mips_ID;
    
}

bool Declaration_Mips::is_Declaration() const
{
    return true;
}

int Declaration_Mips::get_argument_size(){
    //std::cout << "inside declaration mips" << branch[1]->get_argument_size()<< std::endl;
    return branch[1]->get_argument_size();
}

std::map<std::string, std::string> Declaration_Mips::get_argument_map(){
    return branch[1]->get_argument_map();
}
// bool Declaration_Mips::is_Function() const
// {
//     return branch[1]->is_Function();
// }
// bool Declaration_Mips::is_init() const
// {
//     return branch[1]->is_init();
// }
