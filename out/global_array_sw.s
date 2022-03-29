.globl global
.data 
.size global,20
global:
.space 20
.text
.globl f
.ent  f
f:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
#inside argument load
sw $4,24($30)
li $2,3
sw $2,16($30)# ----------------------------------------
lui $2,%hi(global)
addiu $2,$2,%lo(global)
lw $5,16($30)
sll $5,$5,2
addu $5,$5,$2
lw $3,24($30)
li $4,1
lw $3,24($30)
li $4,1
nop
addu $3,$3,$4
sw $3,12($30)
sw $3,16($30)# ----------------------------------------
sw $3,0($5)
li $2,3
sw $2,16($30)# ----------------------------------------
lw $5,16($30)
lui $2,%hi(global)
addiu $2,$2,%lo(global)
sll $5,$5,2
addu $5,$5,$2
lw $2,0($5)
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
