#ifndef ast_Global_Declaration_MIPS_hpp
#define ast_Global_Declaration_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Global_Declaration_Mips
    : public Node
{

public:
    // Declaration_Mips(const std::string specifier, NodePtr declarator);
    Global_Declaration_Mips(const NodePtr specifier);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    std::string get_type() const override;
    std::string get_Id() const override;
    int array_size() const override;
    std::map<std::string, int> get_enumerator_list() override;
    bool is_Enum() const override;
    bool is_Struct() const override;
    bool is_Struct_Declaration() const override;
    bool is_init() const override;
    bool is_Array() const override;
    type_storage get_type_storage() override;
    std::vector<FloatDoubleConst> get_Float_Const() override;
    std::vector<std::string> get_String_Const() override;
};

#endif