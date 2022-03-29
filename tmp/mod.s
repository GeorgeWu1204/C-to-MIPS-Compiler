#start to test
#<----------------is init declaration----------------->
#<----------------is identifier init declaration----------------->
# <----------------------Init_Declarator_Mips: ------------------------>
########################## dynamic computation 1
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 0-------------->
########################## dynamic computation 1
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-24
sw $30,20($29)
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
#x: INT | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $3,100
li $4,66
li $3,100
li $4,66
nop
div $3,$4
mfhi $2
sw $2,8($30)
sw $2,12($30)# ----------------------------------------
sw $2,16($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 2 | 0 | 0
#x: INT | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,16($30)
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,20($29)
addiu $29,$29,24
jr $31
nop
.end  f
