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
        return true;
    }
    else
    {
        return false;
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
   // std::cout << "Upper" << std::endl;
    //upperpart.print_local();
    //std::cout << "initialpart" << std::endl;
    //initialpart.print_local();
    Localvar = initialpart.extract_local_var();
    int original_size = Localvar.size();
    int count_argument = 0;
    int is_called_subcontext_size = 0;
    // this is used to count the number of called_subcontext covered in the context.
    // std::cout << "inside sync" << std::endl;
    std::vector<std::string> ordered_stack(upperpart.extract_local_var().size());
    std::map<std::string, Local_var> UPPER = upperpart.extract_local_var();
    //place all the content inside the upperpart into vector ordered by index.
    for (std::map<std::string, Local_var>::const_iterator it = UPPER.begin(); it != UPPER.end(); ++it)
    {
        //[0 0 1 2 3 4]
        if (it->second.index == 0)
        {
            ordered_stack[count_argument] = "undefined";
            // note the index for arguments is always zero;
            //need to count all the zero before starting to insert into the vector.
            count_argument += 1;
            Localvar.insert(std::make_pair(it->first, it->second));
        }
    }
    for (std::map<std::string, Local_var>::const_iterator it = UPPER.begin(); it != UPPER.end(); ++it)
    {
        if (it->second.index != 0)
        {
            ordered_stack[it->second.index + count_argument - 1] = it->first;
        }
    }
     //std::cout << "stage 1 passed" << std::endl;
    // print_local();
    // std::cout << "<---------->" << std::endl;
    // std::cout << ordered_stack.size() << std::endl;

    for (int i = count_argument; i < ordered_stack.size(); i++)
    {
        //std::cout <<"oderstack content " << i << " | " <<ordered_stack[i] << std::endl;
        if (upperpart.find_local(ordered_stack[i]).type_name == "SUBCONTEXT")
        {
            if (upperpart.find_local(ordered_stack[i]).is_called == false)
            {
                break;
            }
            // else{
            //     // when the subcontext is already called.
            //     is_called_subcontext_size += 1;
            //do n() cothing here
            // }
        }
        else
        {
            //[undef; x; y; SUBCONTEXT; Dynamic] i = 3 index = 2
            //<x, y
            if (Localvar.count(ordered_stack[i]) == 0)
            {
                //std::cout << "matched : " << ordered_stack[i] << std::endl;
                //if cannot find same val
                Local_var var(upperpart.find_local(ordered_stack[i]).type_name, true, original_size + i - count_argument + 1);
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
void Context::assign_type_to_local_var(std::string Name, std::string type)
{
    Localvar.at(Name).assign_type(type);
}

void Context::local_var_called(std::string input)
{
    Localvar.find(input)->second.is_call();
}

// this function is used to generate global Mips function
// void Context::generate_global_var_Mips(std::string var_name, int index)
// {

// }

// print part for testing

void Context::print_context()
{
    print_local();
    print_global();
}
void Context::print_local()
{
    std::cout <<  std::endl;
    std::cout << "inside Local Var: Name : Type | Offset | Index | Is_called" << std::endl;
    for (std::map<std::string, Local_var>::const_iterator it = Localvar.begin(); it != Localvar.end(); ++it)
    {
        std::cout << it->first << ": " << it->second.type_name << " | " << it->second.offset << " | " << it->second.index << " | " << it->second.is_called << std::endl;
    }

    std::cout << "inside Local Var Waiting for Declared" << std::endl;
    for (int i = 0; i < LocalVarWaitingForDeclared.size(); i++)
    {
        std::cout << LocalVarWaitingForDeclared[i] << std::endl;
    }
    std::cout <<  std::endl;
}

void Context::print_global()
{
    std::cout <<  std::endl;
    std::cout << "inside Global Var: " << std::endl;

    for (std::map<std::string, Global_var>::const_iterator it = Globalvar.begin(); it != Globalvar.end(); ++it)
    {
        std::cout << it->first << ": " << it->second.type_name << " | " << it->second.global_size << std::endl;
    }
    std::cout <<  std::endl;
}
