#start to test
########################## dynamic computation 1
#<----------------is init declaration----------------->
# <----------------------: Pointer? ------------------------>
#<----------------is pointer init declaration----------------->
# <----------------------Init_Declarator_Mips: ------------------------>
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
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 3 | 0 | 0
#x: INT | 24 | 1 | 0 | 0
#y: INTPTR | 20 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
addiu $2,$30,24
sw $2,16($30)# ----------------------------------------
sw $2,20($30)
#In assignment expressiono
#ID :y
#0
# <--------------------------------------- dynamic type INTPTR ---------------------------------------> 
# <--------------------------------------- dynamic type after INTPTR ---------------------------------------> 
# dynamic done
lw $2,20($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INTPTR | 16 | 3 | 0 | 0
#x: INT | 24 | 1 | 0 | 0
#y: INTPTR | 20 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $3,64
sw $3,16($30)# ----------------------------------------
sw $3,0($2)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 3 | 0 | 0
#x: INT | 24 | 1 | 0 | 0
#y: INTPTR | 20 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,24($30)
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,28($29)
addiu $29,$29,32
jr $31
nop
.end  f
