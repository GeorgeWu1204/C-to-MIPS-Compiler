#start to test
########################## dynamic computation 1
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
########################## dynamic computation 1
#build complete fully
.globl global
.data 
.size global,20
global:
.space 20
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
#inside argument load
sw $4,24($30)
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#In assignment expressiono
#ID :global
#1
# <--------------------------------------- dynamic type INTArray ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#x: INT | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,3
sw $2,16($30)# ----------------------------------------
lui $2,%hi(global)
addiu $2,$2,%lo(global)
lw $5,16($30)
#
#inside Global Var: Name : Type | GlobalSize | Enum val
#f: INT | 1 | 0
#global: INTArray | 0 | 0
#
sll $5,$5,2
addu $5,$5,$2
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#x: INT | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,24($30)
li $4,1
lw $3,24($30)
li $4,1
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,12($30)
sw $3,16($30)# ----------------------------------------
sw $3,0($5)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#x: INT | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: global-------------------------->
#Condition Expression TYPE: INT
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#x: INT | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,3
sw $2,16($30)# ----------------------------------------
lw $5,16($30)
lui $2,%hi(global)
addiu $2,$2,%lo(global)
#
#inside Global Var: Name : Type | GlobalSize | Enum val
#f: INT | 1 | 0
#global: INTArray | 0 | 0
#
sll $5,$5,2
addu $5,$5,$2
lw $2,0($5)
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,20($29)
addiu $29,$29,24
jr $31
nop
.end  f
