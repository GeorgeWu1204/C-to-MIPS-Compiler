#ifndef ast_Init_Declarator_MIPS_hpp
#define ast_Init_Declarator_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
////// change naame
class Init_Declarator_Mips
    : public Node
{

public:
    // Init_Declarator_Mips(const std::string Declarator, const NodePtr Initializer);
    // for case initializer is a constant;
    Init_Declarator_Mips(const NodePtr Declarator, const NodePtr Initializer);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    bool is_Function() const override;
    std::string get_Id() const override;
    int get_Val() const override;
    std::string get_type() const override;
    std::string get_StringVal() const override;
    bool is_init() const override;
    bool is_Array() const override;
};

#endif