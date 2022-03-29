#start to test
#<----------------is init declaration----------------->
#float vector return 1
#float vector return 2
#float vector return 3
#float vector return 4
#float vector return 5
#float vector return 6
#float vector return 7
#float vector done
#<----------------is array float declaration----------------->
########################## dynamic computation 1
#<----------------is init declaration----------------->
#float vector done
# <----------------------: Pointer? ------------------------>
#<----------------is pointer init declaration----------------->
########################## dynamic computation 1
########################## dynamic computation 1
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 1-------------->
# f1  0-------------->
########################## dynamic computation 1
#build complete fully
LC_7:
.float        1
.float        2
.float        3
.float        4
.float        5
.float        6
.float        7
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-56
sw $30,52($29)
move $30,$29

lui $2,%hi($LC_0)
lwc1 $f0,%lo($LC_0)($2)
swc1 $f0,48($30)
lui $2,%hi($LC_1)
lwc1 $f0,%lo($LC_1)($2)
swc1 $f0,44($30)
lui $2,%hi($LC_2)
lwc1 $f0,%lo($LC_2)($2)
swc1 $f0,40($30)
lui $2,%hi($LC_3)
lwc1 $f0,%lo($LC_3)($2)
swc1 $f0,36($30)
lui $2,%hi($LC_4)
lwc1 $f0,%lo($LC_4)($2)
swc1 $f0,32($30)
lui $2,%hi($LC_5)
lwc1 $f0,%lo($LC_5)($2)
swc1 $f0,28($30)
lui $2,%hi($LC_6)
lwc1 $f0,%lo($LC_6)($2)
swc1 $f0,24($30)
# <---------------------- Declaration ------------------>
# declaration is init
# declaration in floatergth
ininininini
inside the address scope
is in array
li $5,0
sll $5,$5,2
addiu $2,$30,48
subu $2,$2,$5
sw $2,20($30)
#In assignment expressiono
#ID :p
#0
# <--------------------------------------- dynamic type FLOATPTR ---------------------------------------> 
# <--------------------------------------- dynamic type after FLOAT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: FLOAT | 16 | 3 | 0 | 0
#p: FLOATPTR | 20 | 2 | 1 | 0
#x: FLOATArray | 48 | 1 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------------------Cloest ID p---------------------------------->
#<--------------------------------------Context---------------------------------->
#<--------------------------------------type FLOATPTR---------------------------------->
lw $3,20($30)
li $4,1
lw $3,20($30)
li $4,1
# dynamic context ?
#type: FLOAT
nop
sll $4, 2
addu $2,$3,$4
sw $2,16($30)
sw $2,16($30)# ----------------------------------------
sw $2,20($30)
#inside return MIPS
lw $0,20($30)
nop 
lwc1 $f0,0($0)
b L_8
L_8:
nop
move $29,$30
lw $30,52($29)
addiu $29,$29,56
jr $31
nop
.end  f
$LC_0:
     .float   1
$LC_1:
     .float   2
$LC_2:
     .float   3
$LC_3:
     .float   4
$LC_4:
     .float   5
$LC_5:
     .float   6
$LC_6:
     .float   7
