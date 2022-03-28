#ifndef ast_UnaryAddress_MIPS_hpp
#define ast_UnaryAddress_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"
#include "../ast_Compound_statement_MIPS.hpp"


class UnaryAddress_MIPS
    : public Node
{
public:
    // int local_size;
    // std::vector<std::string> return_declare_list;   
    //Compound_statement_Mips csm(const std::vector<NodePtr> Declaration_List, const std::vector<NodePtr> Statement_List);
    UnaryAddress_MIPS(NodePtr Expression_term_1);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    std::string get_Id() const override;
    std::string return_expression_type(Context context) override;
    // std::vector<std::string> return_waiting_to_declared_list() override;
    // bool is_Compound_statement() const override;
    // void build_mock_compound();
    // bool is_Loop() const override;

    
};

#endif
