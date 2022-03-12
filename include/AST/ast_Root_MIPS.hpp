#ifndef ast_Root_MIPS_hpp
#define ast_Root_MIPS_hpp

#include <string>
#include <iostream>

#include "ast_Node.hpp"
#include "ast_Context.hpp"
#include "ast_makeName.hpp"

class Root_Mips
    : public Node
{

public:
    std::map<std::string, Global_var> Global_context;
    Root_Mips(std::vector<NodePtr> root_input);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    void build_global_context();
};

#endif
