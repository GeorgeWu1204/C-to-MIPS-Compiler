.globl arr
.data 
.size arr,12
arr:
        .word 69
        .word 420
        .word 21
.text
.globl f
.ent  f
f:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
li $2,1
sw $2,16($30)# ----------------------------------------
lw $5,16($30)
lui $2,%hi(arr)
addiu $2,$2,%lo(arr)
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
