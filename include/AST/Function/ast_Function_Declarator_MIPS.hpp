#ifndef ast_Function_Declarator_MIPS_hpp
#define ast_Function_Declarator_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"
class Function_Declarator_Mips
    : public Node
{

public:
    Function_Declarator_Mips(NodePtr direct_declarator);
    Function_Declarator_Mips(NodePtr direct_declarator, std::vector<NodePtr> argument_list);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    bool is_Function() const override;
    std::string get_Id() const override;
    int get_argument_size() override;
    std::map<std::string, std::string> get_argument_map() override;
};

#endif
