.globl x
.data 
.size x,8
x:
        .double 99
.text
.globl f
.ent  f
f:
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
#inside argument load
swc1 $f12, 36($30)
swc1 $f13, 32($30)
lui $2,%hi(x)
lwc1 $f2,%lo(x+4)($2)
nop 
lwc1 $f3,%lo(x)($2)
nop 
lwc1 $f4,36($30)
nop 
lwc1 $f5,32($30)
lui $2,%hi(x)
lwc1 $f2,%lo(x+4)($2)
nop 
lwc1 $f3,%lo(x)($2)
nop 
lwc1 $f4,36($30)
nop 
lwc1 $f5,32($30)
nop
add.d $f0,$f2,$f4
swc1 $f0,20($30)
swc1 $f1,16($30)
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
