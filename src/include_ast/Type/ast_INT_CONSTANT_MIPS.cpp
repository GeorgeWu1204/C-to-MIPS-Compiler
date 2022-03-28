#include "AST/Type/ast_INT_CONSTANT_MIPS.hpp"

Int_Constant_Mips::Int_Constant_Mips(const int input)
    : int_number(input)
{
}

void Int_Constant_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    dst << "li "
        << "$" << destReg << "," << get_Val() << std::endl;
    // assign the val to a register? allocate register
}
// void Int_Constant_Mips::prettyPrint(std::ostream &dst)
// {
//     dst << "Integer = " << int_number << std::endl;
// }

int Int_Constant_Mips::get_Val() const
{
    return int_number;
}

bool Int_Constant_Mips::is_Constant() const
{
    return true;
}

int Int_Constant_Mips::get_arithmetic_const_val() {
    return int_number;
}
std::string Int_Constant_Mips::get_cloest_Id() const
{
    return "$INT";
}
// int Int_Constant_Mips::array_size() const {
//     return int_number;
// }