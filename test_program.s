start to test
 opening input file: 
open successfully
Token Type: INT VALUE:[int]
Parser 96 int detected 
int detected
Token Type: INDENTIFIER VALUE:[f]
Parser 114 IDENTIFIER
Token Type: ( VALUE:[(]Token Type: INT VALUE:[int]
Parser 96 int detected 
int detected
Token Type: INDENTIFIER VALUE:[n]
Parser 114 IDENTIFIER
Token Type: ) VALUE:[)]gg

Parser 116 Function_Declarator_with_param
Token Type: { VALUE:[{]gg
Token Type: ( VALUE:[(]Token Type: INDENTIFIER VALUE:[n]
Parser 226 IDENTIFIER

Parser 213 Primary

Parser 209 Unary_expression
Token Type: INT_CONSTANT VALUE:[0]
Parser 227 INI_CONSTANT

Parser 213 Primary
Token Type: ) VALUE:[)]
Parser 209 Unary_expression

Parser 183Assignement Expression
Token Type: { VALUE:[{]Token Type: RETURN VALUE:[return]Token Type: INT_CONSTANT VALUE:[0]
Parser 227 INI_CONSTANT

Parser 213 Primary
Token Type: ; VALUE:[;]
Parser 209 Unary_expression

Parser 183Assignement Expression

Parser 331 RETURN EXPRESSION;

Parser 179 JumpStatement
Token Type: } VALUE:[}]
Parser 131 Compound_statement_Statement  
compond work

Parser 175 CompoundStatement
Token Type: RETURN VALUE:[return]
Parser 177 SelectionStatement
Token Type: INDENTIFIER VALUE:[n]
Parser 226 IDENTIFIER

Parser 213 Primary

Parser 209 Unary_expression
Token Type: INDENTIFIER VALUE:[f]
Parser 226 IDENTIFIER

Parser 213 Primary
Token Type: ( VALUE:[(]Token Type: INDENTIFIER VALUE:[n]
Parser 226 IDENTIFIER

Parser 213 Primary

Parser 209 Unary_expression
Token Type: INT_CONSTANT VALUE:[1]
Parser 227 INI_CONSTANT

Parser 213 Primary
Token Type: ) VALUE:[)]
Parser 209 Unary_expression

Parser 211 FunctionCall with Param
Token Type: ; VALUE:[;]
Parser 209 Unary_expression

Parser 240 Addition

Parser 183Assignement Expression

Parser 331 RETURN EXPRESSION;

Parser 179 JumpStatement
Token Type: } VALUE:[}]
Parser 131 Compound_statement_Statement  
Tried to obtain not implemented content1
Tried to obtain not implemented content1
SelectionStatement is compound
Tried to obtain not implemented content1
Tried to obtain not implemented content1
stage 5b
Tried to obtain not implemented content1
Tried to obtain not implemented content1
stage 10  |  2
compond work

Parser 81 Function
done
lexer pass
after parser


f :
addiu $31, $31, -32
sw $31, 28($31)
sw $30, 24($31)
move $30, $31
sw$4,32($30)
<---Combined Context--->

inside Local Var: Name : Type | Offset | Index | Is_called
$DynamicContext: NotDefined | 8 | 1 | 0
$functioncall: FunctionCal | 8 | 2 | 1
n: INT | 32 | 0 | 1
inside Local Var Waiting for Declared


inside Global Var: 

lw $3, 32($30)
li $4 0
subu 2, $3, $4
beq $ 2, $0 L_1
nop


<---Combined Context--->

inside Local Var: Name : Type | Offset | Index | Is_called
$DynamicContext: NotDefined | 8 | 1 | 0
$functioncall: FunctionCal | 8 | 3 | 1
n: INT | 32 | 0 | 1
inside Local Var Waiting for Declared


inside Global Var: 

li $2 0


L_1:
cannot generate any MIPS code


L_0:
lw $3, 32($30)
lw $3, 32($30)
li $4 1
sub $3 , $4 
jal f:
lw $3, 32($30)
lw $4 0($30)
NotDefined
Dynamic Reference Type not set up
nop
add $2, $3, $4
sw $2 8($30)
nop
move $30, $31
lw $31, 28($31)
lw $30, 24($31)
addiu $31, $31, 32
jr $31
nop
Generate MIPS complete
