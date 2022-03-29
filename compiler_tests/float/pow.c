float f(float x, int n)
{
    float acc=1.0f;
    int i=0;
    while(i<n){
        i++;
        acc=acc*x;
    }
    return acc;
}




f:
        addiu   $sp,$sp,-24
        sw      $fp,20($sp)
        move    $fp,$sp

        swc1    $f12,24($fp)
        sw      $5,28($fp)
        lui     $2,%hi($LC0)
        lwc1    $f0,%lo($LC0)($2)
        nop
        swc1    $f0,8($fp)
        sw      $0,12($fp)
        b       $L2
        nop

$L3:
        lw      $2,12($fp)
        nop
        addiu   $2,$2,1
        sw      $2,12($fp)
        lwc1    $f2,8($fp)
        lwc1    $f0,24($fp)
        nop
        mul.s   $f0,$f2,$f0
        swc1    $f0,8($fp)
$L2:
        lw      $3,12($fp)
        lw      $2,28($fp)
        nop
        slt     $2,$3,$2
        bne     $2,$0,$L3
        nop

        lwc1    $f0,8($fp)
        move    $sp,$fp
        lw      $fp,20($sp)
        addiu   $sp,$sp,24
        j       $31
        nop
