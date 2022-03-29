TEST_FOLDER="compiler_tests"

clear
echo "========================================"
echo " Cleaning the temporaries and outputs"


echo ""
make bin/c_compiler
echo "========================================="

PASSED=0
CHECKED=0

for TEST_DIR in "${TEST_FOLDER}"/*; do
  for test_driver in ${TEST_DIR}/*_driver.c; do
      test=$(basename "${test_driver}")
      test=${test%_driver.c}
      CHECKED=$((CHECKED+1))

      echo "==========================="
      echo ""
      echo "Testing : ${test}"

      bin/c_compiler -S ${TEST_DIR}/${test}.c -o tmp/${test}.s
      mips-linux-gnu-gcc -mfp32 -o tmp/${test}.o  -c tmp/${test}.s
      mips-linux-gnu-gcc -mfp32 -static -o tmp/${test} tmp/${test}.o ${TEST_DIR}/${test}_driver.c
      qemu-mips tmp/${test}
      res=$?
      # echo "Result returned: ${res}"
      if (( ${res} == 0 )); then
        # echo pass
        PASSED=$((PASSED+1))
      else
        echo "fail ${test}"
      fi
  done
done


echo "Test finish, passed ${PASSED}/${CHECKED}"