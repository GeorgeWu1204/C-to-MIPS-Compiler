LC_5:
.float        1
.float        2
.float        3
.float        4
.float        5
.text
.globl f
.ent  f
f:
addiu $29,$29,-48
sw $30,44($29)
move $30,$29
lui $2,%hi($LC_0)
lwc1 $f0,%lo($LC_0+4)($2)
nop 
lwc1 $f1,%lo($LC_0)($2)
lui $2,%hi($LC_1)
lwc1 $f0,%lo($LC_1+4)($2)
nop 
lwc1 $f1,%lo($LC_1)($2)
lui $2,%hi($LC_2)
lwc1 $f0,%lo($LC_2+4)($2)
nop 
lwc1 $f1,%lo($LC_2)($2)
lui $2,%hi($LC_3)
lwc1 $f0,%lo($LC_3+4)($2)
nop 
lwc1 $f1,%lo($LC_3)($2)
lui $2,%hi($LC_4)
lwc1 $f0,%lo($LC_4+4)($2)
nop 
lwc1 $f1,%lo($LC_4)($2)
li $5,0
sll $5,$5,2
addiu $2,$30,40
subu $2,$2,$5
sw $2,20($30)
lw $3,20($30)
li $4,1
lw $3,20($30)
li $4,1
nop
sll $4, 2
addu $2,$3,$4
sw $2,16($30)
sw $2,16($30)# ----------------------------------------
sw $2,20($30)
lw $0,20($30)
nop 
lwc1 $f0,0($0)
b L_6
L_6:
nop
move $29,$30
lw $30,44($29)
addiu $29,$29,48
jr $31
nop
.end  f
$LC_0:
      .double   1
$LC_1:
      .double   2
$LC_2:
      .double   3
$LC_3:
      .double   4
$LC_4:
      .double   5
