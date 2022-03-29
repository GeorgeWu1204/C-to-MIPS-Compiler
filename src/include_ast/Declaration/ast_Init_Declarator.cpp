#include "AST/Declaration/ast_Init_Declarator.hpp"

Init_Declarator_Mips::Init_Declarator_Mips(const NodePtr Declarator, const NodePtr Initializer)
{
    branch.push_back(Declarator);
    branch.push_back(Initializer);
}

void Init_Declarator_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // Declarator '=' Initializer
    int type_size = 0;
    int offset = 0;
    if (branch[0]->is_Array())
    {
        branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        // note here we only consider inside local scope and we assume we only can declare one array at the same time.

        std::cerr << "IT ID: " << branch[0]->get_Id() << " type " << context.find_local(branch[0]->get_Id()).type_name << std::endl;
        if (context.is_Local(branch[0]->get_Id()))
        {

            if (context.find_local(branch[0]->get_Id()).type_name == "INTArray" || context.find_local(branch[0]->get_Id()).type_name == "FLOATArray")
            {
                type_size = 4;
            }
            else if (context.find_local(branch[0]->get_Id()).type_name == "DOUBLEArray")
            {
                type_size = 8;
            }
            offset = stoi(context.find_local(branch[0]->get_Id()).offset);
        }
        std::cerr << "iffset size: " << offset << std::endl;
        for (int i = 0; i < branch[1]->get_size(); i++)
        {
            branch[1]->get_branch(i)->generateMips(dst, context, destReg, make_name, dynamic_offset);

            if (context.find_local(branch[0]->get_Id()).type_name == "FLOATArray" || context.find_local(branch[0]->get_Id()).type_name == "DOUBLEArray")
            {
                dst << "sw1 "
                    << "$f" << destReg << "," << offset - type_size * i << "($30)" << std::endl;
            }
            else
            {
                dst << "sw "
                    << "$" << destReg << "," << offset - type_size * i << "($30)" << std::endl;
            }
        }
    }
    else if (branch[0]->is_Pointer())
    {

        // inideclaration of pointer    int [  *p = ???   ]     SOS
        std::cerr << "# init Dec is pointer" << std::endl;
        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);

        dst << "sw "
            << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "("
            << "$30"
            << ")" << std::endl;
    }
    else if (context.find_local(branch[0]->get_Id()).type_name == "CHAR")
    {
        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        dst << "sb "
            << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "($30)" << std::endl;
    }

    else
    {
        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset); // check
        dst << "sw "
            << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "("
            << "$30"
            << ")" << std::endl;
    }
}

void Init_Declarator_Mips::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
    int higher_offset = stoi(context.find_local(branch[0]->get_Id()).offset);
    // identifier constant
    if (type == "DOUBLE" || type == "FLOAT")
    {
        int type_size = 0;
        int offset = 0;
        if (context.is_Local(branch[0]->get_Id()))
        {
            if (context.find_local(branch[0]->get_Id()).type_name == "INTArray" || context.find_local(branch[0]->get_Id()).type_name == "FLOATArray")
            {
                type_size = 4;
            }
            else if (context.find_local(branch[0]->get_Id()).type_name == "DOUBLEArray")
            {
                type_size = 8;
            }
            offset = stoi(context.find_local(branch[0]->get_Id()).offset);
        }
        if (branch[0]->is_Pointer())
        {
            branch[1]->generateFloatMips(dst, context, destReg, make_name, dynamic_offset, type);
            dst << "sw "
                << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "($30)" << std::endl;
        }
        else
        {
            for (int i = 0; i < branch[1]->get_size(); i++)
            {
                branch[1]->get_branch(i)->generateFloatMips(dst, context, destReg, make_name, dynamic_offset, type);
                if (type == "DOUBLE")
                {
                    // sos not sure if default f0/f1 is gonna work
                    std::cerr << "swc1 "
                              << "$f0," << higher_offset - type_size * i << "("
                              << "$30"
                              << ")" << std::endl;
                    std::cerr << "swc1 "
                              << "$f1," << higher_offset - 4 - type_size * i << "("
                              << "$30"
                              << ")" << std::endl;
                }
                else
                {
                    std::cerr << "swc1 "
                              << "$f0," << higher_offset - type_size * i << "("
                              << "$30"
                              << ")" << std::endl;
                }
            }
        }
    }
}

std::string Init_Declarator_Mips::get_type() const
{
    return branch[0]->get_type();
}

std::string Init_Declarator_Mips::get_Id() const
{
    return branch[0]->get_Id();
}

bool Init_Declarator_Mips::is_Function() const
{ // not sure about whether a function declaration with initized
    return false;
}

bool Init_Declarator_Mips::is_init() const
{
    // std::cerr << "# <----------------------: Init? " << "------------------------>" << std::endl;
    return true;
}
bool Init_Declarator_Mips::is_Identifier() const
{
    return branch[0]->is_Identifier();
}
int Init_Declarator_Mips::get_Val() const
{
    return branch[1]->get_Val();
}
std::string Init_Declarator_Mips::get_StringVal() const
{
    return branch[1]->get_StringVal();
}

bool Init_Declarator_Mips::is_Array() const
{
    return branch[0]->is_Array();
}
int Init_Declarator_Mips::get_arithmetic_const_val()
{
    return branch[0]->get_arithmetic_const_val();
}
bool Init_Declarator_Mips::is_Pointer() const
{
    std::cerr << "# <----------------------: Pointer? "
              << "------------------------>" << std::endl;
    return branch[0]->is_Pointer();
}
std::vector<FloatDoubleConst> Init_Declarator_Mips::get_Float_Const()
{
    return branch[1]->get_Float_Const();
}
std::vector<std::string> Init_Declarator_Mips::get_String_Const()
{
    std::cerr << "# <----------------------Init_Declarator_Mips: "
              << "------------------------>" << std::endl;
    return branch[1]->get_String_Const();
}
std::vector<double> Init_Declarator_Mips::construct_double_const_list()
{
    return branch[1]->construct_double_const_list();
}