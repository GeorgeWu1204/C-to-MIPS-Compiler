int g()
{
    char *x="\\";
    return x[0];
}


        // lui     $2,%hi($LC0)
        // addiu   $2,$2,%lo($LC0)
        // sw      $2,8($fp)