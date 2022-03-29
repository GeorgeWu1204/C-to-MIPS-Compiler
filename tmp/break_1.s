#start to test
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 0-------------->
########################## dynamic computation 1
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 10
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 2
########################## dynamic computation 1
########################## dynamic computation 81
#build complete fully
#<----------------is init declaration----------------->
#<----------------is identifier init declaration----------------->
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
addiu $29,$29,-760
sw $30,756($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 748 | 2 | 0 | 0
#i: INT | 752 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,0
sw $2,12($30)# ----------------------------------------
sw $2,752($30)
#In assignment expressiono
#ID :i
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 748 | 2 | 0 | 0
#i: INT | 752 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,12($30)# ----------------------------------------
sw $2,752($30)
b  L_1


L_2:
#inside compound_statement
##------------------- ASA dynamic offset  80
#stage 1
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 2 | 0 | 0
#0Subcontext: SUBCONTEXT | 748 | 1 | 0 | 0
#i: INT | 752 | 3 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: i-------------------------->
#Condition Expression TYPE: INT
lw $3,752($30)
li $4,3
lw $3,752($30)
li $4,3
nop
slt $2, $4 , $3 
sw $2,8($30)
sw $2,12($30)# ----------------------------------------
beq $2,$0,L_5
nop

#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 1 | 0 | 0
#i: INT | 752 | 4 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: i-------------------------->
#Condition Expression TYPE: INT
lw $2,752($30)
sw $2,12($30)# ----------------------------------------
b L_0
b L_3

L_5:
L_4:
nop
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 748 | 2 | 1 | 0
#i: INT | 752 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $2,752($30)
nop
addiu $3,$2,1
sw $3, 752($30)
sw $2,12($30)# ----------------------------------------


L_1:
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 748 | 2 | 1 | 0
#i: INT | 752 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,752($30)
li $4,5
lw $3,752($30)
li $4,5
nop
slt $2,$3,$4
sw $2,8($30)
sw $2,12($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 748 | 2 | 1 | 0
#i: INT | 752 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,9
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,756($29)
addiu $29,$29,760
jr $31
nop
.end  f
