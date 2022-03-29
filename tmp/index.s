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
#inside argument load
sw $4,24($30)
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#p: INTPTR | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: p-------------------------->
#Condition Expression TYPE: INTPTR
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INTPTR | 16 | 1 | 0 | 0
#p: INTPTR | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,1
sw $2,16($30)# ----------------------------------------
lw $5,16($30)
nop 
lw $2,24($30)
nop 
sll $5,$5,2
addu $5,$2,$5
lw $2, 0($5)
sw $2,16($30)
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
