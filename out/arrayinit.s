.text
.globl f
.ent  f
f:
addiu $29,$29,-40
sw $30,36($29)
move $30,$29
li $2,1
sw $2,12($30)# ----------------------------------------
sw $2,32($30)
li $2,3
sw $2,12($30)# ----------------------------------------
sw $2,28($30)
li $2,5
sw $2,12($30)# ----------------------------------------
sw $2,24($30)
li $2,22
sw $2,12($30)# ----------------------------------------
sw $2,20($30)
li $2,69
sw $2,12($30)# ----------------------------------------
sw $2,16($30)
li $2,3
sw $2,12($30)# ----------------------------------------
lw $5,12($30)
nop 
sll $5,$5,2
li $2,32
subu $5,$2,$5
addu $5,$5,$30
lw $2,0($5)
sw $2,12($30)
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,36($29)
addiu $29,$29,40
jr $31
nop
.end  f
