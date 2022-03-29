.globl y
.data 
.size x,4
y:
        .float 3
.text
.globl f
.ent  f
f:
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
#inside argument load
swc1 $f12, 32($30)
lui $2,%hi(y)
lwc1 $f2,%lo(y)($2)
nop 
lwc1 $f4,32($30)
lui $2,%hi(y)
lwc1 $f2,%lo(y)($2)
nop 
lwc1 $f4,32($30)
nop
add.s $f0,$f2,$f4
swc1 $f0,20($30)
sw $2,24($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,28($29)
addiu $29,$29,32
jr $31
nop
.end  f
