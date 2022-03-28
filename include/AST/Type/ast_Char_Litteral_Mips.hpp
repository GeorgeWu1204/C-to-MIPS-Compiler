#ifndef ast_Char_Litteral_Mips_hpp
#define ast_Char_Litteral_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"

class Char_Litteral_Mips
    : public Node
{
private:
  int char_litteral;

public:
  Char_Litteral_Mips(int value);
  Char_Litteral_Mips();
  void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
  int get_Val() const override;
};
#endif