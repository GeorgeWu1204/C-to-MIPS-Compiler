#include "AST/Pointer/ast_UnaryAddress_MIPS.hpp"

// #include "ast_Node.hpp"
// #include "ast.hpp"

UnaryAddress_MIPS::UnaryAddress_MIPS(NodePtr Expression_term_1)
{
    branch.push_back(Expression_term_1);
}

void UnaryAddress_MIPS::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    int type_size = 2;

    if (context.is_Local(get_Id()))
    {

        std::cerr << "inside the address scope" << std::endl;
        // there's no difference for any type of data.

        if (branch[0]->is_Array())
        {
            std::cerr << "is in array" << std::endl;
            // index 0 ---- > top of the stack
            branch[0]->get_branch(1)->generateMips(dst, context, 5, make_name, dynamic_offset);

            if (context.find_local(get_Id()).type_name == "INTArray")
            {
                type_size = 2;
            }
            dst << "sll "
                << "$5,$5," << type_size << std::endl;
            // now the offset is ready
            dst << "addiu "
                << "$" << destReg << ","
                << "$30"
                << "," << context.find_local(get_Id()).offset << std::endl;
            dst << "subu "
                << "$" << destReg << ",$" << destReg << ",$5" << std::endl;
        }
        else
        {
            dst << "addiu "
                << "$" << destReg << ","
                << "$30"
                << "," << context.find_local(get_Id()).offset << std::endl;
        }
    }
    else if (context.is_Global(get_Id()))
    {
        dst << "lui "
            << "$2,"
            << "%hi(" << get_Id() << ")" << std::endl;
        dst << "addiu "
            << "$2,"
            << "$2,%lo(" << get_Id() << ")" << std::endl;
    }
    else
    {
        std::cerr << "This behaviour has not been defined yet" << std::endl;
    }
}

void UnaryAddress_MIPS::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
    int type_size = 2;
    if (type == "DOUBLE")
    {
        type_size = 4;
    }
    else
    {
        type_size = 2;
    }

    if (context.is_Local(get_Id()))
    {

        std::cerr << "inside the address scope" << std::endl;
        // there's no difference for any type of data.
        if (branch[0]->is_Array())
        {
            std::cerr << "is in array" << std::endl;
            // index 0 ---- > top of the stack
            branch[0]->get_branch(1)->generateFloatMips(dst, context, 5, make_name, dynamic_offset, type);
            // generate [ index ]
            dst << "sll "
                << "$5,$5," << type_size << std::endl;
            // now the offset is ready
            dst << "addiu "
                << "$" << destReg << ","
                << "$30"
                << "," << context.find_local(get_Id()).offset << std::endl;
            dst << "subu "
                << "$" << destReg << ",$" << destReg << ",$5" << std::endl;
        }
        else
        {
            dst << "addiu "
                << "$" << destReg << ","
                << "$30"
                << "," << context.find_local(get_Id()).offset << std::endl;
        }
    }
    else if (context.is_Global(get_Id()))
    {
        dst << "lui "
            << "$2,"
            << "%hi(" << get_Id() << ")" << std::endl;
        dst << "addiu "
            << "$2,"
            << "$2,%lo(" << get_Id() << ")" << std::endl;
    }
    else
    {
        std::cerr << "This behaviour has not been defined yet" << std::endl;
    }
}

std::string UnaryAddress_MIPS::get_Id() const
{
    return branch[0]->get_Id();
}

std::string UnaryAddress_MIPS::return_expression_type(Context context)
{
    std::cerr << "# ?????? plz r u serious" << std::endl;
    return "INT";
}