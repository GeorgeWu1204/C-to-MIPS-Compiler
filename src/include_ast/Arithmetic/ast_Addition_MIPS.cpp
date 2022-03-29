#include "AST/Arithmetic/ast_Addition_MIPS.hpp"
// #include "ast_Node.hpp"
// #include "ast.hpp"

Addition_MIPS::Addition_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{

    // Left = leftinput;
    // Right = rightinput;
}

void Addition_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{

    // context.print_local();
    std::string left_ID = branch[0]->get_cloest_Id();
    std::cerr << "#<--------------------------------------Cloest ID " << left_ID << "---------------------------------->" << std::endl;
    std::cerr << "#<--------------------------------------Context---------------------------------->" << std::endl;
    std::string type;
    if (context.is_Local(left_ID))
    {
        type = context.find_local(left_ID).type_name;
        std::cerr << "#<--------------------------------------type " << type << "---------------------------------->" << std::endl;
    }
    else if (context.is_Global(left_ID))
    {
        type = context.find_global(left_ID).type_name;
    }
    else
    {
        if (left_ID == "$DOUBLE")
        {
            type = "DOUBLE";
        }
        else if (left_ID == "FLOAT")
        {
            type = "FLOAT";
        }
        else if (left_ID == "INT")
        {
            type = "INT";
        }
    }

    if (type == "DOUBLE" || type == "FLOAT")
    {
        generateFloatMips(dst, context, 0, make_name, dynamic_offset, type);
    }
    else
    {
        generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);  // Identifier
        generate_right(dst, context, 4, branch[1], make_name, dynamic_offset); // Express
        if (branch[0]->is_Identifier() || branch[0]->is_Constant() || branch[0]->is_Struct_Call() || branch[0]->is_Pointer())
        {
            generate_left(dst, context, 3, branch[0], make_name, dynamic_offset);
        }
        else
        {
            dst << "lw "
                << "$3," << branch[0]->return_dynamic_offset() << "($30)" << std::endl;
        }

        if (branch[1]->is_Identifier() || branch[1]->is_Constant() || branch[1]->is_Struct_Call() || branch[1]->is_Pointer())
        {
            generate_left(dst, context, 4, branch[1], make_name, dynamic_offset);
            // std::cerr << "# found!" << std::endl;
        }
        else
        {
            dst << "lw "
                << "$4," << branch[1]->return_dynamic_offset() << "($30)" << std::endl;
        }
        std::cerr << "# dynamic context ?" << std::endl;
        std::string type = context.find_local("$DynamicContext").type_name;
        std::cerr << "#"
                  << "type: " << type << std::endl;
        // std::cerr << "#" << context.find_local("$DynamicContext").type_name << std::endl;
        if (type == "INT")
        {
            std::cerr << "#"
                      << "Dynamic Offset: " << dynamic_offset << std::endl;
            dynamic_offset -= 4;
        }
        else if (type == "DOUBLE")
        {
            dynamic_offset -= 8;
        }
        else
        {
            // std::cerr << "#" << "ADD error Dynamic Reference Type not set up" << std::endl;
        }
        std::cerr << "#"
                  << "Dynamic Offset for current offset:" << dynamic_offset << std::endl;
        current_offset = dynamic_offset;
        bool leftpointer = false;
        bool rightpointer = false;
        std::string stringtest;
        // std::cerr << "f1 : ID" <<  Left->get_Id() << std::endl;

        if (context.is_Local(Left->get_Id()))
        {
            // std::cerr << "#inside ptr addition ID: " << Left->get_Id() << std::endl;
            // std::cerr << "#inside ptr addition Type: " << context.find_local(Left->get_Id()).type_name.substr(type.length()-3) << std::endl;
            stringtest = context.find_local(Left->get_Id()).type_name;
            if (stringtest.length() > 3 && stringtest != "CHARPTR")
            {
                if (stringtest.substr(stringtest.length() - 3) == "PTR")
                {
                    leftpointer = true;
                }
            }
        }
        else if (context.is_Global(Left->get_Id()))
        {
            stringtest = context.find_global(Left->get_Id()).type_name;
            if (stringtest.length() > 3 && stringtest != "CHARPTR")
            {
                if (stringtest.substr(stringtest.length() - 3) == "PTR")
                {
                    leftpointer = true;
                }
            }
        }
        if (context.is_Local(Right->get_Id()))
        {
            stringtest = context.find_local(Right->get_Id()).type_name;
            if (stringtest.length() > 3 && stringtest != "CHARPTR")
            {
                if (stringtest.substr(stringtest.length() - 3) == "PTR")
                {
                    rightpointer = true;
                }
            }
        }
        else if (context.is_Global(Right->get_Id()))
        {
            stringtest = context.find_global(Right->get_Id()).type_name;
            if (stringtest.length() > 3 && stringtest != "CHARPTR")
            {
                if (stringtest.substr(stringtest.length() - 3) == "PTR")
                {
                    rightpointer = true;
                }
            }
        }

        if (leftpointer && rightpointer)
        {
            dst << "nop" << std::endl;
            dst << "addu "
                << "$" << destReg << ","
                << "$3"
                << ","
                << "$4"
                << std::endl;
            dst << "sra "
                << "$" << destReg << ",$" << destReg << ",2" << std::endl;
        }
        else if (leftpointer == true && rightpointer == false)
        {
            dst << "nop" << std::endl;
            dst << "sll $4, 2" << std::endl;
            dst << "addu "
                << "$" << destReg << ","
                << "$3"
                << ","
                << "$4"
                << std::endl;
        }
        else if (leftpointer == true && rightpointer == false)
        {
            dst << "nop" << std::endl;
            dst << "sll $4, 2" << std::endl;
            dst << "addu "
                << "$" << destReg << ","
                << "$3"
                << ","
                << "$4"
                << std::endl;
        }
        else
        {
            dst << "nop" << std::endl;
            dst << "addu "
                << "$" << destReg << ","
                << "$3"
                << ","
                << "$4"
                << std::endl;
        }
        dst << "sw "
            << "$" << destReg << "," << current_offset << "($30)" << std::endl;
    }
}
void Addition_MIPS::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{

    generateFloat_left(dst, context, 2, branch[0], make_name, dynamic_offset, type);
    generateFloat_right(dst, context, 4, branch[1], make_name, dynamic_offset, type);

    if (branch[0]->is_Identifier() || branch[0]->is_Struct_Call() || branch[0]->is_Constant())
    {

        generateFloat_left(dst, context, 2, branch[0], make_name, dynamic_offset, type); // Identifier
    }
    else
    {
        if (type == "DOUBLE")
        {
            dst << "lwc1 "
                << "$f2," << branch[0]->return_dynamic_offset() + 4 << "($30)" << std::endl;
            dst << "lwc1 "
                << "$f3," << branch[0]->return_dynamic_offset() << "($30)" << std::endl;
        }
        else
        {
            dst << "lwc1 "
                << "$f2," << branch[0]->return_dynamic_offset() << "($30)" << std::endl;
        }
    }

    if (branch[1]->is_Identifier() || branch[1]->is_Constant() || branch[1]->is_Struct_Call())
    {
        generateFloat_right(dst, context, 4, branch[1], make_name, dynamic_offset, type);
    }
    else
    {
        if (type == "DOUBLE")
        {
            dst << "lwc1 "
                << "$f4," << branch[1]->return_dynamic_offset() + 4 << "($30)" << std::endl;
            dst << "lwc1 "
                << "$f5," << branch[1]->return_dynamic_offset() << "($30)" << std::endl;
        }
        else
        {
            dst << "lwc1 "
                << "$f4," << branch[1]->return_dynamic_offset() << "($30)" << std::endl;
        }
    }
    std::cerr << "#"
              << "type: " << type << std::endl;
    if (type == "FLOAT")
    {
        std::cerr << "#"
                  << "Dynamic Offset: " << dynamic_offset << std::endl;
        dynamic_offset -= 4;
    }
    else if (type == "DOUBLE")
    {
        dynamic_offset -= 8;
    }
    else
    {
        // std::cerr << "#" << "ADD error Dynamic Reference Type not set up" << std::endl;
    }
    std::cerr << "#"
              << "Dynamic Offset for current offset:" << dynamic_offset << std::endl;
    current_offset = dynamic_offset;
    dst << "nop" << std::endl;
    if (type == "FLOAT")
    {
        dst << "add.s "
            << "$f" << destReg << ","
            << "$f2"
            << ",$f4" << std::endl;
        dst << "swc1 "
            << "$f" << destReg << "," << current_offset << "($30)" << std::endl;
    }
    else if (type == "DOUBLE")
    {
        dst << "add.d "
            << "$f" << destReg << ","
            << "$f2"
            << ","
            << "$f4"
            << std::endl;
        dst << "swc1 "
            << "$f" << destReg << "," << current_offset + 4 << "($30)" << std::endl;
        dst << "swc1 "
            << "$f" << destReg + 1 << "," << current_offset << "($30)" << std::endl;
    }
}

int Addition_MIPS::get_arithmetic_const_val()
{
    return branch[0]->get_arithmetic_const_val() + branch[0]->get_arithmetic_const_val();
}
