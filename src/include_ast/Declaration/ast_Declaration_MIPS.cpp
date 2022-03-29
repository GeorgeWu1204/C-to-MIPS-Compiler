#include "AST/Declaration/ast_Declaration_MIPS.hpp"

Declaration_Mips::Declaration_Mips(const NodePtr specifier, const std::vector<NodePtr> declarator_list)
{
    branch.push_back(specifier);
    for (int i = 0; i < declarator_list.size(); i++)
    {
        branch.push_back(declarator_list[i]);
    }
    // std::cerr << "#" << "done" << std::endl;
}
Declaration_Mips::Declaration_Mips(const NodePtr specifier)
{
    // for struct;
    // std::cerr << "#" << "constructing Declaaration Mips" << std::endl;
    branch.push_back(specifier);
    branch.push_back(new Node());
    // std::cerr << "#" << "Passing it to Vector" << branch.size() <<std::endl;
}

Declaration_Mips::Declaration_Mips(const NodePtr specifier, const NodePtr declarator)
{
    // std::cerr << "#" << "constructing Declaaration Mips" << std::endl;
    branch.push_back(specifier);
    branch.push_back(declarator);
    // std::cerr << "#" << "Passing it to Vector" << branch.size() <<std::endl;
}

void Declaration_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // int a(){} new Function definition( new Declaration(), compo)
    // int f(){ int g = 0;} new function
    // int a()
    std::cerr << "# <---------------------- Declaration ------------------>" << std::endl;
    for (int i = 1; i < branch.size(); i++)
    {
        if (branch[i]->is_Function())
        {
            dst << ".text" << std::endl;
            dst << ".globl " << branch[i]->get_Id() << std::endl;
            dst << ".ent  " << branch[i]->get_Id() << std::endl;

            dst << branch[i]->get_Id() << ":" << std::endl;
        }
        else
        {
            std::string type = branch[0]->get_type();

            if (branch[i]->is_init())
            {
                std::cerr << "# declaration is init" << std::endl;
                if (type == "DOUBLE" || type == "FLOAT")
                {
                    std::cerr << "# declaration in floatergth" << std::endl;
                    branch[i]->generateFloatMips(dst, context, destReg, make_name, dynamic_offset, type);
                }
                else
                {
                    std::cerr << "# declaration NOT in float" << std::endl;
                    branch[i]->generateMips(dst, context, destReg, make_name, dynamic_offset); // check
                }
            }
            else
            {
            }
        }
    }
}

std::string Declaration_Mips::get_type() const
{
    // if struct, return struct
    return branch[0]->get_type();
}

// SOS
std::string Declaration_Mips::get_Id() const
{
    // int f();
    return branch[1]->get_Id();
}

bool Declaration_Mips::is_Declaration() const
{
    return true;
}

int Declaration_Mips::get_argument_size()
{
    // std::cerr << "#" << "inside declaration mips" << branch[1]->get_argument_size()<< std::endl;
    return branch[1]->get_argument_size();
}

std::vector<std::pair<std::string, std::string> > Declaration_Mips::get_argument_map()
{
    return branch[1]->get_argument_map();
}
std::map<std::string, int> Declaration_Mips::get_enumerator_list()
{
    return branch[0]->get_enumerator_list();
}
bool Declaration_Mips::is_Enum() const
{
    return branch[0]->is_Enum();
}
// for param
bool Declaration_Mips::is_Pointer() const
{
    return branch[1]->is_Pointer();
}

type_storage Declaration_Mips::get_type_storage()
{
    return branch[0]->get_type_storage();
}
bool Declaration_Mips::is_Struct() const
{
    return branch[0]->is_Struct();
}
bool Declaration_Mips::is_Struct_Declaration() const
{
    return branch[0]->is_Struct_Declaration();
}

// bool Declaration_Mips::is_Function() const
// {
//     return branch[1]->is_Function();
// }
// bool Declaration_Mips::is_init() const
// {
//     return branch[1]->is_init();
// }
