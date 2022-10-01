#include "AST/Arithmetic/ast_Addition_MIPS.hpp"
// #include "ast_Node.hpp"
// #include "ast.hpp"

Addition_MIPS::Addition_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{

    // Left = leftinput;
    // Right = rightinput;
}

void Addition_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{

    generate_left(dst, context, 3, branch[0], make_name, dynamic_offset); //Identifier
    generate_right(dst, context, 4, branch[1], make_name, dynamic_offset); //Express
    if(branch[0]->is_Identifier() || branch[0]->is_Constant()){
        generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);
    }else{
        dst << "lw "
            << "$3 " << branch[0]->return_dynamic_offset() << "($30)" << std::endl;
    }
    if(branch[1]->is_Identifier() || branch[1]->is_Constant()){
        generate_left(dst, context, 4, branch[1], make_name, dynamic_offset);
    }else{
        dst << "lw "
            << "$4 " << branch[1]->return_dynamic_offset() << "($30)" << std::endl;
    }
    std::string type = context.find_local("$DynamicContext").type_name;
    if (type == "INT")
    {
        dynamic_offset += 4;
    }
    else if (type == "DOUBLE")
    {
        dynamic_offset += 8;
    }
    else
    {
        std::cout << "Dynamic Reference Type not set up" << std::endl;
    }
    current_offset = dynamic_offset;
    dst << "nop" << std::endl;
    dst << "add "
        << "$" << destReg << ", "
        << "$"
        << "3"
        << ", "
        << "$"
        << "4" << std::endl;

    dst << "sw "
        << "$" << destReg << " " << current_offset << "($30)" << std::endl;
}
    // if(branch[0]->is_Identifier()){
    //     dst << "lw "
    //             << "$" << destReg << " " << (context.find_local(branch[0]->get_Id())).offset << "("
    //             << "$30"
    //             << ")" << std::endl;
    // }else if(branch[0]->is_Constant()){
    //     generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);
    // }

