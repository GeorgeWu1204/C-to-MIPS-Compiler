
// #include "include/ast.hpp"
#include "AST/ast_Compound_statement_MIPS.hpp"

Compound_statement_Mips::Compound_statement_Mips(const std::vector<NodePtr> Declaration_List)
    : Node(Declaration_List)
{

    build_func_context();

    size = find_stack_size();
}
Compound_statement_Mips::Compound_statement_Mips(const std::vector<NodePtr> Declaration_List, const std::vector<NodePtr> Statement_List)
    : Node(Declaration_List, Statement_List)
{
    build_func_context();
    size = find_stack_size();
}

Compound_statement_Mips::Compound_statement_Mips()
    : Node()
{
    // do nothing here
    size = 0;
    build_func_context();
}

void Compound_statement_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::cerr << "#"
              << "inside compound_statement" << std::endl;
    // InitialBuildContext.print_local();

    // passing the offset from larger context to this subcontext;
    Assign_offset(context.find_local_sub_context_offset(), context);
    std::cerr << "#"
              << "stage 1" << std::endl;

    // std::cerr << "#" << "order variable" << ordered_variable_table.size() << std::endl;
    // std::cerr << "#" << dynamic_context_size << std::endl;
    // std::cerr << "#"
    //           << "<----------------Compound context----------------->" << std::endl;
    // InitialBuildContext.print_local();
    // std::cerr<< "#" << "<----------------ini----------------->" << std::endl;
    // InitialBuildContext.print_context();
    //  Local_var var = InitialBuildContext.find_local("$DynamicContext");
    //  dynamic_offset = stoi(InitialBuildContext.find_local("$DynamicContext").offset);
    // std::cerr << "# Initial Dynamic Offset " << dynamic_offset << std::endl;
    // std::cerr << "#"
    //           << "stage 2" << dynamic_offset << std::endl;

    SubContext.sync_local_context(context, InitialBuildContext);

    // std::cerr << "#"
    //           << "stage 10"  << std::endl;
    Local_var var = SubContext.find_local("$DynamicContext");
    // std::cerr << "#" << "G" << std::endl;

    dynamic_offset = stoi(SubContext.find_local("$DynamicContext").offset);
    // std::cerr << "# After Syn Dynamic Offset " << dynamic_offset << std::endl;
    // std::cerr << "#"<< "<---Combined Context--->" << std::endl;
    // SubContext.print_local();
    // SubContext.print_global();
    //  SubContext.print_local();
    return_label_declared = false;
    int case_index = 0;
    for (int i = 0; i < branch.size(); i++)
    {
        std::cerr << "# LOOP" << std::endl;
        if (branch[i]->is_Case())
        {
            std::cerr << "# is case" << std::endl;
            std::string J_Lable = SubContext.extract_Jump_Label(case_index);
            std::cerr << "# found jump label" << std::endl;
            case_index += 1;
            dst << J_Lable << ": " << std::endl;
            branch[i]->generateMips(dst, SubContext, 2, make_name, dynamic_offset);
        }
        else if (branch[i]->is_Default())
        {
            std::cerr << "# is default" << std::endl;
            std::string J_Lable = SubContext.extract_Jump_Label(case_index); // sos
            case_index += 1;
            dst << J_Lable << ": " << std::endl;
            branch[i]->generateMips(dst, SubContext, 2, make_name, dynamic_offset);
        }
        else if (branch[i]->is_Break())
        {
            std::cerr << "#in break --------" << std::endl;
            dst << "b " << SubContext.get_break_label() << std::endl;
        }
        else if (branch[i]->is_Continue())
        {
            std::cerr << "#in continue --------" << std::endl;
            dst << "b " << SubContext.get_continue_label() << std::endl;
        }
        else
        {
            branch[i]->generateMips(dst, SubContext, 2, make_name, dynamic_offset);
        }
        SubContext.assign_type_to_local_var("$DynamicContext", "NotDefined");
        dynamic_offset = stoi(SubContext.find_local("$DynamicContext").offset);
    }
    // now generate mips inside case after going through all the case
    if (jump_label.size() != 0)
    {
        for (int h = 1; h < jump_label.size(); h++)
        {
            dst << std::endl;
            dst << jump_label[h] << ":" << std::endl;
            branch[index_of_case_branch[h - 1]]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        }
        // escape part
        dst << std::endl;
        dst << jump_label[0] << ": " << std::endl;
    }
}
// void prettyPrint(std::ostream &dst) const override;
//  void build_local_context(){};
//  void get_Local_var(Context &context);

bool Compound_statement_Mips::is_Function_inside() const
{
    return function_inside;
}

int Compound_statement_Mips::find_stack_size()
{
    double count_size = 0;
    // int func_size = 0;
    //  SOS
    int i = 0; // index for subcontext
    int array_index = 0;
    std::map<std::string, Local_var> func_context = InitialBuildContext.extract_local_var();
    std::cerr << "#"
              << "func_context" << std::endl;
    // InitialBuildContext.print_local();

    for (std::map<std::string, Local_var>::const_iterator it = func_context.begin(); it != func_context.end(); ++it)
    {
        // if (it->second.is_called == true)
        // {
        if (it->first == "$DynamicContext")
        { // possible error not back to undefined
            count_size += dynamic_context_size;
        }
        else
        {
            if (it->second.type_name == "INT" || it->second.type_name == "INTPTR")
            {
                count_size += 4;
            }

            else if (it->second.type_name == "DOUBLE" || it->second.type_name == "DOUBLEPTR")
            {
                count_size += 8;
            }

            else if (it->second.type_name == "FLOAT" || it->second.type_name == "FLOATPTR")
            {
                count_size += 4;
            }

            else if (it->second.type_name == "CHAR" || it->second.type_name == "CHARPTR")
            {
                count_size += 4;
            }

            else if (it->second.type_name == "FunctionCal")
            {
                count_size += inside_function_size;
            }
            else if (it->second.type_name == "INTArray" || it->second.type_name == "DOUBLEArray" || it->second.type_name == "FLOATArray")
            {
                // std::cerr << "#"
                //           << "inside arraysize" << arraysize[array_index] << std::endl;
                count_size += arraysize[array_index];
                array_index += 1;
            }
            //}

            else if (it->second.type_name == "SUBCONTEXT")
            {
                std::cerr << "#"
                          << "sub context size" << subcontextsize[i] << std::endl;
                count_size += subcontextsize[i];
                // std::cerr << "#" << "<------->" << std::endl;
                // std::cerr << "#" << subcontextsize[i] << std::endl;
                i += 1;
            }
            else
            {
                // struct
                // std::cerr << "# in struct declaration" << std::endl;
                if (InitialBuildContext.Type_Str.find(it->second.type_name) != InitialBuildContext.Type_Str.end())
                {
                    // when struct is defined within the scope
                    count_size += InitialBuildContext.Type_Str.find(it->second.type_name)->second.type_size;
                }
            }
        }
    }

    // func_size = ceil(count_size / 8) * 8;
    return count_size;
}

int Compound_statement_Mips::get_size() const
{
    // return the number of branch inside
    return branch.size();
}

void Compound_statement_Mips::build_func_context()
{

    // int x = f;
    function_inside = false;
    // std::cerr << "#" << "this compound has branch size of " << branch.size() << std::endl;
    int stack_index = 1;
    // this variable is  used to trace the current index inside the map;
    // index 0 is used to store arguments
    dynamic_context_size = 0;

    int tmp_func_size = 0;
    int tmp_dynamic_size = 0;
    std::string Pointer_type;

    inside_function_size = 0;

    // std::cerr << "#" << "{-----" << "inside build_func" << "-----}" << std::endl;
    for (int g = 0; g < branch.size(); g++)
    {
        // std::cerr << "#" << "<------" << "function_inside  " << function_inside << "----->" <<std::endl;
        if (branch[g]->is_Declaration()) // branch[0] declarator branch[1] declaration list
        {
            // InitialBuildContext is what the context is
            // start from 1 due to type specifier + list
            // int f(), x =4, u, p[8];
            // ENU
            std::cerr << "#"
                      << "stage "
                      << std::endl;

            if (branch[g]->is_Enum()) // enum color {}      [b] r ....
            {
                // initi..
                std::cerr << "#"
                          << "stage 2"
                          << "  |  " << g << "  |  " << std::endl;
                std::map<std::string, int> tmp_enum_list = branch[g]->get_branch(0)->get_enumerator_list();

                if (tmp_enum_list.size() != 0)
                {

                    // enum {A B C D} i store i
                    for (std::map<std::string, int>::iterator it = tmp_enum_list.begin(); it != tmp_enum_list.end(); ++it)
                    {
                        // std::cerr << "map---" << std::endl;
                        // std::cerr << it->first << "|" << it->second << std::endl;
                        Local_var var("ENUM", true, stack_index);
                        var.assign_enum_val(it->second);
                        InitialBuildContext.insert_var_local(std::make_pair(it->first, var));
                        stack_index += 1;
                    }
                }
                // If it is not wih initialization get_size return 0;
                for (int d = 1; d < branch[g]->get_size(); d++)
                {
                    NodePtr declaration_list_element = branch[g]->get_branch(d);
                    Local_var var("INT", true, stack_index);
                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var));
                    stack_index += 1;
                }
            }
            else if (branch[g]->is_Struct())
            {
                // Struct DEFINE { }
                InitialBuildContext.Type_Str.insert(std::make_pair(branch[g]->get_type(), branch[g]->get_type_storage()));
                // std::cerr << "testing" << std::endl;
                // branch[g]->get_type_storage().print_content();
                //  struct x {}
            }
            else if (branch[g]->is_Struct_Declaration())
            {

                // struct x y; structx
                // std::cerr << "# is_struct declaration" << std::endl;
                // branch[g]
                if (InitialBuildContext.Type_Str.find(branch[g]->get_type()) == InitialBuildContext.Type_Str.end())
                {
                    // changes
                    // std::cerr << "# inside localvarwaitingforsizing" << std::endl;
                    std::pair<std::string, std::string> a = std::make_pair(branch[g]->get_type(), branch[g]->get_Id());
                    InitialBuildContext.LocalVarWaitingForSizing.push_back(a);
                }
                Local_var var(branch[g]->get_type(), true, stack_index);
                InitialBuildContext.insert_var_local(std::make_pair(branch[g]->get_Id(), var));
                stack_index += 1;
                // true or not true
            }
            else
            {
                // standard declaration int/double xxxxxxx;
                std::string declaration_type = branch[g]->get_type();
                for (int d = 1; d < branch[g]->get_size(); d++)
                {
                    NodePtr declaration_list_element = branch[g]->get_branch(d);
                    if (declaration_list_element->is_Function())
                    {
                        Local_var var("FunctionDec", true, stack_index);
                        // function declaration,
                        function_inside = true;
                        // function does not need to be stored in ordered_varaible table
                        InitialBuildContext.insert_var_local(std::make_pair(branch[g]->get_Id(), var));
                        stack_index += 1;
                    }
                    else
                    {
                        // not a function
                        //  could be either with ini or not ( i.e x = 10, x[8] = {1,2,3,4} // x,u,o  )
                        if (declaration_list_element->is_init())
                        {
                            std::cerr << "#"
                                      << "<----------------is init declaration----------------->" << std::endl;
                            //  with init
                            // std::cerr << "# Declaration with initizalized" << std::endl;
                            if (declaration_type == "INT")
                            {
                                if (declaration_list_element->is_Identifier())
                                {
                                    std::cerr << "#"
                                              << "<----------------is identifier init declaration----------------->" << std::endl;
                                    std::vector<FloatDoubleConst> a = branch[g]->get_Float_Const();
                                    std::vector<std::string> b = declaration_list_element->get_String_Const();
                                    for (int i = 0; i < a.size(); i++)
                                    {
                                        Float_Const_of_this_compound.push_back(a[i]);
                                    }
                                    for (int i = 0; i < b.size(); i++)
                                    {
                                        String_Const_of_this_compound.push_back(b[i]);
                                    }
                                    // std::cerr<< "#" << "<----------------is identifier init declaration----------------->" << std::endl;
                                    // std::cerr << "# Variable Declaration with initizalized" << std::endl;
                                    Local_var var(declaration_type, true, stack_index); //? not always the case
                                    // ordered_variable_table.push_back(branch[g]->get_Id());
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? make pair
                                    stack_index += 1;
                                }
                                else if (declaration_list_element->is_Array())
                                {
                                    // x[5] = {1, 3, 5, 22, 69};

                                    // sos   sos sos sos string vector how
                                    std::cerr << "#"
                                              << "<----------------is array init declaration----------------->" << std::endl;
                                    // sos
                                    // std::cerr << "ARRAY SIZE" << std::endl;
                                    // std::cerr << "#" << "stage 3" << "  |  " << g << "  |  " << d << declaration_list_element->get_Id() << std::endl;
                                    std::string conc = declaration_type + "Array";
                                    Local_var var(conc, true, stack_index);

                                    // when the array of certain size is declared, it is always called.
                                    // std::cerr << "#" << "arraysize" << declaration_list_element->array_size();
                                    // arraysize.push_back(declaration_list_element->array_size());
                                    arraysize.push_back(declaration_list_element->get_arithmetic_const_val() * 4);

                                    // std::cerr <<"SSS " <<declaration_list_element->get_arithmetic_const_val() << std::endl;                                   //? Node now has array_size() FAIL and array size is a int vector array_size now in the scope not linked
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? get_Id()  two array with in one compound
                                    stack_index += 1;
                                }

                                // Pointer
                                else if (declaration_list_element->is_Pointer())
                                {
                                    std::cerr << "#"
                                              << "<----------------is pointer init declaration----------------->" << std::endl;
                                    std::vector<std::string> b = declaration_list_element->get_String_Const();
                                    for (int i = 0; i < b.size(); i++)
                                    {
                                        String_Const_of_this_compound.push_back(b[i]);
                                    }
                                    // std::cerr << "#ggggggg" << declaration_list_element->get_Id()<< std::endl;
                                    Pointer_type = declaration_type + "PTR";
                                    Local_var var(Pointer_type, true, stack_index); //? not always the case
                                    // ordered_variable_table.push_back(branch[g]->get_Id());
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? make pair
                                    stack_index += 1;
                                }
                            }
                            else if (declaration_type == "FLOAT")
                            {
                                std::vector<FloatDoubleConst> a = declaration_list_element->get_Float_Const();
                                for (int i = 0; i < a.size(); i++)
                                {
                                    std::cerr << "#float vector return " << a[i].value << std::endl;
                                    Float_Const_of_this_compound.push_back(a[i]);
                                }
                                std::cerr << "#float vector done" << std::endl;

                                if (declaration_list_element->get_branch(1)->is_Constant())
                                {
                                    double float_number = declaration_list_element->get_branch(1)->get_Float();
                                    FloatDoubleConst floattype = FloatDoubleConst("FLOAT");
                                    InitialBuildContext.Float_const_str.insert(std::make_pair(float_number, floattype));
                                }
                                else if (declaration_list_element->is_Identifier())
                                {
                                    Local_var var(declaration_type, true, stack_index);                                            //? not always the case
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? make pair
                                    stack_index += 1;
                                }
                                else if (declaration_list_element->is_Array())
                                {
                                    InnerFDarray array_instance(declaration_list_element->get_Id(), "FLOAT", declaration_list_element->construct_double_const_list());
                                    Df_Array_List_of_this_compound.push_back(array_instance);
                                    std::cerr << "#"
                                              << "<----------------is array float declaration----------------->" << std::endl;

                                    std::string conc = declaration_type + "Array";
                                    Local_var var(conc, true, stack_index);

                                    arraysize.push_back(declaration_list_element->get_arithmetic_const_val() * 4);
                                    // std::cerr <<"SSS " <<declaration_list_element->get_arithmetic_const_val() << std::endl;
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var));
                                    stack_index += 1;
                                }
                                else if (declaration_list_element->is_Pointer())
                                {
                                    std::cerr << "#"
                                              << "<----------------is pointer init declaration----------------->" << std::endl;
                                    Pointer_type = declaration_type + "PTR";
                                    Local_var var(Pointer_type, true, stack_index);
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? make pair
                                    stack_index += 1;
                                }
                            }
                            else if (declaration_type == "DOUBLE")
                            {
                                std::vector<FloatDoubleConst> a = declaration_list_element->get_Float_Const();
                                for (int i = 0; i < a.size(); i++)
                                {
                                    Float_Const_of_this_compound.push_back(a[i]);
                                }
                                if (declaration_list_element->get_branch(1)->is_Constant())
                                {
                                    double float_number = declaration_list_element->get_branch(1)->get_Float();
                                    FloatDoubleConst floattype = FloatDoubleConst("DOUBLE");
                                    InitialBuildContext.Float_const_str.insert(std::make_pair(float_number, floattype));
                                }
                                else if (declaration_list_element->is_Identifier())
                                {
                                    // std::cerr<< "#" << "<----------------is identifier init declaration----------------->" << std::endl;
                                    // std::cerr << "# Variable Declaration with initizalized" << std::endl;
                                    Local_var var(declaration_type, true, stack_index); //? not always the case
                                    // ordered_variable_table.push_back(branch[g]->get_Id());
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? make pair
                                    stack_index += 1;
                                }
                                else if (declaration_list_element->is_Array())
                                {
                                    InnerFDarray array_instance(declaration_list_element->get_Id(), "DOUBLE", declaration_list_element->construct_double_const_list());
                                    Df_Array_List_of_this_compound.push_back(array_instance);
                                    std::cerr << "#"
                                              << "<----------------is array init declaration----------------->" << std::endl;
                                    // sos
                                    // std::cerr << "ARRAY SIZE" << std::endl;
                                    // std::cerr << "#" << "stage 3" << "  |  " << g << "  |  " << d << declaration_list_element->get_Id() << std::endl;
                                    std::string conc = declaration_type + "Array";
                                    Local_var var(conc, true, stack_index);

                                    // when the array of certain size is declared, it is always called.
                                    // std::cerr << "#" << "arraysize" << declaration_list_element->array_size();
                                    // arraysize.push_back(declaration_list_element->array_size());
                                    arraysize.push_back(declaration_list_element->get_arithmetic_const_val() * 8);
                                    // std::cerr <<"SSS " <<declaration_list_element->get_arithmetic_const_val() << std::endl;
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var));
                                    stack_index += 1;
                                }
                            }
                            else if (declaration_type == "CHAR")
                            {
                                // char b = 'h';

                                if (declaration_list_element->is_Identifier())
                                {
                                    std::cerr << "#"
                                              << "<----------------is identifier init declaration----------------->" << std::endl;
                                    std::vector<std::string> b = declaration_list_element->get_String_Const();
                                    for (int i = 0; i < b.size(); i++)
                                    {
                                        String_Const_of_this_compound.push_back(b[i]);
                                    }
                                    int acsii_code = declaration_list_element->get_Val();
                                    Local_var var(declaration_type, true, stack_index);
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var));
                                    stack_index += 1;
                                }
                                else if (declaration_list_element->is_Array())
                                {
                                    // sos  sos sos sos string vector how
                                    std::cerr << "#"
                                              << "<----------------is array init declaration----------------->" << std::endl;
                                    // std::cerr << "#" << "stage 3" << "  |  " << g << "  |  " << d << declaration_list_element->get_Id() << std::endl;
                                    std::string conc = declaration_type + "Array";
                                    Local_var var(conc, true, stack_index);
                                    for (int d = 1; d < branch[g]->get_size(); d++)
                                    {
                                        // std::cerr << "Array Declaration With Initialized" << std::endl;
                                        // std::cerr << "array size" << declaration_list_element->array_size() << std::endl;
                                        arraysize.push_back(declaration_list_element->get_arithmetic_const_val());                     //? Node now has array_size() FAIL and array size is a int vector array_size now in the scope not linked
                                        InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? get_Id()  two array with in one compound
                                        stack_index += 1;
                                    }
                                }

                                // Pointer
                                else if (declaration_list_element->is_Pointer())
                                {
                                    std::cerr << "#"
                                              << "<----------------is pointer init declaration----------------->" << std::endl;
                                    std::vector<std::string> b = declaration_list_element->get_String_Const();
                                    for (int i = 0; i < b.size(); i++)
                                    {
                                        String_Const_of_this_compound.push_back(b[i]);
                                    }

                                    Pointer_type = declaration_type + "PTR";
                                    Local_var var(Pointer_type, true, stack_index);

                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? make pair
                                    stack_index += 1;
                                }

                                // char c
                            }
                        }
                        else
                        {
                            // if just declare below
                            if (declaration_list_element->is_Identifier())
                            {
                                // std::cerr << "# pip " << declaration_list_element->get_Id() << std::endl;
                                if (branch[g]->is_Struct_Declaration())
                                {
                                    Local_var var(branch[g]->get_type(), true, stack_index);
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var));
                                    stack_index += 1;
                                }
                                else
                                {
                                    Local_var var(branch[g]->get_type(), stack_index);
                                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var));
                                    // std::cerr << "#" << "Inserted Local Waiting for Call" << declaration_list_element->get_Id() << std::endl;
                                    stack_index += 1;
                                }
                            }
                            else if (declaration_list_element->is_Array())
                            {
                                // int x[8], y[9];
                                // std::cerr << "# Array Declaration without Initialized" << std::endl;
                                std::string conc = declaration_type + "Array";
                                Local_var var(conc, true, stack_index);
                                // when the array of certain size is declared, it is always called.
                                // std::cerr << "#" << "arraysize" << declaration_list_element->array_size();
                                int array_size;
                                std::cerr << "# array constant" << declaration_list_element->get_arithmetic_const_val() << std::endl;
                                if (declaration_type == "INT")
                                {
                                    array_size = declaration_list_element->get_arithmetic_const_val() * 4;
                                }
                                arraysize.push_back(array_size);                                                               //? Node now has array_size() FAIL and array size is a int vector array_size now in the scope not linked
                                InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? get_Id()  two array with in one compound
                                stack_index += 1;
                            }

                            else if (declaration_list_element->is_Pointer())
                            {
                                // int *x;

                                Pointer_type = declaration_type + "PTR";
                                Local_var var(declaration_type, stack_index); //? not always the case
                                // ordered_variable_table.push_back(branch[g]->get_Id());
                                InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? make pair
                                stack_index += 1;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            // statement
            // statement list { y =1; }
            // std::cerr << "# <------------------------------ statment ----------------------> " << std::endl;
            if (branch[g]->is_Function_inside() == true)
            {
                std::cerr << "#"
                          << "stage 5"
                          << "  |  "
                          << "Return function name" << branch[g]->get_Id() << std::endl;
                function_inside = true;
                // need to get type of argument
                // depends on the argument type
                // what if GLOBAL INTO FUNC ARGUMENT SOSOSOSOSOSSO
                tmp_func_size = 0;
                // currently at conditional so we need to go down one layer
                NodePtr Function_call = branch[g]->get_branch(0);
                for (int i = 1; i < Function_call->get_size(); i++)
                {
                    // std::cerr << "endter" << std::endl;
                    //  count the num of arguments
                    NodePtr tmp = Function_call->get_branch(i);
                    // std::cerr << "testnnnnn" << tmp->get_Id() << std::endl;
                    if (InitialBuildContext.is_Local(tmp->get_Id()) == true)
                    {
                        if (InitialBuildContext.find_local(tmp->get_Id()).type_name == "DOUBLE")
                        {
                            tmp_func_size += 8;
                        }
                        else
                        {
                            // FLOAT + INt
                            tmp_func_size += 4;
                        }
                    }
                    else
                    {
                        // std::cerr << "&&& is inside else branch" << std::endl;
                        //  const
                        if (tmp->is_Constant())
                        {
                            if (tmp->get_type() == "INT" || tmp->get_type() == "STRING" || tmp->get_type() == "FLOAT")
                            {
                                tmp_func_size += 4;
                            }
                            else if (tmp->get_type() == "DOUBLE")
                            {
                                tmp_func_size += 8;
                            }
                        }
                        // FLOAT + INt
                        tmp_func_size += 4;
                    }
                    // for float  sos do we need this ? what about for string
                    // std::cerr << "# <--------------------------float_const---------------------------> " << std::endl;
                    std::vector<FloatDoubleConst> a = tmp->get_Float_Const();
                    // std::cerr << "# <-------------------------string_const---------------------------> " << std::endl;
                    std::vector<std::string> b = tmp->get_String_Const();
                    // std::cerr << "# <------------------------------ string_const size: " << b.size() << "----------------------> " << std::endl;
                    for (int i = 0; i < a.size(); i++)
                    {
                        Float_Const_of_this_compound.push_back(a[i]);
                    }
                    for (int i = 0; i < b.size(); i++)
                    {

                        String_Const_of_this_compound.push_back(b[i]);
                    }
                }
                if (tmp_func_size < 16)
                {
                    tmp_func_size = 16;
                }
                // do we need to deal with the size of that function if it is just a call
                if (tmp_func_size > inside_function_size)
                {                                         // ???
                    inside_function_size = tmp_func_size; //
                }
                // function does not need to be stored in ordered_varaible table
            }
            // x = 1;
            // wrong
            // else if (branch[g]->is_Break == true){
            //     // if it is switch or loop detected
            // }
            else if (branch[g]->is_Assignment() == true) //???? if it is not a function call, that go for x = 4? x[2] = 3?
            {
                // x = 1, x = 3, x = x+ y this hasnt implemented yet
                for (int d = 0; d < branch[g]->get_size(); d++)
                {
                    // this is actuallly for x=1;
                    NodePtr assignment_list_element = branch[g]->get_branch(d);

                    // for float
                    std::vector<FloatDoubleConst> a = branch[g]->get_Float_Const();
                    std::vector<std::string> b = branch[g]->get_String_Const();
                    for (int i = 0; i < a.size(); i++)
                    {
                        Float_Const_of_this_compound.push_back(a[i]);
                    }
                    for (int i = 0; i < b.size(); i++)
                    {
                        String_Const_of_this_compound.push_back(b[i]);
                    }
                    // x = 4.0f + 5.0f + y + 9.0f;
                    // need to find x= 4; SOS
                    //  InitialBuildContext.print_local();
                    // std::cerr << "#" << "IN GETID" << branch[g]->get_Id() << std::endl;
                    // std::cerr << "#" << "bracnh 1 lefthandside" << statement_list_element->get_Id() << std::endl;
                    if (branch[g]->is_Constant())
                    {
                        // do nothing here
                        // how do i know whether or not this is a float or not.
                        double float_number = assignment_list_element->get_Float();
                        FloatDoubleConst floattype = FloatDoubleConst("FLOAT");
                        InitialBuildContext.Float_const_str.insert(std::make_pair(float_number, floattype));
                    }
                    else if (InitialBuildContext.extract_local_var().count(assignment_list_element->get_Id()) != 0) // found local variable then set it as called
                    {
                        // after finding the variable in the context.
                        std::cerr << "#"
                                  << "stage 6"
                                  << "  |  " << g << assignment_list_element->get_Id() << std::endl;
                        std::cerr << "#"
                                  << "Found ID in current real context" << branch[g]->get_Id() << std::endl;
                        InitialBuildContext.local_var_called(assignment_list_element->get_Id());
                    }
                    else if (assignment_list_element->is_Pointer())
                    {
                        Pointer_type = assignment_list_element->get_type() + "PTR";
                        Local_var var(Pointer_type, true, stack_index); //? not always the case
                        // ordered_variable_table.push_back(branch[g]->get_Id());
                        InitialBuildContext.local_var_called(assignment_list_element->get_Id()); //? make pair
                    }
                    else // not found marked as wait to declared
                    {
                        std::cerr << "#"
                                  << "stage 7"
                                  << "  |  " << std::endl;
                        std::cerr << "#"
                                  << "Not Found  " << std::endl;
                        InitialBuildContext.insert_local_var_waiting_for_declared(assignment_list_element->get_Id());
                        std::cerr << "#"
                                  << "Done  " << std::endl;
                    }
                }
            }
            // else if (branch[g]->is_Case() == true){

            // }

            // need to consider the statement when the branch size is 1
            else if (branch[g]->is_Jump_statement())
            {
                std::cerr << "# retuning -------------->" << std::endl;
                // for retrun;

                NodePtr conditional = branch[g]->get_branch(0);
                if (conditional->get_type() != "VOID")
                {
                    NodePtr next_branch_0 = conditional->get_branch(0);
                    std::cerr << "# retuning 1 -------------->" << std::endl;
                    // for float and for string
                    std::vector<FloatDoubleConst> a = branch[g]->get_Float_Const();
                    std::cerr << "# retuning 2 -------------->" << std::endl;
                    std::vector<std::string> b = branch[g]->get_String_Const();
                    std::cerr << "# retuning 3 -------------->" << std::endl;
                    for (int i = 0; i < a.size(); i++)
                    {
                        Float_Const_of_this_compound.push_back(a[i]);
                    }
                    std::cerr << "# retuning 4 -------------->" << std::endl;
                    for (int i = 0; i < b.size(); i++)
                    {
                        String_Const_of_this_compound.push_back(b[i]);
                    }
                    //(f1+f2)
                    std::cerr << "# how mang functions inside " << next_branch_0->get_size() << "-------------->" << std::endl;
                    if (next_branch_0->is_Function_inside())
                    {

                        function_inside = true;
                        tmp_func_size = 0;
                        // 1
                        for (int i = 1; i < next_branch_0->get_size(); i++)
                        {
                            // f1 (a, b, c, d)     LOOPING a b c d
                            std::cerr << "# how mang param in function  :" << next_branch_0->get_size() - 1 << "-------------->" << std::endl;
                            NodePtr tmp = next_branch_0->get_branch(i);

                            // std::cerr << tmp->get_cloest_Id() << "   |    " << tmp->get_Id() << std::endl;
                            if (InitialBuildContext.is_Local(tmp->get_cloest_Id()))
                            {
                                if (InitialBuildContext.find_local(tmp->get_cloest_Id()).type_name == "DOUBLE")
                                {
                                    tmp_func_size += 8;
                                }
                                else
                                {
                                    // FLOAT + INt
                                    tmp_func_size += 4;
                                    std::cerr << "inside" << std::endl;
                                }
                            }
                            else
                            {
                                tmp_func_size += 8;
                                InitialBuildContext.insert_local_var_waiting_for_declared(tmp->get_cloest_Id());
                            }
                        }

                        if (tmp_func_size < 16)
                        {
                            tmp_func_size = 16;
                        }
                        // do we need to deal with the size of that function if it is just a call
                        if (tmp_func_size > inside_function_size)
                        {                                         // ???
                            inside_function_size = tmp_func_size; //
                        }
                    }
                    else
                    {
                        for (int d = 0; d < next_branch_0->get_size(); d++) // targeting return {}
                        {
                            // f1
                            std::cerr << "# f1  " << d << "-------------->" << std::endl;
                            NodePtr func = next_branch_0->get_branch(d);
                            if (func->is_Function_inside() == true)
                            {
                                std::cerr << "# is function inside " << d << "-------------->" << std::endl;
                                function_inside = true;
                                tmp_func_size = 0;
                                // 1
                                for (int i = 1; i < func->get_size(); i++)
                                {
                                    // f1 (a, b, c, d)     LOOPING a b c d
                                    std::cerr << "# how mang param in function " << d << " :" << func->get_size() - 1 << "-------------->" << std::endl;
                                    NodePtr tmp = func->get_branch(i);

                                    // std::cerr << tmp->get_cloest_Id() << "   |    " << tmp->get_Id() << std::endl;
                                    if (InitialBuildContext.is_Local(tmp->get_cloest_Id()))
                                    {
                                        if (InitialBuildContext.find_local(tmp->get_cloest_Id()).type_name == "DOUBLE")
                                        {
                                            tmp_func_size += 8;
                                        }
                                        else
                                        {
                                            // FLOAT + INt
                                            tmp_func_size += 4;
                                            std::cerr << "inside" << std::endl;
                                        }
                                    }
                                    else
                                    {
                                        tmp_func_size += 8;
                                        InitialBuildContext.insert_local_var_waiting_for_declared(tmp->get_cloest_Id());
                                    }
                                }

                                if (tmp_func_size < 16)
                                {
                                    tmp_func_size = 16;
                                }
                                // do we need to deal with the size of that function if it is just a call
                                if (tmp_func_size > inside_function_size)
                                {                                         // ???
                                    inside_function_size = tmp_func_size; //
                                }
                                // function does not need to be stored in ordered_varaible table
                            }
                            else if (next_branch_0->is_Constant())
                            {
                                // do nothing here
                            }
                            else if (InitialBuildContext.extract_local_var().count(next_branch_0->get_Id()) != 0) // found local variable then set it as called
                            {
                                // std::cerr << "#"
                                //<< "stage 6"
                                //<< "  |  " << g << std::endl;
                                // std::cerr << "#"
                                //<< "Found ID in current real context" << branch[g]->get_Id() << std::endl;
                                InitialBuildContext.local_var_called(next_branch_0->get_Id());
                            }
                            else // not found marked as wait to declared
                            {
                                std::cerr << "# f2 " << d << "-------------->" << std::endl;
                                // std::cerr << "#"
                                //<< "stage 7"
                                //<< "  |  " << std::endl;
                                // std::cerr << "#"
                                //<< "Not Found  " << branch[g]->get_Id() << std::endl;
                                InitialBuildContext.insert_local_var_waiting_for_declared(next_branch_0->get_Id());
                                std::cerr << "# f3 " << d << "-------------->" << std::endl;
                            }
                        }
                    }
                }

                // std::cerr << "# retuning done -------------->" << std::endl;
            }
            else if (branch[g]->is_Compound_statement()) // Not function call; Not basic assignment;  Compound statement IF WHILE ..
            {

                std::vector<FloatDoubleConst> a = branch[g]->get_Float_Const();
                std::vector<std::string> b = branch[g]->get_String_Const();
                for (int i = 0; i < a.size(); i++)
                {
                    Float_Const_of_this_compound.push_back(a[i]);
                }
                for (int i = 0; i < b.size(); i++)
                {
                    String_Const_of_this_compound.push_back(b[i]);
                }

                for (int d = 0; d < branch[g]->get_size(); d++)
                {

                    if (branch[g]->get_branch(d)->is_Function_inside() == true)
                    {
                        // return f();
                        // std::cerr << "#"
                        //<< "stage 5b" << std::endl;
                        function_inside = true;
                        tmp_func_size = 0;
                        for (int i = 0; i < branch[g]->get_size() - 1; i++)
                        {
                            NodePtr tmp = branch[g]->get_branch(i);
                            if (InitialBuildContext.is_Local(tmp->get_cloest_Id()))
                            {
                                if (InitialBuildContext.find_local(tmp->get_cloest_Id()).type_name == "DOUBLE")
                                {
                                    tmp_func_size += 8;
                                }
                                else
                                {
                                    // FLOAT + INt
                                    tmp_func_size += 4;
                                }
                            }
                            else
                            {
                                tmp_func_size += 8;
                                InitialBuildContext.insert_local_var_waiting_for_declared(tmp->get_cloest_Id());
                            }
                        }
                        if (tmp_func_size < 16)
                        {
                            tmp_func_size = 16;
                        }
                        // do we need to deal with the size of that function if it is just a call
                        if (tmp_func_size > inside_function_size)
                        {                                         // ???
                            inside_function_size = tmp_func_size; //
                        }
                        // function does not need to be stored in ordered_varaible table
                    }
                }
                if (branch[g]->get_context_local_size() != 0)
                {
                    subcontextsize.push_back(branch[g]->get_context_local_size()); //??? here comes the other int vector Not linked;
                    Local_var var("SUBCONTEXT", stack_index);                      // seems like you r not tending to call them
                    std::string var_name = std::to_string(g) + "Subcontext";
                    InitialBuildContext.insert_var_local(std::make_pair(var_name, var));
                    stack_index += 1;
                }
                // std::cerr << "#" << "come out" << std::endl;
                std::vector<std::string> is_call_listed = branch[g]->return_waiting_to_declared_list(); // only compound need return is_call_list
                // std::cerr << "#" << "is called " << is_call_listed[0] << std::endl;
                // std::cerr << "#" << "is called out" << is_call_listed.size() << std::endl;
                //  stack_index += 1;

                for (int i = 0; i < is_call_listed.size(); i++)
                {
                    // the situation when int x; followed by if{ x = 8;}
                    // if it cannot find in this local scope, it is probably global variable and we do not need to care about it.
                    if (InitialBuildContext.extract_local_var().count(is_call_listed[i]) != 0)
                    {
                        InitialBuildContext.local_var_called(is_call_listed[i]); // if this couldnt be found at this layer maybe we should retain the varible and go up for one more layer?
                    }
                }

                // return waiting to size list
            }
        }
        // right side of the "=" leads to dynamic local size

        tmp_dynamic_size = branch[g]->Dynamic_context_size() + 1; // this is initial size 4 for x+4;
        std::cerr << "########################## dynamic computation " << tmp_dynamic_size << std::endl;
        // std::cerr << "#TMP DYNAMIC SIZE: " << tmp_dynamic_size << std::endl;
        //  std::cerr << "#" << "Tmp Dynamic Size identification" << dynamic_context_size << std::endl;

        // SOS
        // if (branch[g]->get_type() == "INT")
        //{

        tmp_dynamic_size = tmp_dynamic_size * 8;
        //}
        if (tmp_dynamic_size > dynamic_context_size)
        {

            dynamic_context_size = tmp_dynamic_size; // Judge for every single code
            // std::cerr << "#"
            //           << "Dynamic Size identification" << dynamic_context_size << std::endl;
            //  std::cerr << "#" << " COMM " << dynamic_context_size << std::endl;
        }
        // std::cerr << "build complete3 "<< std::endl;
        // std::cerr << "#" << "<<---- check functioninside ---->>" << function_inside << std::endl;
    }
    // std::cerr << "#Final DYNAMIC SIZE: " << dynamic_context_size << std::endl;
    //  after going through all nodes, we can add our dynamic size
    //  if(dynamic_context_size != 0){
    // std::cerr<< "#" << "stage 9" << "  |  " << stack_index << std::endl;
    Local_var vard("NotDefined", stack_index);
    InitialBuildContext.insert_var_local(std::make_pair("$DynamicContext", vard));
    stack_index += 1;
    //}
    // std::cerr << "build complete111 "<< std::endl;
    //        std::cerr << "#" << "<<---- check functioninside ---->>" << function_inside << "  |  " << inside_function_size << std::endl;
    if (function_inside == true)
    {
        std::cerr << "#"
                  << "stage 10" << std::endl;
        //<< "  |  " << stack_index << std::endl;
        //        std::cerr << "#" << "inside function call" << std::endl;
        // after declaring the dynamic context, we have the context space for the function call argument.
        // here we only take the largest function argument size.
        Local_var var("FunctionCal", true, stack_index); // why this is then called?
        InitialBuildContext.insert_var_local(std::make_pair("$functioncall", var));
        stack_index += 1;
    }
    std::cerr << "#"
              << "build complete fully" << std::endl;
}

void Compound_statement_Mips::Assign_offset(int index, Context input)
{

    int count = index;
    int subcontext_index = 0;
    int array_index = 0;
    std::vector<int> offset_arrangement(InitialBuildContext.extract_local_var().size()); // two empty but same size vector
    std::vector<int> after_assigned(InitialBuildContext.extract_local_var().size());
    std::map<std::string, Local_var> A = InitialBuildContext.extract_local_var();
    for (std::map<std::string, Local_var>::iterator it = A.begin(); it != A.end(); ++it) // we now have the size and sorted
    {

        // std::cerr << "#" << it->second.index << std::endl;
        // std::cerr << "#" << it->first << std::endl;

        if (it->second.type_name == "INT" || it->second.type_name == "INTPTR")
        {
            offset_arrangement[it->second.index - 1] = 4;
        }
        else if (it->second.type_name == "DOUBLE" || it->second.type_name == "DOUBLEPTR")
        {
            offset_arrangement[it->second.index - 1] = 8;
        }

        else if (it->second.type_name == "FLOAT" || it->second.type_name == "FLOATPTR")
        {
            offset_arrangement[it->second.index - 1] = 4;
        }

        else if (it->second.type_name == "CHAR" || it->second.type_name == "CHARPTR")
        {
            // here we assume char has length of 4; but we only load the first quator of the
            offset_arrangement[it->second.index - 1] = 4;
        }

        else if (it->second.type_name == "SUBCONTEXT")
        {
            // std::cerr << "#" << "offset part" << subcontext_index << "     |     " << subcontextsize[subcontext_index] << std::endl;
            offset_arrangement[it->second.index - 1] = subcontextsize[subcontext_index];
            subcontext_index += 1;
        }
        else if (it->first == "$DynamicContext")
        {
            std::cerr << "##------------------- ASA dynamic offset  " << dynamic_context_size << std::endl;
            offset_arrangement[it->second.index - 1] = dynamic_context_size;
        }
        else if (it->second.type_name == "INTArray" || it->second.type_name == "DOUBLEArray" || it->second.type_name == "FLOATArray")
        {
            offset_arrangement[it->second.index - 1] = arraysize[array_index];
            array_index += 1;
        }
        else if (it->second.type_name == "ENUM")
        {
            offset_arrangement[it->second.index - 1] = 0;
        }

        else
        {
            // struct
            // std::cerr << "#test" << it->second.type_name << std::endl;
            if (InitialBuildContext.Type_Str.find(it->second.type_name) != InitialBuildContext.Type_Str.end())
            {
                offset_arrangement[it->second.index - 1] = InitialBuildContext.Type_Str.find(it->second.type_name)->second.type_size;
            }
            else
            {
                // std::cerr << "anabab" << std::endl;
                if (input.Type_Str.find(it->second.type_name) != InitialBuildContext.Type_Str.end())
                {
                    offset_arrangement[it->second.index - 1] = input.Type_Str.find(it->second.type_name)->second.type_size;
                    // std::cerr << "#inside (" << input.Type_Str.find(it->second.type_name)->second.type_size << ")" << std::endl;
                }
                // offset_arrangement[it->second.index - 1] = input.Type_Str.find(it->second.type_name)->second.type_size;
                // std::cerr << "gg" << std::endl;
            }
        }
    }
    if (offset_arrangement.size() != 0) // calculate the offset
    {
        after_assigned[0] = index;
        for (int i = 1; i < offset_arrangement.size(); i++)
        {
            after_assigned[i] = after_assigned[i - 1] - offset_arrangement[i - 1];
        }
        for (std::map<std::string, Local_var>::const_iterator it = A.begin(); it != A.end(); ++it) // assign offset to var
        {
            InitialBuildContext.assign_offset_to_local_var(it->first, std::to_string(after_assigned[it->second.index - 1]));
        }
    }
}

int Compound_statement_Mips::get_context_local_size()
{
    return size;
}

std::vector<std::string> Compound_statement_Mips::return_waiting_to_declared_list()
{
    // return the undeclared variable in the current scope to the upper scope;
    return InitialBuildContext.read_whole_local_var_type_waiting_for_declared();
}

std::vector<std::pair<std::string, std::string> > Compound_statement_Mips::read_Local_Var_Waiting_For_Sizing()
{
    return InitialBuildContext.LocalVarWaitingForSizing;
}

bool Compound_statement_Mips::is_Compound_statement() const
{
    return true;
}

int Compound_statement_Mips::Dynamic_context_size()
{
    return dynamic_context_size;
}
std::vector<FloatDoubleConst> Compound_statement_Mips::get_Float_Const()
{
    return Float_Const_of_this_compound;
}
std::vector<std::string> Compound_statement_Mips::get_String_Const()
{
    return String_Const_of_this_compound;
}
std::vector<InnerFDarray> Compound_statement_Mips::return_df_array_list()
{
    return Df_Array_List_of_this_compound;
}
/*<--------store variable used in input argument index 0-------->*/
/*<-------store variable used within context--------->*/
/*<-------store variable used within context for dynamic context--------->*/
/*<-------store variable used in function call argument--------->*/
