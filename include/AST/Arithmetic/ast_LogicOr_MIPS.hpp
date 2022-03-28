#ifndef ast_LogicOr_MIPS_hpp
#define ast_LogicOr_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "ast_Arithmetic_MIPS.hpp"
#include "../ast_makeName.hpp"

class LogicOr_MIPS
    : public Arithmetic_MIPS
{

public:
    LogicOr_MIPS(NodePtr leftinput, NodePtr rightinput);

    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    //void generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type) override;
    // void prettyPrint(std::ostream &dst) const override;
    //  void generate_left() const override;
    //  void generate_right() const override;
    int get_arithmetic_const_val() override;
};

#endif
