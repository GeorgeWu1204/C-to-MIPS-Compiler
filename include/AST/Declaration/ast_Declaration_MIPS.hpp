#ifndef ast_Declaration_MIPS_hpp
#define ast_Declaration_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Declaration_Mips
    : public Node
{

public:
    std::vector<NodePtr> declarator_list;
    Declaration_Mips(const NodePtr specifier, NodePtr declarator);
    Declaration_Mips(const NodePtr specifier, const std::vector<NodePtr> declarator);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    bool is_function_declaration();
    std::string get_type() const override;
    std::string get_Id() const override;
    bool is_Declaration() const override;
    bool is_Function() const override;
    bool is_init() const override;
};

#endif