# <------------------------------ statment ----------------------> 
# <------------------------------ statment ----------------------> 
# <------------------------------ statment ----------------------> 
# <------------------------------ statment ----------------------> 
# <------------------------------ statment ----------------------> 
# <---------------------- Declaration ------------------>
.text
.globl search
.ent  search
search:
addiu $29,$29,-112
sw $30,108($29)
move $30,$29
#inside argument load
sw $4,112($30)
move $2,$5
sb $2,116($30)
#inside compound_statement
#stage 1
b L_1


L_2:
#inside compound_statement
#stage 1
# ID: # Tried to obtain sth not exited
#Condition Expression TYPE: 
#<--------------------------------------Cloest ID # Tried to obtain sth not exited---------------------------------->
#<--------------------------------------Context---------------------------------->
lw $3,112($30)
nop 
lb $3,0($3)
lb $4,116($30)
lw $3,112($30)
nop 
lb $3,0($3)
lb $4,116($30)
nop
xor $2,$3,$4
sltu $2,$2,1
andi $2,$2,0x00ff
sw $2,16($30)
sw $2,16($30)# ----------------------------------------
beq $2,$0,L_4
nop

#inside compound_statement
#stage 1
#inside return MIPS
# ID: x
# TYPE: CHARPTR
#Condition Expression TYPE: 
lw $2,112($30)
sw $2,16($30)
b L_0

L_4:
#<--------------------------------------Cloest ID x---------------------------------->
#<--------------------------------------Context---------------------------------->
#<--------------------------------------type CHARPTR---------------------------------->
lw $3,112($30)
li $4,1
lw $3,112($30)
li $4,1
nop
addu $2,$3,$4
sw $2,16($30)
sw $2,16($30)# ----------------------------------------
sw $2,112($30)


L_1: 
# ID: # Tried to obtain sth not exited
#Condition Expression TYPE: 
lw $2,112($30)
nop 
lb $2,0($2)
sw $2,16($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

#inside return MIPS
# ID: $INT
#Condition Expression TYPE: 
li $2,0
sw $2,16($30)
b L_0
L_0:
nop
move $29,$30
lw $30,108($29)
addiu $29,$29,112
jr $31
nop
.end  search
