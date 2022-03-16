#ifndef ast_Enumerator_Mips_hpp
#define ast_Enumerator_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Enumerator_Mips
    : public Node
{
protected:
    std::string enumerator_name;

public:
    Enumerator_Mips(const std::string &input, NodePtr Constant_expression);
    Enumerator_Mips(const std::string &input);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    int get_Val() const override;
    std::string get_Id() const override;
    bool is_Enum() const override;
};
#endif