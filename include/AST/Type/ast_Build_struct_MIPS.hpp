#ifndef ast_Build_struct_MIPS_hpp
#define ast_Build_struct_MIPS_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Build_struct_Mips
    : public Node
{



public:
    type_storage inner_type_store;
    std::string struct_name;
    Build_struct_Mips(const std::string &identifier, const std::vector<NodePtr> Declare_list);
    bool is_Struct() const override;
    void build_storage();
    type_storage get_type_storage() override;
    std::string get_type() const override;
    
};
#endif