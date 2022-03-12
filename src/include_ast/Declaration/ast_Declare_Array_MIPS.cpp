#include"AST/Declaration/ast_Declare_Array_MIPS.hpp"


Declare_Array_Mips::Declare_Array_Mips(const NodePtr header){
    branch.push_back(header);
}

Declare_Array_Mips::Declare_Array_Mips(const NodePtr header, const NodePtr size){
    branch.push_back(header);
    branch.push_back(size);
}


// void Declare_Array_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset){

// }

std::string Declare_Array_Mips::get_type(){
    return branch[0]->get_type();
}

int Declare_Array_Mips::array_size(){
    return branch[1]->array_size();
}

