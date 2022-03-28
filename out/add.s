#Tmp Dynamic Size identification0
#Dynamic Size identification1
.text
.globl f
.ent  f
f:
addiu $29,$29,-24
sw $30,20($29)
move $30,$29
sw $4,24($30)
sw $5,28($30)
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#TOPcontext: SUBCONTEXT | 16 | 1 | 1 | 0
#a: INT | 24 | 0 | 1 | 0
#b: INT | 28 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#inside Local Var Waiting for Declared
##False
##False
#
#
#inside Local Var: Name : Type | Offset | Index | Is_called | Enum val
#$DynamicContext: NotDefined | 16 | 1 | 0 | 0
#a: INT | 24 | 0 | 1 | 0
#b: INT | 28 | 0 | 1 | 0
#inside Local Var Waiting for Declared
#
lw $3,24($30)
lw $4,28($30)
#Dynamic Offset: 16
lw $3,24($30)
lw $4,28($30)
nop
addu $2,$3,$4
sw $2,16($30)
nop
move $29,$30
lw $30,20($29)
addiu $29,$29,24
jr $31
nop
.end  f
