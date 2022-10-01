#ifndef ast_FunctionCall_MIPS_hpp
#define ast_FunctionCall_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"

class FunctionCall_Mips
    : public Node
{

public:
    std::vector<NodePtr> Argument;
    FunctionCall_Mips(const NodePtr functionID, const std::vector<NodePtr> _Argument_expression_list);
    FunctionCall_Mips(const NodePtr functionID);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    bool is_Function_inside() const override;
    std::string get_Id() const override;
    int get_argument_size() override;
};

#endif
