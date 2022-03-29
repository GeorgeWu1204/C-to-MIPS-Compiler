#start to test
#<----------------is init declaration----------------->
#<----------inside double return 1------------------>
#<----------inside double return 2------------------>
#<----------inside double return 3------------------>
#<----------inside double return 4------------------>
#<----------inside double return 5------------------>
<----------------returned float number 1 ------------------------>
<----------------returned float number 2 ------------------------>
<----------------returned float number 3 ------------------------>
<----------------returned float number 4 ------------------------>
<----------------returned float number 5 ------------------------>
#<----------------is array init declaration----------------->
########################## dynamic computation 1
#<----------inside double return 9------------------>
#<----------inside double return 9------------------>
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
LC_6:
.double       1
.double       2
.double       3
.double       4
.double       5
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# declaration is init
# declaration in float
#Init_Declarator_Mips 
#Init_Declarator_Mips left
swc1 $f0,16($30)
swc1 $f1,12($30)
#In assignment expressiono
#ID :arr
#0
# <--------------------------------------- dynamic type DOUBLEArray ---------------------------------------> 
# <--------------------------------------- dynamic type after DOUBLE ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: DOUBLE | -21868 | 2 | 0 | 0
#arr: DOUBLEArray | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,4
sw $2,-21868($30)# ----------------------------------------
lw $5,-21868($30)
li $2,16
subu $5,$2,$5
addu $5,$5,$30
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: DOUBLE | -21868 | 2 | 0 | 0
#arr: DOUBLEArray | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
lui $2,%hi($LC_5)
lwc1 $f0,%lo($LC_5+4)($2)
nop 
lwc1 $f1,%lo($LC_5)($2)
sw $3,-21868($30)# ----------------------------------------
sw $3,0($5)
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | -21868 | 2 | 0 | 0
#arr: DOUBLEArray | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: arr-------------------------->
#Condition Expression TYPE: DOUBLE
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: DOUBLE | -21868 | 2 | 0 | 0
#arr: DOUBLEArray | 16 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,4
sw $2,-21868($30)# ----------------------------------------
lw $5,-21868($30)
nop 
sll $5,$5,3
li $2,16
subu $5,$2,$5
addu $5,$5,$30
lw $2,0($5)
sw $2,-21868($30)
sw $2,-21868($30)# ----------------------------------------
b L_7
L_7:
nop
move $29,$30
lw $30,20($29)
addiu $29,$29,24
jr $31
nop
.end  f
$LC_0:
      .double   1
$LC_1:
      .double   2
$LC_2:
      .double   3
$LC_3:
      .double   4
$LC_4:
      .double   5
$LC_5:
      .double   9
