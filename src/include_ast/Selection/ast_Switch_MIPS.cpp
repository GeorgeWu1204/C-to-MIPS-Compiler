#include "AST/Selection/ast_Switch_MIPS.hpp"

//#include "AST/ast_Static_Class.hpp"
Switch_Mips::Switch_Mips(NodePtr Expression, NodePtr Statement)
{
    branch.push_back(Expression);
    branch.push_back(Statement);
}

void Switch_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // lw      $3,8($fp)
    // li      $2,3                        # 0x3
    // beq     $3,$2,$L2
    // nop

    // lw      $2,8($fp)
    // nop
    // slt     $2,$2,4
    // beq     $2,$0,$L3
    // nop

    // lw      $3,8($fp)
    // li      $2,2                        # 0x2
    // beq     $3,$2,$L4
    // nop

    // lw      $2,8($fp)
    // nop
    // slt     $2,$2,3
    // beq     $2,$0,$L3
    // nop

    // lw      $2,8($fp)
    // nop
    // beq     $2,$0,$L5
    // nop

    // lw      $3,8($fp)
    // li      $2,1                        # 0x1
    // beq     $3,$2,$L6
    // nop

    // b       $L3
    // nop

    // build switch vector

    // step 2 decide if case is empty

    // std::map<std::string, int> case_map;
    // case_map = branch[1]->return_case_address();
    // int result_address = branch[0]->return_dynamic_offset();
    // branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    // for (std::map<std::string, int>::iterator it = case_map.begin(); it != case_map.end(); ++it)
    // {
    //         dst << "li " << "$3, " << it->first << std::endl;
    //         dst << "beq" << "$3, " << "$" << destReg << ", " <<  it->second << std::endl;
    //         dst << "nop" << std::endl;
    // }
    // branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    context.Break_Label = make_name.makeName("L");
    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    int compound_size = branch[1]->get_size();
    switch_context = context;
    for (int i = 0; i < compound_size; i++)
    {
        NodePtr compound_pointer = branch[1]->get_branch(i);
        if (compound_pointer->is_Case())
        {
            dst << "li "
                << "$3," << compound_pointer->get_branch(0)->get_Val() << std::endl;
            std::string jump_label = make_name.makeName("L");
            switch_context.insert_Jump_Label(jump_label);
            dst << "beq "
                << "$3,"
                << "$" << destReg << "," << jump_label << std::endl;
            dst << "nop" << std::endl;
        }
        else if (compound_pointer->is_Default()) // sos
        {
            std::string jump_label = make_name.makeName("L");
            switch_context.insert_Jump_Label(jump_label);
            dst << "b " << jump_label << std::endl;
            dst << "nop" << std::endl;
        }
    }
    branch[1]->generateMips(dst, switch_context, destReg, make_name, dynamic_offset);
    dst << context.Break_Label << ": " << std::endl;
    // std::string Escape_label = make_name.makeName("L");
    // if (branch[1]->get_size() == 0)
    // {
    //     // no else if condition is 0, skip to the end of the selection statement.
    //     // do nothing here
    // }
    // else
    // {
    //     branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    //     branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    // }
}

bool Switch_Mips::is_Compound_statement() const
{
    std::cerr << "#"
              << "Switch is compound" << std::endl;
    return true;
}
bool Switch_Mips::is_Switch() const
{
    return true;
}

int Switch_Mips::get_context_local_size()
{
    return branch[1]->get_context_local_size();
}
std::vector<std::string> Switch_Mips::return_waiting_to_declared_list()
{
    return branch[1]->return_waiting_to_declared_list();
}

// void Selection_statement_Mips::update_local_var_waiting_for_call(Context &context)
// {
//     branch[0]->update_local_var_waiting_for_call(context);
//     branch[2]->update_local_var_waiting_for_call(context);
//     branch[1]->update_local_var_waiting_for_call(context);
// }
