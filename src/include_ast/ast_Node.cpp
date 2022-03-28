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

// std::vector<std::string> Node::get_Id() const
// { // used for debug here
//     return std::vector<std::string>();
// }

std::string Node::get_Id() const
{
    std::cerr << "#"
              << "Tried to obtain not implemented content1" << std::endl;
    // used for debug here
    return "#False";
}
std::string Node::get_StringVal() const
{
    std::cerr << "#Tried to obtin not implemented content2" << std::endl;
    return "#False";
}
std::string Node::get_type() const
{
    std::cerr << "#Tried to obtin not implemented content3" << std::endl;
    return "#False";
}
int Node::get_Val() const
{
    std::cerr << "#Tried to obtin not implemented content4" << std::endl;
    return 0;
}
int Node::array_size() const
{
    return 0;
}

bool Node::is_Ptr() const
{
    return false;
}

bool Node::is_Function() const
{
    // Function declaration and function call;
    return false;
}
bool Node::is_Function_Def() const
{
    return false;
}
bool Node::is_Function_inside() const
{
    // property of compound
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
bool Node::is_Enum() const
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

bool Node::is_Array_Initializer() const
{
    return false;
}
bool Node::is_Mixed() const
{
    return false;
}

bool Node::is_Jump_statement() const
{
    return false;
}

bool Node::is_Break() const
{
    return false;
}

bool Node::is_Continue() const
{
    return false;
}

bool Node::is_Pointer() const
{
    return false;
}

bool Node::is_Struct() const
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
    std::cerr << "#"
              << "cannot generate any MIPS code" << std::endl;
}
void Node::generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type)
{
    std::cerr << "#"
              << "cannot generate any MIPS code" << std::endl;
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
bool Node::is_Conditional_Expression() const
{
    return false;
}
int Node::Dynamic_context_size()
{
    return 0;
}
int Node::return_dynamic_offset()
{
    return 0;
}
int Node::get_argument_size()
{
    return 0;
}
std::map<std::string, int> Node::get_enumerator_list()
{
    return std::map<std::string, int>();
}
std::vector<std::pair<std::string, std::string> > Node::get_argument_map()
{
    return std::vector<std::pair<std::string, std::string> >();
}
std::vector<int> Node::return_assigned_val()
{
    return std::vector<int>();
}
int Node::get_case_index()
{
    return 0;
}
// std::map<std::string, int> return_case_address(){
//     return std::map<std::string, int> ();
// }

bool Node::is_Case() const
{
    return false;
}
bool Node::is_Switch() const
{
    return false;
}
bool Node::is_Loop() const
{
    return false;
}

bool Node::is_Default() const
{
    return false;
}

bool Node::is_Assignment() const
{
    return false;
}
bool Node::is_Type_Specified() const{
    return false;
}

int Node::get_arithmetic_const_val()
{
    return 0;
}

type_storage Node::get_type_storage()
{
    type_storage var("false");
    return var;
}

bool Node::is_Struct_Declaration() const
{
    return false;
}

bool Node::is_Struct_Call() const
{
    return false;
}
std::vector<std::pair<std::string, std::string> > Node::read_Local_Var_Waiting_For_Sizing()
{
    return std::vector<std::pair<std::string, std::string> >();
}

int Node::get_struct_variable_offset(Context input)
{
    return 0;
}
std::vector<FloatDoubleConst> Node::get_Float_Const()
{
    return std::vector<FloatDoubleConst>();
}
bool Node::is_Double_Constant() const
{
    return false;
}
bool Node::is_Float_Constant() const
{
    return false;
}
double Node::get_Float() const
{}

std::string Node::get_cloest_Id() const
{
    return "# Tried to obtain sth not exited";
}

std::vector<std::string> Node:: get_String_Const(){
    return std::vector<std::string>();
}

std::string Node::return_expression_type(Context context)
{
    std::cout << "#Tried to obtain not implemented overaall type " << std::endl;
}