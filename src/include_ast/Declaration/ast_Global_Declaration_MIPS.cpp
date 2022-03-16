
#include "AST/Declaration/ast_Global_Declaration_MIPS.hpp"



//note the function can be declared as int f(int x, int y); in the global scope. it can be called from the context directlhy.
Global_Declaration_Mips::Global_Declaration_Mips(const NodePtr specifier)
{
    branch.push_back(specifier);
}

void Global_Declaration_Mips::generateMips (std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset){
    std::vector<int> var = branch[0]->return_assigned_val();
    //branch[0] points to the new Declaration 

    // only shows the arrays that has been assigned.
    for(int m = 1; m < branch[0]->get_size(); m++){
        
        NodePtr point_to_list_element =  branch[0]->get_branch(m);
        if(point_to_list_element->is_init())
        {
            dst<< point_to_list_element->get_Id() << ":" << std::endl;
            std::cout << "Inside Init" << std::endl;
            if(point_to_list_element->is_Array()){    
                // x[7] ={}; 
                std::cout << "Inside Array" << std::endl;
                NodePtr Array_Init = point_to_list_element->get_branch(1);
                if(Array_Init->is_Array_Initializer()){
                    std::cout << "Inside is_Array_Initializer" << std::endl;
                    for(int r = 0; r < Array_Init->get_size(); r++){
                    dst << "        .word" << " " <<Array_Init->get_branch(r)->get_Val()<< std::endl;
                    }
                }
                
            }else if(point_to_list_element->is_Identifier()){
                std::cout << "Inside is_identified" << std::endl;
                NodePtr Init = point_to_list_element->get_branch(1);
                if(Init->is_Array_Initializer()){
                    dst << "        .word" << " " <<Init->get_branch(0)->get_Val()<< std::endl;
                }else{
                    dst << "        .word" << " " <<Init->get_Val()<< std::endl;
                }
            }
            //int x = {7} or int x = 7; 
        }
        else{
            dst << "gg" << std::endl;
            dst<< point_to_list_element->get_Id() << ":" << std::endl;
        }
        // branch[0] Declaration
                    // Type Init_Declarator_list      int x[9] = {1, 2},y[] = {6,7,8} , p[9] , u = 9;
                            //Declarator Declarator = Initializer
                                        //x         = { Initializer_list ',' }


        //to get every element inside the Init_declarator list int x, x = 9, int y = 8;
        //note here we assume we only assign to the last element declared in the variable.       
        if(point_to_list_element->get_Val()){
            //{1, 2, 3 }
        }
    }

    for (int i = 0; i < var.size(); i++){
        dst <<"      " << ".word" << "    " << var[i] << std::endl;
    }
}

int Global_Declaration_Mips::array_size() const{
    return branch[0]->array_size();
}

std::string Global_Declaration_Mips::get_Id() const{
    // return branch[0]->get_Id();
    return "invalid to get id from a list";
}

std::string Global_Declaration_Mips::get_type() const{
    return branch[0]->get_type();
}

