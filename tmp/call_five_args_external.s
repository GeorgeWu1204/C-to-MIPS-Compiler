#start to test
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 6-------------->
# how mang param in function  :5-------------->
# how mang param in function  :5-------------->
# how mang param in function  :5-------------->
# how mang param in function  :5-------------->
# how mang param in function  :5-------------->
########################## dynamic computation 1
#stage 10
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-64
sw $31,60($29)
sw $30,56($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $4,1
sw $4,52($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $5,2
sw $5,52($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $6,3
sw $6,52($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $7,4
sw $7,52($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,5
sw $2,52($30)# ----------------------------------------
sw $2,16($30)
jal g
sw $2,52($30)
sw $2,52($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $31,60($29)
lw $30,56($29)
addiu $29,$29,64
jr $31
nop
.end  f
