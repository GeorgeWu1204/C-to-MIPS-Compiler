#ifndef ast_For_Mips_hpp
#define ast_For_Mips_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"
#include "../ast_Compound_statement_MIPS.hpp"

class For_Mips
    : public Node
{
public:
    int local_size;
    std::vector<std::string> return_declare_list;   
    //Compound_statement_Mips csm(const std::vector<NodePtr> Declaration_List, const std::vector<NodePtr> Statement_List);
    For_Mips(NodePtr Expression_term_1, NodePtr Expression_term_2, NodePtr Statement_term);
    For_Mips(NodePtr Expression_term_1, NodePtr Expression_term_2, NodePtr Expression_term_3, NodePtr Statement_term);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    int get_context_local_size() override;
    std::vector<std::string> return_waiting_to_declared_list() override;
    bool is_Compound_statement() const override;
    void build_mock_compound();
    
    
};

#endif
