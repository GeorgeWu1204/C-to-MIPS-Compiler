#include "AST/ast_makeName.hpp"

std::string MakeName::makeName(std::string name)
{
    static int count = 0;
    return name + "_" + std::to_string(count++);
}