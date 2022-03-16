#ifndef ast_Function_hpp
#define ast_Function_hpp

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <math.h>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"

class Function
    : public Node
{
protected:
    bool is_func_inside;

public:
    Context Func_context;
    Context Argument_context;
    Function(NodePtr headinput, NodePtr bodyinput);
    int sizeoffunction();
    // std::map<std::string, int> global_var
    // std::map<std::string, std::string> input_to_function();
    // name of variable used in the input and the in
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const;
    void add_argument_to_context(int index);
    bool is_Function() const override;
    std::string get_Id() const override;
    std::string get_type() const override;
};

#endif