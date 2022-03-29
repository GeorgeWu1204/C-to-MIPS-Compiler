#start to test
########################## dynamic computation 1
# retuning -------------->
########################## dynamic computation 1
#build complete fully
.globl x
.data 
.size x,4
x:
        .word 9
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
#inside argument load
sw $4,24($30)
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#In assignment expressiono
#ID :x
#1
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#inside global scope
lui $3,%hi(x)
lw $3,%lo(x)($3)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#y: INT | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $4,24($30)
sw $4,16($30)# ----------------------------------------
#inside global scope
lui $3,%hi(x)
lw $3,%lo(x)($3)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#y: INT | 24 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $4,24($30)
sw $4,16($30)# ----------------------------------------
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sra $3,$3,2
sw $3,12($30)
lui $2,%hi(x)
sw $3,%lo(x)($2)
#inside return MIPS
b L_0
L_0:
nop
move $29,$30
lw $30,20($29)
addiu $29,$29,24
jr $31
nop
.end  f
