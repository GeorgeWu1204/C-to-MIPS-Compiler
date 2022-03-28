#ifndef ast_Enum_specifier_Mips_hpp
#define ast_Enum_specifier_Mips_hpp
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include <string>
#include <iostream>
#include "../ast_makeName.hpp"
class Enum_specifier_Mips
    : public Node
{
protected:
    std::string enumerator_specifier_name;
    std::map<std::string, int> enumrator_map;

public:
    Enum_specifier_Mips(const std::string &identifier,const std::vector<NodePtr> Enumerator_list);
    Enum_specifier_Mips(const std::string &identifier);
    Enum_specifier_Mips(const std::vector<NodePtr> Enumerator_list);

    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    int get_Val() const override;
    std::string get_Id() const override;
    std::map<std::string, int> get_enumerator_list() override;
    bool is_Enum() const override;
    //bool is_Declaration () const override;
};
#endif