
#include "AST/Function/ast_Function_Declarator_MIPS.hpp"

Function_Declarator_Mips::Function_Declarator_Mips(NodePtr direct_declarator)
{
    branch.push_back(direct_declarator);
}

Function_Declarator_Mips::Function_Declarator_Mips(NodePtr direct_declarator, std::vector<NodePtr> argument_list)
{
    branch.push_back(direct_declarator);
    for(int i = 0; i < argument_list.size(); i++){
        branch.push_back(argument_list[i]);
    }
}

void Function_Declarator_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    dst << "function_declarator " << std::endl;
}

bool Function_Declarator_Mips::is_Function() const
{
    return true;
}

std::string Function_Declarator_Mips::get_Id() const
{
    return branch[0]->get_Id();
}

int Function_Declarator_Mips::get_argument_size(){
    return branch.size() - 1;
}

std::map<std::string, std::string> Function_Declarator_Mips::get_argument_map(){
    std::map<std::string , std::string> tmp;
    //std::cout << "inside Function get argument " << std::endl;
    for( int i = 1; i < branch.size(); i ++){
        tmp.insert(std::make_pair(branch[i]->get_Id(), branch[i]->get_type()));
    }
    return tmp;
} 
