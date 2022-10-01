#ifndef ast_Global_Declaration_MIPS_hpp
#define ast_Global_Declaration_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Global_Declaration_Mips
    : public Node
{

public:
    // Declaration_Mips(const std::string specifier, NodePtr declarator);
    Global_Declaration_Mips(const NodePtr specifier);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    std::string get_type() const override;
    std::string get_Id() const override;
    int array_size() const override;
};

#endif