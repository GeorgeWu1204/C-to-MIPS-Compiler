#include "AST/SelfAssignment/ast_Sizeof_MIPS.hpp"

// #include "ast_Node.hpp"
// #include "ast.hpp"

Sizeof_MIPS::Sizeof_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void Sizeof_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // std::cout << "j" << std::endl;
    // std::cout << branch[0]->get_Id() << std::endl;
    context.print_context();
    // branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    std::string type = context.find_local(branch[0]->get_Id()).type_name;
    // std::cout << "j1" << std::endl;
    int size;
    if (type == "INT")
    {

        size = 4;
    }
    else
    {
        // std::cout << "j3" << std::endl;
        if (context.Type_Str.find(type) != context.Type_Str.end())
        {
            // find struct
            // std::cout << "j4" << std::endl;
            size = context.Type_Str.find(type)->second.type_size;
        }
    }
    dst << "li "
        << "$" << destReg << "," << size << std::endl;
}