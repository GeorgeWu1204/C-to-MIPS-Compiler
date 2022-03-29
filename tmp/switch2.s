#start to test
########################## dynamic computation 1
########################## dynamic computation 1
########################## dynamic computation 1
########################## dynamic computation 1
########################## dynamic computation 1
########################## dynamic computation 1
#build complete fully
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
#2Subcontext: SUBCONTEXT | 20 | 2 | 0 | 0
#t: INT | 32 | 0 | 1 | 0
#x: INT | 24 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,12($30)# ----------------------------------------
sw $2,24($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 3 | 0 | 0
#2Subcontext: SUBCONTEXT | 20 | 2 | 0 | 0
#t: INT | 32 | 0 | 1 | 0
#x: INT | 24 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: t-------------------------->
#Condition Expression TYPE: INT
lw $2,32($30)
sw $2,12($30)# ----------------------------------------
li $3,0
beq $3,$2,L_2
nop
li $3,2
beq $3,$2,L_3
nop
li $3,1
beq $3,$2,L_4
nop
b L_5
nop
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
L_2: 
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 1 | 0 | 0
#t: INT | 32 | 0 | 1 | 0
#x: INT | 24 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,1
sw $2,12($30)# ----------------------------------------
sw $2,24($30)
b L_1
L_3: 
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 1 | 0 | 0
#t: INT | 32 | 0 | 1 | 0
#x: INT | 24 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,2
sw $2,12($30)# ----------------------------------------
sw $2,24($30)
L_4: 
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 1 | 0 | 0
#t: INT | 32 | 0 | 1 | 0
#x: INT | 24 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,24($30)
li $4,1
lw $3,24($30)
li $4,1
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sw $2,8($30)
sw $2,12($30)# ----------------------------------------
sw $2,24($30)
b L_1
L_5: 
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 1 | 0 | 0
#t: INT | 32 | 0 | 1 | 0
#x: INT | 24 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,32($30)
li $4,1
lw $3,32($30)
li $4,1
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sw $2,8($30)
sw $2,12($30)# ----------------------------------------
sw $2,24($30)
L_1: 
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 3 | 0 | 0
#2Subcontext: SUBCONTEXT | 20 | 2 | 0 | 0
#t: INT | 32 | 0 | 1 | 0
#x: INT | 24 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,24($30)
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,28($29)
addiu $29,$29,32
jr $31
nop
.end  g
