
#ifndef ast_Selection_statement_MIPS_hpp
#define ast_Selection_statement_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"
class Selection_statement_Mips
    : public Node
{

public:
    Selection_statement_Mips(NodePtr condition_expression, NodePtr statement_1);
    Selection_statement_Mips(NodePtr condition_expression, NodePtr statement_1, NodePtr statement_2);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    int get_context_local_size() override;

    std::vector<std::string> return_waiting_to_declared_list() override;

    bool is_Compound_statement() const override;
    // void prettyPrint(std::ostream &dst) const override;
    int Dynamic_context_size() override;
    //bool is_Function_inside() const override;

};

#endif
