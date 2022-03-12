#ifndef ast_Compound_statement_MIPS_hpp
#define ast_Compound_statement_MIPS_hpp
#include <string>
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
    friend class For_Mips;
    bool function_inside;
    int size;
    int dynamic_context_size;
    int inside_function_size;
    std::vector<int> subcontextsize;
    std::vector<int> arraysize;
    bool is_Function_inside() const override;
    Context SubContext;
    Context InitialBuildContext;
    // this is used to temporarily stored the initial guess of the context. After offset assignment and the combination, we can have the
    // Subcontext passed to the lower level.
    std::vector<std::string> ordered_variable_table;
    // name - (type, offset, is called)
    Compound_statement_Mips(const std::vector<NodePtr> Declaration_List_Or_Statement);
    Compound_statement_Mips(const std::vector<NodePtr> Declaration_List, const std::vector<NodePtr> Statement_List);
    Compound_statement_Mips();

    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    int get_context_local_size() override;
    std::vector<std::string> return_waiting_to_declared_list() override;
    bool is_Compound_statement() const override;

    //  void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    //  int get_context_local_size() override;
    //  std::vector<std::string> return_waiting_to_declared_list() override;
    //  bool is_Compound_statement() const override;

    void build_func_context();
    int find_stack_size();
    int get_size() const override;
    void Assign_offset(int index);

    // void add_to_InitialBuildContext(std::map<std::string, std::string> input, int &stack_index);
    // void enable_call_in_InitialBuildcontext(std::vector<std::string> input);
    //  this function is used to build a new sub context in order to pass is to the next level;
    //  void BuildSubContext(Context UpperContext);
    //  std::vector<std::string> return_waiting_to_declared_list() override;
    //  synchronise var
};

#endif
