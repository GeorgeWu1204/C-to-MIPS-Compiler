#ifndef ast_PointerDeclarator_MIPS_hpp
#define ast_PointerDeclarator_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "../ast_makeName.hpp"
#include "../ast_Compound_statement_MIPS.hpp"

class PointerDeclarator_MIPS
    : public Node
{
public:
  
   //int *x = 
    //Compound_statement_Mips csm(const std::vector<NodePtr> Declaration_List, const std::vector<NodePtr> Statement_List);
    PointerDeclarator_MIPS(NodePtr cast_expression);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    bool is_Pointer() const override;
    std::string get_Id() const override;
    int get_argument_size() override;
    std::vector<std::pair<std::string, std::string> > get_argument_map() override;
    bool is_Function() const override;
    
    // int get_context_local_size() override;
    // std::vector<std::string> return_waiting_to_declared_list() override;
    // bool is_Compound_statement() const override;
    // void build_mock_compound();
    // bool is_Loop() const override;

    
};

#endif
