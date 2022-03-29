#include "AST/SelfAssignment/ast_Sizeof_MIPS.hpp"

// #include "ast_Node.hpp"
// #include "ast.hpp"

Sizeof_MIPS::Sizeof_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void Sizeof_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{

    // Type 1 SIZEOF Unary_expression                                             {$$ = new Sizeof_MIPS($2); }
    // Type 2 SIZEOF    '(' Type_name ')'

    if (branch[0]->is_Type_Specified())
    {
        // Type 2
        std::string tmp = branch[0]->get_type();
        int tmp_size = 0;
        if (tmp == "INT" || tmp == "FLOAT" || tmp == "UNSIGNED")
        {
            tmp_size = 4;
        }
        else if (tmp == "DOUBLE")
        {
            tmp_size = 8;
        }
        else if (tmp == "CHAR")
        {
            tmp_size = 1;
        }
        else if (tmp == "VOID")
        {
            tmp_size = 0;
        }
        dst << "li "
            << "$" << destReg << "," << tmp_size << std::endl;
    }

    else
    {
        // Type 1
        //  std::cerr << "j" << std::endl;
        // std::cerr << branch[0]->get_Id() << std::endl;
        std::string type;
        if (branch[0]->is_Identifier())
        {
            std::cerr << "# " << branch[0]->is_Identifier() << std::endl;
            if (context.is_Local(branch[0]->get_Id()))
            {
                type = context.find_local(branch[0]->get_Id()).type_name;
                std::cerr << "# " << type << std::endl;
            }
            else if (context.is_Global(branch[0]->get_Id()))
            {
                type = context.find_local(branch[0]->get_Id()).type_name;
            }
            else
            {
                std::cerr << "# Size couldnt be found" << std::endl;
            }
        }
        else
        {
            type = branch[0]->return_expression_type(context);
        }
        // branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        // std::cerr << "j1" << std::endl;
        std::cerr << "# " << type << std::endl;
        int size;
        if (type == "INT" || type == "FLOAT" || type == "UNSIGNED")
        {
            size = 4;
        }
        else if (type == "DOUBLE")
        {
            size = 8;
        }
        else if (type == "CHAR")
        {
            size = 1;
        }
        else if (type == "VOID")
        {
            size = 0;
        }
        else if (type.substr(0, 6) == "STRUCT")
        {
            if (context.Type_Str.find(type) != context.Type_Str.end())
            {
                // find struct
                size = context.Type_Str.find(type)->second.type_size;
            }
        }

        dst << "li "
            << "$" << destReg << "," << size << std::endl;
    }
}