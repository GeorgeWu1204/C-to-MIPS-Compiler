.text
.globl g
.ent  g
g:
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
li $3,0
li $4,1
li $3,0
li $4,1
nop
addu $2,$3,$4
sw $2,24($30)
sw $2,24($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,28($29)
addiu $29,$29,32
jr $31
nop
.end  g
