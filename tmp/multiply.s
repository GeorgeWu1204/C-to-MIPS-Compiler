#start to test
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 1-------------->
########################## dynamic computation 1
#stage 10
#build complete fully
########################## dynamic computation 1
########################## dynamic computation 1
#build complete fully
#<----------------is init declaration----------------->
#<----------------is identifier init declaration----------------->
# <----------------------Init_Declarator_Mips: ------------------------>
########################## dynamic computation 1
########################## dynamic computation 10
########################## dynamic computation 1
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 0-------------->
########################## dynamic computation 1
#stage 10
#build complete fully
# <---------------------- Declaration ------------------>
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
#inside compound_statement
##------------------- ASA dynamic offset  80
#stage 1
# <---------------------- Declaration ------------------>
# declaration is init
# declaration NOT in float
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 96 | 4 | 0 | 0
#$functioncall: FunctionCal | 16 | 5 | 1 | 0
#1Subcontext: SUBCONTEXT | 128 | 2 | 0 | 0
#2Subcontext: SUBCONTEXT | 104 | 3 | 0 | 0
#acc: INT | 132 | 1 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,0
sw $2,96($30)# ----------------------------------------
sw $2,132($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 96 | 4 | 0 | 0
#$functioncall: FunctionCal | 16 | 5 | 1 | 0
#1Subcontext: SUBCONTEXT | 128 | 2 | 0 | 0
#2Subcontext: SUBCONTEXT | 104 | 3 | 0 | 0
#acc: INT | 132 | 1 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
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

#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 96 | 1 | 0 | 0
#$functioncall: FunctionCal | 120 | 2 | 1 | 0
#acc: INT | 132 | 3 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 96 | 1 | 0 | 0
#$functioncall: FunctionCal | 120 | 2 | 1 | 0
#acc: INT | 132 | 3 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $4,144($30)
nop
 subu $4,$0,$4
sw $4,96($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 96 | 1 | 0 | 0
#$functioncall: FunctionCal | 120 | 2 | 1 | 0
#acc: INT | 132 | 3 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
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
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#In assignment expressiono
#ID :acc
#0
# <--------------------------------------- dynamic type INT ---------------------------------------> 
# <--------------------------------------- dynamic type after INT ---------------------------------------> 
# dynamic done
lw $3,132($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 96 | 1 | 0 | 0
#$functioncall: FunctionCal | 16 | 6 | 1 | 0
#acc: INT | 132 | 2 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $4,148($30)
sw $4,96($30)# ----------------------------------------
lw $3,132($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: INT | 96 | 1 | 0 | 0
#$functioncall: FunctionCal | 16 | 6 | 1 | 0
#acc: INT | 132 | 2 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $4,148($30)
sw $4,96($30)# ----------------------------------------
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sw $2,92($30)
sw $2,132($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 96 | 1 | 0 | 0
#$functioncall: FunctionCal | 16 | 6 | 1 | 0
#acc: INT | 132 | 2 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $2,144($30)
nop
addiu $3,$2,-1
sw $3,144($30)
sw $2,96($30)# ----------------------------------------


L_2: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 96 | 4 | 0 | 0
#$functioncall: FunctionCal | 16 | 5 | 1 | 0
#1Subcontext: SUBCONTEXT | 128 | 2 | 1 | 0
#2Subcontext: SUBCONTEXT | 104 | 3 | 1 | 0
#acc: INT | 132 | 1 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
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

#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 96 | 4 | 0 | 0
#$functioncall: FunctionCal | 16 | 5 | 1 | 0
#1Subcontext: SUBCONTEXT | 128 | 2 | 1 | 0
#2Subcontext: SUBCONTEXT | 104 | 3 | 1 | 0
#acc: INT | 132 | 1 | 1 | 0
#x: INT | 144 | 0 | 1 | 0
#y: INT | 148 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: acc-------------------------->
#Condition Expression TYPE: INT
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
