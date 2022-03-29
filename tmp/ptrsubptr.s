#start to test
########################## dynamic computation 1
#<----------------is init declaration----------------->
# <----------------------: Pointer? ------------------------>
#<----------------is pointer init declaration----------------->
# <----------------------Init_Declarator_Mips: ------------------------>
########################## dynamic computation 1
#<----------------is init declaration----------------->
# <----------------------: Pointer? ------------------------>
#<----------------is pointer init declaration----------------->
# <----------------------Init_Declarator_Mips: ------------------------>
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
.globl g
.ent  g
g:
addiu $29,$29,-56
sw $30,52($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  16
#stage 1
# <---------------------- Declaration ------------------>
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 20 | 4 | 0 | 0
#p: INTPTR | 28 | 2 | 1 | 0
#q: INTPTR | 24 | 3 | 1 | 0
#x: INTArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 20 | 4 | 0 | 0
#p: INTPTR | 28 | 2 | 1 | 0
#q: INTPTR | 24 | 3 | 1 | 0
#x: INTArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $5,1
sw $5,20($30)# ----------------------------------------
sll $5,$5,2
addiu $2,$30,48
subu $2,$2,$5
sw $2,20($30)# ----------------------------------------
sw $2,28($30)
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 20 | 4 | 0 | 0
#p: INTPTR | 28 | 2 | 1 | 0
#q: INTPTR | 24 | 3 | 1 | 0
#x: INTArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 20 | 4 | 0 | 0
#p: INTPTR | 28 | 2 | 1 | 0
#q: INTPTR | 24 | 3 | 1 | 0
#x: INTArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $5,2
sw $5,20($30)# ----------------------------------------
sll $5,$5,2
addiu $2,$30,48
subu $2,$2,$5
sw $2,20($30)# ----------------------------------------
sw $2,24($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 20 | 4 | 0 | 0
#p: INTPTR | 28 | 2 | 1 | 0
#q: INTPTR | 24 | 3 | 1 | 0
#x: INTArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: q-------------------------->
#Condition Expression TYPE: INTPTR
lw $3,24($30)
lw $4,28($30)
lw $3,24($30)
lw $4,28($30)
# found 1
nop
subu $2,$4,$3
sra $2,$2,2
sw $2,20($30)
sw $2,20($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,52($29)
addiu $29,$29,56
jr $31
nop
.end  g
