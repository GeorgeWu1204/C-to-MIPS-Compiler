#include "AST/Pointer/ast_UnaryAddress_MIPS.hpp"

// #include "ast_Node.hpp"
// #include "ast.hpp"

UnaryAddress_MIPS::UnaryAddress_MIPS(NodePtr Expression_term_1)
{
    branch.push_back(Expression_term_1);
}

void UnaryAddress_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    if (context.is_Local(get_Id()))
    {
        // if (context.find_local(get_Id()).type_name == "ENUMPtr")
        // {
        //     // std::cerr << "in correct" << std::endl;
        //     dst << "li "
        //         << "$" << destReg << "," << context.find_local(get_Id()).enum_val  << std::endl;
        // }
        // else
        // {
        dst << "addiu "
            << "$" << destReg << ","
            << "$30"
            << "," << context.find_local(get_Id()).offset << std::endl;
        // }
    }
    else if (context.is_Global(get_Id()))
    {
        // if (context.find_global(get_Id()).type_name == "ENUMPtr")
        // {
        //     // std::cerr << "in correct" << std::endl;
        //     dst << "li "
        //         << "$" << destReg << "," << context.find_global(get_Id()).enum_val << std::endl;
        // }
        // else
        // {
        dst << "addiu "
            << "$" << destReg << ","
            << "$30"
            << "," << context.find_local(get_Id()).offset << std::endl;
        // }
    }
    else
    {
        std::cerr << "This behaviour has not been defined yet" << std::endl;
    }
}

std::string UnaryAddress_MIPS::get_Id() const
{
    return branch[0]->get_Id();
}