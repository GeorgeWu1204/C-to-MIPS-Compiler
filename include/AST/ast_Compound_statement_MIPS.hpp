#ifndef ast_Compound_statement_MIPS_hpp
#define ast_Compound_statement_MIPS_hpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "ast_Node.hpp"
#include "ast_Context.hpp"
#include "ast_makeName.hpp"
// #include "Iteration/ast_For_MIPS.hpp"

class Compound_statement_Mips
    : public Node
{

public:
    // body definition
    bool function_inside;
    bool return_label_declared;
    int size;
    int dynamic_context_size;
    int inside_function_size;
    std::vector<int> subcontextsize;
    std::vector<int> arraysize;
    std::vector <std::string> jump_label;
    std::vector<int> index_of_case_branch;
    std::map<std::string, int> case_address;

    bool is_Function_inside() const override;
    Context SubContext;
    Context InitialBuildContext;
    // this is used to temporarily stored the initial  of the context. After offset assignment and the combination, we can have the
    // Subcontext passed to the lower level.
    std::vector<std::string> ordered_variable_table;
    // name - (type, offset, is called)
    Compound_statement_Mips(const std::vector<NodePtr> Declaration_List_Or_Statement);
    Compound_statement_Mips(const std::vector<NodePtr> Declaration_List, const std::vector<NodePtr> Statement_List);
    Compound_statement_Mips();

    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    int get_context_local_size() override;
    std::vector<std::string> return_waiting_to_declared_list() override;
    std::vector<std::pair<std::string, std::string> > read_Local_Var_Waiting_For_Sizing() override;


    //std::vector<std::string,std::string> return_unknow_specifier_size_list() override;
    //return the unknow size list |size|

    bool is_Compound_statement() const override;
    //  void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    //  int get_context_local_size() override;
    //  std::vector<std::string> return_waiting_to_declared_list() override;
    //  bool is_Compound_statement() const override;

    void build_func_context();
    int find_stack_size();
    int get_size() const override;
    void Assign_offset(int index, Context input);
    //void generate_case_mips(bool break_labeled, std::vector<std::string> & label_name);
    int Dynamic_context_size() override;


    //for float
    std::vector<FloatDoubleConst> get_Float_Const() override;
    std::vector<FloatDoubleConst> Float_Const_of_this_compound;
    std::vector<std::string> get_String_Const() override;
    std::vector<std::string> String_Const_of_this_compound;
    std::vector<InnerFDarray> return_df_array_list() override;
    std::vector<InnerFDarray> Df_Array_List_of_this_compound;
    
    // void add_to_InitialBuildContext(std::map<std::string, std::string> input, int &stack_index);
    // void enable_call_in_InitialBuildcontext(std::vector<std::string> input);
    //  this function is used to build a new sub context in order to pass is to the next level;
    //  void BuildSubContext(Context UpperContext);
    //  std::vector<std::string> return_waiting_to_declared_list() override;
    //  synchronise var
    //std::map<std::string, int> return_case_address() override;
};

#endif
