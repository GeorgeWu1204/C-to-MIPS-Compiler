#start to test
# <----------------------input : "wibble"------------------------>
#stage 5  |  Return function namefakeputs
# <----------------------push back: wibble------------------------>
########################## dynamic computation 1
#stage 10
#build complete fully
$LC_0:
      .ascii  "wibble\000"
.align  2
# <---------------------- Declaration ------------------>
.text
.globl g
.ent  g
g:
addiu $29,$29,-40
sw $31,36($29)
sw $30,32($29)
move $30,$29
#inside compound_statement
##------------------- ASA dynamic offset  8
#stage 1
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 28 | 1 | 0 | 0
#$functioncall: FunctionCal | 20 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
#<--------------------------Condition_Expression ID: # Tried to obtain sth not exited-------------------------->
#Condition Expression TYPE: 
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext:  | 28 | 1 | 0 | 0
#$functioncall: FunctionCal | 20 | 2 | 1 | 0
#inside Local Var Waiting for Declared
#
lui $4,%hi($LC_0)
addiu $4,$4,%lo($LC_0)
sw $4,28($30)# ----------------------------------------
jal fakeputs
sw $2,28($30)
sw $2,28($30)# ----------------------------------------
L_1:
nop
move $29,$30
lw $31,36($29)
lw $30,32($29)
addiu $29,$29,40
jr $31
nop
.end  g
