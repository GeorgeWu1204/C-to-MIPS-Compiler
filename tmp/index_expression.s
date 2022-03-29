#start to test
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 2
########################## dynamic computation 1
########################## dynamic computation 9
#build complete fully
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 2
########################## dynamic computation 1
########################## dynamic computation 9
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 1
########################## dynamic computation 1
########################## dynamic computation 1
########################## dynamic computation 1
########################## dynamic computation 1
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 0-------------->
########################## dynamic computation 1
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-224
sw $30,220($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
# <---------------------- Declaration ------------------>
# <---------------------- Declaration ------------------>
# <---------------------- Declaration ------------------>
#In assignment expressiono
#ID :i
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 6 | 0 | 0
#3Subcontext: SUBCONTEXT | 176 | 4 | 0 | 0
#5Subcontext: SUBCONTEXT | 96 | 5 | 0 | 0
#acc: INT | 180 | 3 | 1 | 0
#i: INT | 216 | 1 | 1 | 0
#x: INTArray | 212 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,8
sw $2,16($30)# ----------------------------------------
sw $2,216($30)
b  L_1


L_2:
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#In assignment expressiono
#ID :x
#0
# <--------------------------------------- dynamic type INTArray ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#acc: INT | 180 | 4 | 1 | 0
#i: INT | 216 | 2 | 1 | 0
#x: INTArray | 212 | 3 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,216($30)
li $4,8
lw $3,216($30)
li $4,8
# found 1
nop
subu $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
lw $5,16($30)
sll $5,$5,2
li $2,212
subu $5,$2,$5
addu $5,$5,$30
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#acc: INT | 180 | 4 | 1 | 0
#i: INT | 216 | 2 | 1 | 0
#x: INTArray | 212 | 3 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,216($30)
sw $3,12($30)# ----------------------------------------
sw $3,0($5)
L_4:
nop
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 6 | 0 | 0
#3Subcontext: SUBCONTEXT | 176 | 4 | 1 | 0
#5Subcontext: SUBCONTEXT | 96 | 5 | 0 | 0
#acc: INT | 180 | 3 | 1 | 0
#i: INT | 216 | 1 | 1 | 0
#x: INTArray | 212 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $2,216($30)
nop
addiu $3,$2,1
sw $3, 216($30)
sw $2,16($30)# ----------------------------------------


L_1:
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 6 | 0 | 0
#3Subcontext: SUBCONTEXT | 176 | 4 | 1 | 0
#5Subcontext: SUBCONTEXT | 96 | 5 | 0 | 0
#acc: INT | 180 | 3 | 1 | 0
#i: INT | 216 | 1 | 1 | 0
#x: INTArray | 212 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,216($30)
li $4,16
lw $3,216($30)
li $4,16
nop
slt $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

#In assignment expressiono
#ID :acc
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 6 | 0 | 0
#3Subcontext: SUBCONTEXT | 176 | 4 | 1 | 0
#5Subcontext: SUBCONTEXT | 96 | 5 | 0 | 0
#acc: INT | 180 | 3 | 1 | 0
#i: INT | 216 | 1 | 1 | 0
#x: INTArray | 212 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,16($30)# ----------------------------------------
sw $2,180($30)
#In assignment expressiono
#ID :i
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 6 | 0 | 0
#3Subcontext: SUBCONTEXT | 176 | 4 | 1 | 0
#5Subcontext: SUBCONTEXT | 96 | 5 | 0 | 0
#acc: INT | 180 | 3 | 1 | 0
#i: INT | 216 | 1 | 1 | 0
#x: INTArray | 212 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,0
sw $2,16($30)# ----------------------------------------
sw $2,216($30)
b  L_5


L_6:
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#In assignment expressiono
#ID :acc
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#acc: INT | 180 | 4 | 1 | 0
#i: INT | 216 | 2 | 1 | 0
#x: INTArray | 212 | 3 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,180($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 1 | 0 | 0
#acc: INT | 180 | 4 | 1 | 0
#i: INT | 216 | 2 | 1 | 0
#x: INTArray | 212 | 3 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,216($30)
li $4,0
lw $3,216($30)
li $4,0
# dynamic context ?
#type: INT
nop
addu $4,$3,$4
sw $4,12($30)
sw $4,16($30)# ----------------------------------------
lw $5,16($30)
nop 
sll $5,$5,2
li $4,212
subu $5,$4,$5
addu $5,$5,$30
lw $4,0($5)
sw $4,12($30)
lw $3,180($30)
lw $4,12($30)
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sw $2,8($30)
sw $2,16($30)# ----------------------------------------
sw $2,180($30)
L_8:
nop
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 6 | 0 | 0
#3Subcontext: SUBCONTEXT | 176 | 4 | 1 | 0
#5Subcontext: SUBCONTEXT | 96 | 5 | 1 | 0
#acc: INT | 180 | 3 | 1 | 0
#i: INT | 216 | 1 | 1 | 0
#x: INTArray | 212 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $2,216($30)
nop
addiu $3,$2,1
sw $3, 216($30)
sw $2,16($30)# ----------------------------------------


L_5:
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 16 | 6 | 0 | 0
#3Subcontext: SUBCONTEXT | 176 | 4 | 1 | 0
#5Subcontext: SUBCONTEXT | 96 | 5 | 1 | 0
#acc: INT | 180 | 3 | 1 | 0
#i: INT | 216 | 1 | 1 | 0
#x: INTArray | 212 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,216($30)
li $4,8
lw $3,216($30)
li $4,8
nop
slt $2,$3,$4
sw $2,12($30)
sw $2,16($30)# ----------------------------------------
bne $2,$0,L_6
nop

L_7: 

#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 6 | 0 | 0
#3Subcontext: SUBCONTEXT | 176 | 4 | 1 | 0
#5Subcontext: SUBCONTEXT | 96 | 5 | 1 | 0
#acc: INT | 180 | 3 | 1 | 0
#i: INT | 216 | 1 | 1 | 0
#x: INTArray | 212 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: acc-------------------------->
#Condition Expression TYPE: INT
lw $2,180($30)
sw $2,16($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,220($29)
addiu $29,$29,224
jr $31
nop
.end  f
