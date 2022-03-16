
#include "AST/Selection/ast_Selection_statement_MIPS.hpp"
//#include "AST/ast_Static_Class.hpp"
Selection_statement_Mips::Selection_statement_Mips(NodePtr condition_expression, NodePtr statement_1)
{
    branch.push_back(condition_expression);
    branch.push_back(statement_1);
    branch.push_back(new Node());
}

Selection_statement_Mips::Selection_statement_Mips(NodePtr condition_expression, NodePtr statement_1, NodePtr statement_2)
{
    branch.push_back(condition_expression);
    branch.push_back(statement_1);
    branch.push_back(statement_2);
}

int Selection_statement_Mips::get_context_local_size()
{
    // why branch[0]没有？？？ declare in branch[0]
    //std::cout << "Size of branch main " << branch[1]->get_context_local_size() << std::endl;
    //std::cout << "Size of branch else " <<  branch[2]->get_context_local_size() << std::endl;
    return branch[1]->get_context_local_size() + branch[2]->get_context_local_size();
}

void Selection_statement_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    // dst << "In Selection Statement" << std::endl;

    // lw      $3,12($fp)

    // li      $2,1
    // bne     $3,$2,$L2
    // nop
    //

    // lw      $2,12($fp)
    // nop
    // beq     $2,$0,$L2
    // nop
    branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
    if (branch[1]->get_size() == 0)
    {
        // no else if condition is 0, skip to the end of the selection statement.
        std::string Escape_label = make_name.makeName("L");
        dst << "beq "
            << "$ " << destReg << ", "
            << "$0 "
            << Escape_label << std::endl;
        dst << "nop" << std::endl;
        dst << std::endl;
        dst << std::endl;

        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);

        dst << std::endl;
        dst << std::endl;
        dst << Escape_label << ":" << std::endl;
    }
    else
    {
        // with else
        // if condition is zero, jump to else
        std::string Escape_label = make_name.makeName("L");
        std::string Else_lable = make_name.makeName("L");
        dst << "beq "
            << "$ " << destReg << ", "
            << "$0 "
            << Else_lable << std::endl;
        dst << "nop" << std::endl;
        dst << std::endl;
        dst << std::endl;

        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);

        dst << std::endl;
        dst << std::endl;
        dst << Else_lable << ":" << std::endl;

        // dst << "get size" << branch[2]->get_size() << std::endl;

        branch[2]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        dst << std::endl;
        dst << std::endl;
        dst << Escape_label << ":" << std::endl;
    }

    // std::string L = makeName("zero");
    // dst << L << ":" << std::endl;

    // std::string L = makeName("zero");
    // dst << L << ":" << std::endl;
}

std::vector<std::string> Selection_statement_Mips::return_waiting_to_declared_list()
{
    std::vector<std::string>  declared_list;
    for(int i =0; i < branch[0]->return_waiting_to_declared_list().size() ; i++ ){
        declared_list.push_back((branch[0]->return_waiting_to_declared_list())[i]);
    }
    for(int i =0; i < branch[1]->return_waiting_to_declared_list().size() ; i++ ){
        declared_list.push_back((branch[1]->return_waiting_to_declared_list())[i]);
    }
    for(int i =0; i < branch[2]->return_waiting_to_declared_list().size() ; i++ ){
        declared_list.push_back((branch[2]->return_waiting_to_declared_list())[i]);   
    }
    return declared_list;
    
    // std::vector<std::string> Expression_B = branch[0]->return_waiting_to_declared_list();

    // std::vector<std::string> If_A = branch[1]->return_waiting_to_declared_list();

    // std::vector<std::string> If_B = branch[2]->return_waiting_to_declared_list();

    // If_A.insert(If_A.end(), If_B.begin(), If_B.end());

    // Expression_B.insert(Expression_B.end(), If_A.begin(), If_A.end());

    // return Expression_B;
}


bool Selection_statement_Mips::is_Compound_statement() const
{
    std::cout << "SelectionStatement is compound" << std::endl;
    return true;
}

// void Selection_statement_Mips::update_local_var_waiting_for_call(Context &context)
// {
//     branch[0]->update_local_var_waiting_for_call(context);
//     branch[2]->update_local_var_waiting_for_call(context);
//     branch[1]->update_local_var_waiting_for_call(context);
// }
