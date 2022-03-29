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
########################## dynamic computation 12
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 2
########################## dynamic computation 1
########################## dynamic computation 97
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
addiu $29,$29,-904
sw $30,900($29)
move $30,$29
#inside argument load
sw $4,904($30)
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
#In assignment expressiono
#ID :i
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 892 | 2 | 0 | 0
#i: INT | 896 | 1 | 1 | 0
#x: INT | 904 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,32
sw $2,12($30)# ----------------------------------------
sw $2,896($30)
b  L_1


L_2:
#inside compound_statement
##------------------- ASA dynamic offset  96
#stage 1
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 2 | 0 | 0
#1Subcontext: SUBCONTEXT | 892 | 1 | 0 | 0
#i: INT | 896 | 3 | 1 | 0
#x: INT | 904 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,904($30)
nop
addiu $3,$2,-1
sw $3,904($30)
sw $2,12($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 2 | 0 | 0
#1Subcontext: SUBCONTEXT | 892 | 1 | 0 | 0
#i: INT | 896 | 3 | 1 | 0
#x: INT | 904 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: i-------------------------->
#Condition Expression TYPE: INT
#<--------------------------------------Cloest ID i---------------------------------->
#<--------------------------------------Context---------------------------------->
#<--------------------------------------type INT---------------------------------->
lw $3,896($30)
li $4,8
lw $3,896($30)
li $4,8
nop
xor $3,$3,$4
sltu $3,$3,1
andi $3,$3,0x00ff
sw $3,8($30)
#<--------------------------------------Cloest ID i---------------------------------->
#<--------------------------------------Context---------------------------------->
#<--------------------------------------type INT---------------------------------->
lw $3,896($30)
li $4,16
lw $3,896($30)
li $4,16
nop
xor $4,$3,$4
sltu $4,$4,1
andi $4,$4,0x00ff
sw $4,4($30)
lw $3,8($30)
lw $4,4($30)
nop
bne $3,$0,L_6
nop 
beq $4,$0,L_5
L_6:
nop 
li $2,1
b L_7
nop 

L_5:
move $2,$0

L_7:
sw $2,0($30)
sw $2,12($30)# ----------------------------------------
beq $2,$0,L_8
nop

#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
b L_4
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 1 | 0 | 0
#i: INT | 896 | 4 | 1 | 0
#x: INT | 904 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,2
sw $2,12($30)# ----------------------------------------
b L_0

L_8:
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
lw $3,904($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 2 | 0 | 0
#1Subcontext: SUBCONTEXT | 892 | 1 | 1 | 0
#i: INT | 896 | 3 | 1 | 0
#x: INT | 904 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,896($30)
li $4,1
lw $3,896($30)
li $4,1
# dynamic context ?
#type: INT
nop
addu $4,$3,$4
sw $4,8($30)
sw $4,12($30)# ----------------------------------------
lw $3,904($30)
lw $4,12($30)
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sw $2,4($30)
sw $2,904($30)
L_4:
nop
#In assignment expressiono
#ID :i
#0
# dynamic done
#<--------------------------------------Cloest ID i---------------------------------->
#<--------------------------------------Context---------------------------------->
#<--------------------------------------type INT---------------------------------->
lw $3,896($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 892 | 2 | 1 | 0
#i: INT | 896 | 1 | 1 | 0
#x: INT | 904 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
li $4,2
sw $4,12($30)# ----------------------------------------
lw $3,896($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 892 | 2 | 1 | 0
#i: INT | 896 | 1 | 1 | 0
#x: INT | 904 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
li $4,2
sw $4,12($30)# ----------------------------------------
nop
div $3,$4
mflo $2
sw $2,8($30)
sw $2,896($30)


L_1:
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 892 | 2 | 1 | 0
#i: INT | 896 | 1 | 1 | 0
#x: INT | 904 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,896($30)
li $4,0
lw $3,896($30)
li $4,0
nop
slt $2, $4 , $3 
sw $2,4($30)
sw $2,8($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 3 | 0 | 0
#1Subcontext: SUBCONTEXT | 892 | 2 | 1 | 0
#i: INT | 896 | 1 | 1 | 0
#x: INT | 904 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,904($30)
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,900($29)
addiu $29,$29,904
jr $31
nop
.end  f
