#include "AST/Type/ast_Array_Access_Mips.hpp"

Array_Access_Mips::Array_Access_Mips(NodePtr Postfix_expression, NodePtr Expression)
{
    branch.push_back(Postfix_expression);
    branch.push_back(Expression);
}

// need to decide
void Array_Access_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // std::string id = branch[0]->get_Id();
    // x[5] = 7
    // x = g[7+2]
    // get address for the array
    int size_type = 0;
    int array_offset = 0;
    branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
    int result_address = branch[1]->return_dynamic_offset();
    dst << "lw "
        << "$" << destReg << "," << result_address << "($30)" << std::endl;
    if (context.is_Local(branch[0]->get_Id()))
    {

        // get address for the array
        // std::cerr << "#" << "In assignment array local" << std::endl;
        // x[]
        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        int result_address = branch[1]->return_dynamic_offset();
        dst << "lw "
            << "$5," << result_address << "($30)" << std::endl;
        dst << "nop " << std::endl;

        Local_var tmp = context.find_local(branch[0]->get_Id());
        if (tmp.type_name == "CHARPTR")
        {
            dst << "lw "
                << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "($30)" << std::endl;
            // dst << "li "<< "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;
            dst << "subu $5,"
                << "$" << destReg << ", $5" << std::endl;
            // dst << "addu "
            //     << "$5,"
            //     << "$5,"
            //     << "$30" << std::endl;
            dst << "lbu "
                << "$" << destReg << ",0($5)" << std::endl;
        }

        else if (tmp.type_name == "CHARArray")
        {
            dst << "li "
                << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;
            dst << "subu $5,"
                << "$" << destReg << ", $5" << std::endl;
            dst << "addu "
                << "$5,"
                << "$5,"
                << "$30" << std::endl;
            dst << "lbu "
                << "$" << destReg << ",0($5)" << std::endl;
        }

        // std::cerr << "#" << " ID: " << branch[0]->get_Id() << " Type: " << context.find_local(branch[0]->get_Id()).type_name << std::endl;
        else if (tmp.type_name == "INTArray")
        {
            dst << "sll "
                << "$5,"
                << "$5,"
                << "2" << std::endl;
            dst << "li "
                << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;
            dst << "subu "
                << "$5"
                << ","
                << "$" << destReg << ","
                << "$5" << std::endl;
            dst << "addu "
                << "$5,"
                << "$5,"
                << "$30" << std::endl;
            // need to store them into the memory or use 5
            dst << "lw "
                << "$" << destReg << ","
                << "0"
                << "($5)" << std::endl;
            // sos
            current_offset = dynamic_offset;
            dst << "sw "
                << "$" << destReg << "," << current_offset << "($30)"
                << std::endl;
        }
        else if (tmp.type_name == "INTPTR")
        {
            dst << "lw "
                << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "($30)" << std::endl;
            dst << "nop " << std::endl;
            dst << "sll "
                << "$5,"
                << "$5,"
                << "2" << std::endl;
            dst << "addu "
                << "$5,"
                << "$" << destReg << ",$5" << std::endl;
            dst << "lw "
                << "$" << destReg << ", 0"
                << "($5)" << std::endl;
            current_offset = dynamic_offset;
            dst << "sw "
                << "$" << destReg << "," << current_offset << "($30)"
                << std::endl;
        }

        // <--------------------------------------------------------------Previous----------------------------------------------------------------->
    }
    else
    {
        // the accessed array is declared globally; SOS
        dst << "lui "
            << "$" << destReg << ","
            << "%hi"
            << "(" << branch[0]->get_Id() << ")" << std::endl;
        dst << "addu "
            << "$" << destReg << ","
            << "$" << destReg << ","
            << "%lo"
            << "(" << branch[0]->get_Id() << ")" << std::endl;
        if (context.find_local(branch[0]->get_Id()).type_name == "INTArray")
        {
            size_type = 4;
        }
        dst << "li "
            << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;

        dst << "sll "
            << "$5,"
            << "$5," << size_type << std::endl;
        // // destReg address towards array[0]

        dst << "addu"
            << "$5"
            << ","
            << "$5 " << destReg << ","
            << "$" << destReg << std::endl;

        array_offset = size_type * branch[1]->get_arithmetic_const_val();
        dst << "lw "
            << "$" << destReg << "," << array_offset << "("
            << "$5"
            << ")" << std::endl;
    }

    // lui     $2,%hi(x)
    // addiu   $2,$2,%lo(x)
    // lw      $2,8($2)
    // nop

    // need to store them into the memory or use 5
    // dst << "lw "
    //     << " $" <<
    // load from dynamic part

    //
}

bool Array_Access_Mips::is_Array() const
{
    return true;
}

std::string Array_Access_Mips::get_Id() const
{
    return branch[0]->get_Id();
}

int Array_Access_Mips::Dynamic_context_size()
{
    return branch[0]->Dynamic_context_size();
}

int Array_Access_Mips::return_dynamic_offset()
{
    // std::cerr << "# This is a tmp solution" << std::endl;
    return current_offset;
}
std::string Array_Access_Mips::get_cloest_Id() const
{
    return branch[0]->get_cloest_Id();
}