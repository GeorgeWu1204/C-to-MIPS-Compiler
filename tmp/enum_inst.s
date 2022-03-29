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
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
#In assignment expressiono
#ID :day
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
##False: ENUM | 16 | 1 | 1 | 0
#$DynamicContext: INT | 12 | 3 | 0 | 0
#day: INT | 16 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#inside global scope
li $2,5
sw $2,12($30)# ----------------------------------------
sw $2,16($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
##False: ENUM | 16 | 1 | 1 | 0
#$DynamicContext: NotDefined | 12 | 3 | 0 | 0
#day: INT | 16 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: day-------------------------->
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
