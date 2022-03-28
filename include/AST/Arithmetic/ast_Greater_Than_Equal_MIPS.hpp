#ifndef ast_Greater_Than_Equal_MIPS_hpp
#define ast_Greater_Than_Equal_MIPS_hpp
#include <string>
#include <iostream>
#include "../ast_Node.hpp"
#include "../ast_Context.hpp"
#include "ast_Arithmetic_MIPS.hpp"
#include "../ast_makeName.hpp"


class Greater_Than_Equal_MIPS
    : public Arithmetic_MIPS
{

public:
    Greater_Than_Equal_MIPS(NodePtr leftinput, NodePtr rightinput);
    void generateMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset) override;
    //void generateFloatMips(std::ostream &dst, Context &context, int destReg, MakeName &make_name, int &dynamic_offset, std::string type) override;
    // void prettyPrint(std::ostream &dst) const override;
    //  void generate_left() const override;
    //  void generate_right() const override;
    int get_arithmetic_const_val() override;
};

//         li      $2,1                        # 0x1
//         lwc1    $f2,8($fp)
//         lwc1    $f0,12($fp)
//         nop
//         c.le.s  $f0,$f2
//         nop
//         bc1t    $L2
//         nop

//         move    $2,$0
// $L2:
//         andi    $2,$2,0x00ff

#endif
