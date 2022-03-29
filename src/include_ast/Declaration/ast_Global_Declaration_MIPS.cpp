
#include "AST/Declaration/ast_Global_Declaration_MIPS.hpp"

// note the function can be declared as int f(int x, int y); in the global scope. it can be called from the context directlhy.
Global_Declaration_Mips::Global_Declaration_Mips(const NodePtr declaration)
{
    branch.push_back(declaration);
}

void Global_Declaration_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{

    
            std::vector<int> var; // this is use to store array constant if exited
            std::string type = branch[0]->get_type();
            int identifier_size;
            if (type == "INT")
            {
                identifier_size = 4;
            }
            else if (type == "DOUBLE")
            {
                identifier_size = 8;
            }
            else if (type == "FLOAT")
            {
                identifier_size = 4;
            }
            // only shows the arrays that has been assigned.    // int x, x=2, x=20;
            for (int m = 1; m < branch[0]->get_size(); m++)
            {
                std::string type = branch[0]->get_type();
                NodePtr point_to_list_element = branch[0]->get_branch(m);
                if (point_to_list_element->is_init())
                {
                    if (point_to_list_element->is_Array())
                    {
                        var = point_to_list_element->return_assigned_val();
                        dst << ".globl " << point_to_list_element->get_Id() << std::endl;
                        dst << ".data " << std::endl;
                        dst << ".size " << point_to_list_element->get_Id() << "," << identifier_size * point_to_list_element->get_arithmetic_const_val() << std::endl;
                        if(type == "INT"){
                            dst << point_to_list_element->get_Id() << ":" << std::endl;
                            NodePtr Array_Init = point_to_list_element->get_branch(1);
                            if (Array_Init->is_Array_Initializer())
                            {
                                //    std::cerr << "#" << "Inside is_Array_Initializer" << std::endl;
                                for (int r = 0; r < Array_Init->get_size(); r++)
                                {
                                    dst << "        .word"
                                        << " " << Array_Init->get_branch(r)->get_Val() << std::endl;
                                }
                            }
                        }
                        else if (type == "DOUBLE"){
                            dst << point_to_list_element->get_Id() << ":" << std::endl;
                            NodePtr Array_Init = point_to_list_element->get_branch(1);
                            if (Array_Init->is_Array_Initializer())
                            {
                                //    std::cerr << "#" << "Inside is_Array_Initializer" << std::endl;
                                for (int r = 0; r < Array_Init->get_size(); r++)
                                {
                                    dst << "        .double"
                                        << " " << Array_Init->get_branch(r)->get_Float() << std::endl;
                                }
                            }
                        }
                        else if (type == "FLOAT"){
                            dst << point_to_list_element->get_Id() << ":" << std::endl;
                            NodePtr Array_Init = point_to_list_element->get_branch(1);
                            if (Array_Init->is_Array_Initializer())
                            {
                                //    std::cerr << "#" << "Inside is_Array_Initializer" << std::endl;
                                for (int r = 0; r < Array_Init->get_size(); r++)
                                {
                                    dst << "        .float"
                                        << " " << (float)Array_Init->get_branch(r)->get_Float() << std::endl;
                                }
                            }
                        }
                        
                        
                    }
                else if (point_to_list_element->is_Identifier())
                {
                    // std::cerr << "#" << "Inside is_identified" << std::endl;
                    dst << ".globl " << point_to_list_element->get_Id() << std::endl;
                    dst << ".data " << std::endl;
                    dst << ".size "
                        << "x," << identifier_size << std::endl;
                    dst << point_to_list_element->get_Id() << ":" << std::endl;
                    NodePtr Init = point_to_list_element->get_branch(1);
                    if (Init->is_Array_Initializer())
                    {
                        dst << "        .word"
                            << " " << Init->get_branch(0)->get_Val() << std::endl;
                    }
                    else if(type == "FLOAT")
                    {
                        dst << "        .float"
                            << " " << Init->get_Float() << std::endl;
                    }
                    else if(type == "DOUBLE"){
                        dst << "        .double"
                            << " " << Init->get_Float() << std::endl;
                    }
                    else{
                        //INT 
                        dst << "        .word"
                            << " " << Init->get_Val() << std::endl;
                    }
                }
                // int x = {7} or int x = 7;
            }
            else if (point_to_list_element->is_Function())
            {
                std::cerr << "#"
                        << "Is a function declaration" << std::endl;
            }
            else
            {
                //  declaration without initialization
                if (point_to_list_element->is_Identifier())
                {
                    dst << ".globl " << point_to_list_element->get_Id() << std::endl;
                    dst << ".data " << std::endl;
                    dst << ".size " << point_to_list_element->get_Id() << identifier_size << std::endl;
                    dst << point_to_list_element->get_Id() << ":" << std::endl;
                    dst << ".space " << identifier_size << std::endl;
                }
                else if (point_to_list_element->is_Array())
                {
                    dst << ".globl " << point_to_list_element->get_Id() << std::endl;
                    dst << ".data " << std::endl;
                    dst << ".size " << point_to_list_element->get_Id() << "," << identifier_size * point_to_list_element->get_arithmetic_const_val() << std::endl;
                    dst << point_to_list_element->get_Id() << ":" << std::endl;
                    dst << ".space " << identifier_size * point_to_list_element->get_arithmetic_const_val() << std::endl;
                }
            }
            if (point_to_list_element->get_Val())
            {
                //{1, 2, 3 }
            }
        }

        for (int i = 0; i < var.size(); i++)
        {
            dst << "      "
                << ".word"
                << "    " << var[i] << std::endl;
        }
    }
    


int Global_Declaration_Mips::array_size() const
{
    return branch[0]->array_size();
}

std::string Global_Declaration_Mips::get_Id() const
{
    // return branch[0]->get_Id();
    return "invalid to get id from a list";
}

std::string Global_Declaration_Mips::get_type() const
{
    return branch[0]->get_type();
}
std::map<std::string, int> Global_Declaration_Mips::get_enumerator_list()
{
    return branch[0]->get_enumerator_list();
}
bool Global_Declaration_Mips::is_Enum() const
{
    return branch[0]->is_Enum();
}
bool Global_Declaration_Mips::is_Struct() const
{
    return branch[0]->is_Struct();
}
bool Global_Declaration_Mips::is_Struct_Declaration() const
{
    return branch[0]->is_Struct_Declaration();
}

type_storage Global_Declaration_Mips::get_type_storage (){
    return branch[0]->get_type_storage();
} 

std::vector<FloatDoubleConst> Global_Declaration_Mips::get_Float_Const(){
    return branch[0]->get_Float_Const();
}
std::vector<std::string> Global_Declaration_Mips::get_String_Const(){
    return branch[0]->get_String_Const();
}

bool Global_Declaration_Mips::is_Array() const
{
    return branch[0]->is_Array();
}

bool Global_Declaration_Mips::is_init() const{
    return branch[0]->is_init();
}