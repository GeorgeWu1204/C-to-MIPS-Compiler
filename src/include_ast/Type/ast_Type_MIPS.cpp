#include "AST/Type/ast_Type_MIPS.hpp"

Type_Mips::Type_Mips(const std::string &input)
{
    type_specifier = input;    
}



std::string Type_Mips::get_type() const
{
    return type_specifier;
};


bool Type_Mips::is_Type_Specified() const{
    return true;
}
