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
# how mang functions inside 2-------------->
# how mang param in function  :1-------------->
########################## dynamic computation 2
#stage 10
#build complete fully
########################## dynamic computation 26
#stage 10
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl r1
.ent  r1
r1:
addiu $29,$29,-280
sw $31,276($29)
sw $30,272($29)
move $30,$29
#inside argument load
sw $4,280($30)
#inside compound_statement
##------------------- ASA dynamic offset  208
#stage 1
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 228 | 2 | 0 | 0
#$functioncall: FunctionCal | 20 | 3 | 1 | 0
#0Subcontext: SUBCONTEXT | 268 | 1 | 0 | 0
#n: INT | 280 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: n-------------------------->
#Condition Expression TYPE: INT
#<--------------------------------------Cloest ID n---------------------------------->
#<--------------------------------------Context---------------------------------->
#<--------------------------------------type INT---------------------------------->
lw $3,280($30)
li $4,0
lw $3,280($30)
li $4,0
nop
xor $2,$3,$4
sltu $2,$2,1
andi $2,$2,0x00ff
sw $2,224($30)
sw $2,228($30)# ----------------------------------------
beq $2,$0,L_2
nop


#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 228 | 1 | 0 | 0
#$functioncall: FunctionCal | 20 | 4 | 1 | 0
#n: INT | 280 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: $INT-------------------------->
#Condition Expression TYPE: INT
li $2,1
sw $2,228($30)# ----------------------------------------
b L_0
b L_1
nop 

L_2:
#inside compound_statement
##------------------- ASA dynamic offset  16
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 228 | 1 | 0 | 0
#$functioncall: FunctionCal | -8 | 2 | 1 | 0
#n: INT | 280 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 228 | 1 | 0 | 0
#$functioncall: FunctionCal | -8 | 2 | 1 | 0
#n: INT | 280 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,280($30)
li $4,1
lw $3,280($30)
li $4,1
# found 1
nop
subu $4,$3,$4
sw $4,228($30)
sw $4,228($30)# ----------------------------------------
jal r2
sw $2,228($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 228 | 1 | 0 | 0
#$functioncall: FunctionCal | -8 | 2 | 1 | 0
#n: INT | 280 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,280($30)
li $4,1
lw $3,280($30)
li $4,1
# found 1
nop
subu $4,$3,$4
sw $4,224($30)
sw $4,224($30)# ----------------------------------------
jal r2
sw $2,224($30)
lw $3,228($30)
lw $4,224($30)
# dynamic context ?
#type: 
nop
addu $2,$3,$4
sw $2,220($30)
sw $2,228($30)# ----------------------------------------
b L_0


L_1:
L_0:
nop
move $29,$30
lw $31,276($29)
lw $30,272($29)
addiu $29,$29,280
jr $31
nop
.end  r1
