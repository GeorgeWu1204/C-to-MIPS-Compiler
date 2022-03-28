#ifndef ast_Call_struct_MIPS_hpp
#define ast_Call_struct_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
#include "AST/ast_IDENTIFIER_MIPS.hpp"
class Call_struct_Mips
    : public Node
{


public:
    std::string struct_element;
    Call_struct_Mips(const NodePtr struct_variable, const std::string &identifier);
    std::string get_Id() const override;
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    //int get_Val() const override;
    bool is_Struct_Call() const override;
    int get_struct_variable_offset(Context context) override;
    type_storage get_struct(NodePtr inside, Context context);
    std::string return_expression_type(Context context) override;
    
};
#endif