// the aim of the context is used to stored
// 1. Stack frame, which is the function defined. every function is a stack frame.
// 2. Variable declared locally and globally.
// 3. Functions, coz we have the situation where the funciton is called inside the frame.

#ifndef ast_Context_hpp
#define ast_Context_hpp
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <math.h>
#include <unordered_map>

class Global_var
{
public:
    std::string offset;
    std::string type_name;
    int global_size;
    Global_var(std::string var1)
    {
        // when it is a variable
        type_name = var1;
        global_size = 1;
    }
    Global_var(std::string var1, int var2)
    {
        // when it is an array
        type_name = var1;
        global_size = var2;
    }
};

class Local_var
{
public:
    std::string offset;
    std::string type_name;
    bool is_called;
    bool is_inside_function;
    int index;

    // if a variable is only declarated without initialization
    // create variable in context ( to indicate this variable is indeeded declarated )
    // with offset undefined since it is not used yet;
    // is_call indicated whether it is used or not;
    Local_var(std::string type_specifier, int index_input)
    {
        offset = "undefined";
        type_name = type_specifier;
        is_called = false;
        index = index_input;
    }

    // offset is also undefined because at this stage we dont know the total size
    Local_var(std::string type_specifier, bool input, int index_input)
    {
        offset = "undefined";
        type_name = type_specifier;
        is_called = input;
        index = index_input;
    }

    void assign_offset(std::string input)
    {
        offset = input;
    }
    void assign_type(std::string input)
    {
        type_name = input;
    }

    void is_call()
    {
        is_called = true;
    }
};

class Context
{
protected:
    // global va
    std::map<std::string, Global_var> Globalvar;
    std::map<std::string, Local_var> Localvar;
    // this is used to temporarily store the variable that has not been called.
    // variable name ---- variable type

    std::vector<std::string> LocalVarWaitingForDeclared;
    // type name offset (global or local)
public:
    bool is_Local(std::string i);
    bool is_Global(std::string i);
    Global_var find_global(std::string i);
    Local_var find_local(std::string i);
    int find_local_sub_context_offset();

    void insert_var_global(std::pair<std::string, Global_var> i);
    //
    void insert_var_local(std::pair<std::string, Local_var> i);
    void replace_var_local(std::map<std::string, Local_var> i);
    // append variable in upper context to the context passed to the lower level;
    // will be use in generate Mips stage

    std::map<std::string, Global_var> extract_global_var();
    std::map<std::string, Local_var> extract_local_var();
    // inherit all the global variable declared
    void replace_global_var(std::map<std::string, Global_var> _Globalvar);
    // insert content into local_var_waiting map

    void insert_local_var_waiting_for_declared(std::string name);
    std::vector<std::string> read_whole_local_var_type_waiting_for_declared();
    void sync_local_context(Context upperpart, Context initialpart);
    void assign_offset_to_local_var(std::string Name, std::string Offset);
    void assign_type_to_local_var(std::string Name, std::string type);
    void local_var_called(std::string input);
    // void generate_global_var_Mips(std::string var_name, int index);
    // find the size taken for the variable inside
    //  void find_block_size_global(std::string input);
    //  void find_block_size_local();
    // print
    void print_global();
    void print_local();
    void print_context();
};

#endif
