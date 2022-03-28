#include "AST/Pointer/ast_PointerDeclarator_MIPS.hpp"

PointerDeclarator_MIPS::PointerDeclarator_MIPS(NodePtr var)
{
    branch.push_back(var);
}

void PointerDeclarator_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // if (context.is_Local(get_Id()))
    // {
    //     // if (context.find_local(get_Id()).type_name == "ENUMPtr")
    //     // {
    //     //     // std::cerr << "in correct" << std::endl;
    //     //     dst << "li "
    //     //         << "$" << destReg << "," << context.find_local(get_Id()).enum_val  << std::endl;
    //     // }
    //     // else
    //     // {
    //     dst << "lw "
    //         << "$" << destReg << "," << context.find_local(get_Id()).offset << "("
    //         << "$30"
    //         << ")" << std::endl;
    //     dst << "nop " << std::endl;
    //     dst << "lw "
    //         << "$" << destReg << ","
    //         << "0" << destReg << std::endl;
    //     // }
    // }
    // else if (context.is_Global(get_Id()))
    // {
    //     // if (context.find_global(get_Id()).type_name == "ENUMPtr")
    //     // {
    //     //     // std::cerr << "in correct" << std::endl;
    //     //     dst << "li "
    //     //         << "$" << destReg << "," << context.find_global(get_Id()).enum_val << std::endl;
    //     // }
    //     // else
    //     // {
    //     dst << "lw "
    //         << "$" << destReg << "," << context.find_global(get_Id()).offset << "("
    //         << "$30"
    //         << ")" << std::endl;
    //     dst << "nop " << std::endl;
    //     dst << "lw "
    //         << "$" << destReg << ","
    //         << "0" << destReg << std::endl;
    //     // }
    // }
    // else
    // {
    //     std::cerr << "This behaviour has not been defined yet" << std::endl;
    // }
}

bool PointerDeclarator_MIPS::is_Pointer() const
{
    return true;
}
std::string PointerDeclarator_MIPS::get_Id() const
{
    return branch[0]->get_Id();
}
int PointerDeclarator_MIPS::get_argument_size()
{
    return branch[0]->get_argument_size();
}

std::vector<std::pair<std::string, std::string> > PointerDeclarator_MIPS::get_argument_map(){
    return branch[0]->get_argument_map();
}

bool PointerDeclarator_MIPS::is_Function() const
{
    return branch[0]->is_Function();
}
