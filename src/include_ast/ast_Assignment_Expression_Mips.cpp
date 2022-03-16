#include "AST/ast_Assignment_Expression_Mips.hpp"

Assignment_Expression_Mips::Assignment_Expression_Mips(const NodePtr Unary_expression, NodePtr Assignment_expression)
{
    branch.push_back(Unary_expression);
    branch.push_back(Assignment_expression);
}
Assignment_Expression_Mips::Assignment_Expression_Mips(const NodePtr ConditionalExpression)
{
    branch.push_back(ConditionalExpression);
}

std::string Assignment_Expression_Mips::get_Id() const
{
    return branch[0]->get_Id();
}
// right hand side
//
//  int Assignment_Expression_Mips::get_Val() const
//  {
//      return branch[1]->get_Val();
//  }

void Assignment_Expression_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // if (branch.size() == 0)
    //{
    //  condition expression

    // branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    std::cout << "In assignment expressiono" << std::endl;
    std::cout << "ID :" << branch[0]->get_Id() << std::endl;
    std::cout << context.is_Global(branch[0]->get_Id()) << std::endl;
    if (context.find_local("$DynamicContext").type_name == "NotDefined")
    {
        std::cout << "Assignment Expression TYPE: " << branch[0]->get_type() << std::endl;
        context.assign_type_to_local_var("$DynamicContext", context.find_local(branch[0]->get_Id()).type_name);
    }
    //}
    // else
    //{
    // unary expression assignment expression

    // stored in register

    // note that int x, y, z  = 9; only assign value to the last variable.
    if (branch[0]->is_Identifier() && context.is_Local(branch[0]->get_Id()))
    {
        // std::cout << "In assignment local identifier" << std::endl;
        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset); // check
        dst << "sw"
            << " $" << destReg << ", " << context.find_local(branch[0]->get_Id()).offset << "("
            << "$30"
            << ")" << std::endl;
    }
    else if (branch[0]->is_Array())
    {
        // std::cout << "In assignment array could be global or local" << std::endl;
        //  x[0]
        //  x[1]
        // std::cout << "<----check content___." << std::endl;
        // context.print_context();
        if (context.is_Local(branch[0]->get_Id()))
        {
            // get address for the array
            // std::cout << "In assignment array local" << std::endl;
            branch[0]->get_branch(1)->generateMips(dst, context, destReg, make_name, dynamic_offset);
            int result_address = branch[0]->get_branch(1)->return_dynamic_offset();
            dst << "lw"
                << "$5 " << result_address << "($30)" << std::endl;
            std::cout << " ID: " << branch[0]->get_Id() << " Type: " << context.find_local(branch[0]->get_Id()).type_name << std::endl;
            if (context.find_local(branch[0]->get_Id()).type_name == "INTArray")
            {
                dst << "sll"
                    << " $5 ,"
                    << "$5 ,"
                    << "2" << std::endl;
            }

            dst << "li "
                << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;
            dst << "addiu "
                << "$5 "
                << ", "
                << "$5 " << destReg << ", "
                << "$" << destReg << std::endl;
            // need to store them into the memory or use 5

            branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
            // dst << "lw "
            //     << " $" <<
            // load from dynamic part

            dst << "sw "
                << "$3 ,"
                << "0("
                << "$5"
                << ")" << std::endl;
        }
        else if (context.is_Global(branch[0]->get_Id()))
        {
            // std::cout << "In assignment array global" << std::endl;
            branch[0]->get_branch(1)->generateMips(dst, context, destReg, make_name, dynamic_offset);
            // std::cout << "In assignment array global1" << std::endl;
            int result_address = branch[0]->get_branch(1)->return_dynamic_offset();
            // std::cout << "In assignment array global2" << std::endl;
            dst << "lui "
                << "$ " << destReg << ", "
                << "%hi"
                << "(" << branch[0]->get_Id() << ")" << std::endl;
            dst << "addiu "
                << "$ " << destReg << ", "
                << "$ " << destReg << ", "
                << "%lo"
                << "(" << branch[0]->get_Id() << ")" << std::endl;
            // to get the address for the offset 0 of the array
            // Load Expression Result to $5
            // Eg v[r[s[4]]]
            // load the stored value in the memory
            //  branch[0]->get_branch(1)->generateMips(dst, context, destReg, make_name, dynamic_offset);
            //  int result_address = branch[0]->get_branch(1)->return_dynamic_offset();
            dst << "lw"
                << "$5 " << result_address << "($30)" << std::endl;
            if (context.find_global(branch[0]->get_Id()).type_name == "INTArray")
            {
                dst << "sll"
                    << " $5 ,"
                    << "$5 ,"
                    << "2" << std::endl;
            }
            // multiply by 4 and add to the array 0 offset address
            //  calculate array index
            dst << "addiu "
                << "$5"
                << ", "
                << "$5, "
                << "$" << destReg << std::endl;
            // need to store in the memory
            // assign it to the correspond array element
            branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
            dst << "sw "
                << "$3 "
                << ", "
                << "0("
                << "$5"
                << ")" << std::endl;
            // load the result back to the array address.
            // need to refresh dynamic context.
            // std::cout << "not implemented yet in assignment expression Mips" << std::endl;
        }
    }
    //}

    // global var // local call
    // local var  // local call
};
int Assignment_Expression_Mips::array_size() const
{
    std::cout << "I dont think you need this" << std::endl;
    return branch[0]->array_size();
}