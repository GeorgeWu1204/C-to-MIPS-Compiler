#include "AST/Iteration/ast_For_MIPS.hpp"

// sos
For_Mips::For_Mips(NodePtr Expression_term_1, NodePtr Expression_term_2, NodePtr Statement_term)
{
    branch.push_back(Expression_term_1);
    branch.push_back(Expression_term_2);
    branch.push_back(Statement_term);
    build_mock_compound();
}
For_Mips::For_Mips(NodePtr Expression_term_1, NodePtr Expression_term_2, NodePtr Expression_term_3, NodePtr Statement_term)
{
    branch.push_back(Expression_term_1);
    branch.push_back(Expression_term_2);
    branch.push_back(Expression_term_3);
    branch.push_back(Statement_term);
    build_mock_compound();
}

void For_Mips::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::string Condition_Label = make_name.makeName("L");
    std::string Evaluate_Label = make_name.makeName("L");
    if (branch.size() == 4)
    {
        branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        dst << "b"
            << "  " << Condition_Label << std::endl;
        dst << std::endl;
        dst << std::endl;
        // Evaluation part
        dst << Evaluate_Label << ":" << std::endl;
        // branch[2]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        branch[2]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        branch[3]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        dst << std::endl;
        dst << std::endl;
        // Condition part
        dst << Condition_Label << ":" << std::endl;
        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        // back to main
        dst << std::endl;
        dst << std::endl;
    }
    else
    {
        dst << "b"
            << "  " << Condition_Label << std::endl;
        dst << std::endl;
        dst << std::endl;
        // Evaluation part
        dst << Evaluate_Label << ":" << std::endl;

        branch[1]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        branch[2]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        dst << std::endl;
        dst << std::endl;
        // Condition part
        dst << Condition_Label << ":" << std::endl;
        branch[0]->generateMips(dst, context, destReg, make_name, dynamic_offset);
        //  back to main
        dst << std::endl;
        dst << std::endl;
    }
}

int For_Mips::get_context_local_size()
{
    return local_size;
}

bool For_Mips::is_Compound_statement() const
{
    return true;
}

std::vector<std::string> For_Mips::return_waiting_to_declared_list()
{
    return return_declare_list;
}

void For_Mips::build_mock_compound()
{

    Compound_statement_Mips *var = new Compound_statement_Mips(branch);
    local_size = var->get_context_local_size();
    return_declare_list = var->return_waiting_to_declared_list();
}
