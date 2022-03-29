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
addiu $29,$29,-112
sw $30,108($29)
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
#$DynamicContext: INT | 16 | 4 | 0 | 0
#3Subcontext: SUBCONTEXT | 96 | 3 | 0 | 0
#x: INT | 104 | 1 | 1 | 0
#y: INT | 100 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,16($30)# ----------------------------------------
sw $2,100($30)
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 4 | 0 | 0
#3Subcontext: SUBCONTEXT | 96 | 3 | 0 | 0
#x: INT | 104 | 1 | 1 | 0
#y: INT | 100 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,16($30)# ----------------------------------------
sw $2,104($30)
b  L_1


L_2:
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#In assignment expressiono
#ID :y
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#x: INT | 104 | 2 | 1 | 0
#y: INT | 100 | 3 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,100($30)
li $4,1
lw $3,100($30)
li $4,1
# found 1
nop
subu $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
sw $2,100($30)
L_4:
nop
#In assignment expressiono
#ID :x
#0
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 4 | 0 | 0
#3Subcontext: SUBCONTEXT | 96 | 3 | 1 | 0
#x: INT | 104 | 1 | 1 | 0
#y: INT | 100 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,104($30)
li $4,1
lw $3,104($30)
li $4,1
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
sw $2,104($30)


L_1:
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 4 | 0 | 0
#3Subcontext: SUBCONTEXT | 96 | 3 | 1 | 0
#x: INT | 104 | 1 | 1 | 0
#y: INT | 100 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,104($30)
li $4,10
lw $3,104($30)
li $4,10
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
#$DynamicContext: NotDefined | 16 | 4 | 0 | 0
#3Subcontext: SUBCONTEXT | 96 | 3 | 1 | 0
#x: INT | 104 | 1 | 1 | 0
#y: INT | 100 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: y-------------------------->
#Condition Expression TYPE: INT
lw $2,100($30)
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,108($29)
addiu $29,$29,112
jr $31
nop
.end  f
