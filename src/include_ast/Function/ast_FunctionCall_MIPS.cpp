
#include "AST/Function/ast_FunctionCall_MIPS.hpp"

FunctionCall_Mips::FunctionCall_Mips(const NodePtr functionID, const std::vector<NodePtr> _Argument_expression_list)
{
    branch.push_back(functionID);
    for (int i = 0; i < _Argument_expression_list.size(); i++)
    {
        branch.push_back(_Argument_expression_list[i]);
    }
}

FunctionCall_Mips::FunctionCall_Mips(const NodePtr functionID)
{

    branch.push_back(functionID);
}

void FunctionCall_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    int trace_fd_num = 0;
    int trace_int_num = 0;
    if (get_argument_size() <= 16)
    {
        for (int i = 1; i < branch.size(); i++)
        {
            if (branch[i]->get_type() == "DOUBLE" || branch[i]->get_type() == "DOUBLEPTR")
            {
                branch[i]->generateFloatMips(dst, context, 12 + trace_fd_num, make_name, dynamic_offset, "DOUBLE");
                trace_fd_num += 2;
            }
            else if (branch[i]->get_type() == "FLOAT" || branch[i]->get_type() == "FLOATPTR")
            {
                if (trace_fd_num < 4)
                {
                    // 0  2
                    branch[i]->generateFloatMips(dst, context, 12 + trace_fd_num, make_name, dynamic_offset, "FLOAT");
                    trace_fd_num += 2;
                    trace_int_num += 1;
                }
                else
                {
                    branch[i]->generateFloatMips(dst, context, 0, make_name, dynamic_offset, "FLOAT");
                    dst << "move "
                        << "$" << 4 + trace_int_num << ","
                        << "$f0" << std::endl;
                    trace_int_num += 1;
                }
            }
            else
            {
                branch[i]->generateMips(dst, context, 4 + trace_int_num, make_name, dynamic_offset);
                trace_int_num += 1;
            }
        }
    }
    else
    {
        int trace_fd_num = 0;
        int trace_int_num = 0;
        int arg_index = 1;
        int arg_size = 0;
        int str_position = 16;
        while (arg_size < 16)
        {
            if (branch[arg_index]->get_type() == "DOUBLE" || branch[arg_index]->get_type() == "DOUBLEPTR")
            {
                arg_size += 8;
                branch[arg_index]->generateFloatMips(dst, context, 12 + trace_fd_num, make_name, dynamic_offset, "DOUBLE");
                arg_index += 1;
                trace_fd_num += 2;
            }
            else if (branch[arg_index]->get_type() == "FLOAT" || branch[arg_index]->get_type() == "FLOATPTR")
            {

                arg_size += 4;
                branch[arg_index]->generateFloatMips(dst, context, 12 + trace_fd_num, make_name, dynamic_offset, "FLOAT");
                arg_index += 1;
                trace_fd_num += 1;
            }
            else
            {
                // INT
                arg_size += 4;
                // std::cerr << "------test" << std::endl;
                branch[arg_index]->generateMips(dst, context, 4 + trace_int_num, make_name, dynamic_offset);
                arg_index += 1;
                trace_int_num += 1;
            }
        }
        for (int k = arg_index; k < branch.size(); k++)
        {
            if (branch[k]->get_type() == "DOUBLE")
            {
                branch[arg_index]->generateFloatMips(dst, context, 0, make_name, dynamic_offset, "DOUBLE");
                dst << "swc1 "
                    << "$f0," << str_position + 4 << "($30)" << std::endl;
                dst << "swc1 "
                    << "$f1," << str_position << "($30)" << std::endl;
                str_position += 8;
            }
            else if (branch[k]->get_type() == "FLOAT")
            {
                branch[arg_index]->generateFloatMips(dst, context, 0, make_name, dynamic_offset, "DOUBLE");
                dst << "swc1 "
                    << "$f0," << str_position << "($30)" << std::endl;
                str_position += 4;
            }

            else
            {
                branch[k]->generateMips(dst, context, 2, make_name, dynamic_offset);
                dst << "sw "
                    << "$2," << str_position << "($30)" << std::endl;
                str_position += 4;
            }
        }
    }
    current_offset = dynamic_offset;
    dynamic_offset -= 4;
    dst << "jal "
        << branch[0]->get_Id() << std::endl;
    dst << "sw "
        << "$2," << current_offset << "($30)" << std::endl;
}

std::string FunctionCall_Mips::get_Id() const
{
    return branch[0]->get_Id();
}

bool FunctionCall_Mips::is_Function_inside() const
{
    return true;
}

int FunctionCall_Mips::get_argument_size()
{
    int arg_size = 0;
    for (int i = 1; i < branch.size(); i++)
    {
        if (branch[i]->get_type() == "DOUBLE" || branch[i]->get_type() == "DOUBLEPTR")
        {
            if (arg_size % 8 != 0)
            {
                arg_size += 12;
            }
            else
            {
                arg_size += 8;
            }
        }
        else
        {
            arg_size += 4;
        }
    }
    // std::cerr << "<---------------------------  return size ---------------------------->" << std::endl;
    return arg_size;
}
int FunctionCall_Mips::return_dynamic_offset()
{
    return current_offset;
}

std::vector<std::string> FunctionCall_Mips::get_String_Const()
{
    std::vector<std::string> a;
    for (int i = 1; i < branch.size(); i++)
    {
        std::vector<std::string> b = branch[i]->get_String_Const();
        concatenate_string(a, b);
    }
    return a;
}

std::vector<FloatDoubleConst> FunctionCall_Mips::get_Float_Const()
{
    std::vector<FloatDoubleConst> a;
    for (int i = 1; i < branch.size(); i++)
    {
        std::vector<FloatDoubleConst> b = branch[i]->get_Float_Const();
        concatenate_float(a, b);
    }
    return a;
}
void FunctionCall_Mips::concatenate_float(std::vector<FloatDoubleConst> &a, std::vector<FloatDoubleConst> &b)
{
    for (int i = 0; i < b.size(); i++)
    {
        a.push_back(b[i]);
    }
}
void FunctionCall_Mips::concatenate_string(std::vector<std::string> &a, std::vector<std::string> &b)
{
    for (int i = 0; i < b.size(); i++)
    {
        a.push_back(b[i]);
    }
}

/*<-------store variable used within context--------->*/
/*<-------store variable used within context for dynamic context--------->*/
/*<-------store variable used in function argument--------->*/
