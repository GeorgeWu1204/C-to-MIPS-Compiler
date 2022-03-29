#start to test
########################## dynamic computation 1
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 1-------------->
# f1  0-------------->
# f2 0-------------->
# f3 0-------------->
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
#In assignment expressiono
#ID :p
#0
# <--------------------------------------- dynamic type INTPTR ---------------------------------------> 
# <--------------------------------------- dynamic type after INTPTR ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INTPTR | 16 | 1 | 0 | 0
#p: INTPTR | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,24($30)
li $4,1
lw $3,24($30)
li $4,1
# dynamic context ?
#type: INTPTR
nop
sll $4, 2
addu $2,$3,$4
sw $2,16($30)
sw $2,16($30)# ----------------------------------------
sw $2,24($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#p: INTPTR | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
lw $2,24($30)
nop 
lw $2,0($2)
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
