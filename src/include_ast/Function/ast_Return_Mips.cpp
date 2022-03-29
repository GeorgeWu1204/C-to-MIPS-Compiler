#include "AST/Function/ast_Return_Mips.hpp"

Return_Mips::Return_Mips(NodePtr Expression)
{
    branch.push_back(Expression);
}
// Return_Mips::Return_Mips()
// {
//     Return_Mips(new Node());
//     std::cerr << "<------------------- size of a emtpy node ----------------------->" << std::endl;

//     //std::cerr << "<------------------- size of a emtpy node " << branch[0]->get_size() << " ----------------------->" << std::endl;
// }

void Return_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::cerr << "#inside return MIPS" << std::endl;
    std::map<std::string, Local_var> tmp = context.extract_local_var();

    std::string type_name;
    if (context.is_Local(branch[0]->get_Id()))
    {
        type_name = tmp.find(branch[0]->get_Id())->second.type_name;
    }
    else
    {
        // in global instead
        std::map<std::string, Global_var> tmpglobal = context.extract_global_var();
        if (tmpglobal.find(branch[0]->get_Id()) != tmpglobal.end())
        {
            type_name = tmpglobal.find(branch[0]->get_Id())->second.type_name;
        }
    }

    if (type_name == "DOUBLE" || type_name == "DOUBLEPTR" || type_name == "DOUBLEArray")
    {
        branch[0]->generateFloatMips(dst, context, 0, make_name, dynamic_offset, "DOUBLE");
    }
    else if (type_name == "FLOAT" || type_name == "FLOATPTR" || type_name == "FLOATArray")
    {
        branch[0]->generateFloatMips(dst, context, 0, make_name, dynamic_offset, "FLOAT");
    }
    else
    {
        branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    }
    // branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    dst << "b " << context.Function_Ending_Label << std::endl;
}

void Return_Mips::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
    std::cerr << "inside call" << std::endl;
    branch[0]->generateFloatMips(dst, context, 0, make_name, dynamic_offset, type);
    dst << "b " << context.Function_Ending_Label << std::endl;
}
// std::string Return_Mips::get_Id() const
// {
//     return branch[0]->get_Id();
// }

// bool Return_Mips::is_Function_inside() const{
//     return branch[0]->is_Function_inside();
// }

bool Return_Mips::is_Jump_statement() const
{
    return true;
}

int Return_Mips::Dynamic_context_size()
{
    return branch[0]->Dynamic_context_size();
}
std::vector<FloatDoubleConst> Return_Mips::get_Float_Const()
{
    return branch[0]->get_Float_Const();
}

std::vector<std::string> Return_Mips::get_String_Const()
{
    return branch[0]->get_String_Const();
}