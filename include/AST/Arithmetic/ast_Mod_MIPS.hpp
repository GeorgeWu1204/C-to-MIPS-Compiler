#ifndef ast_Mod_MIPS_hpp
#define ast_Mod_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "ast_Arithmetic_MIPS.hpp"
#include "../ast_makeName.hpp"

class Mod_MIPS
    : public Arithmetic_MIPS
{

public:
    Mod_MIPS(NodePtr leftinput, NodePtr rightinput);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    //void prettyPrint(std::ostream &dst) const override;
    // void generate_left(std::ostream &dst, Context &context,  int destReg) const override;
    // void generate_right(std::ostream &dst, Context &context,  int destReg) const override;
};

#endif


