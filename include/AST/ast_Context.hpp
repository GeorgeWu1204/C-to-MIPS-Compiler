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
#include "AST/ast_makeName.hpp"

class Global_var
{
public:
    std::string offset;
    std::string type_name;
    int global_size;
    int enum_val;
    Global_var(std::string var1)
    {
        // when it is a variable function
        type_name = var1;
        global_size = 1;
        enum_val = 0;
    }
    Global_var(std::string var1, int var2)
    {
        // when it is an array
        type_name = var1;
        global_size = var2;
        enum_val = 0;
    }
    Global_var(int var1)
    {
        // enumerator type
        type_name = "ENUM";
        enum_val = var1;
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
    int enum_val;
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
        enum_val = 0;
    }

    // offset is also undefined because at this stage we dont know the total size
    Local_var(std::string type_specifier, bool input, int index_input)
    {
        offset = "undefined";
        type_name = type_specifier;
        is_called = input;
        index = index_input;
        enum_val = 0;
    }

    void assign_enum_val(int input)
    {
        enum_val = input;
    }
    void assign_offset(std::string input)
    {
        offset = input;
    }
    void assign_type(std::string input)
    {
        type_name = input;
    }
    // void assign_size(int input)
    // {
    //     type_size = input;
    // }

    void is_call()
    {
        is_called = true;
    }
};

class type_storage
{
    // INT DOUBLE Specific type
private:
    int index;

public:
    int type_size;
    bool is_struct;
    int offset;
    std::map<std::string, type_storage> struct_content;

    type_storage(std::string input)
    {
        if (input == "INT")
        {
            type_size = 4;
            is_struct = false;
        }
        else if (input == "DOUBLE")
        {
            type_size = 8;
            is_struct = false;
        }
    }
    type_storage()
    {
    }

    void build_struct()
    {
        is_struct = true;
        offset = 0;
        index = 0;
        type_size = 0;
    }

    void add_content(std::string name, type_storage input)
    {
        // inside the struct, we need name -------type--------offset
        // if there is substruct name  ------ substruct
        //
        // std::cerr << " #received" << name << " | " << input.type_size << std::endl;
        is_struct = true;
        //                                        name --- type --- offset the offset should be
        index += 1;
        type_storage tmp = input;
        tmp.offset = type_size;
        if (tmp.is_struct == true)
        {
            tmp.re_arrange_offset(type_size);
        }
        struct_content.insert(std::make_pair(name, tmp));
        type_size += input.type_size;
        // std::cerr << "#final type size" << name << " | " << type_size << std::endl;
    }

    void re_arrange_offset(int input_offset)
    {
        // not sure
        for (std::map<std::string, type_storage>::iterator it = struct_content.begin(); it != struct_content.end(); ++it)
        {
            it->second.offset += input_offset;
        }
    }
    void print_content()
    {
        std::cerr << "#name"
                  << " | "
                  << "typesize"
                  << " | "
                  << "offset" << std::endl;
        for (std::map<std::string, type_storage>::const_iterator it = struct_content.begin(); it != struct_content.end(); ++it)
        {

            std::cerr << it->first << " | " << it->second.type_size << " | " << it->second.offset << std::endl;
        }
        std::cerr << "#end of content" << std::endl;
    }
};

class FloatDoubleConst
{
public:
    std::string type;
    std::string Label_val;
    double value;

    FloatDoubleConst(std::string type_input)
    {
        type = type_input;
    }
    FloatDoubleConst(std::string type_input, double val_input)
    {
        type = type_input;
        value = val_input;
    }

    void assign_label(MakeName &input)
    {
        Label_val = input.makeName("LC");
    }
};

class InnerFDarray
{
public:
    std::string type;
    std::vector<double> vals;
    std::string name;
    InnerFDarray(std::string nameinput, std::string typeinput, std::vector<double> valinput)
    {
        name = nameinput;
        type = typeinput;
        vals = valinput;
    }
};

// return_df_array_list()

class Context
{
protected:
    // global va
    std::map<std::string, Global_var> Globalvar;
    std::map<std::string, Local_var> Localvar;
    // this is used to temporarily store the variable that has not been called.
    // variable name ---- variable type
    // enum color = {BLUE, xxx};
    std::map<std::string, Local_var> Local_Enum;
    std::vector<std::string> LocalVarWaitingForDeclared;
    // type name offset (global or local)
public:
    // for struct sizing
    std::map<double, FloatDoubleConst> Float_const_str;
    // if double vals are the same, goes to the same place as items in map are unique
    std::vector<std::pair<std::string, std::string> > LocalVarWaitingForSizing;
    std::map<std::string, std::string> String_str;
    std::map<std::string, type_storage> Type_Str;
    std::map<std::string, std::string> DFinnerarray_Str;
    std::vector<std::string> Jump_Label;

    std::string Break_Label;
    std::string Continue_Label;
    std::string Function_Ending_Label;
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
    // std::vector<std::string> extract_break_label();
    // inherit all the global variable declared
    void replace_global_var(std::map<std::string, Global_var> _Globalvar);
    // insert content into local_var_waiting map

    void insert_local_var_waiting_for_declared(std::string name);
    std::vector<std::string> read_whole_local_var_type_waiting_for_declared();

    void sync_local_context(Context upperpart, Context initialpart);
    void assign_offset_to_local_var(std::string Name, std::string Offset);
    void assign_type_to_local_var(std::string Name, std::string type);
    void local_var_called(std::string input);
    void replace_break_label(std::string input);
    void replace_continue_label(std::string input);
    // void replace_function_ending_label(std::string input);
    std::string get_break_label();
    std::string get_continue_label();
    // std::string get_function_ending_label();
    void insert_Jump_Label(std::string j_label);
    std::string extract_Jump_Label(int index);

    void assign_label_float_const_str(MakeName &input);
    void print_global();
    void print_local();
    void print_context();
};

#endif
