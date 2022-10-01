#ifndef ast_Arithmetic_MIPS_hpp
#define ast_Arithmetic_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"

class Arithmetic_MIPS
    : public Node
{
protected:
    NodePtr Left;
    NodePtr Right;
    int current_offset;
public:
    
    Arithmetic_MIPS(NodePtr leftinput, NodePtr rightinput);
    virtual void generate_left(std::ostream &dst, Context &context, int destReg, NodePtr leftnode, MakeName &make_name, int &dynamic_offset);
    virtual void generate_right(std::ostream &dst, Context &context, int destReg, NodePtr rightnode, MakeName &make_name, int &dynamic_offset);

    //void generateMips(std::ostream &dst, Context &context, int destReg, NodePtr rightnode, MakeName &make_name, int &dynamic_offset) override;

    //void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // virtual void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) const override;
    //  virtual void prettyPrint(std::ostream &dst) const override;
    // std::string get_Name() const override;
    int Dynamic_context_size() override;
    int  return_dynamic_offset() override;
    //virtual void assign_dynamic_offset(int offset_val); 
    //virtual void pass_offset(int cur_offset, int left_size);
};

#endif
