.text
.globl f
.ent  f
f:
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
lui $2,%hi($LC_0)
lwc1 $f0,%lo($LC_0+4)($2)
nop 
lwc1 $f1,%lo($LC_0)($2)
lwc1 $f0,24($30)
nop 
lwc1 $f1,20($30)
b L_1
L_1:
nop
move $29,$30
lw $30,28($29)
addiu $29,$29,32
jr $31
nop
.end  f
$LC_0:
      .double   45
