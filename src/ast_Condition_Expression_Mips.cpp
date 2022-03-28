
#include "AST/ast_Condition_Expression_Mips.hpp"

Condition_Expression_Mips::Condition_Expression_Mips(const NodePtr condition_expression)
{
    branch.push_back(condition_expression);
}

void Condition_Expression_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // std::cerr << "#"
    //           << "Condition Expression" << std::endl;
    std::string Largest_Type;
    int tmp_size, max_size;
    std::string tmp_type;
    // std::cout << "teseeese" << std::endl;
    //  for (int i = 0; i < branch[0]->get_size(); i++)
    //  {

    //     tmp_type = context.find_local(branch[0]->get_branch(i)->get_Id()).type_name;
    //     if (tmp_type == "INT")
    //     {
    //         tmp_size = 4;
    //     }
    //     else if (tmp_type == "DOUBLE")
    //     {
    //         tmp_size = 8;
    //     }
    //     if (max_size < tmp_size)
    //     {
    //         max_size = tmp_size;
    //     }
    // }
    // switch (max_size)
    // {
    // case 4:
    //     Largest_Type = "INT";
    //     break;
    // case 8:
    //     Largest_Type = "DOUBLE";
    //     break;
    // }
    // std::cerr <<"# ----------------------------------------" << std::endl;

    if (context.find_local("$DynamicContext").type_name == "NotDefined")
    {
        std::string left_ID = branch[0]->get_cloest_Id();
        std::cout << "#"
                  << " ID: " << left_ID << std::endl;
        std::string type;
        if (context.is_Local(left_ID))
        {
            type = context.find_local(left_ID).type_name;
            std::cout << "#"
                      << " TYPE: " << type << std::endl;
        }
        else if (context.is_Global(left_ID))
        {
            type = context.find_global(left_ID).type_name;
        }
        else
        {
            if (left_ID == "$DOUBLE")
            {
                type = "DOUBLE";
            }
            else if (left_ID == "FLOAT")
            {
                type = "FLOAT";
            }
            else if (left_ID == "INT")
            {
                type = "INT";
            }
        }

        std::cout << "#"
                  << "Condition Expression TYPE: " << Largest_Type << std::endl;

        context.assign_type_to_local_var("$DynamicContext", type);
    }
    // std::cout << "tes1234eeee" << std::endl;
    if (branch[0]->is_Constant() || branch[0]->is_Identifier())
    {
        // std::cout << "teseeee" << std::endl;
        current_offset = dynamic_offset;
        // std::cout << "teseeee234" << std::endl;
        branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        dst << "sw "
            << "$" << destReg << "," << current_offset << "($30)" << std::endl;
    }
    else
    {

        current_offset = dynamic_offset;
        branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        dst << "sw "
            << "$" << destReg << "," << current_offset << "($30)"
            << "# ----------------------------------------" << std::endl;
    }
}

void Condition_Expression_Mips::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
    // std::cout << "<----------------------------------Condition_Expression_Mips " << type << " ------------------------------------->" << std::endl;
    branch[0]->generateFloatMips(dst, context, destReg, make_name, dynamic_offset, type);
}

std::string Condition_Expression_Mips::get_type() const
{
    return branch[0]->get_type();
}

bool Condition_Expression_Mips::is_Conditional_Expression() const
{
    return true;
}
int Condition_Expression_Mips::get_arithmetic_const_val()
{
    return branch[0]->get_arithmetic_const_val();
}
int Condition_Expression_Mips::Dynamic_context_size()
{
    // std::cerr << "Getting Dynamic" << std::endl;

    // std::cerr << "Got: " << branch[0]->Dynamic_context_size() << std::endl;
    return branch[0]->Dynamic_context_size();
}

bool Condition_Expression_Mips::is_Function_inside() const
{
    return branch[0]->is_Function_inside();
}
int Condition_Expression_Mips::return_dynamic_offset()
{
    // std::cerr << "# This is a tmp solution" << std::endl;
    return current_offset;
}

std::string Condition_Expression_Mips::get_Id() const
{
    // std::cout << "# this is a tmp solution" << std::endl;
    return branch[0]->get_Id();
}
std::vector<FloatDoubleConst> Condition_Expression_Mips::get_Float_Const()
{
    return branch[0]->get_Float_Const();
}

std::vector<std::string> Condition_Expression_Mips::get_String_Const()
{
    return branch[0]->get_String_Const();
}

std::string Condition_Expression_Mips::get_cloest_Id() const
{
    return branch[0]->get_cloest_Id();
}
bool Condition_Expression_Mips::is_Constant() const
{
    return branch[0]->is_Constant();
}
