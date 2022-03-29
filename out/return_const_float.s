.text
.globl f
.ent  f
f:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
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
