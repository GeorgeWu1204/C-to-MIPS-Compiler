#include "AST/Type/ast_String_LITTERAL_MIPS.hpp"

STRING_LITTERAL_MIPS::STRING_LITTERAL_MIPS( std::string input)
    : string_variable(input)
    { }

void STRING_LITTERAL_MIPS::generateMips(std::ostream &dst, Context &context,  int destReg, MakeName &make_name) 
{
// assign the val to a register? allocate register 
}
// void STRING_LITTERAL_MIPS::prettyPrint(std::ostream &dst){
//     dst << "String = " << string_variable << std::endl;
// }

std::string STRING_LITTERAL_MIPS::get_StringVal() const 
{
    //SOS should be at the bottom already
    // if(branch.empty()){
    //     return identifier_id;
    // }
    // else{
    //     return branch[0]->get_Name();
    // }
    return string_variable;
}





