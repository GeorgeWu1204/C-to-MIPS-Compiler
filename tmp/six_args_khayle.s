#start to test
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 2-------------->
# f1  0-------------->
# f2 0-------------->
# f3 0-------------->
# f1  1-------------->
# f2 1-------------->
# f3 1-------------->
########################## dynamic computation 6
#build complete fully
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 7-------------->
# how mang param in function  :6-------------->
# how mang param in function  :6-------------->
# how mang param in function  :6-------------->
# how mang param in function  :6-------------->
# how mang param in function  :6-------------->
# how mang param in function  :6-------------->
########################## dynamic computation 1
#stage 10
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl g
.ent  g
g:
addiu $29,$29,-64
sw $30,60($29)
move $30,$29
#inside argument load
sw $4,64($30)
sw $5,68($30)
sw $6,72($30)
sw $7,76($30)
#inside compound_statement
##------------------- ASA dynamic offset  48
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 56 | 1 | 0 | 0
#a: INT | 76 | 0 | 1 | 0
#b: INT | 80 | 0 | 1 | 0
#c: INT | 84 | 0 | 1 | 0
#x: INT | 64 | 0 | 1 | 0
#y: INT | 68 | 0 | 1 | 0
#z: INT | 72 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: x-------------------------->
#Condition Expression TYPE: INT
lw $3,64($30)
lw $4,68($30)
lw $3,64($30)
lw $4,68($30)
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,52($30)
lw $4,72($30)
lw $3,52($30)
lw $4,72($30)
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,48($30)
lw $4,76($30)
lw $3,48($30)
lw $4,76($30)
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,44($30)
lw $4,80($30)
lw $3,44($30)
lw $4,80($30)
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,40($30)
lw $4,84($30)
lw $3,40($30)
lw $4,84($30)
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sra $2,$2,2
sw $2,36($30)
sw $2,56($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,60($29)
addiu $29,$29,64
jr $31
nop
.end  g
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-72
sw $31,68($29)
sw $30,64($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 60 | 1 | 0 | 0
#$functioncall: FunctionCal | 52 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 60 | 1 | 0 | 0
#$functioncall: FunctionCal | 52 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $4,1
sw $4,60($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 60 | 1 | 0 | 0
#$functioncall: FunctionCal | 52 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $5,2
sw $5,60($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 60 | 1 | 0 | 0
#$functioncall: FunctionCal | 52 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $6,3
sw $6,60($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 60 | 1 | 0 | 0
#$functioncall: FunctionCal | 52 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $7,4
sw $7,60($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 60 | 1 | 0 | 0
#$functioncall: FunctionCal | 52 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,5
sw $2,60($30)# ----------------------------------------
sw $2,16($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 60 | 1 | 0 | 0
#$functioncall: FunctionCal | 52 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,6
sw $2,60($30)# ----------------------------------------
sw $2,20($30)
jal g
sw $2,60($30)
sw $2,60($30)# ----------------------------------------
b L_1
L_1:
nop
move $29,$30
lw $31,68($29)
lw $30,64($29)
addiu $29,$29,72
jr $31
nop
.end  f
