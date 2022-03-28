

mips-linux-gnu-gcc -mfp32 -static -o my_test.o -c my_test.s

mips-linux-gnu-gcc -mfp32 -static -o my_test my_test.o compiler_tests/my_test_driver.c

qemu-mips my_test

echo $?