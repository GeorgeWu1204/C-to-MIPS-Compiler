#start to test
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 2-------------->
# f1  0-------------->
# f2 0-------------->
# f3 0-------------->
# f1  1-------------->
# f2 1-------------->
# f3 1-------------->
########################## dynamic computation 2
#build complete fully
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 3-------------->
# how mang param in function  :2-------------->
# how mang param in function  :2-------------->
########################## dynamic computation 1
#stage 10
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl g
.ent  g
g:
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
#inside argument load
sw $4,32($30)
sw $5,36($30)
#inside compound_statement
##------------------- ASA dynamic offset  16
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 24 | 1 | 0 | 0
#x: INT | 32 | 0 | 1 | 0
#y: INT | 36 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $3,32($30)
lw $4,36($30)
lw $3,32($30)
lw $4,36($30)
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sw $2,20($30)
sw $2,24($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,28($29)
addiu $29,$29,32
jr $31
nop
.end  g
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-40
sw $31,36($29)
sw $30,32($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 28 | 1 | 0 | 0
#$functioncall: FunctionCal | 20 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 28 | 1 | 0 | 0
#$functioncall: FunctionCal | 20 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $4,10
sw $4,28($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 28 | 1 | 0 | 0
#$functioncall: FunctionCal | 20 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $5,20
sw $5,28($30)# ----------------------------------------
jal g
sw $2,28($30)
sw $2,28($30)# ----------------------------------------
b L_1
L_1:
nop
move $29,$30
lw $31,36($29)
lw $30,32($29)
addiu $29,$29,40
jr $31
nop
.end  f
