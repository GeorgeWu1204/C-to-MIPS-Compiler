#include "AST/Function/ast_Function.hpp"

Function::Function(NodePtr headinput, NodePtr bodyinput)
{
    branch.push_back(headinput);
    branch.push_back(bodyinput);
    func_name = branch[0]->get_Id();
    return_type = branch[0]->get_type();
}

void Function::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    int function_stack_size = 0;
    // note the inner function stack size only depends on the body part.
    if (branch[1]->get_context_local_size() == 0)
    {
        function_stack_size = 8;
    }
    else
    {
        function_stack_size = 16 + branch[1]->get_context_local_size();
    }
    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    // dst<<"addiu" << "$31, " << "$31" << "-" <<sizeoffunction(global_var)<< std::endl;
    dst << "addiu "
        << "$31, "
        << "$31, -" << function_stack_size << std::endl;
    if (branch[1]->is_Function_inside())
    {
        dst << "//there is a function inside" << std::endl;
        dst << "sw "
            << "$31, " << function_stack_size - 4 << "("
            << "$31"
            << ")" << std::endl;
        dst << "sw "
            << "$30, " << function_stack_size - 8 << "("
            << "$31"
            << ")" << std::endl;
    }
    else
    {
        dst << "sw "
            << "$30, " << function_stack_size - 4 << "("
            << "$31"
            << ")" << std::endl;
    }
    dst << "move "
        << "$30, "
        << "$31" << std::endl;
    // Argument Load
    if (branch[0]->get_argument_size() <= 4)
    {
        // when argument size is less than or equal to 4
        for (int m = 0; m < branch[0]->get_argument_size(); m++)
        {
            dst << "sw"
                << "$" << m
                << "," << function_stack_size + 4 * m
                << "("
                << "$30"
                << ")" << std::endl;
        }
    }
    else
    {
        // when the num of arguments exceeds 5 arguments.
        for (int m = 0; m < 4; m++)
        {
            dst << "sw"
                << "$" << m
                << "," << function_stack_size + 4 * m
                << "("
                << "$30"
                << ")" << std::endl;
        }
        // store in memory and can be retrieved directly.
    }

    // body part
    Func_context.sync_local_context(Argument_context, context);
    // synch local context of the context with the or used argument_context directly as context here is empty;
    branch[1]->generateMips(dst, Func_context, destReg, make_name, dynamic_offset);
    dst << "nop" << std::endl;
    dst << "move "
        << "$30, "
        << "$31" << std::endl;
    if (branch[1]->is_Function_inside())
    {
        dst << "//end with function inside" << std::endl;
        dst << "lw "
            << "$31, " << function_stack_size - 4 << "("
            << "$31"
            << ")" << std::endl;
        dst << "lw "
            << "$30, " << function_stack_size - 8 << "("
            << "$31"
            << ")" << std::endl;
    }
    else
    {
        dst << "lw "
            << "$30, " << function_stack_size - 4 << "("
            << "$31"
            << ")" << std::endl;
    }
    dst << "addiu "
        << "$31, "
        << "$31, "
        << function_stack_size << std::endl;
    dst << "jr"
        << " $31" << std::endl;
    dst << "nop" << std::endl;

    // if define function inside a function?
}

void Function::add_argument_to_context(int index)
{
    int u = 0;
    int offset = 0;
    //represent offset index in the map
    std::map<std::string, std::string> argmap = branch[0]->get_argument_map();
    for (std::map<std::string, std::string>::const_iterator it = argmap.begin(); it != argmap.end(); ++it)
    {
        Local_var var(it->second, true, 0);
        //is called directly
        Argument_context.insert_var_local(make_pair(it->first, var));
        
        if(it->second == "INT"){
                offset = 4 * u + index;
                Argument_context.assign_offset_to_local_var(it->first, std::to_string(offset));
        }

    }
}

bool Function::is_Function() const{
    return true;
}

// pretty print


