#ifndef ast_Type_qualifier_list_hpp
#define ast_Type_qualifier_list_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Type_Mips
    : public Node
{

public:
    std::string type_specifier;
    std::string type_qualifier_list;
    Type_Mips(const std::string &input);
    // void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) const override;
    // void prettyPrint(std::ostream &dst) const override;
    std::string get_type() const override;
};

#endif