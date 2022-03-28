#include "AST/Arithmetic/ast_Equal_MIPS.hpp"

Equal_MIPS::Equal_MIPS(NodePtr leftinput, NodePtr rightinput)
    : Arithmetic_MIPS(leftinput, rightinput)
{
}

void Equal_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::string left_ID = branch[0]->get_cloest_Id();
    std::cout << "#<--------------------------------------Cloest ID " << left_ID << "---------------------------------->" << std::endl;
    std::cout << "#<--------------------------------------Context---------------------------------->" << std::endl;
    std::string type;
    if (context.is_Local(left_ID))
    {
        type = context.find_local(left_ID).type_name;
        std::cout << "#<--------------------------------------type " << type << "---------------------------------->" << std::endl;
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
        std::cerr << "#"
                  << "Dynamic Offset: " << dynamic_offset << std::endl;
        if (branch[0]->is_Identifier() || branch[0]->is_Constant() || branch[0]->is_Struct_Call()|| branch[0]->is_Pointer())
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
        }
        else
        {
            dst << "lw "
                << "$4," << branch[1]->return_dynamic_offset() << "($30)" << std::endl;
        }
        std::string type = context.find_local("$DynamicContext").type_name;
        // std::cerr << "#" << context.find_local("$DynamicContext").type_name << std::endl;
        if (type == "INT")
        {
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
        current_offset = dynamic_offset;
        dst << "nop" << std::endl;
        dst << "xor "
            << "$" << destReg << ","
            << "$3"
            << ","
            << "$4" << std::endl;
        dst << "sltu "
            << "$" << destReg << ","
            << "$" << destReg << "," << 1 << std::endl;
        dst << "andi "
            << "$" << destReg << ","
            << "$" << destReg << ","
            << "0x00ff" << std::endl;
        dst << "sw "
            << "$" << destReg << "," << current_offset << "($30)" << std::endl;
    }
    // equal = $3 - $4 = 0;
}
void Equal_MIPS::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
    // lwc1    $f2,8($fp)
    // lwc1    $f0,24($fp)
    // nop
    // add.s   $f0,$f2,$f0
    // swc1    $f0,8($fp)

    std::cout << "#<--------------------------------------Left " << destReg << "---------------------------------->" << std::endl;
    generateFloat_left(dst, context, 2, branch[0], make_name, dynamic_offset, type);
    std::cout << "#<--------------------------------------Right " << destReg << "---------------------------------->" << std::endl;
    generateFloat_right(dst, context, 4, branch[1], make_name, dynamic_offset, type);

    if (branch[0]->is_Identifier() || branch[0]->is_Struct_Call() || branch[0]->is_Constant())
    {
        std::cout << "# Generate Left Start " << std::endl;
        generateFloat_left(dst, context, 2, branch[0], make_name, dynamic_offset, type); // Identifier
        std::cout << "# Generate Left Done" << std::endl;
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

    if (branch[1]->is_Identifier() || branch[1]->is_Constant() || branch[0]->is_Struct_Call())
    {
        generateFloat_right(dst, context, 4, branch[1], make_name, dynamic_offset, type);
    }
    else
    {
        if (type == "DOUBLE")
        {
            dst << "lwc1 "
                << "$f4," << branch[0]->return_dynamic_offset() + 4 << "($30)" << std::endl;
            dst << "lwc1 "
                << "$f5," << branch[0]->return_dynamic_offset() << "($30)" << std::endl;
        }
        else
        {
            dst << "lwc1 "
                << "$f4," << branch[0]->return_dynamic_offset() << "($30)" << std::endl;
        }
    }
    // type = context.find_local("$DynamicContext").type_name;
    std::cerr << "#"
              << "type: " << type << std::endl;
    // std::cerr << "#" << context.find_local("$DynamicContext").type_name << std::endl;
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
        dst << "c.eq.s "
            << "$f2"
            << ",$f0" << std::endl;
        dst << "mfc1 $" << destReg << ", $fcc0" << std::endl;
    }
    else if (type == "DOUBLE")
    {
        dst << "c.eq.d "
            << "$f2"
            << ",$f0" << std::endl;
        dst << "mfc1 $" << destReg << ", $fcc0" << std::endl;
        // dst << "swc1 "
        //     << "$f" << destReg << "," << current_offset + 4 << "($30)" << std::endl;
        // dst << "swc1 "
        //     << "$f" << destReg + 1 << "," << current_offset << "($30)" << std::endl;
    }
}

int Equal_MIPS::get_arithmetic_const_val()
{
    return branch[0]->get_arithmetic_const_val() == branch[1]->get_arithmetic_const_val();
}

//         li      $2,1                        # 0x1
//         lwc1    $f2,8($fp)
//         lwc1    $f0,12($fp)
//         nop
//         c.eq.s  $f2,$f0
//         nop
//         bc1t    $L2
//         nop

//         move    $2,$0
// $L2:
//         andi    $2,$2,0x00ff