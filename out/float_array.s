LC_6:
.double       1
.double       2
.double       3
.double       4
.double       5
.text
.globl f
.ent  f
f:
addiu $29,$29,-64
sw $30,60($29)
move $30,$29
lui $2,%hi($LC_0)
lwc1 $f0,%lo($LC_0+4)($2)
nop 
lwc1 $f1,%lo($LC_0)($2)
lui $2,%hi($LC_1)
lwc1 $f0,%lo($LC_1+4)($2)
nop 
lwc1 $f1,%lo($LC_1)($2)
lui $2,%hi($LC_2)
lwc1 $f0,%lo($LC_2+4)($2)
nop 
lwc1 $f1,%lo($LC_2)($2)
lui $2,%hi($LC_3)
lwc1 $f0,%lo($LC_3+4)($2)
nop 
lwc1 $f1,%lo($LC_3)($2)
lui $2,%hi($LC_4)
lwc1 $f0,%lo($LC_4+4)($2)
nop 
lwc1 $f1,%lo($LC_4)($2)
li $2,4
sw $2,16($30)# ----------------------------------------
lw $5,16($30)
li $2,56
subu $5,$2,$5
addu $5,$5,$30
lui $2,%hi($LC_5)
lwc1 $f0,%lo($LC_5+4)($2)
nop 
lwc1 $f1,%lo($LC_5)($2)
sw $3,16($30)# ----------------------------------------
sw $3,0($5)
b L_7
L_7:
nop
move $29,$30
lw $30,60($29)
addiu $29,$29,64
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
