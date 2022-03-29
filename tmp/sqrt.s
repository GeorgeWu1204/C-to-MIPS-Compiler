#start to test
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 1
#build complete fully
#<----------------is init declaration----------------->
#<----------------is identifier init declaration----------------->
# <----------------------Init_Declarator_Mips: ------------------------>
########################## dynamic computation 1
#<----------------is init declaration----------------->
#<----------------is identifier init declaration----------------->
# <----------------------Init_Declarator_Mips: ------------------------>
########################## dynamic computation 1
########################## dynamic computation 18
#build complete fully
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 0-------------->
########################## dynamic computation 1
#build complete fully
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 0-------------->
########################## dynamic computation 1
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 19
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl bsqrt
.ent  bsqrt
bsqrt:
addiu $29,$29,-352
sw $30,348($29)
move $30,$29
#inside argument load
sw $4,352($30)
sw $5,356($30)
sw $6,360($30)
#inside compound_statement
##------------------- ASA dynamic offset  152
#stage 1
b L_1


L_2:
#inside compound_statement
##------------------- ASA dynamic offset  144
#stage 1
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 160 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 336 | 3 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#mid: INT | 344 | 1 | 1 | 0
#sqr: INT | 340 | 2 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: lo-------------------------->
#Condition Expression TYPE: INT
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 160 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 336 | 3 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#mid: INT | 344 | 1 | 1 | 0
#sqr: INT | 340 | 2 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,352($30)
lw $4,356($30)
lw $3,352($30)
lw $4,356($30)
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,156($30)
sw $3,160($30)# ----------------------------------------
li $4,1
lw $3,160($30)
li $4,1
nop
sra $2,$3, $4
sw $2,152($30)
sw $2,160($30)# ----------------------------------------
sw $2,344($30)
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 160 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 336 | 3 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#mid: INT | 344 | 1 | 1 | 0
#sqr: INT | 340 | 2 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: mid-------------------------->
#Condition Expression TYPE: INT
#<--------------------------------------Cloest ID mid---------------------------------->
#<--------------------------------------Context---------------------------------->
#<--------------------------------------type INT---------------------------------->
lw $3,344($30)
lw $4,344($30)
lw $3,344($30)
lw $4,344($30)
nop
mult $3,$4
mflo $2
sw $2,156($30)
sw $2,160($30)# ----------------------------------------
sw $2,340($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 160 | 4 | 0 | 0
#2Subcontext: SUBCONTEXT | 336 | 3 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#mid: INT | 344 | 1 | 1 | 0
#sqr: INT | 340 | 2 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: sqr-------------------------->
#Condition Expression TYPE: INT
lw $3,340($30)
lw $4,360($30)
lw $3,340($30)
lw $4,360($30)
nop
addiu $4,$4,1
slt $2,$3, $4
andi $2,$2,0x00ff
sw $2,156($30)
sw $2,160($30)# ----------------------------------------
beq $2,$0,L_5
nop


#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#In assignment expressiono
#ID :lo
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 160 | 1 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#mid: INT | 344 | 2 | 1 | 0
#sqr: INT | 340 | 3 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $2,344($30)
sw $2,160($30)# ----------------------------------------
sw $2,352($30)
b L_4
nop 

L_5:
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#In assignment expressiono
#ID :hi
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 160 | 1 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#mid: INT | 344 | 2 | 1 | 0
#sqr: INT | 340 | 3 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $2,344($30)
sw $2,160($30)# ----------------------------------------
sw $2,356($30)


L_4:


L_1: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 160 | 3 | 0 | 0
#0Subcontext: SUBCONTEXT | 344 | 1 | 1 | 0
#1Subcontext: SUBCONTEXT | 176 | 2 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: lo-------------------------->
#Condition Expression TYPE: INT
lw $3,352($30)
li $4,1
lw $3,352($30)
li $4,1
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,156($30)
lw $4,356($30)
lw $3,156($30)
lw $4,356($30)
nop
slt $2,$3,$4
sw $2,152($30)
sw $2,160($30)# ----------------------------------------
bne $2,$0,L_2
nop

L_3: 

#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 160 | 3 | 0 | 0
#0Subcontext: SUBCONTEXT | 344 | 1 | 1 | 0
#1Subcontext: SUBCONTEXT | 176 | 2 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: lo-------------------------->
#Condition Expression TYPE: INT
#<--------------------------------------Cloest ID lo---------------------------------->
#<--------------------------------------Context---------------------------------->
#<--------------------------------------type INT---------------------------------->
lw $3,352($30)
lw $4,352($30)
lw $3,352($30)
lw $4,352($30)
nop
mult $3,$4
mflo $3
sw $3,156($30)
lw $4,360($30)
lw $3,156($30)
lw $4,360($30)
nop
slt $2,$3,$4
sw $2,152($30)
sw $2,160($30)# ----------------------------------------
beq $2,$0,L_7
nop


#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 160 | 1 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: hi-------------------------->
#Condition Expression TYPE: INT
lw $2,356($30)
sw $2,160($30)# ----------------------------------------
b L_0
b L_6
nop 

L_7:
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 160 | 1 | 0 | 0
#hi: INT | 356 | 0 | 1 | 0
#lo: INT | 352 | 0 | 1 | 0
#val: INT | 360 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: lo-------------------------->
#Condition Expression TYPE: INT
lw $2,352($30)
sw $2,160($30)# ----------------------------------------
b L_0


L_6:
L_0:
nop
move $29,$30
lw $30,348($29)
addiu $29,$29,352
jr $31
nop
.end  bsqrt
