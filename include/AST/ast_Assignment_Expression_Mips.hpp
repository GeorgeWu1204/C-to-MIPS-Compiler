#ifndef ast_Assignment_Expression_Mips_hpp
#define ast_Assignment_Expression_Mips_hpp
#include <string>
#include <iostream>
#include "ast_Node.hpp"
#include "ast_Context.hpp"
#include "ast_makeName.hpp"

class Assignment_Expression_Mips
    : public Node
{
public:
    Assignment_Expression_Mips(const NodePtr Unary_expression, const NodePtr Assignment_expression);
    Assignment_Expression_Mips(const NodePtr ConditionalExpression);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    //int get_Val() const override;
    std::string get_Id() const override;
};

#endif
