#ifndef ast_Default_Mips_hpp
#define ast_Default_Mips_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"

class Default_Mips
    : public Node
{
public:
    Default_Mips(NodePtr Statement);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    int get_context_local_size() override;
    std::vector<std::string> return_waiting_to_declared_list() override;
    bool is_Compound_statement() const override;

    bool is_Default() const override;

    int get_case_index() override;

    // void prettyPrint(std::ostream &dst) const override;
};

#endif
