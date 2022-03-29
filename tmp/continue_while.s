#start to test
########################## dynamic computation 1
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 0-------------->
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 11
########################## dynamic computation 1
#build complete fully
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
addiu $29,$29,-120
sw $30,116($29)
move $30,$29
#inside argument load
sw $4,120($30)
sw $5,124($30)
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
b L_1


L_2:
#inside compound_statement
##------------------- ASA dynamic offset  88
#stage 1
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#1Subcontext: SUBCONTEXT | 112 | 1 | 0 | 0
#x: INT | 120 | 0 | 1 | 0
#y: INT | 124 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: y-------------------------->
#Condition Expression TYPE: INT
lw $2,124($30)
nop
addiu $2,$2,1
sw $2, 124($30)
sw $2,16($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#1Subcontext: SUBCONTEXT | 112 | 1 | 0 | 0
#x: INT | 120 | 0 | 1 | 0
#y: INT | 124 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: y-------------------------->
#Condition Expression TYPE: INT
lw $3,124($30)
li $4,5
lw $3,124($30)
li $4,5
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,12($30)
lw $4,120($30)
lw $3,12($30)
lw $4,120($30)
nop
slt $2,$3,$4
sw $2,8($30)
sw $2,16($30)# ----------------------------------------
beq $2,$0,L_4
nop

#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
b L_1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#x: INT | 120 | 0 | 1 | 0
#y: INT | 124 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,4
sw $2,16($30)# ----------------------------------------
b L_0

L_4:
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#1Subcontext: SUBCONTEXT | 112 | 1 | 1 | 0
#x: INT | 120 | 0 | 1 | 0
#y: INT | 124 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,120($30)
nop
addiu $2,$2,-1
sw $2,120($30)
sw $2,16($30)# ----------------------------------------


L_1: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#0Subcontext: SUBCONTEXT | 112 | 1 | 1 | 0
#x: INT | 120 | 0 | 1 | 0
#y: INT | 124 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: y-------------------------->
#Condition Expression TYPE: INT
lw $3,124($30)
lw $4,120($30)
lw $3,124($30)
lw $4,120($30)
nop
slt $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#0Subcontext: SUBCONTEXT | 112 | 1 | 1 | 0
#x: INT | 120 | 0 | 1 | 0
#y: INT | 124 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,120($30)
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,116($29)
addiu $29,$29,120
jr $31
nop
.end  f
