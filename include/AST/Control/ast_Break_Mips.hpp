#ifndef ast_Break_Mips_hpp
#define ast_Break_Mips_hpp

#include "ast/ast_node.hpp"

class Break_Mips
    : public Node
{
public:
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    bool is_Break() const override;
};

#endif
