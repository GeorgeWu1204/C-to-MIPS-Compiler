#include "AST/Arithmetic/ast_Arithmetic_MIPS.hpp"

Arithmetic_MIPS::Arithmetic_MIPS(NodePtr leftinput, NodePtr rightinput)
{
    branch.push_back(leftinput);
    branch.push_back(rightinput);
    Left = leftinput;
    Right = rightinput;
}
void Arithmetic_MIPS::generate_left(std::ostream &dst, Context &context, int destReg, NodePtr leftnode, MakeName &make_name, int &dynamic_offset)
{

    // if it is variable defined before.

    // maybe we dont need to differeniate them
    // if (leftnode->is_Identifier())
    // {
    //     if (context.is_Local(leftnode->get_Id()))
    //     {
    //         //leftnode->generateMips(dst, context, destReg, make_name, dynamic_offset); SOS
    //         dst << "lw "
    //             << "$" << destReg << " " << (context.find_local(leftnode->get_Id())).offset << "("
    //             << "$30"
    //             << ")" << std::endl;

    //         // assume int type
    //         // do not add dynamic offset
    //     }
    // }else if (leftnode->is_Constant())
    // {
    //     leftnode->generateMips(dst, context, destReg, make_name, dynamic_offset);
    //     // assume int type
    //     // do not add dynamic offset
    // }
    // else if (leftnode->is_Function())
    // {
    //     // dst << "sw" << "$2" <<
    //     dst << "not supported" << std::endl;
    // }
    // else
    // {
    //     leftnode->generateMips(dst, context, destReg, make_name, dynamic_offset); 
    // }
    if (leftnode->is_Function())
    {
        dst << "not supported" << std::endl;
    }
    else
    {
        leftnode->generateMips(dst, context, destReg, make_name, dynamic_offset); 
    }
}

void Arithmetic_MIPS::generate_right(std::ostream &dst, Context &context, int destReg, NodePtr rightnode, MakeName &make_name, int &dynamic_offset)
{
    // if (rightnode->is_Identifier())
    // {
    //     if (context.is_Local(rightnode->get_Id()))
    //     {

    //         dst << "lw "
    //             << "$" << destReg << " " << (context.find_local(rightnode->get_Id())).offset << "("
    //             << "$30"
    //             << ")" << std::endl;
    //         // assume int type
    //         // do not add dynamic offset
    //     }
    // }
    // else if (rightnode->is_Function())
    // {
    //     // dst << "sw" << "$2" <<
    //     dst << "not supported" << std::endl;
    // }
    // else
    // {

    //     rightnode->generateMips(dst, context, destReg, make_name, dynamic_offset);
       
    // }
    
    if (rightnode->is_Function())
    {
        // dst << "sw" << "$2" <<
        dst << "not supported" << std::endl;
    }
    else
    {

        rightnode->generateMips(dst, context, destReg, make_name, dynamic_offset);
       
    }
}

int Arithmetic_MIPS::return_dynamic_offset(){
    return current_offset;
}

int Arithmetic_MIPS::Dynamic_context_size()
{
    return branch[0]->Dynamic_context_size() + branch[1]->Dynamic_context_size() + 1;
}

// void Arithmetic_MIPS::assign_dynamic_offset(int offset_val){
//     current_offset = offset_val;
// }
// void Arithmetic_MIPS::pass_offset(int cur_offset, int left_size){

// }
