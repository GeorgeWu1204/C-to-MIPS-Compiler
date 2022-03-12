start to test
 opening input file: 
open successfully
Token Type: INT VALUE:[int]
Parser 93int detected
int detected
Token Type: INDENTIFIER VALUE:[f]
Parser 114 IDENTIFIER
Token Type: ( VALUE:[(]Token Type: ) VALUE:[)]
Parser 116 Function_Declarator
Token Type: { VALUE:[{]gg
Token Type: INT VALUE:[int]
Parser 93int detected
int detected
Token Type: INDENTIFIER VALUE:[u]
Parser 114 IDENTIFIER
gg
Token Type: INT_CONSTANT VALUE:[0]
Parser 227 INI_CONSTANT

Parser 213 Primary
Token Type: ; VALUE:[;]
Parser 209 Unary_expression

Parser 158 Init_Declarator
Token Type: INT VALUE:[int]
Parser 93int detected
int detected
Token Type: INDENTIFIER VALUE:[x]
Parser 114 IDENTIFIER
gg
Token Type: INT_CONSTANT VALUE:[9]
Parser 227 INI_CONSTANT

Parser 213 Primary
Token Type: ; VALUE:[;]
Parser 209 Unary_expression

Parser 158 Init_Declarator
Token Type: FOR VALUE:[for]Token Type: ( VALUE:[(]Token Type: INDENTIFIER VALUE:[u]
Parser 226 IDENTIFIER

Parser 213 Primary

Parser 209 Unary_expression
Token Type: INT_CONSTANT VALUE:[0]
Parser 227 INI_CONSTANT

Parser 213 Primary
Token Type: ; VALUE:[;]
Parser 209 Unary_expression

Parser 186 Assignment

Parser 183 Expression

Parser 314 Expression;
Token Type: INDENTIFIER VALUE:[u]
Parser 226 IDENTIFIER

Parser 213 Primary

Parser 209 Unary_expression
Token Type: INT_CONSTANT VALUE:[0]
Parser 227 INI_CONSTANT

Parser 213 Primary
Token Type: ; VALUE:[;]
Parser 209 Unary_expression

Parser 285 Smaller Than
done

Parser 183 Expression

Parser 314 Expression;
Token Type: INDENTIFIER VALUE:[u]
Parser 226 IDENTIFIER

Parser 213 Primary

Parser 209 Unary_expression
Token Type: INDENTIFIER VALUE:[u]
Parser 226 IDENTIFIER

Parser 213 Primary

Parser 209 Unary_expression
Token Type: INT_CONSTANT VALUE:[1]
Parser 227 INI_CONSTANT

Parser 213 Primary
Token Type: ) VALUE:[)]
Parser 209 Unary_expression

Parser 240 Addition

Parser 186 Assignment

Parser 183 Expression
Token Type: { VALUE:[{]Token Type: INDENTIFIER VALUE:[x]
Parser 226 IDENTIFIER

Parser 213 Primary

Parser 209 Unary_expression
Token Type: INDENTIFIER VALUE:[x]
Parser 226 IDENTIFIER

Parser 213 Primary

Parser 209 Unary_expression
Token Type: INT_CONSTANT VALUE:[1]
Parser 227 INI_CONSTANT

Parser 213 Primary
Token Type: ; VALUE:[;]
Parser 209 Unary_expression

Parser 240 Addition

Parser 186 Assignment

Parser 183 Expression

Parser 314 Expression;

Parser 176 ExpressionStatement
Token Type: } VALUE:[}]
Parser 131 Compound_statement_Statement  
compond work

Parser 175 CompoundStatement

Parser 344 FOR(Expression_statement Expression_statement Expression)

Parser 178 IterationStatement
Token Type: } VALUE:[}]
Parser 133 Compound_statement_Declaration_AND_Statement
compond work

Parser 77 Function
lexer pass
after parser


f :
addiu $31, $31, -24
sw $30, 20($31)
move $30, $31
inside Local Var: 
2Subcontext: SUBCONTEXT | 16 | 2 | 0
u: INT | 8 | 0 | 1
x: INT | 12 | 1 | 1
inside Local Var Waiting for Declared
li $2 0
sw $2, 8($30)
li $2 9
sw $2, 12($30)
hI
li $2 0
inside is identifier
sw $2, 8($30)
b  L_0


L_1:
hI
lw $3 8($30)
li $4 1
nop
add $2, $3, $4
inside is identifier
sw $2, 8($30)
inside Local Var: 
inside Local Var Waiting for Declared
hI
lw $3 12($30)
li $4 1
nop
add $2, $3, $4
inside is identifier
sw $2, 12($30)


L_0:
LESS THAMN
lw $3 8($30)
li $4 0
slt 2, $3, $4


nop
move $30, $31
lw $30, 20($31)
addiu $31, $31, 24
jr $31
nop
Generate MIPS complete
