#start to test
# <----------------------input : "hello"------------------------>
#<----------------is init declaration----------------->
# <----------------------: Pointer? ------------------------>
#<----------------is pointer init declaration----------------->
# <----------------------Init_Declarator_Mips: ------------------------>
# <----------------------push back: hello------------------------>
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
$LC_0:
      .ascii  "hello\000"
.align  2
# <---------------------- Declaration ------------------>
.text
.globl g
.ent  g
g:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 2 | 0 | 0
#x: CHARPTR | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
lui $2,%hi($LC_0)
addiu $2,$2,%lo($LC_0)
sw $2,12($30)# ----------------------------------------
sw $2,16($30)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 12 | 2 | 0 | 0
#x: CHARPTR | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: CHAR
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: CHAR | 12 | 2 | 0 | 0
#x: CHARPTR | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,12($30)# ----------------------------------------
lw $5,12($30)
nop 
lw $2,16($30)
subu $5,$2, $5
lbu $2,0($5)
sw $2,12($30)# ----------------------------------------
b L_1
L_1:
nop
move $29,$30
lw $30,20($29)
addiu $29,$29,24
jr $31
nop
.end  g
