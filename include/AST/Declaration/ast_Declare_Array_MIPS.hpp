#ifndef ast_Declare_Array_MIPS_hpp
#define ast_Declare_Array_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Declare_Array_Mips
    : public Node
{

public:
    // Declaration_Mips(const std::string specifier, NodePtr declarator);
    Declare_Array_Mips(const NodePtr header, const NodePtr size);
    Declare_Array_Mips(const NodePtr header);
    //void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // no need to generate mips here.
    std::string get_type() const override;
    std::string get_Id() const override;
    int array_size() const override;
};

#endif