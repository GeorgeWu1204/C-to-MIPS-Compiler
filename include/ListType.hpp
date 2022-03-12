#ifndef ListType_hpp
#define ListType_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "AST/ast_Node.hpp"

typedef std::vector<NodePtr> build_vector;
// this is used to build a new NodePtr vector
typedef build_vector *ListTypePtr;
// define a pointer to the vector

inline ListTypePtr build_new_list (NodePtr input){
    ListTypePtr result = new build_vector;
    result->push_back(input);
    return result;
}

inline ListTypePtr add_to_list (ListTypePtr origin, NodePtr input){
    origin->push_back(input);
    return origin;
}





#endif