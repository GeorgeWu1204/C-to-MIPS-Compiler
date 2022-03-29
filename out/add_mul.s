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
lwc1 $f2,40($30)
lwc1 $f2,44($30)
lwc1 $f4,48($30)
lwc1 $f2,44($30)
lwc1 $f4,48($30)
nop
mul.s $f4,$f2,$f4
swc1 $f4,28($30)
lwc1 $f2,40($30)
lwc1 $f4,28($30)
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
