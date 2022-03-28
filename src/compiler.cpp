#include <iostream>
#include "ast.hpp"

int main()
// int main(int argc, char *argv[])
{

    Context context;
    MakeName make_name;
    int dynamic_offset;
    std::cerr << "#"
              << "start to test" << std::endl;
    // std::string Test = "compiler_tests/my_test/test1.c";

    std::string Test = "compiler_tests/my_test.c";
    // const NodePtr ast = parseAST(argv[2]);
    // Node *ast = parseAST(argv[2]);
    const NodePtr ast = parseAST(Test);
    std::cerr << "#"
              << "after parser" << std::endl;
    std::cerr << "#"
              << "" << std::endl;
    std::cerr << "#"
              << "" << std::endl;
    // ast->get_Id();
    ast->generateMips(std::cout, context, 2, make_name, dynamic_offset);

    std::cerr << "#"
              << "Generate MIPS complete" << std::endl;
}

// #include<iostream>

// int main()
// {
// 	std::cerr << "#" << "f:" << std::endl;
// 	std::cerr << "#" << "PUSH0:" << std::endl;
// 	std::cerr << "#" << "addiu $sp, $sp, -44" << std::endl;
// 	std::cerr << "#" << "sw $ra, 40($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "sw $fp, 36($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "sw $s0, 4($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "sw $s1, 8($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "sw $s2, 12($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "sw $s3, 16($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "sw $s4, 20($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "sw $s5, 24($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "sw $s6, 28($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "sw $s7, 32($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "move $fp, $sp" << std::endl;
// 	std::cerr << "#" << "body2:" << std::endl;
// 	std::cerr << "#" << "li $v0, 42" << std::endl;
// 	std::cerr << "#" << "addiu $sp, $sp, 0" << std::endl;
// 	std::cerr << "#" << "move $fp, $sp" << std::endl;
// 	std::cerr << "#" << "b POP1" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "addiu $sp, $sp, 0" << std::endl;
// 	std::cerr << "#" << "move $fp, $sp" << std::endl;
// 	std::cerr << "#" << "POP1:" << std::endl;
// 	std::cerr << "#" << "mtc1 $v0, $f0" << std::endl;
// 	std::cerr << "#" << "lw $s0, 4($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "lw $s1, 8($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "lw $s2, 12($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "lw $s3, 16($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "lw $s4, 20($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "lw $s5, 24($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "lw $s6, 28($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "lw $s7, 32($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "lw $ra, 40($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "lw $fp, 36($sp)" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << "move $sp, $fp" << std::endl;
// 	std::cerr << "#" << "jr $ra" << std::endl;
// 	std::cerr << "#" << "nop" << std::endl;
// 	std::cerr << "#" << ".global f" << std::endl;
// }
