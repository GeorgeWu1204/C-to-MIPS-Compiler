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
    std::cerr << "#"
              << "In assignment expressiono" << std::endl;
    std::cerr << "#"
              << "ID :" << branch[0]->get_Id() << std::endl;
    std::cerr << "#" << context.is_Global(branch[0]->get_Id()) << std::endl;

    // sos
    if (context.find_local("$DynamicContext").type_name == "NotDefined")
    {
        // std::cerr << "#"
        //           << "Assignment Expression TYPE: " << branch[0]->return_expression_type(context) << std::endl;
        // context.assign_type_to_local_var("$DynamicContext", branch[0]->return_expression_type(context));

        std::string tmp_type = "NotDefined";
        if (context.is_Local(branch[0]->get_Id()))
        {
            tmp_type = context.find_local(branch[0]->get_Id()).type_name;
        }
        else if (context.is_Global(branch[0]->get_Id()))
        {
            tmp_type = context.find_global(branch[0]->get_Id()).type_name;
        }
        std::cerr << "# <--------------------------------------- dynamic type " << tmp_type << " ---------------------------------------> " << std::endl;
        if (tmp_type.length() > 6)
        {
            if (tmp_type.substr(tmp_type.length() - 3) == "PTR")
            {
                tmp_type = tmp_type.erase(tmp_type.length() - 3, tmp_type.length());
            }
            else if (tmp_type.substr(tmp_type.length() - 5) == "Array")
            {
                tmp_type = tmp_type.erase(tmp_type.length() - 5, tmp_type.length());
            }
            else
            {
                std::cerr << "# struct ? i dont understand" << std::endl;
            }
        }
        std::cerr << "# <--------------------------------------- dynamic type after " << tmp_type << " ---------------------------------------> " << std::endl;
        context.assign_type_to_local_var("$DynamicContext", tmp_type);
        // INTARRAY
        // SOSOSOSOOSOSOSOSOSOSOSOSO
    }
    std::cerr << "# dynamic done" << std::endl;
    // unary expression assignment expression
    // stored in register
    // note that int x, y, z  = 9; only assign value to the last variable.
    if (branch[0]->is_Identifier())
    {

        if (context.is_Local(branch[0]->get_Id()))
        {
            // std::cerr << "#" << "In assignment local identifier" << std::endl;
            Local_var tmp = context.find_local(branch[0]->get_Id());
            if (tmp.type_name == "DOUBLE" || tmp.type_name == "FLOAT")
            {
                std::cerr << "#check double" << std::endl;
                branch[1]->generateFloatMips(dst, context, destReg, make_name, dynamic_offset, tmp.type_name); // check
                int higher_offset = stoi(context.find_local(branch[0]->get_Id()).offset);
                if (tmp.type_name == "DOUBLE")
                {

                    // sos not sure if default f0/f1 is gonna work
                    std::cerr << "swc1 "
                              << "$f" << destReg << "," << higher_offset << "("
                              << "$30"
                              << ")" << std::endl;
                    std::cerr << "swc1 "
                              << "$f" << destReg + 1 << "," << higher_offset - 4 << "("
                              << "$30"
                              << ")" << std::endl;
                }
                else
                {
                    std::cerr << "swc1 "
                              << "$f" << destReg << "," << higher_offset << "("
                              << "$30"
                              << ")" << std::endl;
                }
                // store to the stack
                // dst << "sw"
                //     << " $" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "("
                //     << "$30"
                //     << ")" << std::endl;
            }
            else if (tmp.type_name == "CHAR")
            {
                branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset); // check
                dst << "sb "
                    << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "($30)" << std::endl;
            }
            else
            {

                branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset); // check
                dst << "sw"
                    << " $" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "("
                    << "$30"
                    << ")" << std::endl;
            }
        }
        else if (context.is_Global(branch[0]->get_Id()))
        {

            Global_var tmp = context.find_global(branch[0]->get_Id());
            if (tmp.type_name == "DOUBLE" || tmp.type_name == "FLOAT")
            { // SOS not cover yet
            }
            else if (tmp.type_name == "CHAR")
            {
            }
            else
            {
                // INT
                branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset); // check
                // Left Side
                dst << "lui "
                    << "$" << destReg << ",%hi(" << branch[0]->get_Id() << ")" << std::endl;
                dst << "sw "
                    << "$3"
                    << ",%lo(" << branch[0]->get_Id() << ")("
                    << "$" << destReg << ")" << std::endl;
            }
        }
    }
    else if (branch[0]->is_Pointer())
    {

        std::cerr << "# is Pointer Assignment" << std::endl;
        dst << "lw "
            << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "("
            << "$30"
            << ")" << std::endl;
        branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
        dst << "sw "
            << "$3"
            << ","
            << "0"
            << "($"
            << destReg
            << ")" << std::endl;
    }
    else if (branch[0]->is_Array())
    {
        // std::cerr << "inside assi" << std::endl;

        // std::cerr << "#" << "In assignment array could be global or local" << std::endl;
        //  x[0]
        //  x[1]
        // std::cerr << "#" << "<----check content___." << std::endl;
        // context.print_context();

        /*
                branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
                int result_address = branch[1]->return_dynamic_offset();
                dst << "lw "
                    << "$5," << result_address << "($30)" << std::endl;
                dst << "nop " << std::endl;

                Local_var tmp = context.find_local(branch[0]->get_Id());
                if (tmp.type_name == "CHARPTR")
                {
                    dst << "lw"
                        << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "($30)" << std::endl;
                    // dst << "li "<< "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;
                    dst << "subu $5,"
                        << "$" << destReg << ", $5" << std::endl;
                    dst << "lbu "
                        << "$" << destReg << ",$5($30)" << std::endl;
                }

                else if (tmp.type_name == "CHARArray")
                {
                    dst << "li "
                        << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;
                    dst << "subu $5,"
                        << "$" << destReg << ", $5" << std::endl;
                    dst << "lbu "
                        << "$" << destReg << ",$5($30)" << std::endl;
                }
        */
        // std::cerr << "#inside assignmenet" << std::endl;
        if (context.is_Local(branch[0]->get_Id()))
        {
            Local_var tmp = context.find_local(branch[0]->get_Id());
            // get address for the array
            // std::cerr << "#" << "In assignment array local" << std::endl;
            branch[0]->get_branch(1)->generateMips(dst, context, destReg, make_name, dynamic_offset);
            int result_address = branch[0]->get_branch(1)->return_dynamic_offset();
            dst << "lw "
                << "$5," << result_address << "($30)" << std::endl;
            // std::cerr << "#" << " ID: " << branch[0]->get_Id() << " Type: " << context.find_local(branch[0]->get_Id()).type_name << std::endl;
            if (tmp.type_name == "CHARPTR")
            {
                dst << "lw"
                    << "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << "($30)" << std::endl;
                // dst << "li "<< "$" << destReg << "," << context.find_local(branch[0]->get_Id()).offset << std::endl;
                dst << "subu $5,"
                    << "$" << destReg << ", $5" << std::endl;
                branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
                dst << "sb "
                    << "$3"
                    << ",$5($30)" << std::endl;
            }
            else
            {
                if (context.find_local(branch[0]->get_Id()).type_name == "INTArray")
                {
                    dst << "sll "
                        << "$5,"
                        << "$5,"
                        << "2" << std::endl;
                }
                else if (context.find_local(branch[0]->get_Id()).type_name == "CHARArray")
                {
                    // do nothing
                }
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
                branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
                dst << "sw "
                    << "$3"
                    << ","
                    << "0"
                    << "($5)" << std::endl;
            }
        }
        else if (context.is_Global(branch[0]->get_Id()))
        {
            // std::cerr << "#" << "In assignment array global" << std::endl;
            branch[0]->get_branch(1)->generateMips(dst, context, destReg, make_name, dynamic_offset);
            // std::cerr << "#" << "In assignment array global1" << std::endl;
            int result_address = branch[0]->get_branch(1)->return_dynamic_offset();
            // std::cerr << "#" << "In assignment array global2" << std::endl;
            dst << "lui "
                << "$" << destReg << ","
                << "%hi"
                << "(" << branch[0]->get_Id() << ")" << std::endl;
            dst << "addiu "
                << "$" << destReg << ","
                << "$" << destReg << ","
                << "%lo"
                << "(" << branch[0]->get_Id() << ")" << std::endl;
            // to get the address for the offset 0 of the array
            // Load Expression Result to $5
            // Eg v[r[s[4]]]
            // load the stored value in the memory
            //  branch[0]->get_branch(1)->generateMips(dst, context, destReg, make_name, dynamic_offset);
            //  int result_address = branch[0]->get_branch(1)->return_dynamic_offset();
            dst << "lw "
                << "$5"
                << "," << result_address << "($30)" << std::endl;
            context.print_global();
            if (context.is_Global(branch[0]->get_Id()))
            {
                // std::cerr << "is in global" << std::endl;
                if (context.find_global(branch[0]->get_Id()).type_name == "INTArray")
                {
                    dst << "sll "
                        << "$5,"
                        << "$5,"
                        << "2" << std::endl;
                }
            }
            // multiply by 4 and add to the array 0 offset address
            //  calculate array index
            dst << "addu "
                << "$5"
                << ","
                << "$5,"
                << "$" << destReg << std::endl;
            // need to store in the memory
            // assign it to the correspond array element
            branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
            dst << "sw "
                << "$3"
                << ","
                << "0("
                << "$5"
                << ")" << std::endl;
            // load the result back to the array address.
            // need to refresh dynamic context.
            // std::cerr << "#" << "not implemented yet in assignment expression Mips" << std::endl;
        }
    }
    else if (branch[0]->is_Struct_Call())
    {

        // std::cerr << "#in struct call" << std::endl;
        if (context.is_Local(branch[0]->get_Id()))
        {
            int tmp_offset = stoi(context.find_local(branch[0]->get_Id()).offset);
            // std::cerr << "check 1" << tmp_offset <<std::endl;
            // x.y.z = ((x.y).z).g
            tmp_offset -= branch[0]->get_struct_variable_offset(context);
            // context.Type_Str.find(context.find_local(branch[0]->get_Id()).type_name)->second.struct_content.find(branch[1]->get_Id())->second.offset;
            // std::cerr << "check 2" << tmp_offset << std::endl;
            branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
            dst << "sw"
                << " $3," << tmp_offset << "($30)" << std::endl;
            // dst << "lw " << "$" << destReg << "," << tmp_offset << "($30)"<< std::endl;
        }
        else if (context.is_Global(branch[0]->get_Id()))
        { // global
            // std::cerr << "#inside global" << std::endl;
            int tmp_offset = stoi(context.find_global(branch[0]->get_Id()).offset);
            // tmp_offset += context.Type_Str.find(branch[0]->get_type())->second.struct_content.find(branch[1]->get_Id())->second.offset;
            branch[1]->generateMips(dst, context, 3, make_name, dynamic_offset);
            // dst << "lw " << "$" << destReg << "," << tmp_offset << "($30)"<< std::endl;
        }
    }
}

int Assignment_Expression_Mips::array_size() const
{
    std::cerr << "#"
              << "I dont think you need this" << std::endl;
    return branch[0]->array_size();
}
bool Assignment_Expression_Mips::is_Assignment() const
{
    return true;
}
std::vector<FloatDoubleConst> Assignment_Expression_Mips::get_Float_Const()
{
    return branch[1]->get_Float_Const();
}

std::vector<std::string> Assignment_Expression_Mips::get_String_Const()
{
    return branch[1]->get_String_Const();
}
std::string Assignment_Expression_Mips::get_cloest_Id() const
{
    // tmp solution
    return branch[0]->get_cloest_Id();
}