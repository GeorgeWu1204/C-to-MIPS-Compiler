#ifndef ast_Double_Constant_Mips_hpp
#define ast_Double_Constant_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"

class Double_Constant_Mips
    : public Node
{
private:
  double float_number;

public:
  Double_Constant_Mips(double value);
  void generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type) override;

  double get_Float() const override;
  bool is_Double_Constant() const override;
  std::vector<FloatDoubleConst> get_Float_Const() override;
  // int getSize() const override;
  std::string get_cloest_Id() const override;
  std::string get_type() const override;
  std::string return_expression_type(Context context) override;
};

#endif