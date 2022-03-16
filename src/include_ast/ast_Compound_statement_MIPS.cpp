
// #include "include/ast.hpp"
#include "AST/ast_Compound_statement_MIPS.hpp"

Compound_statement_Mips::Compound_statement_Mips(const std::vector<NodePtr> Declaration_List)
    : Node(Declaration_List)
{
    //std::cout << "Statement_list" << Declaration_List.size() << std::endl;
    build_func_context();
    //std::cout << "build completed" << std::endl;
    size = find_stack_size();
    //std::cout << "SIZE: " << size << std::endl;
}
Compound_statement_Mips::Compound_statement_Mips(const std::vector<NodePtr> Declaration_List, const std::vector<NodePtr> Statement_List)
    : Node(Declaration_List, Statement_List)
{

    //std::cout << "Statement_list" << Statement_List.size() << std::endl;

    // std::cout << "branch size " << branch.size() << std::endl;
    build_func_context();
    size = find_stack_size();
}

Compound_statement_Mips::Compound_statement_Mips()
    : Node()
{
    // do nothing here
    size = 0;
}

void Compound_statement_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // std::cout << "inside compound_statement" << std::endl;
    // InitialBuildContext.print_local();

    // passing the offset from larger context to this subcontext;
    Assign_offset(context.find_local_sub_context_offset());
    //std::cout << "stage 1" << std::endl;

    // std::cout << "order variable" << ordered_variable_table.size() << std::endl;
    // std::cout << dynamic_context_size << std::endl;
    // std::cout << "<----------------context----------------->" << std::endl;
    // context.print_context();
    // std::cout << "<----------------ini----------------->" << std::endl;
    // InitialBuildContext.print_context();
    Local_var var = InitialBuildContext.find_local("$DynamicContext");
    // std::cout << "G" << std::endl;

    dynamic_offset = stoi(InitialBuildContext.find_local("$DynamicContext").offset);
    // std::cout << "stage 2" << dynamic_offset << std::endl;
    SubContext.sync_local_context(context, InitialBuildContext);
    //std::cout << "<---Combined Context--->" << std::endl;
    //SubContext.print_local();
    //SubContext.print_global();
    //  SubContext.print_local();
    for (int i = 0; i < branch.size(); i++)
    {
        branch[i]->generateMips(dst, SubContext, 2, make_name, dynamic_offset);
        dynamic_offset = stoi(SubContext.find_local("$DynamicContext").offset);
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
    int func_size = 0;
    // SOS
    int i = 0; // index for subcontext
    int array_index = 0;
    std::map<std::string, Local_var> func_context = InitialBuildContext.extract_local_var();
    // std::cout << "func_context" << std::endl;
    // InitialBuildContext.print_local();

    for (std::map<std::string, Local_var>::const_iterator it = func_context.begin(); it != func_context.end(); ++it)
    {
        if (it->second.is_called == true)
        {
            if (it->second.type_name == "INT")
            {
                count_size += 4;
            }

            else if (it->second.type_name == "FunctionCal")
            {
                count_size += inside_function_size;
            }
            else if (it->second.type_name == "INTArray")
            {
                std::cout << "inside arraysize" << std::endl;
                count_size += 4 * arraysize[array_index];
                array_index += 1;
            }
        }

        if (it->second.type_name == "SUBCONTEXT")
        {
            // std::cout << "sub context size" << subcontextsize[i] << std::endl;
            count_size += subcontextsize[i];
            // std::cout << "<------->" << std::endl;
            // std::cout << subcontextsize[i] << std::endl;
            i += 1;
        }

        if (it->first == "$DynamicContext")
        {
            count_size += dynamic_context_size;
        }
    }

    func_size = ceil(count_size / 8) * 8;
    return func_size;
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
    // std::cout << "this compound has branch size of " << branch.size() << std::endl;
    int stack_index = 1;
    // this variable is  used to trace the current index inside the map;
    // index 0 is used to store arguments
    dynamic_context_size = 0;

    int tmp_func_size = 0;
    int tmp_dynamic_size = 0;

    inside_function_size = 0;

    // std::cout << "{-----" << "inside build_func" << "-----}" << std::endl;
    for (int g = 0; g < branch.size(); g++)
    {
        // std::cout << "<------" << "function_inside  " << function_inside << "----->" <<std::endl;
        if (branch[g]->is_Declaration()) // branch[0] declarator branch[1] declaration list
        {
            std::string declaration_type = branch[g]->get_type();
            for (int d = 1; d < branch[g]->get_size(); d++)
            { // InitialBuildContext is what the context is
                // start from 1 due to type specifier + list
                NodePtr declaration_list_element = branch[g]->get_branch(d);
                if (declaration_list_element->is_Function())
                {
                    // std::cout << "stage 1" << "  |  " << g << branch[g]->get_Id().back() <<std::endl;  //?
                    // Local_var var("FunctionDec", true, stack_index);
                    // // function declaration,
                    // function_inside = true;
                    // // function does not need to be stored in ordered_varaible table
                    // InitialBuildContext.insert_var_local(std::make_pair(branch[g]->get_Id().back(), var));
                    // stack_index += 1;
                    //std::cout << "stage 1"
                    //          << "  |  " << g << " | " << d << declaration_list_element->get_Id() << std::endl; //?
                    Local_var var("FunctionDec", true, stack_index);
                    // function declaration,
                    function_inside = true;
                    // function does not need to be stored in ordered_varaible table
                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var));
                    stack_index += 1;
                }
                else if (declaration_list_element->is_init())
                {
                    // int x, y,z = 8; only assign value to z instead of x and y
                    //  assign call to the last variable declared.
                    //std::cout << "stage 2"
                    //          << "  |  " << g << "  |  " << d << declaration_list_element->get_Id() << std::endl;
                    Local_var var(declaration_type, true, stack_index); //? not always the case
                    // ordered_variable_table.push_back(branch[g]->get_Id());
                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? make pair
                    stack_index += 1;
                    // if(branch[g]->get_Id().size() > 1) {
                    //     for(int i = 0; i < branch[g]->get_Id().size() - 1; i++){
                    //         Local_var var(branch[g]->get_type(), stack_index);                                        // int x = 10, z= 7, y=3, o;
                    //         InitialBuildContext.insert_var_local(std::make_pair(branch[g]->get_Id()[i], var));        //? we might need to go down the branch
                    //         std::cout << "Inserted Local Waiting for Call" << branch[g]->get_Id()[i] << std::endl;
                    //         stack_index += 1;
                    //     }

                    // }
                }
                else if (declaration_list_element->is_Array())
                {
                   // std::cout << "stage 3"
                    //          << "  |  " << g << "  |  " << d << declaration_list_element->get_Id() << std::endl;
                    std::string conc = declaration_type + "Array";
                    Local_var var(conc, true, stack_index);
                    // when the array of certain size is declared, it is always called.
                    //std::cout << "arraysize" << declaration_list_element->array_size();
                    arraysize.push_back(declaration_list_element->array_size());                                   //? Node now has array_size() FAIL and array size is a int vector array_size now in the scope not linked
                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var)); //? get_Id()  two array with in one compound
                    stack_index += 1;
                }
                else
                {
                    //  int x; false automatically
                    //std::cout << "stage 4"
                    //          << "  |  " << g << declaration_list_element->get_Id() << std::endl;
                    Local_var var(branch[g]->get_type(), stack_index);
                    InitialBuildContext.insert_var_local(std::make_pair(declaration_list_element->get_Id(), var));
                    // std::cout << "Inserted Local Waiting for Call" << declaration_list_element->get_Id() << std::endl;
                    stack_index += 1;
                }
            }
        }
        else
        {
            //statement
            // x = 1;
            for (int d = 1; d < branch[g]->get_size(); d++)
            { // InitialBuildContext is what the context is
                // start from 1 due to type specifier + list
                NodePtr statement_list_element = branch[g]->get_branch(d);

                // statement list { y =1; }
                // for (int m = 0; m < branch[g]->get_size(); m++)
                //{
                // std::cout << "BRanch-G size" << branch[g]->get_size() << std::endl;

                // function call f();
                // x[1] = {f(),j()} 
                if (statement_list_element->is_Function_inside() == true)
                {
                    std::cout << "stage 5"
                              << "  |  " << g << statement_list_element->get_Id() << std::endl;
                    //  function call
                    function_inside = true;
                    if (statement_list_element->get_argument_size() > 4)
                    {
                        tmp_func_size = statement_list_element->get_argument_size() * 4; // tmp_func_size for recording size of argument
                    }
                    else
                    {
                        tmp_func_size = 16;
                    } // do we need to deal with the size of that function if it is just a call
                    if (tmp_func_size > inside_function_size)
                    {                                         // ???
                        inside_function_size = tmp_func_size; //
                    }
                    // function does not need to be stored in ordered_varaible table
                }
                // x = 1;
                // wrong
                else if (branch[g]->get_Id() != "False") //???? if it is not a function call, that go for x = 4? x[2] = 3?
                {
                    // need to find x= 4; SOS
                    //  InitialBuildContext.print_local();
                    //std::cout << "IN GETID" << branch[g]->get_Id() << std::endl;
                    //std::cout << "bracnh 1 lefthandside" << statement_list_element->get_Id() << std::endl;
                    if (statement_list_element->is_Constant())
                    {
                        //do nothing here
                    }
                    else if (InitialBuildContext.extract_local_var().count(statement_list_element->get_Id()) != 0) // found local variable then set it as called
                    {
                        //std::cout << "stage 6"
                        //          << "  |  " << g << statement_list_element->get_Id() << std::endl;
                        //  std::cout << "Found ID in current real context" << branch[g]->get_Id() << std::endl;
                        InitialBuildContext.local_var_called(statement_list_element->get_Id());
                    }
                    else // not found marked as wait to declared
                    {
                        //std::cout << "stage 7"
                        //          << "  |  " << g << statement_list_element->get_Id() << std::endl;
                        //  std::cout << "Not Found  " << branch[g]->get_Id() << std::endl;
                        InitialBuildContext.insert_local_var_waiting_for_declared(statement_list_element->get_Id());
                    }
                }
            }
            // need to consider the statement when the branch size is 1
            if(branch[g]-> is_Jump_statement()){
                //return expression
                NodePtr next_branch_0 = branch[g]->get_branch(0);
                for (int d = 0; d < next_branch_0->get_size(); d++){
                    
                    if (next_branch_0->get_branch(d)->is_Function_inside() == true)
                    {
                        // return f();
                        std::cout << "stage 5b" << std::endl;
                        function_inside = true;
                        if (next_branch_0->get_argument_size() > 4)
                        {
                            tmp_func_size = next_branch_0->get_argument_size() * 4; // tmp_func_size for recording size of argument
                        }
                        else
                        {
                            tmp_func_size = 16;
                        } // do we need to deal with the size of that function if it is just a call
                        if (tmp_func_size > inside_function_size)
                        {                                         // ???
                            inside_function_size = tmp_func_size; //
                        }
                        // function does not need to be stored in ordered_varaible table
                    }
                    if (next_branch_0->is_Constant())
                        {
                            //do nothing here
                        }
                        else if (InitialBuildContext.extract_local_var().count(next_branch_0->get_Id()) != 0) // found local variable then set it as called
                        {
                            //std::cout << "stage 6"
                            //          << "  |  " << g << statement_list_element->get_Id() << std::endl;
                            //  std::cout << "Found ID in current real context" << branch[g]->get_Id() << std::endl;
                            InitialBuildContext.local_var_called(next_branch_0->get_Id());
                        }
                        else // not found marked as wait to declared
                        {
                            //std::cout << "stage 7"
                            //          << "  |  " << g << statement_list_element->get_Id() << std::endl;
                            //  std::cout << "Not Found  " << branch[g]->get_Id() << std::endl;
                            InitialBuildContext.insert_local_var_waiting_for_declared(next_branch_0->get_Id());
                        }
                }


            }
            if (branch[g]->is_Compound_statement()) // Not function call; Not basic assignment;  Compound statement IF WHILE ..
            {
                //std::cout << "IN side statement" << std::endl;
                //std::cout << "stage 8"
                //          << "  |  " << g << branch[g]->get_context_local_size() << std::endl;
                if(branch[g]->get_context_local_size() != 0 ){
                    subcontextsize.push_back(branch[g]->get_context_local_size()); //??? here comes the other int vector Not linked;
                    Local_var var("SUBCONTEXT", stack_index); // seems like you r not tending to call them
                    std::string var_name = std::to_string(g) + "Subcontext";
                    InitialBuildContext.insert_var_local(std::make_pair(var_name, var));
                    stack_index += 1;
                }
                //std::cout << "come out" << std::endl;
                std::vector<std::string> is_call_listed = branch[g]->return_waiting_to_declared_list(); // only compound need return is_call_list
                //std::cout << "is called " << is_call_listed[0] << std::endl;
                //std::cout << "is called out" << is_call_listed.size() << std::endl;
                // stack_index += 1;

                for (int i = 0; i < is_call_listed.size(); i++)
                {
                    // the situation when int x; followed by if{ x = 8;}
                    // if it cannot find in this local scope, it is probably global variable and we do not need to care about it.
                    if (InitialBuildContext.extract_local_var().count(is_call_listed[i]) != 0)
                    {
                        InitialBuildContext.local_var_called(is_call_listed[i]); // if this couldnt be found at this layer maybe we should retain the varible and go up for one more layer?
                    }
                }
                
            }
        }
        // right side of the "=" leads to dynamic local size
        
        tmp_dynamic_size = branch[g]->Dynamic_context_size();
        if (branch[g]->get_type() == "INT")
        {
            tmp_dynamic_size *= 4;
        }
        if (tmp_dynamic_size > dynamic_context_size)
        {

            dynamic_context_size = tmp_dynamic_size; // Judge for every single code
            //std::cout << " COMM " << dynamic_context_size << std::endl;
        }
        // std::cout << "<<---- check functioninside ---->>" << function_inside << std::endl;
    }
    // after going through all nodes, we can add our dynamic size
    // if(dynamic_context_size != 0){
   // std::cout << "stage 9"
             // << "  |  " << stack_index << std::endl;
    Local_var vard("NotDefined", stack_index);
    InitialBuildContext.insert_var_local(std::make_pair("$DynamicContext", vard));
    stack_index += 1;
    //}

    //        std::cout << "<<---- check functioninside ---->>" << function_inside << "  |  " << inside_function_size << std::endl;
    if (function_inside == true)
    {
        std::cout << "stage 10" << "  |  " << stack_index <<std::endl;
        //        std::cout << "inside function call" << std::endl;
        // after declaring the dynamic context, we have the context space for the function call argument.
        // here we only take the largest function argument size.
        Local_var var("FunctionCal", true, stack_index); // why this is then called?
        InitialBuildContext.insert_var_local(std::make_pair("$functioncall", var));
        stack_index += 1;
    }
}

void Compound_statement_Mips::Assign_offset(int index)
{

    int count = index;
    int subcontext_index = 0;
    int array_index = 0;
    std::vector<int> offset_arrangement(InitialBuildContext.extract_local_var().size()); // two empty but same size vector
    std::vector<int> after_assigned(InitialBuildContext.extract_local_var().size());
    std::map<std::string, Local_var> A = InitialBuildContext.extract_local_var();
    for (std::map<std::string, Local_var>::iterator it = A.begin(); it != A.end(); ++it) // we now have the size and sorted
    {

        // std::cout << it->second.index << std::endl;
        // std::cout << it->first << std::endl;
        if (it->second.type_name == "INT")
        {
            offset_arrangement[it->second.index - 1] = 4;
        }
        else if (it->second.type_name == "SUBCONTEXT")
        {
            //std::cout << "offset part" << subcontext_index << "     |     " << subcontextsize[subcontext_index] << std::endl;
            offset_arrangement[it->second.index - 1] = subcontextsize[subcontext_index];
            subcontext_index += 1;
        }
        else if (it->first == "$DynamicContext")
        {
            offset_arrangement[it->second.index - 1] = dynamic_context_size;
        }
        else if (it->second.type_name == "INTArray")
        {
            offset_arrangement[it->second.index - 1] = arraysize[array_index];
            array_index += 1;
        }

        // extract_local_var().at(ordered_variable_table[m]).assign_offset(std::to_string(count));
    }
    if (offset_arrangement.size() != 0) // calculate the offset
    {
        after_assigned[0] = index;
        for (int i = 1; i < offset_arrangement.size(); i++)
        {
            after_assigned[i] = after_assigned[i - 1] + offset_arrangement[i - 1];
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

// void Compound_statement_Mips::BuildSubContext(Context input){
//     SubContext.sync_local_context(context, InitialBuildContext);
// }

std::vector<std::string> Compound_statement_Mips::return_waiting_to_declared_list()
{
    // return the undeclared variable in the current scope to the upper scope;
    return InitialBuildContext.read_whole_local_var_type_waiting_for_declared();
}

bool Compound_statement_Mips::is_Compound_statement() const
{
    return true;
}

// void Compound_statement_Mips::add_to_InitialBuildContext(std::map<std::string, std::string> input, int &stack_index){
//     for (std::map<std::string, std::string>::iterator it = input.begin(); it != input.end(); ++it){
//         Local_var var(it->second, true, stack_index);
//         stack_index += 1;
//         InitialBuildContext.insert_var_local(std::make_pair(it->first, var));
//     }
// }
//

/*<--------store variable used in input argument-------->*/
/*<-------store variable used within context--------->*/
/*<-------store variable used within context for dynamic context--------->*/
/*<-------store variable used in function call argument--------->*/
