.text
.globl f
.ent  f
f:
addiu $29,$29,-40
sw $30,36($29)
move $30,$29
swc1 $f12, 40($30)
sw $5,44($30)


lui $2,%hi($LC_0)
lwc1 $f0,%lo($LC_0)($2)
li $2,0
sw $2,28($30)
b L_2


L_3:
lw $2,28($30)
nop
addiu $3,$2,1
sw $3, 28($30)

lwc1 $f2,32($30)
lwc1 $f4,40($30)

lwc1 $f2,32($30)
lwc1 $f4,40($30)
nop
mul.s $f2,$f2,$f4
swc1 $f2,12($30)


L_2: 
lw $3,28($30)
lw $4,44($30)
lw $3,28($30)
lw $4,44($30)
nop
slt $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
bne $2,$0,L_3
nop

L_4: 

lwc1 $f0,32($30)
b L_1
L_1:
nop
move $29,$30
lw $30,36($29)
addiu $29,$29,40
jr $31
nop
.end  f
$LC_0:
     .float   1
