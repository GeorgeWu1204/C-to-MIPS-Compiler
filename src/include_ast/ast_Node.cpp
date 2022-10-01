#include "AST/ast_Node.hpp"

Node::Node(std::vector<NodePtr> branch_input)
    : branch(branch_input)
{
}
Node::Node(NodePtr left_input, NodePtr middle_input, NodePtr right_input)
{
    branch.push_back(left_input);
    branch.push_back(middle_input);
    branch.push_back(right_input);
}

Node::Node(std::vector<NodePtr> left_input, std::vector<NodePtr> right_input)
{
    branch = left_input;
    for (int i = 0; i < right_input.size(); i++)
    {
        branch.push_back(right_input[i]);
    }
}

Node::Node()
    : branch(std::vector<NodePtr>())
{
}

std::string Node::get_Id() const
{
    std::cerr << "Tried to obtin not implemented content" << std::endl;
    return "False";
}
std::string Node::get_StringVal() const
{
    std::cerr << "Tried to obtin not implemented content" << std::endl;
    return "False";
}
std::string Node::get_type() const
{
    std::cerr << "Tried to obtin not implemented content" << std::endl;
    return "False";
}
int Node::get_Val() const
{
    std::cerr << "Tried to obtin not implemented content" << std::endl;
    return 0;
}
int Node::array_size() const{
    return 0;
}

bool Node::is_Ptr() const
{
    return false;
}

bool Node::is_Function() const
{
    return false;
}
bool Node::is_Function_inside() const
{
    return false;
}
bool Node::is_init() const
{
    return false;
}

bool Node::is_Declaration() const
{
    return false;
}

bool Node::is_Statement() const
{
    return false;
}
bool Node::is_Identifier() const
{
    return false;
}

bool Node::is_Constant() const
{
    return false;
}
bool Node::is_Array() const
{
    return false;
}
bool Node::is_Compound_statement() const
{
    return false;
}
bool Node::is_Mixed() const
{
    return false;
}

// branch size()
int Node::get_size() const
{
    return branch.size();
}

NodePtr Node::get_branch(int index) const
{
    return branch[index];
}

int Node::get_context_local_size()
{
    return 0;
}

void Node::generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset)
{
    std::cout << "cannot generate any MIPS code" << std::endl;
}

void Node::prettyPrint(std::ostream &dst) const
{
    std::cerr << "cannot generate any MIPS code" << std::endl;
}

void Node::build_local_context(Context &context)
{
}

std::vector<std::string> Node::return_waiting_to_declared_list()
{
    return std::vector<std::string>();
}

Node::~Node()
{
    for (int i = 0; i < branch.size(); i++)
    {
        delete branch[i];
    }
}

int Node::Dynamic_context_size()
{
    return 0;
    
}
int Node::return_dynamic_offset(){
    return 0;
}
int Node::get_argument_size()
{
    return 0;
}

std::map<std::string, std::string> Node::get_argument_map(){
    return std::map<std::string, std::string>();
}

std::vector<int> Node::return_assigned_val(){
    return std::vector<int>();
}


