%code requires{
  #include "../include/ast.hpp"
  #include "../include/ListType.hpp"
  #include <cassert>
  extern NodePtr g_root; // A way of getting the AST out
  extern FILE *yyin;

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

%union{
  NodePtr top;
  ListTypePtr list;
  //double double_number;
  int int_number;
  std::string *string;
  yytokentype token;
  //????
}

  

%token CONSTANT FLOAT_CONSTANT 


%token IDENTIFIER INT_CONSTANT STRING_LITERAL SIZEOF 
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME 

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN


%type <top> Expression Postfix_expression Primary_expression Constant_expression
%type <top> And_expression Xor_expression Or_expression  Shift_expression
%type <top> Assignment_expression Unary_expression Multiplicative_expression Cast_expression Additive_expression 
%type <top> Relational_expression Logical_and_expression Logical_or_expression Equality_expression Conditional_expression
%type <top> Declarator Declaration_specifiers Direct_declarator  Declaration  Init_declarator Initializer 
%type <top> Function_definition 
%type <top> Selection_statement Iteration_statement
%type <top> Statement Compound_statement Expression_statement Jump_statemnet
%type <top> External_declaration ROOT
%type <top> Parameter_declaration
%type <top> Enumerator Enum_specifier


%type <int_number> INT_CONSTANT
//sos
%type <string> IDENTIFIER STRING_LITERAL Type_specifier Unary_operator

%type <list> Declaration_list Init_declarator_list Initializer_list Statement_list Argument_expression_list Translation_unit Identifier_list Parameter_list Parameter_type_list Enumerator_list


%start ROOT

%%
ROOT 
  : Translation_unit { g_root = new Root_Mips(*$1);}
  ;

Translation_unit
  : External_declaration                                            {$$ = build_new_list($1);}
  | Translation_unit External_declaration                           {$$ = add_to_list($1,$2);}
  ;

External_declaration
  : Function_definition                                             {$$ = $1;}
  | Declaration                                                     {std::cout << std::endl; std::cout <<"Parser "<< "76" << " Global" << std::endl;$$ = new Global_Declaration_Mips($1);std::cout << "done" << std::endl;}
  ;

//function definition or declaration globally;
Function_definition
  : Declaration_specifiers Declarator Compound_statement             {std::cout << std::endl; std::cout <<"Parser "<< "81" << " Function" << std::endl;$$ = new Function(new Declaration_Mips($1, $2), $3);std::cout << "done" << std::endl;}//int variable() {...}
	//| Declaration_specifiers Declarator Declaration_list Compound_statement     {std::cout << "" << std::endl;}      //int Variable int a,b,c; {...}
	//| Declarator Declaration_list Compound_statement                                //int int a,b,c; {...}
	//| Declarator Compound_statement                                                   {}//Variable() {...}           
	;

Declaration_specifiers
  : Type_specifier                                                   {$$ = new Type_Mips(*$1);}
	/* | Storage_class_specifier
	| Storage_class_specifier declaration_specifiers
	| Type_specifier Declaration_specifiers
	| Type_qualifier
	| Type_qualifier Declaration_specifiers */
	;
  
Type_specifier
	: INT                                                              {std::cout<< std::endl; std::cout<< "Parser" << " 96 " << "int detected "<< std::endl; $$ = new std::string("INT");  std::cout<< "int detected"<< std::endl;}
	/* | CHAR
	| SHORT
	| VOID
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME */
	;

// variable Name
Declarator                                                           
	: Direct_declarator                                                 {std::cout <<"gg" << std::endl; $$ = $1;}
//| Pointer Direct_declarator                                         {std::cerr << " Diclerator_Mips Unsupported" << std::endl;}
	;


Direct_declarator                                    
	: IDENTIFIER                                                        {std::cout << std::endl;std::cout <<"Parser "<< "114" << " IDENTIFIER" << std::endl; $$ = new Identifier_Mips(*$1);}//  Variable
	| '(' Declarator ')'                                                {std::cerr << " Diclerator_Mips Unsupported" << std::endl;}//$$ = new Declarator_Mips($2);}// (Variable())                                                                      
  | Direct_declarator '(' ')'                                         {std::cout << std::endl;std::cout <<"Parser "<< "116" << " Function_Declarator" << std::endl; $$ = new Function_Declarator_Mips($1);}
  //| Declarator  SOS
  
	| Direct_declarator '[' Constant_expression ']'                     {std::cout << std::endl;std::cout <<"Parser "<< "196" << " array_Declarator_with_param" << std::endl; $$ = new Declare_Array_Mips($1, $3);}
	| Direct_declarator '[' ']'                                         {std::cout << std::endl;std::cout <<"Parser "<< "196" << " array_Declarator" << std::endl; $$ = new Declare_Array_Mips($1);}
	| Direct_declarator '(' Parameter_type_list ')'                     {std::cout << std::endl;std::cout <<"Parser "<< "116" << " Function_Declarator_with_param" << std::endl; $$ = new Function_Declarator_Mips($1, *$3);}
	/* | Direct_declarator '(' Identifier_list ')' sos */
	;

Parameter_type_list
	: Parameter_list                                                    {$$ = $1;} //sos
	/* | Parameter_list ',' ELLIPSIS */
	;
Parameter_list
	: Parameter_declaration                                             {$$ = build_new_list($1);}
	| Parameter_list ',' Parameter_declaration                          {$$ = add_to_list($1, $3);}
	;
Parameter_declaration
	: Declaration_specifiers Declarator                                 {$$ = new Declaration_Mips($1, $2);}
	/* | declaration_specifiers abstract_declarator
	| declaration_specifiers */
	;
Identifier_list
	: IDENTIFIER                                                        {$$ = build_new_list($1);}
	| Identifier_list ',' IDENTIFIER                                    {$$ = add_to_list($1, $3);}
	;

Constant_expression
  : Conditional_expression                                            {$$ = $1;}
	;

Compound_statement
  : '{' '}'                                                           {$$ = new Compound_statement_Mips();}       // sos
  | '{' Statement_list '}'                                            {std::cout << std::endl;std::cout <<"Parser "<< "131" << " Compound_statement_Statement  " << std::endl; $$ = new Compound_statement_Mips(*$2);std::cout<< "compond work" << std::endl;}
  | '{' Declaration_list  '}'                                         {std::cout << std::endl;std::cout <<"Parser "<< "132" << " Compound_statement_Declaration" << std::endl; $$ = new Compound_statement_Mips(*$2); std::cout<< "compond work" << std::endl;}// {int a,b,c; int d,f,g;}
  | '{' Declaration_list Statement_list '}'                           {std::cout << std::endl;std::cout <<"Parser "<< "133" << " Compound_statement_Declaration_AND_Statement" << std::endl;$$ = new Compound_statement_Mips(*$2, *$3); std::cout<< "compond work" << std::endl;} // {int a,b,c; a=b+c;}
  ;

//  Declaration int a, b, c;
Declaration_list                                                      
	: Declaration                                                       {$$ = build_new_list($1);}                                                                  // this is used to build a new list
	| Declaration_list Declaration                                      {$$ = add_to_list($1,$2);}//int a, b, c; int a, b, c; int a, b, c;
                                                                      // this is used to add on to the original list.
  ;
  
Declaration
	: Declaration_specifiers ';'                                        {std::cerr << "Unsupported" << std::endl;}//  so far this is just int; //sos
	| Declaration_specifiers Init_declarator_list ';'                   {$$ = new Declaration_Mips($1, *$2);}//  int a,b,c;
  //sosososososossosososo
  ;

//init_declarator_list varible, variable, variable
Init_declarator_list                                                   
	: Init_declarator                                                   {$$ = build_new_list($1);}
	| Init_declarator_list ',' Init_declarator                          {$$ = add_to_list($1, $3);}
	;


Init_declarator                                                        
	: Declarator                                                        {$$ = $1;}
	| Declarator '=' Initializer                                        {std::cout << std::endl;std::cout <<"Parser "<< "158" << " Init_Declarator" << std::endl;$$ = new Init_Declarator_Mips($1,$3);} //declarator: Variable "=" [a = a + b]
  //check int a = b = 5;
  ;
                                                                      // int x[7] = 1; x[7] = 4;
Initializer                                               
	: Assignment_expression                                             {$$ = $1;}  // a = assignment || a>b
	| '{' Initializer_list '}'                                          {$$ = new Array_Initializer_Mips(*$2);}  //  a[2][2] = {{'1', '2'}, {'2', '3'}}
  | '{' Initializer_list ',' '}'                                      {$$ = new Array_Initializer_Mips(*$2);}  // char a[3] = {'a', 'b'};
  ;
                                                                      // std::vector<NodePtr> * 
Initializer_list                                  
  : Initializer                                                       {$$ = build_new_list($1);}//std::cerr << "Unsupported" << std::endl;} // a>b
	| Initializer_list ',' Initializer                                  {$$ = add_to_list($1, $3);}         //{{2,4},3}
	;


Enum_specifier  
	: ENUM '{' Enumerator_list '}'                                      {$$ = new Enum_specifier_Mips(*$3);}
	| ENUM IDENTIFIER '{' Enumerator_list '}'                           {$$ = new Enum_specifier_Mips(*$2, *$4);}
	| ENUM IDENTIFIER                                                   {$$ = new Enum_specifier_Mips(*$2);}
	;

Enumerator_list
	: Enumerator                                                        {$$ = build_new_list($1);}
	| Enumerator_list ',' Enumerator                                    {$$ = add_to_list($1, $3);}
	;

Enumerator
	: IDENTIFIER                                                        {$$ = new Enumerator_Mips(*$1);}
	| IDENTIFIER '=' Constant_expression                                {$$ = new Enumerator_Mips(*$1, $3);}
	;


Statement 
  : Compound_statement                                                {std::cout << std::endl;std::cout <<"Parser "<< "175" << " CompoundStatement" << std::endl;$$ = $1;}
  | Expression_statement                                              {std::cout << std::endl;std::cout <<"Parser "<< "176" << " ExpressionStatement" << std::endl;$$ = $1;}
  | Selection_statement                                               {std::cout << std::endl;std::cout <<"Parser "<< "177" << " SelectionStatement" << std::endl;$$ = $1;}
  | Iteration_statement                                               {std::cout << std::endl;std::cout <<"Parser "<< "178" << " IterationStatement" << std::endl;$$ = $1;}
  | Jump_statemnet                                                    {std::cout << std::endl;std::cout <<"Parser "<< "179" << " JumpStatement" << std::endl;$$ = $1;}
  ;

Expression 
  :  Assignment_expression                                            {std::cout << std::endl;std::cout <<"Parser "<< "183" << "Assignement Expression" << std::endl; $$ = $1;}
  |  Expression ',' Assignment_expression                             {std::cerr << "Unsupported" << std::endl;}
  ;


Assignment_expression
  : Unary_expression '='          Assignment_expression                {$$ = new Assignment_Expression_Mips($1,$3);}
	| Unary_expression MUL_ASSIGN   Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new Multiplication_MIPS($1, $3));}
	| Unary_expression DIV_ASSIGN   Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new Division_MIPS($1, $3));}
	| Unary_expression MOD_ASSIGN   Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new Mod_MIPS($1, $3));}
	| Unary_expression ADD_ASSIGN   Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new Addition_MIPS($1, $3));}
	| Unary_expression SUB_ASSIGN   Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new Subtraction_MIPS($1, $3));}
	| Unary_expression LEFT_ASSIGN  Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new Left_Shift_MIPS($1, $3));}
	| Unary_expression RIGHT_ASSIGN Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new Right_Shift_MIPS($1, $3));}
	| Unary_expression AND_ASSIGN   Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new BitAnd_MIPS($1, $3));}
	| Unary_expression XOR_ASSIGN   Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new BitXor_MIPS($1, $3));}
	| Unary_expression OR_ASSIGN    Assignment_expression                {$$ = new Assignment_Expression_Mips($1, new BitOr_MIPS($1, $3));}
  | Conditional_expression                                             {$$ = $1;} 
	;


//Variable Constant Identity

Unary_expression                                                        
	: Postfix_expression                                                  {std::cout << std::endl;std::cout <<"Parser "<< "209" << " Unary_expression" << std::endl; $$ = $1;}
	| INC_OP Unary_expression                                             {$$ = new Pre_Increment_MIPS($2);}//$$ = Inc_Unary}}
  //++
  | DEC_OP Unary_expression                                             {$$ = new Pre_Decrement_MIPS($2);}
  //--
  | Unary_operator Cast_expression                                      {std::cout << "Unsupported 3" << std::endl;}
  | SIZEOF Unary_expression                                             {std::cout << "Unsupported 4" << std::endl;}
  ;  

Unary_operator
	: '&'                                                                 {$$ = new std::string("&");}
	| '*'                                                                 {$$ = new std::string("*");}
	| '+'                                                                 {$$ = new std::string("+");}
	| '-'                                                                 {$$ = new std::string("-");}
	| '~'                                                                 {$$ = new std::string("~");}
	| '!'                                                                 {$$ = new std::string("!");}
	;
  //| SIZEOF '(' Type_name ')'

Postfix_expression
	: Primary_expression                                                  {std::cout << std::endl;std::cout <<"Parser "<< "213" << " Primary" << std::endl;$$ = $1;}
	| Postfix_expression '(' ')'                                          {std::cout << std::endl;std::cout <<"Parser "<< "211" << " FunctionCall" << std::endl; $$ = new FunctionCall_Mips($1);std::cout << "FunctionCall Done" << std::endl;}
	| Postfix_expression '(' Argument_expression_list ')'                 {std::cout << std::endl;std::cout <<"Parser "<< "211" << " FunctionCall with Param" << std::endl;$$ = new FunctionCall_Mips($1, *$3);}
	/* | postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER */
	| Postfix_expression INC_OP                                           {$$ = new Post_Increment_MIPS($1);}
	| Postfix_expression DEC_OP                                           {$$ = new Post_Decrement_MIPS($1);}
  | Postfix_expression '[' Expression ']'                               {std::cout << std::endl;std::cout <<"Parser "<< "255" << "Array_Access_Mips" << std::endl;$$ = new Array_Access_Mips($1, $3);}
	;

Argument_expression_list
	: Assignment_expression                                               {$$ = build_new_list($1);}
	| Argument_expression_list ',' Assignment_expression                  {$$ = add_to_list($1, $3);}
	;

Primary_expression
	: IDENTIFIER                                                          {std::cout << std::endl;std::cout <<"Parser "<< "226" << " IDENTIFIER" << std::endl; $$ = new Identifier_Mips(*$1);}
	| INT_CONSTANT                                                        {std::cout << std::endl;std::cout <<"Parser "<< "227" << " INI_CONSTANT" << std::endl;$$ = new Int_Constant_Mips($1);}
	| STRING_LITERAL                                                      {std::cerr << "Unsupported" << std::endl;}
//	| '(' Expression ')'                                                  {std::cout << std::endl;std::cout <<"Parser "<< "252" << " Primary Expression" << std::endl;$$ = new Int_Constant_Mips($1);}
	;




Additive_expression
  : Multiplicative_expression                                           {$$ = $1;}
  | Additive_expression '+' Multiplicative_expression                   {std::cout << std::endl;std::cout <<"Parser "<< "240" << " Addition" << std::endl; $$ = new Addition_MIPS($1,$3);}
  | Additive_expression '-' Multiplicative_expression                   {$$ = new Subtraction_MIPS($1,$3);}
  ;



Multiplicative_expression
  : Cast_expression                                                     {$$ = $1;}                             
  | Multiplicative_expression '*' Cast_expression                       {$$ = new Multiplication_MIPS($1,$3);}
  | Multiplicative_expression '/' Cast_expression                       {$$ = new Division_MIPS($1,$3);}
  | Multiplicative_expression '%' Cast_expression                       {$$ = new Mod_MIPS($1,$3);}
  ;

//
Cast_expression
  : Unary_expression                                                    {$$ = $1;}
//| '(' Type_name ')' Cast_expression                                   {$$ = Type_name_Cast_expression_MIPS($2, $4);}
  ;

Shift_expression
  : Additive_expression                                                 {$$ = $1;}
  | Shift_expression LEFT_OP Additive_expression                        {$$ = new Left_Shift_MIPS($1,$3);}
  | Shift_expression RIGHT_OP Additive_expression                       {$$ = new Right_Shift_MIPS($1,$3);}
  ;  

Relational_expression
  : Shift_expression                                                    {$$ = $1;}
  | Relational_expression '>' Shift_expression                          {$$ = new Greater_Than_MIPS($1,$3);}
  | Relational_expression '<' Shift_expression                          {std::cout << std::endl;std::cout <<"Parser "<< "285" << " Smaller Than" << std::endl;$$ = new Less_Than_MIPS($1,$3);std::cout <<"done" << std::endl;}
  | Relational_expression LE_OP Shift_expression                        {$$ = new Less_Than_Equal_MIPS($1,$3);}
  | Relational_expression GE_OP Shift_expression                        {$$ = new Greater_Than_Equal_MIPS($1,$3);}

Equality_expression
  : Relational_expression                                               {$$ = $1;}
  | Equality_expression EQ_OP Relational_expression                     {$$ = new Equal_MIPS($1,$3);}
  | Equality_expression NE_OP Relational_expression                     {$$ = new NotEqual_MIPS($1,$3);}
  ;
  
Conditional_expression
  : Logical_or_expression                                               {$$ = $1;}
  | Logical_or_expression '?' Expression ':'  Conditional_expression    {std::cerr << "Unsupported" << std::endl;}  
  //SOS
  ;
Logical_or_expression
  : Logical_and_expression                                              {$$ = $1;}
  | Logical_or_expression OR_OP Logical_and_expression                  {$$ = new LogicOr_MIPS($1, $3);}
  ;
//and
Logical_and_expression
  : Or_expression                                                       {$$ = $1;}
  | Logical_and_expression AND_OP Or_expression                         {$$ = new LogicAnd_MIPS($1, $3);}
  ;
Or_expression 
  : Xor_expression                                                      {$$ = $1;}
  | Or_expression '|' Xor_expression                                    {$$ = new BitOr_MIPS($1, $3);}

Xor_expression
  : And_expression                                                      {$$ = $1;}
  | Xor_expression '^' And_expression                                   {$$ = new BitXor_MIPS($1, $3);}
  ;

And_expression  
  : Equality_expression                                                 {$$ = $1;}
  | And_expression '&' Equality_expression                              {$$ = new BitAnd_MIPS($1, $3);}
  ;


Statement_list
  : Statement                                                           {$$ = build_new_list($1);}
  | Statement_list Statement                                            {$$ = add_to_list($1, $2);}
  ;

Expression_statement
  : ';'                                                                 {std::cout << std::endl;std::cout <<"Parser "<< "314" << ";" << std::endl;}//$$ = new Semicolon_MIPS($1);}    //sos
  | Expression ';'                                                      {std::cout << std::endl;std::cout <<"Parser "<< "314" << " Expression;" << std::endl; $$ = $1;}
  ;

Selection_statement     
  : IF '(' Expression ')'  Statement                                    {$$ = new Selection_statement_Mips($3,$5);}
  | IF '(' Expression ')'  Statement  ELSE Statement                    {$$ = new Selection_statement_Mips($3, $5, $7);}
  | SWITCH '(' Expression ')' Statement                                 {std::cerr << "Unsupported" << std::endl;}
  ;

Iteration_statement
  : WHILE '(' Expression ')' Statement                                              {std::cout << std::endl;std::cout <<"Parser "<< "324" << " While" << std::endl; $$ = new While_Mips($3,$5);}
  //|DO Statement WHILE '(' Expression ')' ';'
  | FOR '(' Expression_statement Expression_statement ')' Statement                 {std::cout << std::endl;std::cout <<"Parser "<< "343" << " FOR(Expression_statement Expression_statement)" << std::endl;$$ = new For_Mips($3,$4,$6);}
  | FOR '(' Expression_statement Expression_statement Expression ')' Statement      {std::cout << std::endl;std::cout <<"Parser "<< "344" << " FOR(Expression_statement Expression_statement Expression)" << std::endl;$$ = new For_Mips($3,$4,$5,$7);}//$$ = new FOR_THREE_MIPS ($3, $4, $5);}   //for (; --i >= 0;)
  ;

Jump_statemnet
  : RETURN  ';'                                                          {std::cout <<"Parser "<< "RETURN;" << std::endl; $$ = new Return_Mips();}
  //| BREAK ';'
  //| CONTINUE ';'
  | RETURN Expression ';'                                                {std::cout<<std::endl;std::cout <<"Parser "<< "331"<<" RETURN EXPRESSION;" << std::endl; $$ = new Return_Mips($2);}
  ;




%%

NodePtr g_root;

const NodePtr parseAST(std::string filename)
{
  yyin = fopen(filename.c_str(), "r");
  std::cout << " opening input file: " << std::endl;
  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << filename << std::endl;
    exit(1);
  }
  std::cout<<"open successfully" << std::endl;
  g_root=NULL;
  yyparse(); 

  std::cout<<"lexer pass" << std::endl;
  return g_root;
}

/*
make c_compiler
bin/c_compiler -S compiler_tests/my_test/test1.c -o test_program.s


make bin/c_compiler -B
bin/c_compiler -S compiler_tests/array/declare_global.c -o test_program.s
mips-linux-gnu-gcc -mfp32 -o test_program.o -c test_program.s
mips-linux-gnu-gcc -mfp32 -static -o test_program test_program.o compiler_tests/array/declare_global_driver.c
qemu-mips test_program
*/