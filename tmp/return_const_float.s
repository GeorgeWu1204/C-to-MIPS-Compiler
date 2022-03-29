#start to test
# retuning -------------->
# retuning 1 -------------->
#<----------inside double return 6------------------>
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
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $DOUBLE-------------------------->
#Condition Expression TYPE: DOUBLE
lui $2,%hi($LC_0)
lwc1 $f0,%lo($LC_0+4)($2)
nop 
lwc1 $f1,%lo($LC_0)($2)
sw $2,16($30)# ----------------------------------------
b L_1
L_1:
nop
move $29,$30
lw $30,20($29)
addiu $29,$29,24
jr $31
nop
.end  f
$LC_0:
      .double   6
