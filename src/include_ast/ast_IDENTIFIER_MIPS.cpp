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
        std::string type = context.find_local(identifier_id).type_name;
        if (context.find_local(identifier_id).type_name == "ENUM")
        {
            // std::cerr << "in correct" << std::endl;
            dst << "li "
                << "$" << destReg << "," << context.find_local(identifier_id).enum_val << std::endl;
        }
        else
        {
            if (type == "DOUBLE" || type == "FLOAT")
            {
                generateFloatMips(dst, context, destReg, make_name, dynamic_offset, type);
            }
            else if (type == "CHAR")
            {
                dst << "lb "
                    << "$" << destReg << "," << context.find_local(identifier_id).offset << "("
                    << "$30"
                    << ")" << std::endl;
            }
            else
            {
                // std::cerr << "adse----" <<  type << std::endl;
                dst << "lw "
                    << "$" << destReg << "," << context.find_local(identifier_id).offset << "("
                    << "$30"
                    << ")" << std::endl;
            }
        }
    }
    else if (context.is_Global(identifier_id))
    {
        std::cerr << "#inside global scope" << std::endl;
        std::string type = context.find_global(identifier_id).type_name;
        if (context.find_global(identifier_id).type_name == "ENUM")
        {
            dst << "li "
                << "$" << destReg << "," << context.find_global(identifier_id).enum_val << std::endl;
        }
        else
        {
            if (type == "DOUBLE" || type == "FLOAT")
            {
                
                generateFloatMips(dst, context, destReg, make_name, dynamic_offset, type);
            }
            else
            {
                dst << "lui $" << destReg << ",%hi"
                    << "(" << identifier_id << ")" << std::endl;
                dst << "lw "
                    << "$" << destReg << ","
                    << "%lo"
                    << "(" << identifier_id << ")("
                    << "$" << destReg << ")" << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "This behaviour has not been defined yet" << std::endl;
    }
}

// not sure about the type param yet
void Identifier_Mips::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
    // Declaration might go here?

    // to check if it is in the context
    //  if in context
    // std::cerr << "<----------------------------------identifier " << type << " ------------------------------------->" << std::endl;
    if (context.is_Local(identifier_id))
    {
        // std::string type = context.find_local(identifier_id).type_name ;
        if (type == "ENUM")
        {
            // std::cerr << "in correct" << std::endl;
            dst << "li "
                << "$" << destReg << "," << context.find_local(identifier_id).enum_val << std::endl;
        }
        else if (type == "DOUBLE")
        {
            dst << "lwc1 "
                << "$f" << destReg << "," << stoi(context.find_local(identifier_id).offset) << "($30)" << std::endl;
            dst << "nop " << std::endl;
            dst << "lwc1 "
                << "$f" << destReg + 1 << "," << stoi(context.find_local(identifier_id).offset) - 4 << "($30)" << std::endl;
        }
        else if (type == "FLOAT")
        {
            dst << "lwc1 "
                << "$f" << destReg << "," << context.find_local(identifier_id).offset << "($30)" << std::endl;
        }
        else
        {
            dst << "lw "
                << "$" << destReg << "," << context.find_local(identifier_id).offset << "("
                << "$30"
                << ")" << std::endl;
        }
    }
    else if (context.is_Global(identifier_id))
    {
        if (type == "ENUM")
        {
            // std::cerr << "in correct" << std::endl;
            dst << "li "
                << "$" << destReg << "," << context.find_global(identifier_id).enum_val << std::endl;
        }
        else if (type == "DOUBLE")
        {
            dst << "lui "
                << "$2,%hi(" << identifier_id << ")" << std::endl;
            dst << "lwc1 "
                << "$f" << destReg << ",%lo(" << identifier_id << "+4)($2)" << std::endl;
            dst << "nop " << std::endl;
            dst << "lwc1 "
                << "$f" << destReg + 1 << ",%lo(" << identifier_id << ")($2)" << std::endl;
            dst << "nop " << std::endl;
        }
        else if (type == "FLOAT")
        {

            dst << "lui "
                << "$2,%hi(" << identifier_id << ")" << std::endl;
            dst << "lwc1 "
                << "$f" << destReg << ",%lo(" << identifier_id << ")($2)" << std::endl;
            dst << "nop " << std::endl;
        }
        else
        {
            dst << "lw "
                << "$" << destReg << "," << context.find_global(identifier_id).offset << "("
                << "$30"
                << ")" << std::endl;
        }
    }
    else
    {
        std::cerr << "This behaviour has not been defined yet" << std::endl;
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
    // std::cerr << "in get id" << identifier_id <<std::endl;
    return identifier_id;
}
// SOS

std::vector<std::string> Identifier_Mips::return_waiting_to_declared_list()
{
    // std::cerr << "#" << " SOS: Maybe you are swred" << std::endl;
    std::vector<std::string> a;
    a.push_back(identifier_id);
    return a;
}

bool Identifier_Mips::is_Identifier() const
{
    return true;
}

std::string Identifier_Mips::get_cloest_Id() const
{
    return identifier_id;
}

std::string Identifier_Mips::return_expression_type(Context context)
{
    std::string type;
    if (context.is_Local(identifier_id))
    {
        type = context.find_local(identifier_id).type_name;
    }
    else if (context.is_Global(identifier_id))
    {
        type = context.find_local(identifier_id).type_name;
    }
    else
    {
        std::cerr << "NOT FOUND" << std::endl;
    }
    if (type == "ENUM")
    {
        type == "INT";
    }
    return type;
}

// void Identifier_MIPS::PrettyPrint(std::ostream &dst)
// {
//     dst << "Identifier: " << identifier_id << std::endl;
// }
