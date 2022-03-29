
#include "AST/Function/ast_Function_Declarator_MIPS.hpp"

Function_Declarator_Mips::Function_Declarator_Mips(NodePtr direct_declarator)
{
    branch.push_back(direct_declarator);
}

Function_Declarator_Mips::Function_Declarator_Mips(NodePtr direct_declarator, std::vector<NodePtr> argument_list)
{
    branch.push_back(direct_declarator);
    for (int i = 0; i < argument_list.size(); i++)
    {
        branch.push_back(argument_list[i]);
    }
}

void Function_Declarator_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
}

bool Function_Declarator_Mips::is_Function() const
{
    return true;
}

std::string Function_Declarator_Mips::get_Id() const
{
    return branch[0]->get_Id();
}

int Function_Declarator_Mips::get_argument_size()
{
    int arg_size = 0;
    for (int i = 1; i < branch.size(); i++)
    {
        if (branch[i]->get_type() == "DOUBLE" || branch[i]->get_type() == "DOUBLEPTR")
        {
            if (arg_size % 8 != 0)
            {
                arg_size += 12;
            }
            else
            {
                arg_size += 8;
            }
        }
        else
        {
            arg_size += 4;
        }
    }
    return arg_size;
}

std::vector<std::pair<std::string, std::string> > Function_Declarator_Mips::get_argument_map()
{
    std::vector<std::pair<std::string, std::string> > argument_vector;
    std::cerr << "#"
              << "inside Function get argument " << std::endl;

    for (int i = 1; i < branch.size(); i++)
    {
        if (branch[i]->is_Pointer())
        {
            argument_vector.push_back(std::make_pair(branch[i]->get_Id(), branch[i]->get_type() + "PTR"));
        }
        else
        {
            argument_vector.push_back(std::make_pair(branch[i]->get_Id(), branch[i]->get_type()));
        }
    }
    return argument_vector;
}

int Function_Declarator_Mips::get_size() const
{
    std::cerr << "declarator" << branch.size() << std::endl;
    return branch.size();
}

std::string Function_Declarator_Mips::get_type() const
{
    return branch[0]->get_type();
}