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
    std::map<double, FloatDoubleConst> float_const_store;
    std::map<std::string, type_storage> tmp_store_str;
    std::map<std::string, std::string> String_const_store;
    Root_Mips(std::vector<NodePtr> root_input);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    void build_global_context();
    void build_Float_str();
    void build_String_str(MakeName &make_name);
};

#endif
