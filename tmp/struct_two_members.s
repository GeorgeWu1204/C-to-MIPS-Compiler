#start to test
########################## dynamic computation 1
########################## dynamic computation 1
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
########################## dynamic computation 2
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
##------------------- ASA dynamic offset  16
#stage 1
# <---------------------- Declaration ------------------>
#In assignment expressiono
#ID :g
#0
# <--------------------------------------- dynamic type STRUCTx ---------------------------------------> 
# <--------------------------------------- dynamic type after STRUCTx ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: STRUCTx | 24 | 2 | 0 | 0
#g: STRUCTx | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $3,17
sw $3,24($30)# ----------------------------------------
sw $3,32($30)
#In assignment expressiono
#ID :g
#0
# <--------------------------------------- dynamic type STRUCTx ---------------------------------------> 
# <--------------------------------------- dynamic type after STRUCTx ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: STRUCTx | 24 | 2 | 0 | 0
#g: STRUCTx | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $3,13
sw $3,24($30)# ----------------------------------------
sw $3,28($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 24 | 2 | 0 | 0
#g: STRUCTx | 32 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
lw $3,32($30)
lw $4,28($30)
lw $3,32($30)
lw $4,28($30)
# dynamic context ?
#type: 
nop
addu $2,$3,$4
sw $2,24($30)
sw $2,24($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,36($29)
addiu $29,$29,40
jr $31
nop
.end  f
