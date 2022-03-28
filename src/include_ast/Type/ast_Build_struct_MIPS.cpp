#include "AST/Type/ast_Build_struct_MIPS.hpp"

Build_struct_Mips::Build_struct_Mips(const std::string &identifier, const std::vector<NodePtr> Declare_list)
{
  // composed of int x, y, z ; int z;
    struct_name = identifier;
    for (int i  = 0; i < Declare_list.size(); i++){
        branch.push_back(Declare_list[i]);
    }
    build_storage();
    // Node(Declare_list);
}


void Build_struct_Mips::build_storage(){
    NodePtr tmpnode;
    std::string tmptype;
    for (int i = 0; i < branch.size(); i++){
        //std::cout << "# <--------------------  building stcurt ---------------------->" << std::endl;
        if (branch[i]->is_Struct()){
            //struct { struct x, y, z;}
            for(int g = 1; g < branch[i]->get_size(); g++){
                tmpnode = branch[i]->get_branch(g);   
                inner_type_store.build_struct();     
                inner_type_store.add_content(tmpnode->get_Id(), tmpnode->get_type_storage());
      
            }
        }
        tmptype = branch[i]->get_branch(0)->get_type();
        for(int g = 1; g < branch[i]->get_size(); g++){
            tmpnode = branch[i]->get_branch(g);
            if(tmptype == "INT"){
                type_storage tmp("INT");
                inner_type_store.add_content(tmpnode->get_Id(), tmp);
            }
            //std::cout << "current size 4$" << inner_type_store.type_size << std::endl;
        }
    }
}
    
bool Build_struct_Mips::is_Struct () const{
    //std::cout << "# <-------------------- calliing the struct ---------------------->" << std::endl;
    return true;
}

type_storage Build_struct_Mips::get_type_storage(){
    return inner_type_store;
}

std::string Build_struct_Mips::get_type() const{
    return "STRUCT" + struct_name;
}

