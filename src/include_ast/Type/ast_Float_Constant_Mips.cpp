#include "ast/Type/ast_Float_Constant_Mips.hpp"

Float_Constant_Mips::Float_Constant_Mips(float value)
    : float_number(value)
{ }

void Float_Constant_Mips::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
  if (context.Float_const_str.find(float_number) != context.Float_const_str.end())
  {
    dst << "lui "
        << "$2,"
        << "%hi"
        << "($" << context.Float_const_str.find(float_number)->second.Label_val << ")" << std::endl;
    dst << "lwc1 "
        << "$f0"
        << ",%lo($" << context.Float_const_str.find(float_number)->second.Label_val << ")($2)" << std::endl;
  }
}
void Float_Constant_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
  if (context.Float_const_str.find(float_number) != context.Float_const_str.end())
  {
    dst << "lui "
        << "$2,"
        << "%hi"
        << "($" << context.Float_const_str.find(float_number)->second.Label_val << ")" << std::endl;
    dst << "lwc1 "
        << "$f0"
        << ",%lo($" << context.Float_const_str.find(float_number)->second.Label_val << ")($2)" << std::endl;
  }
}

double Float_Constant_Mips::get_Float() const
{
  return float_number;
}

bool Float_Constant_Mips::is_Float_Constant() const
{
  return true;
}
std::vector<FloatDoubleConst> Float_Constant_Mips::get_Float_Const()
{
  std::vector<FloatDoubleConst> a;
  a.push_back(FloatDoubleConst("FLOAT", float_number));
  return a;
}
std::string Float_Constant_Mips::get_type() const
{
    return "FLOAT";
}
std::string Float_Constant_Mips::return_expression_type(Context context)
{
    return "FLOAT";
}

std::string Float_Constant_Mips::get_cloest_Id() const
{
    return "$FLOAT";
}