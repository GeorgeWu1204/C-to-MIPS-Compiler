#ifndef ast_Continuous_Mips_hpp
#define ast_Continuous_Mips_hpp

#include "ast/ast_node.hpp"

class Continuous_Mips
    : public Node
{
public:
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;

    bool is_Continue() const override;
};

#endif
