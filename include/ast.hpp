#ifndef generic_ast_hpp
#define generic_ast_hpp
//Arithmetic
#include "AST/Arithmetic/ast_Addition_MIPS.hpp"
#include "AST/Arithmetic/ast_Arithmetic_MIPS.hpp"
#include "AST/Arithmetic/ast_BitAnd_MIPS.hpp"
#include "AST/Arithmetic/ast_BitOr_MIPS.hpp"
#include "AST/Arithmetic/ast_BitXor_MIPS.hpp"
#include "AST/Arithmetic/ast_Division_MIPS.hpp"
#include "AST/Arithmetic/ast_Equal_MIPS.hpp"
#include "AST/Arithmetic/ast_Greater_Than_MIPS.hpp"
#include "AST/Arithmetic/ast_Left_Shift_MIPS.hpp"
#include "AST/Arithmetic/ast_Less_Than_MIPS.hpp"
#include "AST/Arithmetic/ast_LogicAnd_MIPS.hpp"
#include "AST/Arithmetic/ast_LogicOr_MIPS.hpp"
#include "AST/Arithmetic/ast_Mod_MIPS.hpp"
#include "AST/Arithmetic/ast_Multiplication_MIPS.hpp"
#include "AST/Arithmetic/ast_NotEqual_MIPS.hpp"
#include "AST/Arithmetic/ast_Right_Shift.hpp"
#include "AST/Arithmetic/ast_Subtraction_MIPS.hpp"
#include "AST/Arithmetic/ast_Less_Than_Equal_MIPS.hpp"
#include "AST/Arithmetic/ast_Greater_Than_Equal_MIPS.hpp"

//Declaration
#include "AST/Declaration/ast_Declaration_MIPS.hpp"
#include "AST/Declaration/ast_Init_Declarator.hpp"
#include "AST/Declaration/ast_Global_Declaration_MIPS.hpp"
#include "AST/Declaration/ast_Declare_Array_MIPS.hpp"

// Function
#include "AST/Function/ast_Function_Declarator_MIPS.hpp"
#include "AST/Function/ast_Function.hpp"
#include "AST/Function/ast_Return_Mips.hpp"
#include "AST/Function/ast_FunctionCall_MIPS.hpp"


// Type
#include "AST/Type/ast_INT_CONSTANT_MIPS.hpp"
#include "AST/Type/ast_Type_MIPS.hpp"
#include "AST/Type/ast_Array_Access_Mips.hpp"
#include "AST/Type/ast_Array_Initializer_Mips.hpp"

//Selection
#include "AST/Selection/ast_Selection_statement_MIPS.hpp"

//Interation
#include "AST/Iteration/ast_For_MIPS.hpp"
#include "AST/Iteration/ast_While_MIPS.hpp"
//General
#include "AST/ast_IDENTIFIER_MIPS.hpp"
#include "AST/ast_Node.hpp"
#include "AST/ast_Context.hpp"
#include "AST/ast_Assignment_Expression_MIPS.hpp"
#include "AST/ast_Compound_statement_MIPS.hpp"
#include "AST/ast_Root_MIPS.hpp"

//SelfAssignment
#include "AST/SelfAssignment/ast_Post_Decrement_MIPS.hpp"
#include "AST/SelfAssignment/ast_Post_Increment_MIPS.hpp"
#include "AST/SelfAssignment/ast_Pre_Decrement_MIPS.hpp"
#include "AST/SelfAssignment/ast_Pre_Increment_MIPS.hpp"


extern const NodePtr parseAST(std::string filename);
#endif
