.text
.globl f
.ent  f
f:
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
#inside argument load
sw $4,32($30)
sw $5,36($30)
lw $3,32($30)
lw $4,36($30)
lw $3,32($30)
lw $4,36($30)
nop
bne $3,$0,L_2
nop 
beq $4,$0,L_1
L_2:
nop 
li $2,1
b L_3
nop 

L_1:
move $2,$0

L_3:
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
