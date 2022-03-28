#include "AST/Type/ast_Struct_Declaration_Mips.hpp"

Struct_Declaration_Mips::Struct_Declaration_Mips(const std::string &identifier){
    struct_name = identifier;
}

std::string Struct_Declaration_Mips::get_Id() const{
    return struct_name;
}

std::string Struct_Declaration_Mips::get_type() const
{
    return "STRUCT" + struct_name;
}
// std::string Declare_struct_Mips::get_type() const{
//     return "STRUCT" + branch[0]->get_Id();
// }

bool Struct_Declaration_Mips::is_Struct_Declaration() const{
    return true;
}

