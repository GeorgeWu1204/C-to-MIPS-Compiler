#start to test
########################## dynamic computation 1
########################## dynamic computation 1
#build complete fully
#<----------------is init declaration----------------->
#float vector return 1
#float vector done
########################## dynamic computation 1
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
addiu $29,$29,-40
sw $30,36($29)
move $30,$29
#inside argument load
swc1 $f12, 40($30)
sw $5,44($30)
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# declaration is init
# declaration in float
#Init_Declarator_Mips 
lui $2,%hi($LC_0)
lwc1 $f0,%lo($LC_0)($2)
#Init_Declarator_Mips left
swc1 $f0,32($30)
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 24 | 3 | 0 | 0
#acc: FLOAT | 32 | 1 | 1 | 0
#i: INT | 28 | 2 | 1 | 0
#n: INT | 44 | 0 | 1 | 0
#x: FLOAT | 40 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,0
sw $2,16($30)# ----------------------------------------
sw $2,28($30)
b L_2


L_3:
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#acc: FLOAT | 32 | 2 | 1 | 0
#i: INT | 28 | 3 | 1 | 0
#n: INT | 44 | 0 | 1 | 0
#x: FLOAT | 40 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: i-------------------------->
#Condition Expression TYPE: INT
lw $2,28($30)
nop
addiu $3,$2,1
sw $3, 28($30)
sw $2,16($30)# ----------------------------------------
#In assignment expressiono
#ID :acc
#0
# <--------------------------------------- dynamic type FLOAT ---------------------------------------> 
# <--------------------------------------- dynamic type after FLOAT ---------------------------------------> 
# dynamic done
#check double
#<--------------------------------------Left 2---------------------------------->
lwc1 $f2,32($30)
#<--------------------------------------Right 2---------------------------------->
lwc1 $f4,40($30)
# Generate Left Start 
lwc1 $f2,32($30)
# Generate Left Done
lwc1 $f4,40($30)
nop
mul.s $f2,$f2,$f4
swc1 $f2,12($30)
swc1 $f2,32($30)


L_2: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 24 | 3 | 1 | 0
#acc: FLOAT | 32 | 1 | 1 | 0
#i: INT | 28 | 2 | 1 | 0
#n: INT | 44 | 0 | 1 | 0
#x: FLOAT | 40 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: i-------------------------->
#Condition Expression TYPE: INT
lw $3,28($30)
lw $4,44($30)
lw $3,28($30)
lw $4,44($30)
nop
slt $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
bne $2,$0,L_3
nop

L_4: 

#inside return MIPS
lwc1 $f0,32($30)
b L_1
L_1:
nop
move $29,$30
lw $30,36($29)
addiu $29,$29,40
jr $31
nop
.end  f
$LC_0:
     .float   1
