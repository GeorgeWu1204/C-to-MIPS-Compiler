#ifndef ast_INT_CONSTANT_MIPS_hpp
#define ast_INT_CONSTANT_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Int_Constant_Mips
    : public Node
{
protected:
    int int_number;

public:
    Int_Constant_Mips(const int input);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    int get_Val() const override;
    bool is_Constant() const override;
    int get_arithmetic_const_val() override;
    std::string get_cloest_Id() const override;
};

#endif
