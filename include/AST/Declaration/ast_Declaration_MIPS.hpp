#ifndef ast_Declaration_MIPS_hpp
#define ast_Declaration_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Declaration_Mips
    : public Node
{

public:
    std::vector<NodePtr> declarator_list;
    Declaration_Mips(const NodePtr specifier);
    Declaration_Mips(const NodePtr specifier, const NodePtr declarator);
    Declaration_Mips(const NodePtr specifier, const std::vector<NodePtr> declarator);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    // void prettyPrint(std::ostream &dst) const override;
    bool is_function_declaration();
    std::string get_type() const override;
    std::string get_Id() const override;
    bool is_Declaration() const override;
    int get_argument_size() override;
    std::vector< std::pair<std::string, std::string> >  get_argument_map() override;
    type_storage get_type_storage () override;
    std::map<std::string, int> get_enumerator_list() override;
    bool is_Enum() const override;
    bool is_Struct() const override;
    bool is_Struct_Declaration() const override;
    // for param
    bool is_Pointer() const override;

    // bool is_Function() const override;
    // bool is_init() const override;
};

#endif