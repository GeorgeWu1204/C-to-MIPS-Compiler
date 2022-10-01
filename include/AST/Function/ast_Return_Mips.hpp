#ifndef ast_Return_Mips_hpp
#define ast_Return_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"
class Return_Mips
    : public Node
{
public:
    Return_Mips();
    Return_Mips(NodePtr Expression);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    std::string get_Id() const override;
};

#endif