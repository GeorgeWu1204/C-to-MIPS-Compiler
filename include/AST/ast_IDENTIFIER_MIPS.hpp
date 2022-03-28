#ifndef ast_IDENTIFIER_MIPS_hpp
#define ast_IDENTIFIER_MIPS_hpp

#include <string>
#include <iostream>

#include "ast_Node.hpp"
#include "ast_Context.hpp"
#include "ast_makeName.hpp"

class Identifier_Mips
    : public Node
{

protected:
    std::string identifier_id;

public:
    Identifier_Mips(const std::string &input);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    void generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type) override;
    // void prettyPrint(std::ostream &dst) const override;
    std::string get_Id() const override;
    std::string get_cloest_Id() const override;
    bool is_Identifier() const override;
    std::vector<std::string> return_waiting_to_declared_list() override;
    std::string return_expression_type(Context context);
};

#endif
