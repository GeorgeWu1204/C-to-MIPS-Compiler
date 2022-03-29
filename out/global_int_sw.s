.globl x
.data 
.size x,4
x:
        .word 42
.text
.globl f
.ent  f
f:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
#inside argument load
sw $4,24($30)
lw $3,24($30)
sw $3,16($30)# ----------------------------------------
lui $2,%hi(x)
sw $3,%lo(x)($2)
lui $2,%hi(x)
lw $2,%lo(x)($2)
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,20($29)
addiu $29,$29,24
jr $31
nop
.end  f
