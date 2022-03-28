#ifndef ast_StructElement_Declaration_Mips_hpp
#define ast_StructElement_Declaration_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class StructElement_Declaration_Mips
    : public Node
{
public:
    StructElement_Declaration_Mips(const NodePtr type_name, const std::vector<NodePtr> Declare_list);
    std::string get_type() const override;
    //void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    //int get_Val() const override;   
};
#endif