#ifndef ast_Switch_MIPS_hpp
#define ast_Switch_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"

class Switch_Mips
    : public Node
{
public:
    // SWITCH '(' Expression ')' Statement
    Context switch_context;
    std::vector<int> case_index;
    std::vector<std::string> jump_label;
    Switch_Mips(NodePtr Expression, NodePtr Statement);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    int get_context_local_size() override;
    std::vector<std::string> return_waiting_to_declared_list() override;
    bool is_Compound_statement() const override;
    bool is_Switch() const override;
    // void prettyPrint(std::ostream &dst) const override;
};

#endif