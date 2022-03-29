
#include "AST/Type/ast_Array_Initializer_Mips.hpp"

Array_Initializer_Mips::Array_Initializer_Mips(std::vector<NodePtr> input)
    : Node(input)
{
}

bool Array_Initializer_Mips::is_Array_Initializer() const
{
    return true;
}

std::vector<FloatDoubleConst> Array_Initializer_Mips::get_Float_Const()
{
    std::vector<FloatDoubleConst> a;
    for (int i = 0; i < branch.size(); i++)
    {
        std::vector<FloatDoubleConst> b = branch[i]->get_Float_Const();
        concatenate_float(a, b);
    }
    return a;
}
void Array_Initializer_Mips::concatenate_float(std::vector<FloatDoubleConst> &a, std::vector<FloatDoubleConst> &b)
{
    for (int i = 0; i < b.size(); i++)
    {
        a.push_back(b[i]);
    }
}

std::vector<double> Array_Initializer_Mips::construct_double_const_list()
{
    // i know this is going to be a double sht so i dont care
    std::vector<double> double_list;
    for (int i = 0; i < branch.size(); i++)
    {
        double_list.push_back(branch[i]->get_Float());
        // std::cerr << "<----------------returned float number " << branch[i]->get_Float() << " ------------------------>" << std::endl;
    }
    return double_list;
}