#include "AST/Declaration/ast_Init_Declarator.hpp"

Init_Declarator_Mips::Init_Declarator_Mips(const NodePtr Declarator, const NodePtr Initializer)
{
    branch.push_back(Declarator);
    branch.push_back(Initializer);
}

void Init_Declarator_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    if (branch[0]->is_Array())
    {
        branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        for (int i = 0; i < branch[0]->array_size(); i++)
        {
            branch[1], get_branch(i)->generateMips(dst, context, destReg, make_name, dynamic_offset);
            dst << "sw " << destReg << context.find << "($30)" << std::endl;
        }
    }
    else
    {
        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        dst << "sw "
            << "$" << destReg << ", " << context.find_local(branch[0]->get_Id()).offset << "("
            << "$30"
            << ")" << std::endl;
    }
}

std::string Init_Declarator_Mips::get_type() const
{
    return branch[0]->get_type();
}

std::string Init_Declarator_Mips::get_Id() const
{
    return branch[0]->get_Id();
}

bool Init_Declarator_Mips::is_Function() const
{
    // not sure about whether a function declaration with initized
    return false;
}

bool Init_Declarator_Mips::is_init() const
{
    return true;
}

int Init_Declarator_Mips::get_Val() const
{
    return branch[1]->get_Val();
}
std::string Init_Declarator_Mips::get_StringVal() const
{
    return branch[1]->get_StringVal();
}
