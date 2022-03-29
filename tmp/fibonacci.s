#start to test
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
########################## dynamic computation 10
########################## dynamic computation 10
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 2-------------->
# how mang param in function  :1-------------->
########################## dynamic computation 2
#stage 10
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl fib
.ent  fib
fib:
addiu $29,$29,-128
sw $31,124($29)
sw $30,120($29)
move $30,$29
#inside argument load
sw $4,128($30)
#inside compound_statement
##------------------- ASA dynamic offset  80
#stage 1
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 100 | 3 | 0 | 0
#$functioncall: FunctionCal | 20 | 4 | 1 | 0
#0Subcontext: SUBCONTEXT | 116 | 1 | 0 | 0
#1Subcontext: SUBCONTEXT | 108 | 2 | 0 | 0
#x: INT | 128 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $3,128($30)
li $4,0
lw $3,128($30)
li $4,0
nop
addiu $4,$4,1
slt $2,$3, $4
andi $2,$2,0x00ff
sw $2,96($30)
sw $2,100($30)# ----------------------------------------
beq $2,$0,L_1
nop

#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 100 | 1 | 0 | 0
#x: INT | 128 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,0
sw $2,100($30)# ----------------------------------------
b L_0

L_1:
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 100 | 3 | 0 | 0
#$functioncall: FunctionCal | 20 | 4 | 1 | 0
#0Subcontext: SUBCONTEXT | 116 | 1 | 1 | 0
#1Subcontext: SUBCONTEXT | 108 | 2 | 0 | 0
#x: INT | 128 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
#<--------------------------------------Cloest ID x---------------------------------->
#<--------------------------------------Context---------------------------------->
#<--------------------------------------type INT---------------------------------->
lw $3,128($30)
li $4,1
lw $3,128($30)
li $4,1
nop
xor $2,$3,$4
sltu $2,$2,1
andi $2,$2,0x00ff
sw $2,96($30)
sw $2,100($30)# ----------------------------------------
beq $2,$0,L_2
nop

#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 100 | 1 | 0 | 0
#$functioncall: FunctionCal | 20 | 5 | 1 | 0
#x: INT | 128 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,1
sw $2,100($30)# ----------------------------------------
b L_0

L_2:
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 100 | 3 | 0 | 0
#$functioncall: FunctionCal | 20 | 4 | 1 | 0
#0Subcontext: SUBCONTEXT | 116 | 1 | 1 | 0
#1Subcontext: SUBCONTEXT | 108 | 2 | 1 | 0
#x: INT | 128 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 100 | 3 | 0 | 0
#$functioncall: FunctionCal | 20 | 4 | 1 | 0
#0Subcontext: SUBCONTEXT | 116 | 1 | 1 | 0
#1Subcontext: SUBCONTEXT | 108 | 2 | 1 | 0
#x: INT | 128 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,128($30)
li $4,1
lw $3,128($30)
li $4,1
# found 1
nop
subu $4,$3,$4
sw $4,100($30)
sw $4,100($30)# ----------------------------------------
jal fib
sw $2,100($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 100 | 3 | 0 | 0
#$functioncall: FunctionCal | 20 | 4 | 1 | 0
#0Subcontext: SUBCONTEXT | 116 | 1 | 1 | 0
#1Subcontext: SUBCONTEXT | 108 | 2 | 1 | 0
#x: INT | 128 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,128($30)
li $4,2
lw $3,128($30)
li $4,2
# found 1
nop
subu $4,$3,$4
sw $4,96($30)
sw $4,96($30)# ----------------------------------------
jal fib
sw $2,96($30)
lw $3,100($30)
lw $4,96($30)
# dynamic context ?
#type: 
nop
addu $2,$3,$4
sw $2,92($30)
sw $2,100($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $31,124($29)
lw $30,120($29)
addiu $29,$29,128
jr $31
nop
.end  fib
