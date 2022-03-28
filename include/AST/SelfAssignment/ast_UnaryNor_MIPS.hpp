#ifndef ast_UnaryNor_MIPS_hpp
#define ast_UnaryNor_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"

class UnaryNor_MIPS
    : public Node
{
public:
    UnaryNor_MIPS(const NodePtr input);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    // int get_Val() const override;
    std::string get_Id() const override;
    bool is_Function_inside() const override;
    std::string get_cloest_Id() const override;
    std::string return_expression_type(Context context);
};

#endif