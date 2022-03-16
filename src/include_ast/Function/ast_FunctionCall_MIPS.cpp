
#include "AST/Function/ast_FunctionCall_MIPS.hpp"

FunctionCall_Mips::FunctionCall_Mips(const NodePtr functionID, const std::vector<NodePtr> _Argument_expression_list)
{
    branch.push_back(functionID);
    for(int i = 0; i < _Argument_expression_list.size(); i++){
        branch.push_back(_Argument_expression_list[i]);
    }
}

FunctionCall_Mips::FunctionCall_Mips(const NodePtr functionID)
{

    branch.push_back(functionID);
}

void FunctionCall_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // int starting_reg = 4;
    // for(int i = 0; i < Argument.size(); i++){
    //     if(Argument[i]->get_Id())
    //     {
    //          dst << "lw" << " " << "$"<< starting_reg <<
    //     }

    // }
    if(branch.size() <= 5){
        for(int i = 1; i < branch.size(); i++){
            branch[i]->generateMips(dst, context, 3 + i, make_name, dynamic_offset);
        }

    }
    else{
        int out_size = branch.size() - 5;
        for(int k = 0; k < out_size; k++){
            branch[5 + k]->generateMips(dst, context, 2, make_name, dynamic_offset);
            dst << "sw " << "$2" << k*4 + 16 << "( $30 )" << std::endl;
        }
        for(int i = 0; i < 4; i++){
            branch[i]->generateMips(dst, context, 4 + i, make_name, dynamic_offset);
        }
    }
    dst << "jal"
        << " " << branch[0]->get_Id().back() << ":" << std::endl;
}

// declaration
// spcifier declarator
//          direct_declara / Init_declarat
//                           declarator "=" Initializer
//                           int x = 0;
//                                          Assignment Expression
//                                          Identifier/constant/string_Val
//                                           x = 0;
// statement
// Assignment Expression -> get_id
// branch -> get_id != false -> map  is call = t;

std::string FunctionCall_Mips::get_Id() const
{
    return branch[0]->get_Id();
}

bool FunctionCall_Mips::is_Function_inside() const
{
    return true;
}

int FunctionCall_Mips::get_argument_size() {
    return branch.size() -1;
}

//when the function is called, the arrangement inside local context


/*<-------store variable used within context--------->*/
/*<-------store variable used within context for dynamic context--------->*/
/*<-------store variable used in function argument--------->*/
