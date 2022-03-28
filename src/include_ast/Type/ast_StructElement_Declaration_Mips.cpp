#include"AST/Type/ast_StructElement_Declaration_Mips.hpp"


StructElement_Declaration_Mips::StructElement_Declaration_Mips(const NodePtr type_name, const std::vector<NodePtr> Declare_list ){
    branch.push_back(type_name);
    for (int i  = 0; i < Declare_list.size(); i++){
        branch.push_back(Declare_list[i]);
    }
}

std::string StructElement_Declaration_Mips::get_type() const
{
    return branch[0]->get_type();
}

