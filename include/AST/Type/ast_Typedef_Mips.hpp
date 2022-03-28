#ifndef ast_Typedef_Mips_hpp
#define ast_Typedef_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Typedef_Mips
    : public Node
{

public:
    Typedef_Mips(const NodePtr input);
    // void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) const override;
    //std::string get_type() const override;
};

#endif