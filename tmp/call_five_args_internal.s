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
########################## dynamic computation 5
#build complete fully
# retuning -------------->
# retuning 1 -------------->
# retuning 2 -------------->
# retuning 3 -------------->
# retuning 4 -------------->
# how mang functions inside 6-------------->
# how mang param in function  :5-------------->
# how mang param in function  :5-------------->
# how mang param in function  :5-------------->
# how mang param in function  :5-------------->
# how mang param in function  :5-------------->
########################## dynamic computation 1
#stage 10
#build complete fully
# <---------------------- Declaration ------------------>
.text
.globl g
.ent  g
g:
addiu $29,$29,-56
sw $30,52($29)
move $30,$29
#inside argument load
sw $4,56($30)
sw $5,60($30)
sw $6,64($30)
sw $7,68($30)
#inside compound_statement
##------------------- ASA dynamic offset  40
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 48 | 1 | 0 | 0
#a: INT | 56 | 0 | 1 | 0
#b: INT | 60 | 0 | 1 | 0
#c: INT | 64 | 0 | 1 | 0
#d: INT | 68 | 0 | 1 | 0
#e: INT | 72 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: a-------------------------->
#Condition Expression TYPE: INT
lw $3,56($30)
lw $4,60($30)
lw $3,56($30)
lw $4,60($30)
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,44($30)
lw $4,64($30)
lw $3,44($30)
lw $4,64($30)
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,40($30)
lw $4,68($30)
lw $3,40($30)
lw $4,68($30)
# dynamic context ?
#type: INT
nop
addu $3,$3,$4
sw $3,36($30)
lw $4,72($30)
lw $3,36($30)
lw $4,72($30)
# dynamic context ?
#type: INT
nop
addu $2,$3,$4
sra $2,$2,2
sw $2,32($30)
sw $2,48($30)# ----------------------------------------
b L_0
L_0:
nop
move $29,$30
lw $30,52($29)
addiu $29,$29,56
jr $31
nop
.end  g
# <---------------------- Declaration ------------------>
.text
.globl f
.ent  f
f:
addiu $29,$29,-64
sw $31,60($29)
sw $30,56($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#inside return MIPS
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $4,1
sw $4,52($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $5,2
sw $5,52($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $6,3
sw $6,52($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $7,4
sw $7,52($30)# ----------------------------------------
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 52 | 1 | 0 | 0
#$functioncall: FunctionCal | 44 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
li $2,5
sw $2,52($30)# ----------------------------------------
sw $2,16($30)
jal g
sw $2,52($30)
sw $2,52($30)# ----------------------------------------
b L_1
L_1:
nop
move $29,$30
lw $31,60($29)
lw $30,56($29)
addiu $29,$29,64
jr $31
nop
.end  f
