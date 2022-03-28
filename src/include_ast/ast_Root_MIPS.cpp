#include "AST/ast_Root_MIPS.hpp"

Root_Mips::Root_Mips(std::vector<NodePtr> root_input)
    : Node(root_input)
{
    build_global_context();
    build_Float_str();
    
}
void Root_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    build_String_str(make_name);
    context.replace_global_var(Global_context);
    context.Type_Str = tmp_store_str;
    context.Float_const_str = float_const_store;
    context.assign_label_float_const_str(make_name);
    context.String_str = String_const_store;
    // generate declared string
    //std::cout << "inside root" << std::endl;
    for (std::map<std::string, std::string>::iterator it = String_const_store.begin(); it != String_const_store.end(); ++it){
        dst << "$" << it->second << ":" << std::endl;
        dst << "      .ascii " << " \"" << it->first << "\\" <<  "000" << "\"" << std::endl;
        dst << ".align  2" << std::endl;
    }
    

    //std::cout << "confirm"<< std::endl;
    //context.Type_Str.find("STRUCTx")->second.print_content();
    //std::cout << "test 2<<< " << context.Type_Str.find("STRUCTx")->second.type_size << std::endl;
    //std::cout << "test 4<<< " << tmp_store_str.find("STRUCTx")->second.type_size << std::endl;
    // context.print_global();
    for (int i = 0; i < branch.size(); i++)
    {
        std::cerr << "#"
                  << " Generate the first mip" << std::endl;
        branch[i]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    }
    //now print the $LC

    if(context.Float_const_str.size() != 0){
        for(std::map<double, FloatDoubleConst>::iterator it = context.Float_const_str.begin(); it != context.Float_const_str.end(); ++it)
        {
            dst << "$" << it->second.Label_val << ":" <<std::endl;
            if(it->second.type =="FLOAT"){
                dst << "     " << ".float   " <<  float(it->first) << std::endl;
            }
            else if( it->second.type == "DOUBLE"){
                dst << "      " << ".double   " << it->first << std::endl; 
            }
        }
    }
}

// int f(int u),h(int x);
void Root_Mips::build_global_context()
{
    for (int i = 0; i < branch.size(); i++)
    {
        if(branch[i]->is_Function_Def() == true){
            std::string func_type = branch[i]->get_type();
            Global_var tmp (func_type);
            Global_context.insert(std::make_pair(branch[i]->get_Id(), func_type));
        }
        else{

            if (branch[i]->is_Function() == false)
            {
                if (branch[i]->is_Struct())
                {
                    //std::cout << "inside root struct" << std::endl;
                    type_storage tmp_str = branch[i]->get_type_storage();
                    //tmp_str.print_content();
                    tmp_store_str.insert(std::make_pair(branch[i]->get_type(), tmp_str));
                    //std::cout << "test "<< branch[i]->get_type() << std::endl;
                }
                else
                {

                    if (branch[i]->is_Enum())
                    {
                        // declaration and type is enum
                        // enum color {BLUE} i,k,o;
                        // std::cerr << "inside enum" << std::endl;
                        std::map<std::string, int> enumerator_map;
                        enumerator_map = branch[i]->get_enumerator_list();
                        if (enumerator_map.size() != 0)
                        {
                            for (std::map<std::string, int>::const_iterator it = enumerator_map.begin(); it != enumerator_map.end(); ++it)
                            {
                                // std::cerr << "map---" << std::endl;
                                // std::cerr << it->first << "|" << it->second << std::endl;
                                Global_var var(it->second);
                                Global_context.insert(std::make_pair(it->first, var));
                            }
                        }
                        // /enum color {BLUE} i,k,o;
                        for (int g = 1; g < branch[i]->get_size(); g++)
                        {
                            NodePtr tmp = branch[i]->get_branch(g);
                            std::cerr << "inside global " << i << std::endl;
                            std::cerr << "#"
                                    << "property    " << tmp->get_type() << " | " << branch[i]->array_size() << std::endl;
                            Global_var var(tmp->get_type(), 4);
                            Global_context.insert(std::make_pair(tmp->get_Id(), var));
                        }
                    }
                    for (int g = 1; g < branch[i]->get_size(); g++)
                    {
                        NodePtr tmp = branch[i]->get_branch(g);
                        std::cerr << "inside global " << i << std::endl;
                        std::cerr << "#"
                                << "property    " << tmp->get_type() << " | " << branch[i]->array_size() << std::endl;
                        Global_var var(tmp->get_type(), branch[i]->array_size());
                        Global_context.insert(std::make_pair(tmp->get_Id(), var));
                    }
                }
            }
        }
    }
}


void Root_Mips::build_Float_str(){
    //std::cout<< "build_float in root start" << std::endl;
    for (int i = 0 ; i < branch.size(); i ++){
        std::vector<FloatDoubleConst> tmp_v = branch[i]->get_Float_Const();
        for ( int g = 0; g < tmp_v.size(); g++){
            //std::cout << "back" << i << std::endl;
            FloatDoubleConst final_val (tmp_v[g].type);
            float_const_store.insert(std::make_pair(tmp_v[g].value, final_val));
        }
    }

}


void Root_Mips::build_String_str(MakeName &make_name){
    std::vector<std::string> tmp;
    std::string tmp_label;
    for (int m = 0; m < branch.size(); m++){
        tmp = branch[m]->get_String_Const();
        for (int h = 0; h < tmp.size(); h++){
            tmp_label = make_name.makeName("LC");
            String_const_store.insert(std::make_pair(tmp[h], tmp_label));
        }

    }
}