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
    branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
    int result_address = branch[1]->return_dynamic_offset();
    dst << "lw"
        << "$ "<<destReg << ","<< result_address << "($30)" << std::endl;
    if (context.is_Local(branch[0]->get_Id()))
    {
        if (context.find_local(branch[0]->get_Id()).type_name == "INTArray")
        {
            size_type = 2;
        }
        
        // destReg address towards array[0]
        dst << "li "
            << "$5" << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;
        dst << "sll"
            << " $5 "<< ","
            << "$5 "<< "," << size_type << std::endl;
        dst << "addiu "
            << "$5 "
            << ", "
            << "$5"  << ", "
            << "$" << destReg << std::endl;
        //
        dst << "lw " << "$"<< destReg << ", 0("
            << "$5"
            << ")" << std::endl;
    }
    else
    {
        // the accessed array is declared globally;
        dst << "lui "
            << "$ " << destReg << ", "
            << "%hi"
            << "(" << branch[0]->get_Id() << ")" << std::endl;
        dst << "addiu "
            << "$ " << destReg << ", "
            << "$ " << destReg << ", "
            << "%lo"
            << "(" << branch[0]->get_Id() << ")" << std::endl;
        if (context.find_local(branch[0]->get_Id()).type_name == "INTArray")
        {
            size_type = 4;
        }
            dst << "li "
                << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;
            
            dst << "sll"
                << " $5 ,"
                << "$5 ," << size_type << std::endl;
            // destReg address towards array[0]

            dst << "addiu "
                << "$5 "
                << ", "
                << "$5 " << destReg << ", "
                << "$" << destReg << std::endl;
            //
            dst << "lw " << "$" <<destReg << ", 0("
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
