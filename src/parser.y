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
  int int_number;
  float float_number;
  double double_number;
  std::string *string;
  yytokentype token;

}


%token CONSTANT FLOAT_CONSTANT DOUBLE_CONSTANT


%token IDENTIFIER INT_CONSTANT STRING_LITERAL SIZEOF CHAR_LITERAL
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
%type <top> Statement Compound_statement Expression_statement Jump_statemnet Labeled_statement
%type <top> External_declaration ROOT
%type <top> Parameter_declaration
%type <top> Enumerator Enum_specifier
%type <top> Type_specifier Struct_specifier Struct_declaration Specifier_qualifier_list Struct_declarator Storage_class_specifier

%type <int_number> INT_CONSTANT CHAR_LITERAL
%type <float_number> FLOAT_CONSTANT
%type <double_number> DOUBLE_CONSTANT
//sos
%type <string> IDENTIFIER STRING_LITERAL 

%type <list> Declaration_list Init_declarator_list Initializer_list Statement_list Argument_expression_list Translation_unit Identifier_list Parameter_list Parameter_type_list Enumerator_list Struct_declaration_list 
%type <list> Struct_declarator_list

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
  | Declaration                                                     {$$ = new Global_Declaration_Mips($1);}
  ;

//function definition or declaration globally;
Function_definition
  : Declaration_specifiers Declarator Compound_statement             {$$ = new Function(new Declaration_Mips($1, $2), $3);}//int variable() {...}
	//| Declaration_specifiers Declarator Declaration_list Compound_statement     {std::cerr << "#" << "" << std::endl;}      //int Variable int a,b,c; {...}
	//| Declarator Declaration_list Compound_statement                                //int int a,b,c; {...}
	//| Declarator Compound_statement                                                   {}//Variable() {...}           
	;

Declaration_specifiers
  : Type_specifier                                                   {$$ = $1;}
  | Type_specifier Declaration_specifiers                            {}
	| TYPEDEF                                                          {}
	| TYPEDEF Declaration_specifiers                                   {$$ = new Typedef_Mips($2);}
	;




Pointer
	: '*'                                                              {}
	/* | '*' Type_qualifier_list */
	| '*' Pointer                                                      {}
	;

Type_specifier
	: INT                                                              {$$ = new Type_Mips("INT");}
	| Struct_specifier                                                 {$$ = $1;}
  | FLOAT                                                            {$$ = new Type_Mips("FLOAT");}
	| DOUBLE                                                           {$$ = new Type_Mips("DOUBLE");}
  | CHAR                                                             {$$ = new Type_Mips("CHAR");}
	| VOID                                                             {$$ = new Type_Mips("VOID");}
	| UNSIGNED                                                         {$$ = new Type_Mips("UNSIIGNED");}
  //| TYPE_NAME */
	| Enum_specifier                                                    {$$ = $1;}
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

// variable Name
Declarator                                                           
	: Direct_declarator                                                 {$$ = $1;}
  | Pointer Direct_declarator                                         {$$ = new PointerDeclarator_MIPS($2);}
	;


Direct_declarator                                    
	: IDENTIFIER                                                        {$$ = new Identifier_Mips(*$1);}//  Variable
	| '(' Declarator ')'                                                {std::cerr  << " Diclerator_Mips Unsupported" << std::endl;}//$$ = new Declarator_Mips($2);}// (Variable())                                                                      
  | Direct_declarator '(' ')'                                         {$$ = new Function_Declarator_Mips($1);}
  //| Declarator  SOS
	| Direct_declarator '[' Constant_expression ']'                     {$$ = new Declare_Array_Mips($1, $3);}
	| Direct_declarator '[' ']'                                         {$$ = new Declare_Array_Mips($1);}
	| Direct_declarator '(' Parameter_type_list ')'                     {$$ = new Function_Declarator_Mips($1, *$3);}
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
// Type And Struct
Struct_specifier
	: STRUCT IDENTIFIER '{' Struct_declaration_list '}'                  {$$ = new Build_struct_Mips(*$2, *$4);}              
	//| STRUCT '{' Struct_declaration_list '}'
	| STRUCT IDENTIFIER                                                  {$$ = new Struct_Declaration_Mips(*$2);}
	;


Struct_declaration_list
	: Struct_declaration                                                 {$$ = build_new_list($1);}
	| Struct_declaration_list Struct_declaration                         {$$ = add_to_list($1, $2);}
	;


Struct_declaration
	:  Specifier_qualifier_list Struct_declarator_list ';'               {$$ = new StructElement_Declaration_Mips($1, *$2);}
	;
  
Struct_declarator_list
	: Struct_declarator                                                  {$$ = build_new_list($1);}
	| Struct_declarator_list ',' Struct_declarator                       {$$ = add_to_list($1, $3);}
	;

// neglect const
Struct_declarator
	: Declarator                                                         {$$ = $1;}
	//| ':' Constant_expression                                              {} //
	//| Declarator ':' Constant_expression                                   {} // 
	;

Specifier_qualifier_list
	: Type_specifier                                                     {$$ = $1;}
  //| Type_specifier Specifier_qualifier_list                            {$$ = new Type_qualifier_list($1,$2);}
	;

Identifier_list
	: IDENTIFIER                                                        {$$ = build_new_list(*$1);}
	| Identifier_list ',' IDENTIFIER                                    {$$ = add_to_list($1, *$3);}
	;

Constant_expression
  : Conditional_expression                                            {$$ = $1;}
	;

Compound_statement
  : '{' '}'                                                           {$$ = new Compound_statement_Mips();}       // sos
  | '{' Statement_list '}'                                            {$$ = new Compound_statement_Mips(*$2);std::cerr << "# compond work" << std::endl;}
  | '{' Declaration_list  '}'                                         {$$ = new Compound_statement_Mips(*$2); std::cerr << "# compond work" << std::endl;}// {int a,b,c; int d,f,g;}
  | '{' Declaration_list Statement_list '}'                           {$$ = new Compound_statement_Mips(*$2, *$3); std::cerr << "# compond work" << std::endl;} // {int a,b,c; a=b+c;}
  ;

//  Declaration int a, b, c;
Declaration_list                                                      
	: Declaration                                                       {$$ = build_new_list($1);}                                                                  // this is used to build a new list
	| Declaration_list Declaration                                      {$$ = add_to_list($1,$2);}//int a, b, c; int a, b, c; int a, b, c;
                                                                      // this is used to add on to the original list.
  ;
  
Declaration
	: Declaration_specifiers ';'                                        {$$ = new Declaration_Mips($1);}//  for struct, enum
	// struct { abnab }  + ;
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
	| Declarator '=' Initializer                                        {$$ = new Init_Declarator_Mips($1,$3);} //declarator: Variable "=" [a = a + b]
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
  : Initializer                                                       {$$ = build_new_list($1);}//std::cerr  << "Unsupported" << std::endl;} // a>b
	| Initializer_list ',' Initializer                                  {$$ = add_to_list($1, $3);}         //{{2,4},3}
	;


Statement 
  : Compound_statement                                                {$$ = $1;}
  | Expression_statement                                              {$$ = $1;}
  | Selection_statement                                               {$$ = $1;}
  | Iteration_statement                                               {$$ = $1;}
  | Jump_statemnet                                                    {$$ = $1;}
  | Labeled_statement                                                 {$$ = $1;}
  ;

Expression 
  :  Assignment_expression                                            {$$ = $1;}
  |  Expression ',' Assignment_expression                             { std::cerr  << "Not assessed by spec (?)" << std::endl; }
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
  | Conditional_expression                                             {$$ = new Condition_Expression_Mips($1);} 
	;


//Variable Constant Identity

Unary_expression                                                        
	: Postfix_expression                                                  {$$ = $1;}
	| INC_OP Unary_expression                                             {$$ = new Pre_Increment_MIPS($2);}//$$ = Inc_Unary}}
  //++
  | DEC_OP Unary_expression                                             {$$ = new Pre_Decrement_MIPS($2);}
  //--                                 
  |	'&' Cast_expression                                                 {$$ = new UnaryAddress_MIPS($2);}
	| '*' Cast_expression                                                 {$$ = new UnaryPointer_MIPS($2);}      
	| '+' Cast_expression                                                 {$$ = $2;}        
	| '-' Cast_expression                                                 {$$ = new UnarySub_MIPS($2);}     
	| '~' Cast_expression                                                 {$$ = new UnaryNor_MIPS($2);}              
	| '!' Cast_expression                                                 {$$ = new UnaryNot_MIPS($2);}             
  | SIZEOF Unary_expression                                             {$$ = new Sizeof_MIPS($2);}
  ;  

  //| SIZEOF '(' Type_name ')'

Postfix_expression
	: Primary_expression                                                  {$$ = $1;}
	| Postfix_expression '(' ')'                                          {$$ = new FunctionCall_Mips($1);}
	| Postfix_expression '(' Argument_expression_list ')'                 {$$ = new FunctionCall_Mips($1, *$3);}
  | Postfix_expression '.' IDENTIFIER                                   {$$ = new Call_struct_Mips($1, *$3);}
  /*| postfix_expression PTR_OP IDENTIFIER */
	| Postfix_expression INC_OP                                           {$$ = new Post_Increment_MIPS($1);}
	| Postfix_expression DEC_OP                                           {$$ = new Post_Decrement_MIPS($1);}
  | Postfix_expression '[' Expression ']'                               {$$ = new Array_Access_Mips($1, $3);}
	;

Argument_expression_list
	: Assignment_expression                                               {$$ = build_new_list($1);}
	| Argument_expression_list ',' Assignment_expression                  {$$ = add_to_list($1, $3);}
	;

Primary_expression
	: IDENTIFIER                                                          {  $$ = new Identifier_Mips(*$1);}
	| INT_CONSTANT                                                        {  $$ = new Int_Constant_Mips($1);}
  | FLOAT_CONSTANT                                                      { $$ = new Float_Constant_Mips($1);}
  | CHAR_LITERAL                                                        {$$ = new Char_Litteral_Mips($1);}
  | DOUBLE_CONSTANT                                                     { $$ = new Double_Constant_Mips($1);}
	| STRING_LITERAL                                                      {$$ = new STRING_LITTERAL_MIPS(*$1);}
  | '(' Expression ')'                                                  {  $$ = $2;}
  
	;



Additive_expression
  : Multiplicative_expression                                           {$$ = $1;}
  | Additive_expression '+' Multiplicative_expression                   {$$ = new Addition_MIPS($1,$3);}
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
  | Relational_expression '<' Shift_expression                          {$$ = new Less_Than_MIPS($1,$3);}
  | Relational_expression LE_OP Shift_expression                        {$$ = new Less_Than_Equal_MIPS($1,$3);}
  | Relational_expression GE_OP Shift_expression                        {$$ = new Greater_Than_Equal_MIPS($1,$3);}

Equality_expression
  : Relational_expression                                               {$$ = $1;}
  | Equality_expression EQ_OP Relational_expression                     {$$ = new Equal_MIPS($1,$3);}
  | Equality_expression NE_OP Relational_expression                     {$$ = new NotEqual_MIPS($1,$3);}
  ;
  
Conditional_expression
  : Logical_or_expression                                               {$$ = $1;}
  | Logical_or_expression '?' Expression ':'  Conditional_expression    {std::cerr  << "Unsupported" << std::endl;}  
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

Labeled_statement	
	: CASE Constant_expression ':' Statement                              {$$ = new Case_Mips($2, $4);}
	| DEFAULT ':' Statement                                               {$$ = new Default_Mips($3);}
  /* | IDENTIFIER ':' Statement                                            {$$ = } */
	; 


   //: SOS';'                                                                 {std::cerr  << "Unsupported" << std::endl;}//$$ = new Semicolon_MIPS($1);}    //sos
Expression_statement
  : Expression ';'                                                      {$$ = $1;} 
  ;

Selection_statement     
  : IF '(' Expression ')'  Statement                                    {$$ = new Selection_statement_Mips($3,$5);}
  | IF '(' Expression ')'  Statement  ELSE Statement                    {$$ = new Selection_statement_Mips($3, $5, $7);}
  | SWITCH '(' Expression ')' Statement                                 {$$ = new Switch_Mips($3, $5);}
  ;

Iteration_statement
  : WHILE '(' Expression ')' Statement                                              { $$ = new While_Mips($3,$5);}
  //|DO Statement WHILE '(' Expression ')' ';'
  | FOR '(' Expression_statement Expression_statement ')' Statement                 {$$ = new For_Mips($3,$4,$6);}
  | FOR '(' Expression_statement Expression_statement Expression ')' Statement      {$$ = new For_Mips($3,$4,$5,$7);}//$$ = new FOR_THREE_MIPS ($3, $4, $5);}   //for (; --i >= 0;)
  ;

Jump_statemnet
  : RETURN  ';'                                                          { $$ = new Return_Mips();}
  | BREAK ';'                                                            { $$ = new Break_Mips();}
  | CONTINUE ';'                                                         { $$ = new Continuous_Mips();}
  | RETURN Expression ';'                                                { $$ = new Return_Mips($2);}
  ;




%%

NodePtr g_root;

const NodePtr parseAST(std::string filename)
{
  yyin = fopen(filename.c_str(), "r");
  std::cerr << "#" << " opening input file: " << std::endl;
  if(yyin == NULL){
    std::cerr << "#Couldn't open input file: " << filename << std::endl;
    exit(1);
  }
  std::cerr <<"#open successfully" << std::endl;
  g_root=NULL;
  yyparse(); 

  std::cerr <<"#lexer pass" << std::endl;
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