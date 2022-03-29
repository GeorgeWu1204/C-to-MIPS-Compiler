#start to test
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 2-------------->
# f1  0-------------->
# f2 0-------------->
# f3 0-------------->
# f1  1-------------->
# f2 1-------------->
# f3 1-------------->
########################## dynamic computation 3
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
swc1 $f14, 44($30)
sw $6,48($30)
#inside compound_statement
##------------------- ASA dynamic offset  24
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 32 | 1 | 0 | 0
#x: FLOAT | 40 | 0 | 1 | 0
#y: FLOAT | 44 | 0 | 1 | 0
#z: FLOAT | 48 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: FLOAT
#<--------------------------------------Left 2---------------------------------->
lwc1 $f2,40($30)
#<--------------------------------------Right 2---------------------------------->
lwc1 $f4,44($30)
# Generate Left Start 
lwc1 $f2,40($30)
# Generate Left Done
lwc1 $f4,44($30)
nop
mul.s $f2,$f2,$f4
swc1 $f2,28($30)
lwc1 $f4,48($30)
lwc1 $f2,28($30)
lwc1 $f4,48($30)
nop
add.s $f0,$f2,$f4
swc1 $f0,24($30)
sw $2,32($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,36($29)
addiu $29,$29,40
jr $31
nop
.end  f
