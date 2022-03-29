#start to test
#<----------------is init declaration----------------->
#<----------------is identifier init declaration----------------->
# <----------------------Init_Declarator_Mips: ------------------------>
########################## dynamic computation 1
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
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 3 | 0 | 0
#x: INT | 20 | 2 | 1 | 0
#y: INT | 24 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,10
sw $2,16($30)# ----------------------------------------
sw $2,24($30)
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 3 | 0 | 0
#x: INT | 20 | 2 | 1 | 0
#y: INT | 24 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $3,20
lw $4,24($30)
li $3,20
lw $4,24($30)
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sra $2,$2,2
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
sw $2,20($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 3 | 0 | 0
#x: INT | 20 | 2 | 1 | 0
#y: INT | 24 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,20($30)
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
