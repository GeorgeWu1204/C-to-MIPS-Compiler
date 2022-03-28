#include "AST/Arithmetic/ast_LogicOr_MIPS.hpp"

LogicOr_MIPS::LogicOr_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void LogicOr_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);  // Identifier
    generate_right(dst, context, 4, branch[1], make_name, dynamic_offset); // Express
    // std::cerr << "#"
    //           << "Dynamic Offset: " << dynamic_offset << std::endl;
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
    std::string false_position = make_name.makeName("L");
    std::string suc_position = make_name.makeName("L");
    std::string jump_out = make_name.makeName("L");

    current_offset = dynamic_offset;
    dst << "nop" << std::endl;
    // greater than
    dst << "bne "
        << "$3,"
        << "$0," << suc_position << std::endl;
    // greater than
    dst << "nop " << std::endl;
    dst << "beq "
        << "$4,"
        << "$0," << false_position << std::endl;
    dst << "nop " << std::endl;
    dst << "li "
        << "$2," << 1 << std::endl;
    dst << "b " << jump_out << std::endl;
    dst << "nop " << std::endl;
    dst << std::endl;
    dst << false_position << ":" << std::endl;
    dst << "move "
        << "$" << destReg << ",$0" << std::endl;
    dst << std::endl;
    dst << jump_out << ":" << std::endl;
    dst << "sw "
        << "$" << destReg << "," << current_offset << "($30)" << std::endl;
    // greater than
}

int LogicOr_MIPS::get_arithmetic_const_val()
{
    return branch[0]->get_arithmetic_const_val() || branch[1]->get_arithmetic_const_val();
}
