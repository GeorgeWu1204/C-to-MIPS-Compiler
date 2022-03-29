#start to test
########################## dynamic computation 1
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
#inside argument load
sw $4,24($30)
sw $5,28($30)
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
#In assignment expressiono
#ID :z
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 2 | 0 | 0
#x: INT | 24 | 0 | 1 | 0
#y: INT | 28 | 0 | 1 | 0
#z: INT | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,24($30)
lw $4,28($30)
lw $3,24($30)
lw $4,28($30)
# found 1
nop
subu $2,$3,$4
sw $2,8($30)
sw $2,12($30)# ----------------------------------------
sw $2,16($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 2 | 0 | 0
#x: INT | 24 | 0 | 1 | 0
#y: INT | 28 | 0 | 1 | 0
#z: INT | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: z-------------------------->
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
