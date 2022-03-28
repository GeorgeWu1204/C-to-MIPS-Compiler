#ifndef ast_Struct_Declaration_Mips_hpp
#define ast_Struct_Declaration_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Struct_Declaration_Mips
    : public Node
{


public:
    std::string struct_name; 
    Struct_Declaration_Mips(const std::string &identifier);
    
    std::string get_Id() const override;
    std::string get_type() const override;
    bool is_Struct_Declaration() const override;


    //void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    //int get_Val() const override;
    
};
#endif