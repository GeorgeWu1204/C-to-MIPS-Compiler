#start to test
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 2
########################## dynamic computation 1
########################## dynamic computation 9
#build complete fully
########################## dynamic computation 1
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
addiu $29,$29,-136
sw $30,132($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# <---------------------- Declaration ------------------>
#In assignment expressiono
#ID :i
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 92 | 3 | 0 | 0
#i: INT | 128 | 1 | 1 | 0
#x: INTArray | 124 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,12($30)# ----------------------------------------
sw $2,128($30)
b  L_1


L_2:
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INTArray ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 1 | 0 | 0
#i: INT | 128 | 2 | 1 | 0
#x: INTArray | 124 | 3 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $2,128($30)
sw $2,12($30)# ----------------------------------------
lw $5,12($30)
sll $5,$5,2
li $2,124
subu $5,$2,$5
addu $5,$5,$30
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 1 | 0 | 0
#i: INT | 128 | 2 | 1 | 0
#x: INTArray | 124 | 3 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,128($30)
sw $3,12($30)# ----------------------------------------
sw $3,0($5)
L_4:
nop
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 92 | 3 | 1 | 0
#i: INT | 128 | 1 | 1 | 0
#x: INTArray | 124 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $2,128($30)
nop
addiu $3,$2,1
sw $3, 128($30)
sw $2,12($30)# ----------------------------------------


L_1:
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 92 | 3 | 1 | 0
#i: INT | 128 | 1 | 1 | 0
#x: INTArray | 124 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,128($30)
li $4,8
lw $3,128($30)
li $4,8
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
#$DynamicContext: NotDefined | 12 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 92 | 3 | 1 | 0
#i: INT | 128 | 1 | 1 | 0
#x: INTArray | 124 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 92 | 3 | 1 | 0
#i: INT | 128 | 1 | 1 | 0
#x: INTArray | 124 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,4
sw $2,12($30)# ----------------------------------------
lw $5,12($30)
nop 
sll $5,$5,2
li $2,124
subu $5,$2,$5
addu $5,$5,$30
lw $2,0($5)
sw $2,12($30)
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,132($29)
addiu $29,$29,136
jr $31
nop
.end  f
