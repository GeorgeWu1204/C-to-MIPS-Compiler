#ifndef ast_Node_hpp
#define ast_Node_hpp
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "ast_Context.hpp"
#include "ast_makeName.hpp"

class Node;

typedef Node *NodePtr;

class Node
{
protected:
    std::vector<NodePtr> branch;
    // ensure inherited class can access it.
public:
    Node(std::vector<NodePtr> branch_input);
    Node(std::vector<NodePtr> left_input, std::vector<NodePtr> right_input);

    Node(NodePtr left_input, NodePtr middle_input, NodePtr right_input);
    Node();

    // Node(NodePtr leftinput, NodePtr rightinput);
    // not sure Node()  Node(vector<NodePtr> v1, vector<NodePtr> v2) used in sequence
    virtual std::string get_Id() const;
    virtual std::string get_type() const;
    virtual int array_size() const;
    // get type specifier INT
    virtual int get_Val() const;
    virtual std::string get_StringVal() const;
    
    virtual bool is_Ptr() const;
    virtual bool is_Function() const;
    virtual bool is_Constant() const;
    virtual bool is_Identifier() const;
    virtual bool is_Array() const;


    // stack implementation
    virtual bool is_Function_inside() const;
    virtual int get_size() const;

    // initialized
    virtual bool is_init() const;
    // check if it is declaration
    virtual bool is_Declaration() const;
    // check if it is statement
    virtual bool is_Statement() const;
    virtual bool is_Compound_statement() const;
    virtual bool is_Mixed() const;
    
    virtual NodePtr get_branch(int index) const;

    virtual ~Node();
    //! Tell and expression to print itself to the given stream

    virtual void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset);
    // SOS
    virtual void prettyPrint(std::ostream &dst) const;
    // build local context
    virtual void build_local_context(Context &context);
    //
    virtual int get_context_local_size();


    // return upward
    virtual std::vector<std::string> return_waiting_to_declared_list();

    virtual int Dynamic_context_size();
    virtual int  return_dynamic_offset();
    virtual int get_argument_size();

    virtual std::map<std::string, std::string> get_argument_map();
    
    virtual std::vector<int> return_assigned_val();

};

#endif