.text
.globl f
.ent  f
f:
addiu $29,$29,-112
sw $30,108($29)
move $30,$29
li $2,0
sw $2,16($30)# ----------------------------------------
sw $2,100($30)
li $2,0
sw $2,16($30)# ----------------------------------------
sw $2,104($30)
b  L_1


L_2:
lw $3,100($30)
li $4,1
lw $3,100($30)
li $4,1
nop
subu $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
sw $2,100($30)
L_4:
nop
lw $3,104($30)
li $4,1
lw $3,104($30)
li $4,1
nop
addu $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
sw $2,104($30)


L_1:
lw $3,104($30)
li $4,10
lw $3,104($30)
li $4,10
nop
slt $2,$3,$4
sw $2,8($30)
sw $2,12($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

lw $2,100($30)
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,108($29)
addiu $29,$29,112
jr $31
nop
.end  f
