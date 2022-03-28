#ifndef ast_STRING_LITTERAL_MIPS_hpp
#define ast_STRING_LITTERAL_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>

#include "../ast_makeName.hpp"

class STRING_LITTERAL_MIPS
    : public Node
{


public:
    std::string string_variable;
    STRING_LITTERAL_MIPS(std::string input);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    std::string get_StringVal() const override;
    std::vector<std::string> get_String_Const() override;
    std::string get_type() const override;
    bool is_Constant() const override;

};

#endif
