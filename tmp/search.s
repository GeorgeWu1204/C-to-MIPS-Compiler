#start to test
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 0-------------->
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 10
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
.globl search
.ent  search
search:
addiu $29,$29,-112
sw $30,108($29)
move $30,$29
#inside argument load
sw $4,112($30)
move $2,$5
sb $2,116($30)
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
b L_1


L_2:
#inside compound_statement
##------------------- ASA dynamic offset  80
#stage 1
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#0Subcontext: SUBCONTEXT | 104 | 1 | 0 | 0
#c: CHAR | 116 | 0 | 1 | 0
#x: CHARPTR | 112 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#<--------------------------------------Cloest ID # Tried to obtain sth not exited---------------------------------->
#<--------------------------------------Context---------------------------------->
lw $3,112($30)
nop 
lb $3,0($3)
lb $4,116($30)
lw $3,112($30)
nop 
lb $3,0($3)
lb $4,116($30)
nop
xor $2,$3,$4
sltu $2,$2,1
andi $2,$2,0x00ff
sw $2,16($30)
sw $2,16($30)# ----------------------------------------
beq $2,$0,L_4
nop

#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#c: CHAR | 116 | 0 | 1 | 0
#x: CHARPTR | 112 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: CHAR
lw $2,112($30)
sw $2,16($30)# ----------------------------------------
b L_0

L_4:
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type CHARPTR ---------------------------------------> 
# <--------------------------------------- dynamic type after CHAR ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: CHAR | 16 | 2 | 0 | 0
#0Subcontext: SUBCONTEXT | 104 | 1 | 1 | 0
#c: CHAR | 116 | 0 | 1 | 0
#x: CHARPTR | 112 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,112($30)
li $4,1
lw $3,112($30)
li $4,1
# dynamic context ?
#type: CHAR
nop
addu $2,$3,$4
sw $2,16($30)
sw $2,16($30)# ----------------------------------------
sw $2,112($30)


L_1: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#0Subcontext: SUBCONTEXT | 104 | 1 | 1 | 0
#c: CHAR | 116 | 0 | 1 | 0
#x: CHARPTR | 112 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
lw $2,112($30)
nop 
lb $2,0($2)
sw $2,16($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 2 | 0 | 0
#0Subcontext: SUBCONTEXT | 104 | 1 | 1 | 0
#c: CHAR | 116 | 0 | 1 | 0
#x: CHARPTR | 112 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,0
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,108($29)
addiu $29,$29,112
jr $31
nop
.end  search
