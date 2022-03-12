#ifndef ast_Greater_Than_MIPS_hpp
#define ast_Greater_Than_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "ast_Arithmetic_MIPS.hpp"
#include "../ast_makeName.hpp"

class Greater_Than_MIPS
    : public Arithmetic_MIPS
{

public:
    Greater_Than_MIPS(NodePtr leftinput, NodePtr rightinput);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    //  void generate_left() const override;
    //  void generate_right() const override;
};

#endif
