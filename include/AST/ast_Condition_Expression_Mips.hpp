#ifndef ast_Condition_Expression_Mips_hpp
#define ast_Condition_Expression_Mips_hpp
#include <string>
#include <iostream>
#include "ast_Node.hpp"
#include "ast_Context.hpp"
#include "ast_makeName.hpp"

class Condition_Expression_Mips
    : public Node
{
public:
    Condition_Expression_Mips(const NodePtr condition_expression);
    int current_offset;
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    void generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type) override;
    // void prettyPrint(std::ostream &dst) const override;
    // int get_Val() const override;
    std::string get_type() const override;
    int get_arithmetic_const_val() override;
    bool is_Conditional_Expression() const override;
    int Dynamic_context_size() override;
    bool is_Function_inside() const override;
    int return_dynamic_offset() override;
    std::string get_Id() const override;
    std::vector<FloatDoubleConst> get_Float_Const() override;
    double get_Float() const override;
    std::vector<std::string> get_String_Const() override;
    std::string get_cloest_Id() const override;
    bool is_Constant() const override;
    std::string return_expression_type(Context context) override;
    bool is_Identifier() const override ;
    int get_Val() const override;

};

#endif
