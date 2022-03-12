
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

    // std::cout << "Statement_list" << Statement_List.size() << std::endl;
    // std::cout << "inside two nodePtr vector input" << std::endl;
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
    // std::cout << "<---UpperContext--->" << std::endl;
    // context.print_local();
    
    Assign_offset(context.find_local_sub_context_offset());
    // std::cout << "order variable" << ordered_variable_table.size() << std::endl;
    dynamic_offset = stoi(context.find_local("$DynamicContext").offset);
    SubContext.sync_local_context(context, InitialBuildContext);
    for (int i = 0; i < branch.size(); i++)
    {   
        
        branch[i]->generateMips(dst, SubContext, 2, make_name, dynamic_offset);
        dynamic_offset = stoi(context.find_local("$DynamicContext").offset);
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
    int i = 0;
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

            else if (it->second.type_name == "Function")
            {
                count_size += inside_function_size;
            }
            else if(it->second.type_name == "INTArray")
            {
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
    int stack_index = 0;
    // this variable is  used to trace the current index inside the map;
    dynamic_context_size = 0;
    int tmp_func_size = 0;
    inside_function_size = 0;
    for (int g = 0; g < branch.size(); g++)
    {
        if (branch[g]->is_Declaration())
        {

            if (branch[g]->is_Function())
            {
                Local_var var("FunctionDec", true, stack_index);
                // function declaration,
                function_inside = true;
                // function does not need to be stored in ordered_varaible table
                InitialBuildContext.insert_var_local(std::make_pair(branch[g]->get_Id(), var));
                stack_index += 1;
            }
            else if (branch[g]->is_init())
            {
                // std::cout << "is_init" << std::endl;
                Local_var var(branch[g]->get_type(), true, stack_index);
                // ordered_variable_table.push_back(branch[g]->get_Id());
                InitialBuildContext.insert_var_local(std::make_pair(branch[g]->get_Id(), var));
                stack_index += 1;
            }
            else if (branch[g]->is_Array())
            {
                std::string conc = branch[g]->get_type() + "Array";
                Local_var var(conc, true, stack_index);
                //when the array of certain size is declared, it is always called.
                arraysize.push_back(branch[g]->array_size());
                InitialBuildContext.insert_var_local(std::make_pair(branch[g]->get_Id(), var));
                stack_index += 1;
            }
            else
            {
                //  int x; false automatically
                Local_var var(branch[g]->get_type(), stack_index);
                InitialBuildContext.insert_var_local(std::make_pair(branch[g]->get_Id(), var));
                // std::cout << "Inserted Local Waiting for Call" << std::endl;
                stack_index += 1;
            }
        }
        else
        {
            // statement list { y =1; }
            // for (int m = 0; m < branch[g]->get_size(); m++)
            //{
            // std::cout << "BRanch-G size" << branch[g]->get_size() << std::endl;

            // function call f();
            if (branch[g]->is_Function_inside() == true)
            {
                
                // function call
                function_inside = true;
                if(branch[g]->get_argument_size() > 4){
                    tmp_func_size = branch[g]->get_argument_size() * 4;
                }
                else{
                    tmp_func_size = 16;
                }

                if(tmp_func_size > inside_function_size){
                    inside_function_size = tmp_func_size;
                }
                // function does not need to be stored in ordered_varaible table

            }
            // x = 1;
            else if (branch[g]->get_Id() != "False")
            {
                // InitialBuildContext.print_local();
                if (InitialBuildContext.extract_local_var().count(branch[g]->get_Id()))
                {
                    // std::cout << "Found ID in current real context" << branch[g]->get_Id() << std::endl;
                    InitialBuildContext.local_var_called(branch[g]->get_Id());
                }
                else
                {
                    // std::cout << "Not Found  " << branch[g]->get_Id() << std::endl;
                    InitialBuildContext.insert_local_var_waiting_for_declared(branch[g]->get_Id());
                }
            }
            // else if(branch[g]->is_Mixed()){
            //     //this is used to build FOR, WHILE which are composed of Expression + Compound etc. They both affect the construction of the context.

            //     add_to_InitialBuildContext(branch[g]->return_mixed_map(), stack_index);
            //     enable_call_in_InitialBuildcontext(branch[g]->return_waiting_to_declared_list());
            //     subcontextsize.push_back(branch[g]->get_context_local_size());
            // }

            else if (branch[g]->is_Compound_statement())
            {
                subcontextsize.push_back(branch[g]->get_context_local_size());
                Local_var var("SUBCONTEXT", stack_index);
                std::string var_name = std::to_string(g) + "Subcontext";
                InitialBuildContext.insert_var_local(std::make_pair(var_name, var));
                std::vector<std::string> is_call_listed = branch[g]->return_waiting_to_declared_list();
                // stack_index += 1;

                for (int i = 0; i < is_call_listed.size(); i++)
                {
                    // the situation when int x; followed by if{ x = 8;}
                    // if it cannot find in this local scope, it is probably global variable and we do not need to care about it.
                    if (InitialBuildContext.extract_local_var().count(is_call_listed[i]) != 0)
                    {
                        InitialBuildContext.local_var_called(is_call_listed[i]);
                    }
                }
                stack_index += 1;
            }
        }
        // right side of the "=" leads to dynamic local size
        if(branch[g]->get_context_local_size() > dynamic_context_size){
            dynamic_context_size = branch[g]->get_context_local_size();
        }
        
    }
    //after going through all nodes, we can add our dynamic size
    if(dynamic_context_size != 0){
        Local_var vard("NotDefined", stack_index);
        InitialBuildContext.insert_var_local(std::make_pair("$DynamicContext", vard));
        stack_index += 1;
    }
    if(function_inside = true){
        //after declaring the dynamic context, we have the context space for the function call argument.
        //here we only take the largest function argument size.
        Local_var var("FunctionCal", true, stack_index);
        InitialBuildContext.insert_var_local(std::make_pair("$functioncall", var));
        stack_index += 1;

    }
    

}

void Compound_statement_Mips::Assign_offset(int index)
{

    int count = index;
    int subcontext_index = 0;
    int array_index = 0;
    std::vector<int> offset_arrangement(InitialBuildContext.extract_local_var().size());
    std::vector<int> after_assigned(InitialBuildContext.extract_local_var().size());
    std::map<std::string, Local_var> A = InitialBuildContext.extract_local_var();
    for (std::map<std::string, Local_var>::iterator it = A.begin(); it != A.end(); ++it)
    {

        // std::cout << it->second.index << std::endl;
        if (it->second.type_name == "INT")
        {
            offset_arrangement[it->second.index] = 4;
        }
        else if (it->second.type_name == "SUBCONTEXT")
        {
            offset_arrangement[it->second.index] = subcontextsize[subcontext_index];
            subcontext_index += 1;
        }
        else if(it->first == "$DynamicContext")
        {
            offset_arrangement[it->second.index] = dynamic_context_size;
        }
        else if(it->second.type_name == "INTArray")
        {
            offset_arrangement[it->second.index] = arraysize[array_index];
            array_index += 1;
        }

        // extract_local_var().at(ordered_variable_table[m]).assign_offset(std::to_string(count));
    }
    if (offset_arrangement.size() != 0)
    {
        after_assigned[0] = index;
        for (int i = 1; i < offset_arrangement.size(); i++)
        {
            after_assigned[i] = after_assigned[i - 1] + offset_arrangement[i - 1];
        }
        for (std::map<std::string, Local_var>::const_iterator it = A.begin(); it != A.end(); ++it)
        {
            InitialBuildContext.assign_offset_to_local_var(it->first, std::to_string(after_assigned[it->second.index]));
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



/*<-------store variable used within context--------->*/
/*<-------store variable used within context for dynamic context--------->*/
/*<-------store variable used in function argument--------->*/
