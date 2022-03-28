#include "AST/Arithmetic/ast_Arithmetic_MIPS.hpp"

Arithmetic_MIPS::Arithmetic_MIPS(NodePtr leftinput, NodePtr rightinput)
{
    branch.push_back(leftinput);
    branch.push_back(rightinput);
    Left = leftinput;
    Right = rightinput;
}


void Arithmetic_MIPS::generate_left(std::ostream &dst, Context &context, int destReg, NodePtr leftnode, MakeName &make_name, int &dynamic_offset)
{
    if (leftnode->is_Function())
    {
        dst << "# not supported" << std::endl;
    }
    else
    {
        leftnode->generateMips(dst, context, destReg, make_name, dynamic_offset);
    }
}
void Arithmetic_MIPS::generate_right(std::ostream &dst, Context &context, int destReg, NodePtr rightnode, MakeName &make_name, int &dynamic_offset)
{
    if (rightnode->is_Function())
    {
        // dst << "sw" << "$2" <<
        dst << "not supported" << std::endl;
    }
    else
    {

        rightnode->generateMips(dst, context, destReg, make_name, dynamic_offset);
    }
}

void Arithmetic_MIPS::generateFloat_left(std::ostream &dst, Context &context, int destReg, NodePtr leftnode, MakeName &make_name, int &dynamic_offset, std::string type)
{

    if (leftnode->is_Function())
    {
        dst << "# not supported" << std::endl;
    }
    else
    {
        leftnode->generateFloatMips(dst, context, destReg, make_name, dynamic_offset,type);
    }
}
void Arithmetic_MIPS::generateFloat_right(std::ostream &dst, Context &context, int destReg, NodePtr rightnode, MakeName &make_name, int &dynamic_offset, std::string type)
{
    if (rightnode->is_Function())
    {
        // dst << "sw" << "$2" <<
        dst << "not supported" << std::endl;
    }
    else
    {
        rightnode->generateFloatMips(dst, context, destReg, make_name, dynamic_offset,type);
    }
}


std::vector<FloatDoubleConst> Arithmetic_MIPS::get_Float_Const()
{
    std::vector<FloatDoubleConst> branch1 = Right->get_Float_Const(); 
    std::vector<FloatDoubleConst> branch2 = Left->get_Float_Const();
    for(int i =0;i<branch2.size(); i++)
    {
        branch1.push_back(branch2[i]); 
    }
    return branch1;
}

int Arithmetic_MIPS::return_dynamic_offset()
{
    return current_offset;
}

int Arithmetic_MIPS::Dynamic_context_size()
{
    return branch[0]->Dynamic_context_size() + branch[1]->Dynamic_context_size() + 1;
}

bool Arithmetic_MIPS::is_Function_inside() const
{
    if (branch[0]->is_Function_inside() || branch[1]->is_Function_inside())
    {
        return true;
    }
    else
    {
        return false;
    }
   
}
std::string Arithmetic_MIPS::get_cloest_Id() const
{
    return branch[0]->get_cloest_Id();
}
