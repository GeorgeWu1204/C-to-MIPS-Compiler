.text
.globl g
.ent  g
g:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
li $2,104
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,20($29)
addiu $29,$29,24
jr $31
nop
.end  g
