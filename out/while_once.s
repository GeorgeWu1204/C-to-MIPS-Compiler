.text
.globl f
.ent  f
f:
addiu $29,$29,-32
sw $30,28($29)
move $30,$29
li $2,1
sw $2,12($30)# ----------------------------------------
sw $2,24($30)
b L_1


L_2:
li $2,0
sw $2,12($30)# ----------------------------------------
sw $2,24($30)


L_1: 
lw $2,24($30)
sw $2,12($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

li $2,19937
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,28($29)
addiu $29,$29,32
jr $31
nop
.end  f
