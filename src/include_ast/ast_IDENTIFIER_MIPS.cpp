#include "AST/ast_IDENTIFIER_MIPS.hpp"

Identifier_Mips::Identifier_Mips(const std::string &input)
    : identifier_id(input)
{
}

void Identifier_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // Declaration might go here?

    // to check if it is in the context
    //  if in context

    if (context.is_Local(identifier_id))
    {
        dst << "lw"
            << " $" << destReg << ", " << context.find_local(identifier_id).offset << "("
            << "$30"
            << ")" << std::endl;
    }
    else
    {
        std::cerr << "This behaviour has not been defined yet";
    }
}

std::string Identifier_Mips::get_Id() const
{
    // SOS should be at the bottom already
    //  if(branch.empty()){
    //      return identifier_id;
    //  }
    //  else{
    //      return branch[0]->get_Name();
    //  }
    return identifier_id;
}
// SOS

std::vector<std::string> Identifier_Mips::return_waiting_to_declared_list()
{
    std::cout << " SOS: Maybe you are swred" << std::endl;
    std::vector<std::string> a;
    a.push_back(identifier_id);
    return a;
}

bool Identifier_Mips::is_Identifier() const
{
    return true;
}

// void Identifier_MIPS::PrettyPrint(std::ostream &dst)
// {
//     dst << "Identifier: " << identifier_id << std::endl;
// }
