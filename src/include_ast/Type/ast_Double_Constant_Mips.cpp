#include "ast/Type/ast_Double_Constant_Mips.hpp"

Double_Constant_Mips::Double_Constant_Mips(double value)
    : float_number(value)
{
}

void Double_Constant_Mips::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
  if (context.Float_const_str.find(float_number) != context.Float_const_str.end())
  {
    dst << "lui "
        << "$2,"
        << "%hi"
        << "($" << context.Float_const_str.find(float_number)->second.Label_val << ")" << std::endl;
    dst << "lwc1 "
        << "$f0"
        << ","
        << "%lo($" << context.Float_const_str.find(float_number)->second.Label_val << "+4"
        << ")($2)" << std::endl;
    dst << "nop " << std::endl;
    dst << "lwc1 "
        << "$f1"
        << ",%lo($" << context.Float_const_str.find(float_number)->second.Label_val << ")($2)" << std::endl;
  }
}
void Double_Constant_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
  if (context.Float_const_str.find(float_number) != context.Float_const_str.end())
  {
    dst << "lui "
        << "$2,"
        << "%hi"
        << "($" << context.Float_const_str.find(float_number)->second.Label_val << ")" << std::endl;
    dst << "lwc1 "
        << "$f0"
        << ","
        << "%lo($" << context.Float_const_str.find(float_number)->second.Label_val << "+4"
        << ")($2)" << std::endl;
    dst << "nop " << std::endl;
    dst << "lwc1 "
        << "$f1"
        << ",%lo($" << context.Float_const_str.find(float_number)->second.Label_val << ")($2)" << std::endl;
  }
}

double Double_Constant_Mips::get_Float() const
{
  return float_number;
}

bool Double_Constant_Mips::is_Double_Constant() const
{
  return true;
}
std::vector<FloatDoubleConst> Double_Constant_Mips::get_Float_Const()
{
  std::cerr << "#<----------inside double return " << float_number << "------------------>" << std::endl;
  std::vector<FloatDoubleConst> a;
  a.push_back(FloatDoubleConst("DOUBLE", float_number));
  return a;
}

std::string Double_Constant_Mips::get_cloest_Id() const
{
  return "$DOUBLE";
}
std::string Double_Constant_Mips::return_expression_type(Context context)
{
  return "DOUBLE";
}

std::string Double_Constant_Mips::get_type() const
{
  return "DOUBLE";
}
