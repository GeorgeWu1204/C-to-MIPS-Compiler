#ifndef ast_Array_Initializer_Mips_hpp
#define ast_Array_Initializer_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Array_Initializer_Mips
    : public Node
{


public:
    Array_Initializer_Mips(std::vector<NodePtr> input);
    
    //void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // override;
    bool is_Array_Initializer() const override;
    std::vector<FloatDoubleConst> get_Float_Const() override;

    //std::vector<FloatDoubleConst> get_String_Const() override; // do we need this? sos
    void concatenate_float(std::vector<FloatDoubleConst> &a, std::vector<FloatDoubleConst> &b);
    std::vector<double> construct_double_const_list() override;
};

#endif