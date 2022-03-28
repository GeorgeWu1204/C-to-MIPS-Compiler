#include "AST/Arithmetic/ast_Less_Than_MIPS.hpp"

Less_Than_MIPS::Less_Than_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void Less_Than_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::cerr << "#"
              << "LESS THAMN" << std::endl;
    generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);  // Identifier
    generate_right(dst, context, 4, branch[1], make_name, dynamic_offset); // Express
    std::cerr << "#"
              << "Dynamic Offset: " << dynamic_offset << std::endl;
    if (branch[0]->is_Identifier() || branch[0]->is_Constant() || branch[0]->is_Struct_Call()|| branch[0]->is_Pointer())
    {
        generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);
    }
    else
    {
        dst << "lw "
            << "$3," << branch[0]->return_dynamic_offset() << "($30)" << std::endl;
    }
    if (branch[1]->is_Identifier() || branch[1]->is_Constant() || branch[1]->is_Struct_Call() || branch[1]->is_Pointer())
    {
        generate_left(dst, context, 4, branch[1], make_name, dynamic_offset);
    }
    else
    {
        dst << "lw "
            << "$4," << branch[1]->return_dynamic_offset() << "($30)" << std::endl;
    }
    std::string type = context.find_local("$DynamicContext").type_name;
    // std::cerr << "#" << context.find_local("$DynamicContext").type_name << std::endl;
    if (type == "INT")
    {
        dynamic_offset -= 4;
    }
    else if (type == "DOUBLE")
    {
        dynamic_offset -= 8;
    }
    else
    {
        // std::cerr << "#" << "ADD error Dynamic Reference Type not set up" << std::endl;
    }
    current_offset = dynamic_offset;
    dst << "nop" << std::endl;
    dst << "slt "
        << "$" << destReg << ","
        << "$3"
        << ","
        << "$4" << std::endl;

    dst << "sw "
        << "$" << destReg << "," << current_offset << "($30)" << std::endl;
    // less than, if $3 < $4
}

int Less_Than_MIPS::get_arithmetic_const_val()
{
    return branch[0]->get_arithmetic_const_val() < branch[1]->get_arithmetic_const_val();
}
