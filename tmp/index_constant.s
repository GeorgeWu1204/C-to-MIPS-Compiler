#start to test
########################## dynamic computation 1
########################## dynamic computation 1
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 2-------------->
# f1  0-------------->
# f1  1-------------->
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
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INTArray ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 2 | 0 | 0
#x: INTArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,16($30)# ----------------------------------------
lw $5,16($30)
sll $5,$5,2
li $2,48
subu $5,$2,$5
addu $5,$5,$30
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 2 | 0 | 0
#x: INTArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $3,23
sw $3,16($30)# ----------------------------------------
sw $3,0($5)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#x: INTArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 2 | 0 | 0
#x: INTArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,16($30)# ----------------------------------------
lw $5,16($30)
nop 
sll $5,$5,2
li $2,48
subu $5,$2,$5
addu $5,$5,$30
lw $2,0($5)
sw $2,16($30)
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,52($29)
addiu $29,$29,56
jr $31
nop
.end  f
