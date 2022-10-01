#include "AST/Pointer/ast_UnaryPointer_MIPS.hpp"

UnaryPointer_MIPS::UnaryPointer_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void UnaryPointer_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    if (context.is_Local(get_Id()))
    {

        if (context.find_local(get_Id()).type_name == "CHARPTR")
        {
            dst << "lw "
                << "$" << destReg << "," << context.find_local(get_Id()).offset << "("
                << "$30"
                << ")" << std::endl;
            dst << "nop " << std::endl;
            dst << "lb "
                << "$" << destReg << ","
                << "0"
                << "($" << destReg << ")" << std::endl;
        }
        else
        {
            dst << "lw "
                << "$" << destReg << "," << context.find_local(get_Id()).offset << "("
                << "$30"
                << ")" << std::endl;
            dst << "nop " << std::endl;
            dst << "lw "
                << "$" << destReg << ","
                << "0"
                << "($" << destReg << ")" << std::endl;
        }

        // }
    }
    else if (context.is_Global(get_Id()))
    {

        if (context.find_global(get_Id()).type_name == "CHARPTR")
        {
            dst << "lw "
                << "$" << destReg << "," << context.find_global(get_Id()).offset << "("
                << "$30"
                << ")" << std::endl;
            dst << "nop " << std::endl;
            dst << "lb "
                << "$" << destReg << ","
                << "0"
                << "($" << destReg << ")" << std::endl;
        }
        else
        {
            dst << "lw "
                << "$" << destReg << "," << context.find_global(get_Id()).offset << "("
                << "$30"
                << ")" << std::endl;
            dst << "nop " << std::endl;
            dst << "lw "
                << "$" << destReg << ","
                << "0"
                << "($" << destReg << ")" << std::endl;
        }
    }
    else
    {
        std::cerr << "This behaviour has not been defined yet" << std::endl;
    }
}

void UnaryPointer_MIPS::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
    if (context.is_Local(get_Id()))
    {
        dst << "lw "
            << "$" << destReg << "," << context.find_local(get_Id()).offset << "("
            << "$30"
            << ")" << std::endl;
        dst << "nop " << std::endl;
        dst << "lwc1 "
            << "$f" << destReg << ","
            << "0"
            << "($" << destReg << ")" << std::endl; // }
    }
    else if (context.is_Global(get_Id()))
    {

        dst << "lw "
            << "$" << destReg << "," << context.find_global(get_Id()).offset << "("
            << "$30"
            << ")" << std::endl;
        dst << "nop " << std::endl;
        dst << "lwc1 "
            << "$f" << destReg << ","
            << "0"
            << "($" << destReg << ")" << std::endl;
    }
    else
    {
        std::cerr << "This behaviour has not been defined yet" << std::endl;
    }
}

bool UnaryPointer_MIPS::is_Pointer() const
{
    return true;
}
std::string UnaryPointer_MIPS::get_Id() const
{
    return branch[0]->get_Id();
}
std::string UnaryPointer_MIPS::return_expression_type(Context context)
{
    std::cerr << "# Pointer sizing, returing int " << std::endl;
    return "INT";
}