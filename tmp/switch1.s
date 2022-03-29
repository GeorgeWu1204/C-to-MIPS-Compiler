#start to test
########################## dynamic computation 1
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 1
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl g
.ent  g
g:
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
#inside argument load
sw $4,32($30)
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#0Subcontext: SUBCONTEXT | 24 | 1 | 0 | 0
#x: INT | 32 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,32($30)
sw $2,16($30)# ----------------------------------------
li $3,1
beq $3,$2,L_2
nop
li $3,2
beq $3,$2,L_3
nop
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
L_2: 
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#x: INT | 32 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,10
sw $2,16($30)# ----------------------------------------
b L_0
L_3: 
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#x: INT | 32 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,11
sw $2,16($30)# ----------------------------------------
b L_0
L_1: 
L_0:
nop
move $29,$30
lw $30,28($29)
addiu $29,$29,32
jr $31
nop
.end  g
