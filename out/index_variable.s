.text
.globl f
.ent  f
f:
addiu $29,$29,-136
sw $30,132($29)
move $30,$29
li $2,0
sw $2,12($30)# ----------------------------------------
sw $2,128($30)
b  L_1


L_2:
lw $2,128($30)
sw $2,12($30)# ----------------------------------------
lw $5,12($30)
sll $5,$5,2
li $2,124
subu $5,$2,$5
addu $5,$5,$30
lw $3,128($30)
sw $3,12($30)# ----------------------------------------
sw $3,0($5)
L_4:
nop
lw $2,128($30)
nop
addiu $3,$2,1
sw $3, 128($30)
sw $2,12($30)# ----------------------------------------


L_1:
lw $3,128($30)
li $4,8
lw $3,128($30)
li $4,8
nop
slt $2,$3,$4
sw $2,8($30)
sw $2,12($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

li $2,4
sw $2,12($30)# ----------------------------------------
lw $5,12($30)
nop 
sll $5,$5,2
li $2,124
subu $5,$2,$5
addu $5,$5,$30
lw $2,0($5)
sw $2,12($30)
sw $2,12($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,132($29)
addiu $29,$29,136
jr $31
nop
.end  f
