#ifndef ast_While_Mips_hpp
#define ast_While_Mips_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"

class While_Mips
    : public Node
{
public:
    While_Mips(NodePtr Expression_term, NodePtr Statement_term);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    int get_context_local_size() override;
    std::vector<std::string> return_waiting_to_declared_list() override;
    bool is_Compound_statement() const override;
};

#endif