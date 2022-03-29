$LC_0:
      .ascii  "wibble\000"
.align  2
.text
.globl g
.ent  g
g:
addiu $29,$29,-40
sw $31,36($29)
sw $30,32($29)
move $30,$29
lui $4,%hi($LC_0)
addiu $4,$4,%lo($LC_0)
sw $4,28($30)# ----------------------------------------
jal fakeputs
sw $2,28($30)
sw $2,28($30)# ----------------------------------------
L_1:
nop
move $29,$30
lw $31,36($29)
lw $30,32($29)
addiu $29,$29,40
jr $31
nop
.end  g
