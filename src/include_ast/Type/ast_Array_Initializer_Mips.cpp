
#include "AST/Type/ast_Array_Initializer_Mips.hpp"

Array_Initializer_Mips::Array_Initializer_Mips(std::vector<NodePtr> input)
    : Node(input)
{}

// void Array_Initializer_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
// {
//     std::string id = branch[0]->get_Id();
//     branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
// }

// std::vector<int> Array_Initializer_Mips::return_assigned_val (){
//     std::vector<int> tmp;
//     for(int i = 1; i < branch.size(); i++){
//         tmp.push_back()
//     }
// }

bool Array_Initializer_Mips::is_Array_Initializer() const
{
    return true;
}
