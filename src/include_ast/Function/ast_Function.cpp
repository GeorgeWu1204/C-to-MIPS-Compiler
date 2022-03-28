#include "AST/Function/ast_Function.hpp"

Function::Function(NodePtr headinput, NodePtr bodyinput)
{
    branch.push_back(headinput);
    branch.push_back(bodyinput);
}

void Function::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{

    int function_stack_size = 0;
    int struct_upper_level_size = 0;
    // note the inner function stack size only depends on the body part.
    Local_var var("SUBCONTEXT", 1);
    context.insert_var_local(std::make_pair("TOPcontext", var));
    // std::cout << "find struct " << context.Type_Str.find("STRUCTx")->second.type_size << std::endl;
    std::vector<std::pair<std::string, std::string> > wait_for_struct_size = branch[1]->read_Local_Var_Waiting_For_Sizing();
    // read_Local_Var_Waiting_For_Sizing
    // std::cout << "{{{" << wait_for_struct_size.size() << std::endl;
    for (int i = 0; i < wait_for_struct_size.size(); i++)
    {
        // std::cout << "{{{{{" << wait_for_struct_size[i].first << " | " << wait_for_struct_size[i].second << std::endl;
        if (context.Type_Str.find(wait_for_struct_size[i].first) != context.Type_Str.end())
        {
            // find in context
            // std::cout << "<<<test" << context.Type_Str.find(wait_for_struct_size[i].first)->second.type_size << std::endl;
            struct_upper_level_size += context.Type_Str.find(wait_for_struct_size[i].first)->second.type_size;
        }
    }

    if (branch[1]->get_context_local_size() == 0 && wait_for_struct_size.size() == 0)
    {
        function_stack_size = 8;
    }
    else
    {
        // std::cout << "hihihi" << std::endl;
        //  std::cerr << "#" << "func_size_check" << function_stack_size<<std::endl;
        function_stack_size = 16 + branch[1]->get_context_local_size() + struct_upper_level_size;
    }
    function_stack_size = ceil(function_stack_size / 8) * 8;

    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    // dst<<"addiu " << "$31, " << "$31" << "-" <<sizeoffunction(global_var)<< std::endl;
    dst << "addiu "
        << "$29,"
        << "$29,-" << function_stack_size << std::endl;
    if (branch[1]->is_Function_inside())
    {
        // dst << "//there is a function inside" << std::endl;
        dst << "sw "
            << "$31," << function_stack_size - 4 << "("
            << "$29"
            << ")" << std::endl;
        dst << "sw "
            << "$30," << function_stack_size - 8 << "("
            << "$29"
            << ")" << std::endl;
        context.assign_offset_to_local_var("TOPcontext", std::to_string(function_stack_size - 12));
    }
    else
    {
        dst << "sw "
            << "$30," << function_stack_size - 4 << "("
            << "$29"
            << ")" << std::endl;
        context.assign_offset_to_local_var("TOPcontext", std::to_string(function_stack_size - 8));
    }
    dst << "move "
        << "$30,"
        << "$29" << std::endl;
    // Argument Load
    // dst << "what" << branch[0]->get_argument_size() << std::endl;
    if (branch[0]->get_argument_size() != 0)
    {
        dst << "#inside argument load" << std::endl;
        add_argument_to_context(function_stack_size);
        // double is different here.
        if (branch[0]->get_argument_size() <= 16)
        {
            // dst << "#condition 1" << std::endl;
            int trace_fd_num = 0;
            int trace_int_num = 0;
            int cur_arg_offset = 0;
            int sup_float_reg = 0;
            std::vector<std::pair<std::string, std::string> > argmap = branch[0]->get_argument_map();
            // if less than 16, we need to store the value inside the register into the stack
            for (int m = 0; m < argmap.size(); m++)
            {
                // std::cout << "inside loopn" << branch[0]->get_argument_map().size() << std::endl;
                // NodePtr tmp = branch[0]->get_branch(m);
                std::string tmp_id = argmap[m].first;
                std::string tmp_type = argmap[m].second;
                // dst << "#Get type function load " << tmp->get_type() << " offset " << Argument_context.find_local(tmp->get_Id()).offset<< std::end;
                // dst << " ID " << branch[0]->get_argument_map()[m].first << std::endl;
                // Argument_context.print_local();
                cur_arg_offset = stoi(Argument_context.find_local(tmp_id).offset);
                if (tmp_type == "DOUBLE" || tmp_type == "DOUBLEPTR")
                {
                    dst << "swc1 "
                        << "$f" << 12 + trace_fd_num << ", " << cur_arg_offset << "($30)" << std::endl;
                    trace_fd_num += 1;
                    dst << "swc1 "
                        << "$f" << 12 + trace_fd_num << ", " << cur_arg_offset - 4 << "($30)" << std::endl;
                    trace_fd_num += 1;
                }
                else if (tmp_type == "FLOAT" || tmp_type == "FLOATPTR")
                {
                    if (trace_fd_num < 4)
                    {
                        // 0  2
                        dst << "swc1 "
                            << "$f" << 12 + trace_fd_num << ", " << cur_arg_offset << "($30)" << std::endl;
                        trace_fd_num += 2;
                        trace_int_num += 1;
                    }
                    else
                    {
                        dst << "sw "
                            << "$" << 4 + trace_int_num << "," << cur_arg_offset << "($30)" << std::endl;
                        trace_int_num += 1;
                    }
                }
                else if (tmp_type == "CHAR"){
                    dst << "move $2," << "$" << trace_int_num + 4 <<std::endl;
                    dst << "sb $2," << cur_arg_offset << "($30)" << std::endl;
                    trace_int_num += 1;
                }

                else
                {
                    // INT INTPTR CHARPTR
                    dst << "sw"
                        << " $" << trace_int_num + 4 << "," << cur_arg_offset << "($30)" << std::endl;
                    trace_int_num += 1;
                }
            }
        }
        else
        {
            // when the num of arguments exceeds 5 arguments.
            int valid_index = 0;
            int trace_fd_num = 0;
            int trace_int_reg = 0;
            int cur_arg_offset = 0;
            int sup_float_reg = 0;
            while (true)
            {
                NodePtr tmp = branch[0]->get_branch(valid_index);
                cur_arg_offset = stoi(Argument_context.find_local(tmp->get_Id()).offset) - function_stack_size;
                if (cur_arg_offset > 16)
                {
                    break;
                }
                else
                {
                    if (tmp->get_type() == "DOUBLE" || tmp->get_type() == "DOUBLEPTR")
                    {
                        dst << "swc1 "
                            << "$f" << 12 + trace_fd_num << ", " << cur_arg_offset << "($30)" << std::endl;
                        trace_fd_num += 1;
                        dst << "swc1 "
                            << "$f" << 12 + trace_fd_num << ", " << cur_arg_offset - 4 << "($30)" << std::endl;
                        trace_fd_num += 1;
                    }
                    else if (tmp->get_type() == "FLOAT" || tmp->get_type() == "FLOATPTR")
                    {
                        if (trace_fd_num < 4)
                        {
                            // 0  2
                            dst << "swc1 "
                                << "$f" << 12 + trace_fd_num << ", " << cur_arg_offset << "($30)" << std::endl;
                            trace_fd_num += 2;
                        }
                        else
                        {
                            dst << "sw "
                                << "$" << 6 + sup_float_reg << "," << cur_arg_offset << "($30)" << std::endl;
                            sup_float_reg += 1;
                        }
                    }
                    else
                    {
                        dst << "sw"
                            << " $" << trace_int_reg + 4
                            << "," << cur_arg_offset << "($30)" << std::endl;
                        trace_int_reg += 1;
                    }
                }
                valid_index += 1;
            }
        }
        // store in memory and can be retrieved directly.
    }

    // body part
    // argument context;
    // std::cerr << "#" << "argumentcontext" << std::endl;
    // Argument_context.print_local();
    // std::cout << "find struct " << context.Type_Str.find("STRUCTx")->second.type_size << std::endl;
    Func_context.sync_local_context(context, Argument_context);
    // std::cout << "find struct 2" << Func_context.Type_Str.find("STRUCTx")->second.type_size << std::endl;
    std::string Function_Ending_label = make_name.makeName("L");
    Func_context.Function_Ending_Label = Function_Ending_label;
    //  std::cerr<< "#" << "done 81" << std::endl;
    //  Func_context.print_local();
    //  synch local context of the context with the or used argument_context directly as context here is empty;
    branch[1]->generateMips(dst, Func_context, destReg, make_name, dynamic_offset);
    // std::cerr << "#" << "done 85" << std::endl;
    dst << Func_context.Function_Ending_Label << ":" << std::endl;

    dst << "nop" << std::endl;

    dst << "move "
        << "$29,"
        << "$30" << std::endl;
    if (branch[1]->is_Function_inside())
    {
        // dst << "//end with function inside" << std::endl;
        dst << "lw "
            << "$31," << function_stack_size - 4 << "("
            << "$29"
            << ")" << std::endl;
        dst << "lw "
            << "$30," << function_stack_size - 8 << "("
            << "$29"
            << ")" << std::endl;
    }
    else
    {
        dst << "lw "
            << "$30," << function_stack_size - 4 << "("
            << "$29"
            << ")" << std::endl;
    }
    dst << "addiu "
        << "$29,"
        << "$29,"
        << function_stack_size << std::endl;
    dst << "jr "
        << "$31" << std::endl;
    dst << "nop" << std::endl;
    dst << ".end  " << branch[0]->get_Id() << std::endl;

    // if define function inside a function?
}

void Function::add_argument_to_context(int index)
{
    int u = 0;
    int offset = index;
    int tot_size = 0;
    // represent offset index in the map
    std::vector<std::pair<std::string, std::string> > argmap = branch[0]->get_argument_map();

    for (int i = 0; i < argmap.size(); i++)
    {
        Local_var var(argmap[i].second, true, 0);
        // is called directly
        Argument_context.insert_var_local(make_pair(argmap[i].first, var));
        // std::cout << "-------" << i << argmap[i].second << std::endl;
        // Need to consider double double int | double int double

        if (argmap[i].second == "INT" || argmap[i].second == "INTPTR")
        {
            tot_size += 4;
            Argument_context.assign_offset_to_local_var(argmap[i].first, std::to_string(offset));
            offset += 4;
        }
        else if (argmap[i].second == "DOUBLE" || argmap[i].second == "DOUBLEPTR")
        {
            Argument_context.assign_offset_to_local_var(argmap[i].first, std::to_string(offset));
            if (tot_size % 8 != 0)
            { // when int double
                offset += 12;
            }
            else
            {
                offset += 8;
            }
        }
        else if (argmap[i].second == "FLOAT" || argmap[i].second == "FLOATPTR")
        {
            Argument_context.assign_offset_to_local_var(argmap[i].first, std::to_string(offset));
            tot_size += 4;
            offset += 4;
        }
        else if (argmap[i].second == "CHAR" || argmap[i].second == "CHARPTR")
        {
            Argument_context.assign_offset_to_local_var(argmap[i].first, std::to_string(offset));
            tot_size += 4;
            offset += 4;
        }
    }
}

bool Function::is_Function() const
{
    return true;
}

std::string Function::get_Id() const
{
    return branch[0]->get_Id();
}
std::string Function::get_type() const
{
    return branch[0]->get_type();
}
bool Function::is_Function_Def() const
{
    return true;
}

std::vector<FloatDoubleConst> Function::get_Float_Const()
{
    return branch[1]->get_Float_Const();
}
std::vector<std::string> Function::get_String_Const()
{
    return branch[1]->get_String_Const();
}
