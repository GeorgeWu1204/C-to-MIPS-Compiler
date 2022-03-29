.text
.globl f
.ent  f
f:
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
#inside argument load
sw $4,32($30)
lw $3,32($30)
li $4,10
lw $3,32($30)
li $4,10
nop
addu $2,$3,$4
sw $2,20($30)
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
