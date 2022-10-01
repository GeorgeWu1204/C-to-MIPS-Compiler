#include "AST/ast_Context.hpp"

bool Context::is_Local(std::string i)
{
    if (Localvar.find(i) != Localvar.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Context::is_Global(std::string i)
{
    if (Globalvar.find(i) != Globalvar.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

Global_var Context::find_global(std::string i)
{
    return Globalvar.find(i)->second;
}

Local_var Context::find_local(std::string i)
{
    return Localvar.find(i)->second;
}

void Context::insert_var_global(std::pair<std::string, Global_var> i)
{
    Globalvar.insert(i);
}

void Context::insert_var_local(std::pair<std::string, Local_var> i)
{
    Localvar.insert(i);
}

void Context::replace_var_local(std::map<std::string, Local_var> i)
{
    Localvar = i;
}

int Context::find_local_sub_context_offset()
{
    for (std::map<std::string, Local_var>::iterator it = Localvar.begin(); it != Localvar.end(); ++it)
    {
        if (it->second.type_name == "SUBCONTEXT" && it->second.is_called == false)
        {
            it->second.is_call();
            return stoi(it->second.offset);
        }
    }
    return 8;
}

// void Context::insert_func(Function i)
// {
//     sfc.push_back(i);
// }

void Context::replace_global_var(std::map<std::string, Global_var> input)
{
    Globalvar = input;
}

std::map<std::string, Local_var> Context::extract_local_var()
{
    return Localvar;
}

std::map<std::string, Global_var> Context::extract_global_var()
{
    return Globalvar;
}

void Context::insert_local_var_waiting_for_declared(std::string name)
{
    LocalVarWaitingForDeclared.push_back(name);
}

std::vector<std::string> Context::read_whole_local_var_type_waiting_for_declared()
{

    return LocalVarWaitingForDeclared;
}

void Context::sync_local_context(Context upperpart, Context initialpart)
{
    Localvar = initialpart.extract_local_var();
    int original_size = Localvar.size();
    //std::cout << "inside sync" << std::endl;
    std::vector<std::string> ordered_stack(upperpart.extract_local_var().size());
    std::map<std::string, Local_var> UPPER = upperpart.extract_local_var();

    for (std::map<std::string, Local_var>::const_iterator it = UPPER.begin(); it != UPPER.end(); ++it)
    {
        ordered_stack[it->second.index] = it->first;
    }
    //std::cout << "stage 1 passed" << std::endl;
    print_local();
    //std::cout << "<---------->" << std::endl;
    //std::cout << ordered_stack.size() << std::endl;

    for (int i = 0; i < ordered_stack.size(); i++)
    {
        //std::cout << ordered_stack[i] << std::endl;
        if ( upperpart.find_local(ordered_stack[i]).type_name == "SUBCONTEXT" )
        {
            if (upperpart.find_local(ordered_stack[i]).is_called == false)
            {
                break;
            }
            
        }
        else
            {
                if(Localvar.count(ordered_stack[i])== 0){
                Local_var var(upperpart.find_local(ordered_stack[i]).type_name, true ,original_size + i );
                var.offset = upperpart.find_local(ordered_stack[i]).offset;
                Localvar.insert(make_pair(ordered_stack[i], var));
                }
            }
    }
    //std::cout << "stage 2 passed" << std::endl;
    Globalvar = upperpart.extract_global_var();
}


void Context::assign_offset_to_local_var(std::string Name, std::string Offset)
{
    Localvar.at(Name).assign_offset(Offset);
}

void Context::local_var_called(std::string input)
{
    Localvar.find(input)->second.is_call();
}

// this function is used to generate global Mips function
// void Context::generate_global_var_Mips(std::string var_name, int index)
// {
    


// }

//print part for testing

void Context::print_local()
{
    std::cout << "inside Local Var: " << std::endl;
    for (std::map<std::string, Local_var>::const_iterator it = Localvar.begin(); it != Localvar.end(); ++it)
    {
        std::cout << it->first << ": " << it->second.type_name << " | " << it->second.offset << " | " << it->second.index<< " | " << it->second.is_called << std::endl;
    }

    std::cout << "inside Local Var Waiting for Declared" << std::endl;
    for (int i = 0; i < LocalVarWaitingForDeclared.size(); i++)
    {
        std::cout << LocalVarWaitingForDeclared[i] << std::endl;
    }
}

void Context::print_global(){

    std::cout << "inside Global Var: " << std::endl;
    
    for (std::map<std::string, Global_var>::const_iterator it = Globalvar.begin(); it != Globalvar.end(); ++it)
    {
        std::cout << it->first << ": " << it->second.type_name << " | " << it->second.global_size << std::endl;
    }

}




