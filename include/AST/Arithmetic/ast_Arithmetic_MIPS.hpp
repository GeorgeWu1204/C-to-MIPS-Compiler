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
    enum Type
    {
        char_ = 2,
        int_ = 4,
        float_ = 4,
        double_ = 8
    };
    Arithmetic_MIPS(NodePtr leftinput, NodePtr rightinput);
    virtual void generate_left(std::ostream &dst, Context &context, int destReg, NodePtr leftnode, MakeName &make_name, int &dynamic_offset);
    virtual void generate_right(std::ostream &dst, Context &context, int destReg, NodePtr rightnode, MakeName &make_name, int &dynamic_offset);
    virtual void generateFloat_left(std::ostream &dst, Context &context, int destReg, NodePtr leftnode, MakeName &make_name, int &dynamic_offset, std::string type);
    virtual void generateFloat_right(std::ostream &dst, Context &context, int destReg, NodePtr rightnode, MakeName &make_name, int &dynamic_offset, std::string type);
    // void generateMips(std::ostream &dst, Context &context, int destReg, NodePtr rightnode, MakeName &make_name, int &dynamic_offset) override;

    // void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    //  virtual void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) const override;
    //   virtual void prettyPrint(std::ostream &dst) const override;
    //  std::string get_Name() const override;
    int Dynamic_context_size() override;
    int return_dynamic_offset() override;
    bool is_Function_inside() const override;
    virtual std::string get_cloest_Id() const override;
    std::vector<FloatDoubleConst> get_Float_Const() override;
    std::string return_expression_type(Context context) override;
    int enumerator_convertor(std::string input);

    // virtual void assign_dynamic_offset(int offset_val);
    // virtual void pass_offset(int cur_offset, int left_size);
};

#endif
