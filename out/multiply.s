.text
.globl multiply
.ent  multiply
multiply:
addiu $29,$29,-144
sw $31,140($29)
sw $30,136($29)
move $30,$29
#inside argument load
sw $4,144($30)
sw $5,148($30)
li $2,0
sw $2,96($30)# ----------------------------------------
sw $2,132($30)
lw $3,144($30)
li $4,0
lw $3,144($30)
li $4,0
nop
slt $2,$3,$4
sw $2,92($30)
sw $2,96($30)# ----------------------------------------
beq $2,$0,L_1
nop

lw $4,144($30)
nop
 subu $4,$0,$4
sw $4,96($30)# ----------------------------------------
lw $5,148($30)
sw $5,96($30)# ----------------------------------------
jal multiply
sw $2,96($30)
nop
 subu $2,$0,$2
sw $2,96($30)# ----------------------------------------
b L_0

L_1:
b L_2


L_3:
lw $3,132($30)
lw $4,148($30)
sw $4,96($30)# ----------------------------------------
lw $3,132($30)
lw $4,148($30)
sw $4,96($30)# ----------------------------------------
nop
addu $2,$3,$4
sw $2,92($30)
sw $2,132($30)
lw $2,144($30)
nop
addiu $3,$2,-1
sw $3,144($30)
sw $2,96($30)# ----------------------------------------


L_2: 
lw $3,144($30)
li $4,0
lw $3,144($30)
li $4,0
nop
slt $2, $4 , $3 
sw $2,92($30)
sw $2,96($30)# ----------------------------------------
bne $2,$0,L_3
nop

L_4: 

lw $2,132($30)
sw $2,96($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $31,140($29)
lw $30,136($29)
addiu $29,$29,144
jr $31
nop
.end  multiply
