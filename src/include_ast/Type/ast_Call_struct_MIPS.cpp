#include "AST/Type/ast_Call_struct_MIPS.hpp"

Call_struct_Mips::Call_struct_Mips(const NodePtr var_name, const std::string &identifier){
    struct_element = identifier;
    NodePtr tmp = new Identifier_Mips(struct_element);
    //left
    branch.push_back(var_name);
    //right
    branch.push_back(tmp);

}

std::string Call_struct_Mips::get_Id() const{
    //std::cout << "# returning a struct element" << branch[0]->get_Id() << std::endl;
    // should return the leftmost id.
    return branch[0]->get_Id();
}

void Call_struct_Mips:: generateMips (std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) {
    int tmp_offset = stoi(context.find_local(branch[0]->get_Id()).offset);
    //std::cout << "in call" << tmp_offset << std::endl;
    tmp_offset -= get_struct_variable_offset(context);
    dst << "lw " << "$" << destReg << "," << tmp_offset << "($30)"<< std::endl; 
}

bool Call_struct_Mips::is_Struct_Call() const {
    return true;
}

int Call_struct_Mips::get_struct_variable_offset(Context context){
    // find the offset;
    //std::cout << "insed step 2" << std::endl;
    type_storage tmp = get_struct(branch[0], context);
    //std::cout << "struct pass" << std::endl;
    //tmp.struct_content.find(context.find_local(branch[1]->get_Id()).type_name)->second.print_content();
    //std::cout << " offset ID" << branch[1]->get_Id() << std::endl;;
    
    return tmp.struct_content.find(branch[1]->get_Id())->second.offset;
}
    // ((x.y).z).k

type_storage Call_struct_Mips::get_struct(NodePtr inside, Context context){
    //inside = branch [0]
    //std::cout << "insed step 1" << std::endl;
    std::string name_in_str;
    
    if(inside->is_Struct_Call() == true){
        //std::cout << "move to if " << std::endl;
        // if(inside->is_Struct_Call()){
        //     std::cout << "insed step 3" << std::endl;
        //     name_in_str = context.find_local(branch[1]->get_branch(1)->get_Id()).type_name;
        // }
        // else{
        //     std::cout << "insed step 4" << std::endl;
        //     name_in_str = inside->get_branch(1)->get_Id();
        // }
        return get_struct(inside->get_branch(0), context).struct_content.find(branch[1]->get_Id())->second;
        //[x.y].z
        //[x.y]
    }
    else{
        //std::cout << "#inside else branch" << std::endl;
        //find local -> Id -> type --------- in type_str use type -> struct content -> (branch[i]->get_id)
        //std::cout << "id" << context.find_local(inside->get_Id()).type_name << std::endl;
        //context.Type_Str.find(context.find_local(inside->get_Id()).type_name)->second.print_content();
        std::pair<std::string, type_storage> result; 
        result.second = context.Type_Str.find(context.find_local(inside->get_Id()).type_name)->second;
        //std::cout << "pass success" << std::endl;
        result.first = context.Type_Str.find(context.find_local(inside->get_Id()).type_name)->first;
        return result.second;
    }
}
std::string Call_struct_Mips::return_expression_type(Context context)
{
    std::string type;
    int size;
    size = context.Type_Str.find(context.find_local(branch[0]->get_Id()).type_name)->second.struct_content.find(branch[1]->get_Id())->second.type_size;
    if(size==4){
        return "INT";
    }else if(size == 8){
        return "DOUBLE";
    }else if(size == 1){
        return "CHAR";
    }
    return type;
}
