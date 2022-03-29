#start to test
########################## dynamic computation 1
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
addiu $29,$29,-56
sw $30,52($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# <---------------------- Declaration ------------------>
#In assignment expressiono
#ID :y
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#x: INTArray | 44 | 2 | 1 | 0
#y: INT | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,13
sw $2,12($30)# ----------------------------------------
sw $2,48($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 3 | 0 | 0
#x: INTArray | 44 | 2 | 1 | 0
#y: INT | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: y-------------------------->
#Condition Expression TYPE: INT
lw $2,48($30)
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,52($29)
addiu $29,$29,56
jr $31
nop
.end  f
