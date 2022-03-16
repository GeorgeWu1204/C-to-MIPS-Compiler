#ifndef ast_Pre_Increment_MIPS_hpp
#define ast_Pre_Increment_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"

class Pre_Increment_MIPS
    : public Node
{
public:
    Pre_Increment_MIPS(const NodePtr input);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    // int get_Val() const override;
    std::string get_Id() const override;
};

#endif
