#include <iostream>
#include "ast.hpp"

int main(int argc, char *argv[])
{
    Context context;
    MakeName make_name;
    int dynamic_offset;
    std::cerr << "#"
              << "start to test" << std::endl;
    // std::cerr << argc << std::endl;
    // std::cerr << argv[2] << std::endl;
    // std::string Test = "compiler_tests/my_test.c";
    const NodePtr ast = parseAST();
    // const NodePtr ast = parseAST(Test);

    std::cerr << "#"
              << "after parser" << std::endl;
    std::cerr << "#"
              << "" << std::endl;
    std::cerr << "#"
              << "" << std::endl;
    ast->generateMips(std::cout, context, 2, make_name, dynamic_offset);
    std::cerr << "#"
              << "Generate MIPS complete" << std::endl;
}

