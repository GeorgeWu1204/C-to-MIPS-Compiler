#!/bin/bash


if which dos2unix ; then
    DOS2UNIX="dos2unix"
elif which fromdos ; then
    DOS2UNIX="fromdos"
else
    >&2 echo "warning: dos2unix is not installed."
    # This should work on Linux and MacOS, it matches all the carriage returns with sed and removes
    # them.  `tr` is used instead of `sed` because some versions of `sed` don't recognize the
    # carriage return symbol.  Something similar could be implemented with `sed` if necessary or
    # worst case it could be disabled by substituting it with `cat`.  One other thing to note is
    # that there are no quotes around the \r, which is so that it gets converted by bash.
    DOS2UNIX="tr -d \r"
    # DOS2UNIX="sed -e s/\r//g"
    # DOS2UNIX="cat"
fi
echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
echo " Force building compiler"
make bin/c_compiler -B

bin/c_compiler -S ../compiler_tests/my_test/test1.c -o test_program.s

#mips-linux-gnu-gcc -mfp32 -o test_program.o -c test_program.s

#mips-linux-gnu-gcc -mfp32 -static -o test_program test_program.o test_program_driver.c

