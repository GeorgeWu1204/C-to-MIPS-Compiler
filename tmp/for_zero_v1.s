#start to test
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 0-------------->
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 2
########################## dynamic computation 1
########################## dynamic computation 9
#build complete fully
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
addiu $29,$29,-104
sw $30,100($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 92 | 2 | 0 | 0
#x: INT | 96 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,12($30)# ----------------------------------------
sw $2,96($30)
b  L_1


L_2:
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 1 | 0 | 0
#x: INT | 96 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,1
sw $2,12($30)# ----------------------------------------
b L_0
L_4:
nop
#In assignment expressiono
#ID :x
#0
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 92 | 2 | 1 | 0
#x: INT | 96 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,96($30)
li $4,1
lw $3,96($30)
li $4,1
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sw $2,8($30)
sw $2,12($30)# ----------------------------------------
sw $2,96($30)


L_1:
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 92 | 2 | 1 | 0
#x: INT | 96 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,96($30)
li $4,0
lw $3,96($30)
li $4,0
nop
slt $2,$3,$4
sw $2,4($30)
sw $2,8($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 92 | 2 | 1 | 0
#x: INT | 96 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,19937
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,100($29)
addiu $29,$29,104
jr $31
nop
.end  f
