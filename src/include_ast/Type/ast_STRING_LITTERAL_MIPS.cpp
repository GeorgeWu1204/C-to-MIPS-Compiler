#include "AST/Type/ast_String_LITTERAL_MIPS.hpp"

STRING_LITTERAL_MIPS::STRING_LITTERAL_MIPS(std::string input)
{
    std::cerr << "# <----------------------input : " << input << "------------------------>" << std::endl;
    string_variable = input;
    string_variable.erase(0, 1);
    string_variable.erase(string_variable.size() - 1);
}

void STRING_LITTERAL_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{

    std::string tmp = context.String_str.find(string_variable)->second;
    dst << "lui "
        << "$" << destReg << ",%hi"
        << "($" << tmp << ")" << std::endl;
    dst << "addiu "
        << "$" << destReg << ","
        << "$" << destReg << ",%lo($" << tmp << ")" << std::endl;
}
// void STRING_LITTERAL_MIPS::prettyPrint(std::ostream &dst){
//     dst << "String = " << string_variable << std::endl;
// }

std::string STRING_LITTERAL_MIPS::get_StringVal() const
{
    return string_variable;
}

std::vector<std::string> STRING_LITTERAL_MIPS::get_String_Const()
{

    std::vector<std::string> a;
    a.push_back(string_variable);
    std::cerr << "# <----------------------push back: " << a[0] << "------------------------>" << std::endl;
    return a;
}

std::string STRING_LITTERAL_MIPS::get_type() const
{
    return "STRING";
}

bool STRING_LITTERAL_MIPS::is_Constant() const
{
    return true;
}