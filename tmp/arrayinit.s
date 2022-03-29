#start to test
#<----------------is init declaration----------------->
#<----------------is array init declaration----------------->
########################## dynamic computation 1
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 2-------------->
# f1  0-------------->
# f1  1-------------->
########################## dynamic computation 1
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-40
sw $30,36($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 2 | 0 | 0
#x: INTArray | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,1
sw $2,12($30)# ----------------------------------------
sw $2,32($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 2 | 0 | 0
#x: INTArray | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,3
sw $2,12($30)# ----------------------------------------
sw $2,28($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 2 | 0 | 0
#x: INTArray | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,5
sw $2,12($30)# ----------------------------------------
sw $2,24($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 2 | 0 | 0
#x: INTArray | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,22
sw $2,12($30)# ----------------------------------------
sw $2,20($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 2 | 0 | 0
#x: INTArray | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,69
sw $2,12($30)# ----------------------------------------
sw $2,16($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 2 | 0 | 0
#x: INTArray | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 2 | 0 | 0
#x: INTArray | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,3
sw $2,12($30)# ----------------------------------------
lw $5,12($30)
nop 
sll $5,$5,2
li $2,32
subu $5,$2,$5
addu $5,$5,$30
lw $2,0($5)
sw $2,12($30)
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,36($29)
addiu $29,$29,40
jr $31
nop
.end  f
