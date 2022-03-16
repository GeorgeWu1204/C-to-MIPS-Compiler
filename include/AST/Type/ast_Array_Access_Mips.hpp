#ifndef ast_Array_Access_Mips_hpp
#define ast_Array_Access_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Array_Access_Mips
    : public Node
{
protected:
    int int_number;

public:
    Array_Access_Mips(NodePtr Postfix_expression, NodePtr Expression);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    std::string get_Id() const override;

    bool is_Array() const override;
};

#endif