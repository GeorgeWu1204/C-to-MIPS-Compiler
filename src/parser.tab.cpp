/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

  #include "../include/ast.hpp"
  #include "../include/ListType.hpp"
  #include <cassert>
  extern NodePtr g_root; // A way of getting the AST out
  extern FILE *yyin;

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 125 "src/parser.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CONSTANT = 258,
    FLOAT_CONSTANT = 259,
    DOUBLE_CONSTANT = 260,
    IDENTIFIER = 261,
    INT_CONSTANT = 262,
    STRING_LITERAL = 263,
    SIZEOF = 264,
    CHAR_LITERAL = 265,
    PTR_OP = 266,
    INC_OP = 267,
    DEC_OP = 268,
    LEFT_OP = 269,
    RIGHT_OP = 270,
    LE_OP = 271,
    GE_OP = 272,
    EQ_OP = 273,
    NE_OP = 274,
    AND_OP = 275,
    OR_OP = 276,
    MUL_ASSIGN = 277,
    DIV_ASSIGN = 278,
    MOD_ASSIGN = 279,
    ADD_ASSIGN = 280,
    SUB_ASSIGN = 281,
    LEFT_ASSIGN = 282,
    RIGHT_ASSIGN = 283,
    AND_ASSIGN = 284,
    XOR_ASSIGN = 285,
    OR_ASSIGN = 286,
    TYPE_NAME = 287,
    TYPEDEF = 288,
    EXTERN = 289,
    STATIC = 290,
    AUTO = 291,
    REGISTER = 292,
    CHAR = 293,
    SHORT = 294,
    INT = 295,
    LONG = 296,
    SIGNED = 297,
    UNSIGNED = 298,
    FLOAT = 299,
    DOUBLE = 300,
    CONST = 301,
    VOLATILE = 302,
    VOID = 303,
    STRUCT = 304,
    UNION = 305,
    ENUM = 306,
    ELLIPSIS = 307,
    CASE = 308,
    DEFAULT = 309,
    IF = 310,
    ELSE = 311,
    SWITCH = 312,
    WHILE = 313,
    DO = 314,
    FOR = 315,
    GOTO = 316,
    CONTINUE = 317,
    BREAK = 318,
    RETURN = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "src/parser.y"

  NodePtr top;
  ListTypePtr list;
  int int_number;
  float float_number;
  double double_number;
  std::string *string;
  yytokentype token;


#line 212 "src/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   730

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  277

#define YYUNDEFTOK  2
#define YYMAXUTOK   319


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,     2,     2,     2,    82,    75,     2,
      70,    71,    65,    76,    68,    77,    80,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    74,
      84,    69,    83,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    87,    67,    78,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    72,    73,    77,    78,    83,    90,    91,
      92,    93,   100,   102,   106,   107,   108,   109,   110,   111,
     112,   114,   118,   119,   120,   124,   125,   129,   130,   135,
     136,   141,   142,   143,   145,   146,   147,   152,   156,   157,
     161,   167,   169,   174,   175,   180,   184,   185,   190,   196,
     206,   210,   211,   212,   213,   218,   219,   224,   226,   232,
     233,   238,   239,   244,   245,   246,   250,   251,   256,   257,
     258,   259,   260,   261,   265,   266,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   289,   290,
     292,   294,   295,   296,   297,   298,   299,   300,   306,   307,
     308,   309,   311,   312,   313,   317,   318,   322,   323,   324,
     325,   326,   327,   328,   335,   336,   337,   343,   344,   345,
     346,   351,   356,   357,   358,   362,   363,   364,   365,   366,
     369,   370,   371,   375,   376,   380,   381,   385,   386,   389,
     390,   393,   394,   398,   399,   404,   405,   409,   410,   417,
     421,   422,   423,   427,   429,   430,   434,   435,   436,   437
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANT", "FLOAT_CONSTANT",
  "DOUBLE_CONSTANT", "IDENTIFIER", "INT_CONSTANT", "STRING_LITERAL",
  "SIZEOF", "CHAR_LITERAL", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'*'", "'{'", "'}'", "','", "'='", "'('",
  "')'", "'['", "']'", "';'", "'&'", "'+'", "'-'", "'~'", "'!'", "'.'",
  "'/'", "'%'", "'>'", "'<'", "'?'", "':'", "'|'", "'^'", "$accept",
  "ROOT", "Translation_unit", "External_declaration",
  "Function_definition", "Declaration_specifiers", "Pointer",
  "Type_specifier", "Enum_specifier", "Enumerator_list", "Enumerator",
  "Declarator", "Direct_declarator", "Parameter_type_list",
  "Parameter_list", "Parameter_declaration", "Struct_specifier",
  "Struct_declaration_list", "Struct_declaration",
  "Struct_declarator_list", "Struct_declarator",
  "Specifier_qualifier_list", "Constant_expression", "Compound_statement",
  "Declaration_list", "Declaration", "Init_declarator_list",
  "Init_declarator", "Initializer", "Initializer_list", "Statement",
  "Expression", "Assignment_expression", "Unary_expression",
  "Postfix_expression", "Argument_expression_list", "Primary_expression",
  "Additive_expression", "Multiplicative_expression", "Cast_expression",
  "Shift_expression", "Relational_expression", "Equality_expression",
  "Conditional_expression", "Logical_or_expression",
  "Logical_and_expression", "Or_expression", "Xor_expression",
  "And_expression", "Statement_list", "Labeled_statement",
  "Expression_statement", "Selection_statement", "Iteration_statement",
  "Jump_statemnet", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,    42,   123,   125,    44,    61,
      40,    41,    91,    93,    59,    38,    43,    45,   126,    33,
      46,    47,    37,    62,    60,    63,    58,   124,    94
};
# endif

#define YYPACT_NINF (-140)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     667,   667,  -140,  -140,  -140,  -140,  -140,  -140,    37,    18,
       7,   667,  -140,  -140,     8,   667,  -140,  -140,  -140,  -140,
     -35,   -21,    59,  -140,  -140,  -140,   -26,     9,  -140,    22,
      33,    25,    -8,  -140,  -140,   679,    59,    21,   103,  -140,
    -140,    35,    25,   214,   499,  -140,   195,   312,     9,  -140,
    -140,    60,  -140,     9,   110,   620,  -140,    59,  -140,  -140,
    -140,  -140,  -140,  -140,   620,  -140,   620,   620,   620,    24,
      16,    46,    56,    58,    40,    50,   575,   620,  -140,   620,
     620,   620,   620,   620,   620,     8,  -140,   290,  -140,  -140,
      13,  -140,   181,     0,  -140,   104,   -23,  -140,    62,    10,
     164,  -140,    11,   128,    66,    84,   109,   366,  -140,  -140,
    -140,  -140,  -140,   499,  -140,  -140,  -140,     9,   118,   123,
    -140,  -140,   124,  -140,  -140,   129,  -140,  -140,  -140,  -140,
      15,  -140,  -140,  -140,  -140,  -140,  -140,  -140,   114,   469,
     620,   620,   620,   620,  -140,  -140,  -140,    17,  -140,    -7,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,   393,   620,  -140,
     620,   620,   620,   620,   620,   620,   620,   620,   620,   620,
     620,  -140,  -140,   590,   620,   211,   620,   620,   620,   620,
     620,   620,   620,   620,   620,   620,   620,   620,   620,   620,
     620,   620,   620,   620,   620,  -140,  -140,  -140,   120,  -140,
    -140,   667,  -140,     9,  -140,   469,  -140,    44,    54,    97,
     620,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,    98,   -27,
    -140,   -23,   -23,  -140,  -140,  -140,   104,   104,    62,    62,
      62,    62,    10,    10,   128,   -57,    66,    84,   109,   164,
    -140,   484,  -140,  -140,  -140,   469,   469,   469,   605,   620,
    -140,  -140,   620,  -140,  -140,   145,  -140,  -140,   469,   108,
    -140,  -140,   469,  -140,   469,  -140,  -140
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    18,    14,    20,    16,    17,    19,     0,     0,
       0,     2,     3,     5,     0,     8,    21,    15,     6,    11,
      42,    24,     0,     1,     4,    31,    12,     0,    57,     0,
      61,    29,     0,    59,     9,     0,     0,    27,     0,    25,
      13,     0,    30,     0,     0,     7,     0,     0,     0,    58,
      49,     0,    43,     0,     0,     0,    22,     0,    32,   109,
     111,   107,   108,   112,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,    68,     0,    55,   145,
       0,    74,   121,    88,    98,   122,   114,   117,   125,   130,
     143,    87,   133,   135,   137,   139,   141,     0,    73,    69,
      70,    71,    72,     0,    62,    63,    33,     0,     0,    37,
      38,    35,     0,   121,    50,    61,    60,    41,    44,    48,
       0,    46,    23,    28,    26,    97,    89,    90,     0,     0,
       0,     0,     0,     0,   158,   157,   156,     0,    92,     0,
      91,    93,    94,    95,    96,    53,    56,     0,     0,   149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,   146,    66,     0,    40,
      36,     0,    34,     0,    45,     0,   148,     0,     0,     0,
       0,   159,   113,    54,    75,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    76,    99,   105,     0,     0,
     101,   115,   116,   118,   119,   120,   123,   124,   128,   129,
     126,   127,   131,   132,   136,     0,   138,   140,   142,   144,
      64,     0,    39,    47,   147,     0,     0,     0,     0,     0,
     100,   104,     0,    65,    67,   150,   152,   153,     0,     0,
     106,   134,     0,   154,     0,   151,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,   218,  -140,     1,   199,     5,  -140,   194,
     174,    -4,   203,  -140,  -140,    36,  -140,  -140,   183,  -140,
      38,  -140,    -5,   206,  -140,   -25,  -140,   200,  -108,  -140,
     -82,   -73,    -6,   -47,  -140,  -140,  -140,    12,    19,   -29,
     -65,    26,    48,   -46,  -140,    67,    64,    57,    68,   173,
    -140,  -139,  -140,  -140,  -140
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    29,    15,    16,    38,
      39,   125,    31,   118,   119,   120,    17,    51,    52,   130,
     131,    53,   122,    86,    87,    18,    32,    33,   114,   198,
      89,    90,    91,    92,    93,   228,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   124,    19,   147,   210,   197,   149,    23,   123,   124,
      30,   158,   171,   172,    25,    25,    34,   135,    88,   136,
     137,   123,   124,    41,    21,   196,   183,   184,    25,   262,
     123,    35,   189,   123,   123,   123,   123,   123,   115,    26,
      50,   158,   178,    20,    85,    36,   261,   117,   148,   129,
     133,   150,   151,   152,   153,   154,    50,   206,   179,   180,
      48,   158,   156,   138,   212,    37,    49,   207,   208,   209,
     173,   258,   174,    26,    26,   196,   181,   182,    27,    27,
     175,   158,    28,   203,    22,   158,   140,   159,    85,   204,
      55,   211,    27,   185,   186,    46,   190,    47,     2,    43,
       3,   229,    44,     4,     5,     6,    58,   115,     7,     8,
     139,     9,   158,   199,   144,   255,   141,   245,   238,   239,
     240,   241,   158,   254,   145,   256,   142,   127,   143,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   264,   123,   123,   123,   123,   191,   233,
     234,   235,   214,   192,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   158,   259,   227,   257,   260,
      56,    57,   193,   265,   266,   267,   158,   132,    57,   274,
     176,   177,   187,   188,   194,   269,   273,   250,   251,   200,
     275,   201,   276,   236,   237,   231,   232,   202,    44,   129,
     205,   272,   117,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   242,   243,   123,   271,   230,    59,    60,
      61,    62,    63,    64,    65,    40,    66,    67,     1,    24,
      54,   134,    42,     2,   128,     3,    45,   252,     4,     5,
       6,   253,   249,     7,     8,   115,     9,     1,   126,   247,
     170,     0,     2,   270,     3,   246,   244,     4,     5,     6,
     157,   248,     7,     8,     0,     9,   116,    68,    69,    70,
       0,    71,    72,     0,    73,     0,    74,    75,    76,    77,
      43,    78,     0,     0,    79,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,    64,    65,     1,    66,    67,     0,     0,     2,     0,
       3,     0,     0,     4,     5,     6,     0,     0,     7,     8,
       0,     9,     0,    68,    69,    70,     0,    71,    72,     0,
      73,     0,    74,    75,    76,    77,    43,   155,     0,     0,
      79,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      59,    60,    61,    62,    63,    64,    65,    77,    66,    67,
       0,     0,    79,     0,     0,   121,     0,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      69,    70,     0,    71,    72,     0,    73,     0,    74,    75,
      76,    77,    43,   195,     0,     0,    79,     0,     0,     0,
       0,    80,    81,    82,    83,    84,    68,    69,    70,     0,
      71,    72,     0,    73,     0,    74,    75,    76,    77,    43,
     213,     0,     0,    79,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,    64,    65,     0,    66,    67,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    69,    70,     0,    71,    72,     0,    73,
       0,    74,    75,    76,    77,    43,     0,     0,     0,    79,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    77,
     113,   263,     0,     0,    79,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    77,   113,     0,     0,     0,    79,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,    79,     0,     0,     0,   146,
      80,    81,    82,    83,    84,    77,     0,     0,     0,     0,
      79,   226,     0,     0,     0,    80,    81,    82,    83,    84,
      77,     0,     0,     0,     0,    79,   268,     0,     0,     0,
      80,    81,    82,    83,    84,    77,     0,     0,     0,     0,
      79,     0,     0,     0,     0,    80,    81,    82,    83,    84,
       1,     0,     0,     0,     0,     2,     0,     3,     0,     0,
       4,     5,     6,     0,     0,     7,     8,     2,     9,     3,
       0,     0,     4,     5,     6,     0,     0,     7,     8,     0,
       9
};

static const yytype_int16 yycheck[] =
{
      47,    47,     1,    76,   143,   113,    79,     0,    55,    55,
      14,    68,    12,    13,     6,     6,    15,    64,    43,    66,
      67,    68,    68,    27,     6,   107,    16,    17,     6,    86,
      77,    66,    21,    80,    81,    82,    83,    84,    44,    65,
      35,    68,    65,     6,    43,    66,    73,    46,    77,    53,
      55,    80,    81,    82,    83,    84,    51,   139,    81,    82,
      68,    68,    87,    68,    71,     6,    74,   140,   141,   142,
      70,   210,    72,    65,    65,   157,    14,    15,    70,    70,
      80,    68,    74,    68,    66,    68,    70,    74,    87,    74,
      69,    74,    70,    83,    84,    70,    85,    72,    38,    66,
      40,   174,    69,    43,    44,    45,    71,   113,    48,    49,
      86,    51,    68,   117,    74,    71,    70,   190,   183,   184,
     185,   186,    68,   205,    74,    71,    70,    67,    70,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   251,   191,   192,   193,   194,    20,   178,
     179,   180,   158,    87,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,    68,    68,   173,    71,    71,
      67,    68,    88,   255,   256,   257,    68,    67,    68,    71,
      76,    77,    18,    19,    75,   258,   268,    67,    68,    71,
     272,    68,   274,   181,   182,   176,   177,    73,    69,   203,
      86,    56,   201,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   187,   188,   262,   262,     6,     4,     5,
       6,     7,     8,     9,    10,    26,    12,    13,    33,    11,
      36,    57,    29,    38,    51,    40,    30,   201,    43,    44,
      45,   203,   194,    48,    49,   251,    51,    33,    48,   192,
      69,    -1,    38,   259,    40,   191,   189,    43,    44,    45,
      87,   193,    48,    49,    -1,    51,    71,    53,    54,    55,
      -1,    57,    58,    -1,    60,    -1,    62,    63,    64,    65,
      66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    10,    33,    12,    13,    -1,    -1,    38,    -1,
      40,    -1,    -1,    43,    44,    45,    -1,    -1,    48,    49,
      -1,    51,    -1,    53,    54,    55,    -1,    57,    58,    -1,
      60,    -1,    62,    63,    64,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
       4,     5,     6,     7,     8,     9,    10,    65,    12,    13,
      -1,    -1,    70,    -1,    -1,    73,    -1,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    -1,    57,    58,    -1,    60,    -1,    62,    63,
      64,    65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    53,    54,    55,    -1,
      57,    58,    -1,    60,    -1,    62,    63,    64,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    -1,    57,    58,    -1,    60,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    65,
      66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    65,    66,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    65,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      65,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    65,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      33,    -1,    -1,    -1,    -1,    38,    -1,    40,    -1,    -1,
      43,    44,    45,    -1,    -1,    48,    49,    38,    51,    40,
      -1,    -1,    43,    44,    45,    -1,    -1,    48,    49,    -1,
      51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    38,    40,    43,    44,    45,    48,    49,    51,
      90,    91,    92,    93,    94,    96,    97,   105,   114,    94,
       6,     6,    66,     0,    92,     6,    65,    70,    74,    95,
     100,   101,   115,   116,    94,    66,    66,     6,    98,    99,
      95,   100,   101,    66,    69,   112,    70,    72,    68,    74,
      96,   106,   107,   110,    98,    69,    67,    68,    71,     4,
       5,     6,     7,     8,     9,    10,    12,    13,    53,    54,
      55,    57,    58,    60,    62,    63,    64,    65,    67,    70,
      75,    76,    77,    78,    79,    94,   112,   113,   114,   119,
     120,   121,   122,   123,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    66,   117,   121,    71,    94,   102,   103,
     104,    73,   111,   122,   132,   100,   116,    67,   107,   100,
     108,   109,    67,   111,    99,   122,   122,   122,   111,    86,
      70,    70,    70,    70,    74,    74,    74,   120,   128,   120,
     128,   128,   128,   128,   128,    67,   114,   138,    68,    74,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      69,    12,    13,    70,    72,    80,    76,    77,    65,    81,
      82,    14,    15,    16,    17,    83,    84,    18,    19,    21,
      85,    20,    87,    88,    75,    67,   119,   117,   118,   100,
      71,    68,    73,    68,    74,    86,   119,   120,   120,   120,
     140,    74,    71,    67,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,    71,   121,   124,   120,
       6,   127,   127,   128,   128,   128,   126,   126,   129,   129,
     129,   129,   130,   130,   134,   120,   135,   136,   137,   131,
      67,    68,   104,   109,   119,    71,    71,    71,   140,    68,
      71,    73,    86,    67,   117,   119,   119,   119,    71,   120,
     121,   132,    56,   119,    71,   119,   119
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    94,    94,
      94,    94,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   101,   101,   101,   101,   102,   103,   103,
     104,   105,   105,   106,   106,   107,   108,   108,   109,   110,
     111,   112,   112,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   127,   127,   127,
     127,   128,   129,   129,   129,   130,   130,   130,   130,   130,
     131,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     141,   141,   141,   142,   142,   142,   143,   143,   143,   143
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     2,     1,     3,     1,     3,     1,
       2,     1,     3,     3,     4,     3,     4,     1,     1,     3,
       2,     5,     2,     1,     2,     3,     1,     3,     1,     1,
       1,     2,     3,     3,     4,     1,     2,     2,     3,     1,
       3,     1,     3,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       4,     3,     2,     2,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     4,     3,     2,
       5,     7,     5,     5,     6,     7,     2,     2,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 68 "src/parser.y"
                     { g_root = new Root_Mips(*(yyvsp[0].list));}
#line 1700 "src/parser.tab.cpp"
    break;

  case 3:
#line 72 "src/parser.y"
                                                                    {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1706 "src/parser.tab.cpp"
    break;

  case 4:
#line 73 "src/parser.y"
                                                                    {(yyval.list) = add_to_list((yyvsp[-1].list),(yyvsp[0].top));}
#line 1712 "src/parser.tab.cpp"
    break;

  case 5:
#line 77 "src/parser.y"
                                                                    {(yyval.top) = (yyvsp[0].top);}
#line 1718 "src/parser.tab.cpp"
    break;

  case 6:
#line 78 "src/parser.y"
                                                                    {(yyval.top) = new Global_Declaration_Mips((yyvsp[0].top));}
#line 1724 "src/parser.tab.cpp"
    break;

  case 7:
#line 83 "src/parser.y"
                                                                     {(yyval.top) = new Function(new Declaration_Mips((yyvsp[-2].top), (yyvsp[-1].top)), (yyvsp[0].top));}
#line 1730 "src/parser.tab.cpp"
    break;

  case 8:
#line 90 "src/parser.y"
                                                                     {(yyval.top) = (yyvsp[0].top);}
#line 1736 "src/parser.tab.cpp"
    break;

  case 9:
#line 91 "src/parser.y"
                                                                     {}
#line 1742 "src/parser.tab.cpp"
    break;

  case 10:
#line 92 "src/parser.y"
                                                                           {}
#line 1748 "src/parser.tab.cpp"
    break;

  case 11:
#line 93 "src/parser.y"
                                                                           {(yyval.top) = new Typedef_Mips((yyvsp[0].top));}
#line 1754 "src/parser.tab.cpp"
    break;

  case 12:
#line 100 "src/parser.y"
                                                                           {}
#line 1760 "src/parser.tab.cpp"
    break;

  case 13:
#line 102 "src/parser.y"
                                                                           {}
#line 1766 "src/parser.tab.cpp"
    break;

  case 14:
#line 106 "src/parser.y"
                                                                           {(yyval.top) = new Type_Mips("INT");}
#line 1772 "src/parser.tab.cpp"
    break;

  case 15:
#line 107 "src/parser.y"
                                                                           {(yyval.top) = (yyvsp[0].top);}
#line 1778 "src/parser.tab.cpp"
    break;

  case 16:
#line 108 "src/parser.y"
                                                                     {(yyval.top) = new Type_Mips("FLOAT");}
#line 1784 "src/parser.tab.cpp"
    break;

  case 17:
#line 109 "src/parser.y"
                                                                           {(yyval.top) = new Type_Mips("DOUBLE");}
#line 1790 "src/parser.tab.cpp"
    break;

  case 18:
#line 110 "src/parser.y"
                                                                     {(yyval.top) = new Type_Mips("CHAR");}
#line 1796 "src/parser.tab.cpp"
    break;

  case 19:
#line 111 "src/parser.y"
                                                                           {(yyval.top) = new Type_Mips("VOID");}
#line 1802 "src/parser.tab.cpp"
    break;

  case 20:
#line 112 "src/parser.y"
                                                                           {(yyval.top) = new Type_Mips("UNSIIGNED");}
#line 1808 "src/parser.tab.cpp"
    break;

  case 21:
#line 114 "src/parser.y"
                                                                            {(yyval.top) = (yyvsp[0].top);}
#line 1814 "src/parser.tab.cpp"
    break;

  case 22:
#line 118 "src/parser.y"
                                                                            {(yyval.top) = new Enum_specifier_Mips(*(yyvsp[-1].list));}
#line 1820 "src/parser.tab.cpp"
    break;

  case 23:
#line 119 "src/parser.y"
                                                                            {(yyval.top) = new Enum_specifier_Mips(*(yyvsp[-3].string), *(yyvsp[-1].list));}
#line 1826 "src/parser.tab.cpp"
    break;

  case 24:
#line 120 "src/parser.y"
                                                                            {(yyval.top) = new Enum_specifier_Mips(*(yyvsp[0].string));}
#line 1832 "src/parser.tab.cpp"
    break;

  case 25:
#line 124 "src/parser.y"
                                                                            {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1838 "src/parser.tab.cpp"
    break;

  case 26:
#line 125 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 1844 "src/parser.tab.cpp"
    break;

  case 27:
#line 129 "src/parser.y"
                                                                            {(yyval.top) = new Enumerator_Mips(*(yyvsp[0].string));}
#line 1850 "src/parser.tab.cpp"
    break;

  case 28:
#line 130 "src/parser.y"
                                                                            {(yyval.top) = new Enumerator_Mips(*(yyvsp[-2].string), (yyvsp[0].top));}
#line 1856 "src/parser.tab.cpp"
    break;

  case 29:
#line 135 "src/parser.y"
                                                                            {(yyval.top) = (yyvsp[0].top);}
#line 1862 "src/parser.tab.cpp"
    break;

  case 30:
#line 136 "src/parser.y"
                                                                      {(yyval.top) = new PointerDeclarator_MIPS((yyvsp[0].top));}
#line 1868 "src/parser.tab.cpp"
    break;

  case 31:
#line 141 "src/parser.y"
                                                                            {(yyval.top) = new Identifier_Mips(*(yyvsp[0].string));}
#line 1874 "src/parser.tab.cpp"
    break;

  case 32:
#line 142 "src/parser.y"
                                                                            {std::cerr  << " Diclerator_Mips Unsupported" << std::endl;}
#line 1880 "src/parser.tab.cpp"
    break;

  case 33:
#line 143 "src/parser.y"
                                                                      {(yyval.top) = new Function_Declarator_Mips((yyvsp[-2].top));}
#line 1886 "src/parser.tab.cpp"
    break;

  case 34:
#line 145 "src/parser.y"
                                                                            {(yyval.top) = new Declare_Array_Mips((yyvsp[-3].top), (yyvsp[-1].top));}
#line 1892 "src/parser.tab.cpp"
    break;

  case 35:
#line 146 "src/parser.y"
                                                                            {(yyval.top) = new Declare_Array_Mips((yyvsp[-2].top));}
#line 1898 "src/parser.tab.cpp"
    break;

  case 36:
#line 147 "src/parser.y"
                                                                            {(yyval.top) = new Function_Declarator_Mips((yyvsp[-3].top), *(yyvsp[-1].list));}
#line 1904 "src/parser.tab.cpp"
    break;

  case 37:
#line 152 "src/parser.y"
                                                                            {(yyval.list) = (yyvsp[0].list);}
#line 1910 "src/parser.tab.cpp"
    break;

  case 38:
#line 156 "src/parser.y"
                                                                            {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1916 "src/parser.tab.cpp"
    break;

  case 39:
#line 157 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 1922 "src/parser.tab.cpp"
    break;

  case 40:
#line 161 "src/parser.y"
                                                                            {(yyval.top) = new Declaration_Mips((yyvsp[-1].top), (yyvsp[0].top));}
#line 1928 "src/parser.tab.cpp"
    break;

  case 41:
#line 167 "src/parser.y"
                                                                             {(yyval.top) = new Build_struct_Mips(*(yyvsp[-3].string), *(yyvsp[-1].list));}
#line 1934 "src/parser.tab.cpp"
    break;

  case 42:
#line 169 "src/parser.y"
                                                                             {(yyval.top) = new Struct_Declaration_Mips(*(yyvsp[0].string));}
#line 1940 "src/parser.tab.cpp"
    break;

  case 43:
#line 174 "src/parser.y"
                                                                             {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1946 "src/parser.tab.cpp"
    break;

  case 44:
#line 175 "src/parser.y"
                                                                             {(yyval.list) = add_to_list((yyvsp[-1].list), (yyvsp[0].top));}
#line 1952 "src/parser.tab.cpp"
    break;

  case 45:
#line 180 "src/parser.y"
                                                                             {(yyval.top) = new StructElement_Declaration_Mips((yyvsp[-2].top), *(yyvsp[-1].list));}
#line 1958 "src/parser.tab.cpp"
    break;

  case 46:
#line 184 "src/parser.y"
                                                                             {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1964 "src/parser.tab.cpp"
    break;

  case 47:
#line 185 "src/parser.y"
                                                                             {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 1970 "src/parser.tab.cpp"
    break;

  case 48:
#line 190 "src/parser.y"
                                                                             {(yyval.top) = (yyvsp[0].top);}
#line 1976 "src/parser.tab.cpp"
    break;

  case 49:
#line 196 "src/parser.y"
                                                                             {(yyval.top) = (yyvsp[0].top);}
#line 1982 "src/parser.tab.cpp"
    break;

  case 50:
#line 206 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 1988 "src/parser.tab.cpp"
    break;

  case 51:
#line 210 "src/parser.y"
                                                                      {(yyval.top) = new Compound_statement_Mips();}
#line 1994 "src/parser.tab.cpp"
    break;

  case 52:
#line 211 "src/parser.y"
                                                                      {(yyval.top) = new Compound_statement_Mips(*(yyvsp[-1].list));std::cerr << "# compond work" << std::endl;}
#line 2000 "src/parser.tab.cpp"
    break;

  case 53:
#line 212 "src/parser.y"
                                                                      {(yyval.top) = new Compound_statement_Mips(*(yyvsp[-1].list)); std::cerr << "# compond work" << std::endl;}
#line 2006 "src/parser.tab.cpp"
    break;

  case 54:
#line 213 "src/parser.y"
                                                                      {(yyval.top) = new Compound_statement_Mips(*(yyvsp[-2].list), *(yyvsp[-1].list)); std::cerr << "# compond work" << std::endl;}
#line 2012 "src/parser.tab.cpp"
    break;

  case 55:
#line 218 "src/parser.y"
                                                                            {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 2018 "src/parser.tab.cpp"
    break;

  case 56:
#line 219 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-1].list),(yyvsp[0].top));}
#line 2024 "src/parser.tab.cpp"
    break;

  case 57:
#line 224 "src/parser.y"
                                                                            {(yyval.top) = new Declaration_Mips((yyvsp[-1].top));}
#line 2030 "src/parser.tab.cpp"
    break;

  case 58:
#line 226 "src/parser.y"
                                                                      {(yyval.top) = new Declaration_Mips((yyvsp[-2].top), *(yyvsp[-1].list));}
#line 2036 "src/parser.tab.cpp"
    break;

  case 59:
#line 232 "src/parser.y"
                                                                            {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 2042 "src/parser.tab.cpp"
    break;

  case 60:
#line 233 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 2048 "src/parser.tab.cpp"
    break;

  case 61:
#line 238 "src/parser.y"
                                                                            {(yyval.top) = (yyvsp[0].top);}
#line 2054 "src/parser.tab.cpp"
    break;

  case 62:
#line 239 "src/parser.y"
                                                                            {(yyval.top) = new Init_Declarator_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 2060 "src/parser.tab.cpp"
    break;

  case 63:
#line 244 "src/parser.y"
                                                                            {(yyval.top) = (yyvsp[0].top);}
#line 2066 "src/parser.tab.cpp"
    break;

  case 64:
#line 245 "src/parser.y"
                                                                            {(yyval.top) = new Array_Initializer_Mips(*(yyvsp[-1].list));}
#line 2072 "src/parser.tab.cpp"
    break;

  case 65:
#line 246 "src/parser.y"
                                                                      {(yyval.top) = new Array_Initializer_Mips(*(yyvsp[-2].list));}
#line 2078 "src/parser.tab.cpp"
    break;

  case 66:
#line 250 "src/parser.y"
                                                                      {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 2084 "src/parser.tab.cpp"
    break;

  case 67:
#line 251 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 2090 "src/parser.tab.cpp"
    break;

  case 68:
#line 256 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 2096 "src/parser.tab.cpp"
    break;

  case 69:
#line 257 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 2102 "src/parser.tab.cpp"
    break;

  case 70:
#line 258 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 2108 "src/parser.tab.cpp"
    break;

  case 71:
#line 259 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 2114 "src/parser.tab.cpp"
    break;

  case 72:
#line 260 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 2120 "src/parser.tab.cpp"
    break;

  case 73:
#line 261 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 2126 "src/parser.tab.cpp"
    break;

  case 74:
#line 265 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 2132 "src/parser.tab.cpp"
    break;

  case 75:
#line 266 "src/parser.y"
                                                                      { std::cerr  << "Not assessed by spec (?)" << std::endl; }
#line 2138 "src/parser.tab.cpp"
    break;

  case 76:
#line 271 "src/parser.y"
                                                                       {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 2144 "src/parser.tab.cpp"
    break;

  case 77:
#line 272 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Multiplication_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2150 "src/parser.tab.cpp"
    break;

  case 78:
#line 273 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Division_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2156 "src/parser.tab.cpp"
    break;

  case 79:
#line 274 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Mod_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2162 "src/parser.tab.cpp"
    break;

  case 80:
#line 275 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Addition_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2168 "src/parser.tab.cpp"
    break;

  case 81:
#line 276 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Subtraction_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2174 "src/parser.tab.cpp"
    break;

  case 82:
#line 277 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Left_Shift_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2180 "src/parser.tab.cpp"
    break;

  case 83:
#line 278 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Right_Shift_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2186 "src/parser.tab.cpp"
    break;

  case 84:
#line 279 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new BitAnd_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2192 "src/parser.tab.cpp"
    break;

  case 85:
#line 280 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new BitXor_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2198 "src/parser.tab.cpp"
    break;

  case 86:
#line 281 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new BitOr_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 2204 "src/parser.tab.cpp"
    break;

  case 87:
#line 282 "src/parser.y"
                                                                       {(yyval.top) = new Condition_Expression_Mips((yyvsp[0].top));}
#line 2210 "src/parser.tab.cpp"
    break;

  case 88:
#line 289 "src/parser.y"
                                                                              {(yyval.top) = (yyvsp[0].top);}
#line 2216 "src/parser.tab.cpp"
    break;

  case 89:
#line 290 "src/parser.y"
                                                                              {(yyval.top) = new Pre_Increment_MIPS((yyvsp[0].top));}
#line 2222 "src/parser.tab.cpp"
    break;

  case 90:
#line 292 "src/parser.y"
                                                                        {(yyval.top) = new Pre_Decrement_MIPS((yyvsp[0].top));}
#line 2228 "src/parser.tab.cpp"
    break;

  case 91:
#line 294 "src/parser.y"
                                                                            {(yyval.top) = new UnaryAddress_MIPS((yyvsp[0].top));}
#line 2234 "src/parser.tab.cpp"
    break;

  case 92:
#line 295 "src/parser.y"
                                                                              {(yyval.top) = new UnaryPointer_MIPS((yyvsp[0].top));}
#line 2240 "src/parser.tab.cpp"
    break;

  case 93:
#line 296 "src/parser.y"
                                                                              {(yyval.top) = (yyvsp[0].top);}
#line 2246 "src/parser.tab.cpp"
    break;

  case 94:
#line 297 "src/parser.y"
                                                                              {(yyval.top) = new UnarySub_MIPS((yyvsp[0].top));}
#line 2252 "src/parser.tab.cpp"
    break;

  case 95:
#line 298 "src/parser.y"
                                                                              {(yyval.top) = new UnaryNor_MIPS((yyvsp[0].top));}
#line 2258 "src/parser.tab.cpp"
    break;

  case 96:
#line 299 "src/parser.y"
                                                                              {(yyval.top) = new UnaryNot_MIPS((yyvsp[0].top));}
#line 2264 "src/parser.tab.cpp"
    break;

  case 97:
#line 300 "src/parser.y"
                                                                        {(yyval.top) = new Sizeof_MIPS((yyvsp[0].top));}
#line 2270 "src/parser.tab.cpp"
    break;

  case 98:
#line 306 "src/parser.y"
                                                                              {(yyval.top) = (yyvsp[0].top);}
#line 2276 "src/parser.tab.cpp"
    break;

  case 99:
#line 307 "src/parser.y"
                                                                              {(yyval.top) = new FunctionCall_Mips((yyvsp[-2].top));}
#line 2282 "src/parser.tab.cpp"
    break;

  case 100:
#line 308 "src/parser.y"
                                                                              {(yyval.top) = new FunctionCall_Mips((yyvsp[-3].top), *(yyvsp[-1].list));}
#line 2288 "src/parser.tab.cpp"
    break;

  case 101:
#line 309 "src/parser.y"
                                                                        {(yyval.top) = new Call_struct_Mips((yyvsp[-2].top), *(yyvsp[0].string));}
#line 2294 "src/parser.tab.cpp"
    break;

  case 102:
#line 311 "src/parser.y"
                                                                              {(yyval.top) = new Post_Increment_MIPS((yyvsp[-1].top));}
#line 2300 "src/parser.tab.cpp"
    break;

  case 103:
#line 312 "src/parser.y"
                                                                              {(yyval.top) = new Post_Decrement_MIPS((yyvsp[-1].top));}
#line 2306 "src/parser.tab.cpp"
    break;

  case 104:
#line 313 "src/parser.y"
                                                                        {(yyval.top) = new Array_Access_Mips((yyvsp[-3].top), (yyvsp[-1].top));}
#line 2312 "src/parser.tab.cpp"
    break;

  case 105:
#line 317 "src/parser.y"
                                                                              {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 2318 "src/parser.tab.cpp"
    break;

  case 106:
#line 318 "src/parser.y"
                                                                              {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 2324 "src/parser.tab.cpp"
    break;

  case 107:
#line 322 "src/parser.y"
                                                                              {  (yyval.top) = new Identifier_Mips(*(yyvsp[0].string));}
#line 2330 "src/parser.tab.cpp"
    break;

  case 108:
#line 323 "src/parser.y"
                                                                              {  (yyval.top) = new Int_Constant_Mips((yyvsp[0].int_number));}
#line 2336 "src/parser.tab.cpp"
    break;

  case 109:
#line 324 "src/parser.y"
                                                                        { (yyval.top) = new Float_Constant_Mips((yyvsp[0].float_number));}
#line 2342 "src/parser.tab.cpp"
    break;

  case 110:
#line 325 "src/parser.y"
                                                                        {(yyval.top) = new Char_Litteral_Mips((yyvsp[0].int_number));}
#line 2348 "src/parser.tab.cpp"
    break;

  case 111:
#line 326 "src/parser.y"
                                                                        { (yyval.top) = new Double_Constant_Mips((yyvsp[0].double_number));}
#line 2354 "src/parser.tab.cpp"
    break;

  case 112:
#line 327 "src/parser.y"
                                                                              {(yyval.top) = new STRING_LITTERAL_MIPS(*(yyvsp[0].string));}
#line 2360 "src/parser.tab.cpp"
    break;

  case 113:
#line 328 "src/parser.y"
                                                                        {  (yyval.top) = (yyvsp[-1].top);}
#line 2366 "src/parser.tab.cpp"
    break;

  case 114:
#line 335 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2372 "src/parser.tab.cpp"
    break;

  case 115:
#line 336 "src/parser.y"
                                                                        {(yyval.top) = new Addition_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2378 "src/parser.tab.cpp"
    break;

  case 116:
#line 337 "src/parser.y"
                                                                        {(yyval.top) = new Subtraction_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2384 "src/parser.tab.cpp"
    break;

  case 117:
#line 343 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2390 "src/parser.tab.cpp"
    break;

  case 118:
#line 344 "src/parser.y"
                                                                        {(yyval.top) = new Multiplication_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2396 "src/parser.tab.cpp"
    break;

  case 119:
#line 345 "src/parser.y"
                                                                        {(yyval.top) = new Division_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2402 "src/parser.tab.cpp"
    break;

  case 120:
#line 346 "src/parser.y"
                                                                        {(yyval.top) = new Mod_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2408 "src/parser.tab.cpp"
    break;

  case 121:
#line 351 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2414 "src/parser.tab.cpp"
    break;

  case 122:
#line 356 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2420 "src/parser.tab.cpp"
    break;

  case 123:
#line 357 "src/parser.y"
                                                                        {(yyval.top) = new Left_Shift_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2426 "src/parser.tab.cpp"
    break;

  case 124:
#line 358 "src/parser.y"
                                                                        {(yyval.top) = new Right_Shift_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2432 "src/parser.tab.cpp"
    break;

  case 125:
#line 362 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2438 "src/parser.tab.cpp"
    break;

  case 126:
#line 363 "src/parser.y"
                                                                        {(yyval.top) = new Greater_Than_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2444 "src/parser.tab.cpp"
    break;

  case 127:
#line 364 "src/parser.y"
                                                                        {(yyval.top) = new Less_Than_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2450 "src/parser.tab.cpp"
    break;

  case 128:
#line 365 "src/parser.y"
                                                                        {(yyval.top) = new Less_Than_Equal_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2456 "src/parser.tab.cpp"
    break;

  case 129:
#line 366 "src/parser.y"
                                                                        {(yyval.top) = new Greater_Than_Equal_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2462 "src/parser.tab.cpp"
    break;

  case 130:
#line 369 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2468 "src/parser.tab.cpp"
    break;

  case 131:
#line 370 "src/parser.y"
                                                                        {(yyval.top) = new Equal_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2474 "src/parser.tab.cpp"
    break;

  case 132:
#line 371 "src/parser.y"
                                                                        {(yyval.top) = new NotEqual_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2480 "src/parser.tab.cpp"
    break;

  case 133:
#line 375 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2486 "src/parser.tab.cpp"
    break;

  case 134:
#line 376 "src/parser.y"
                                                                        {std::cerr  << "Unsupported" << std::endl;}
#line 2492 "src/parser.tab.cpp"
    break;

  case 135:
#line 380 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2498 "src/parser.tab.cpp"
    break;

  case 136:
#line 381 "src/parser.y"
                                                                        {(yyval.top) = new LogicOr_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2504 "src/parser.tab.cpp"
    break;

  case 137:
#line 385 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2510 "src/parser.tab.cpp"
    break;

  case 138:
#line 386 "src/parser.y"
                                                                        {(yyval.top) = new LogicAnd_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2516 "src/parser.tab.cpp"
    break;

  case 139:
#line 389 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2522 "src/parser.tab.cpp"
    break;

  case 140:
#line 390 "src/parser.y"
                                                                        {(yyval.top) = new BitOr_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2528 "src/parser.tab.cpp"
    break;

  case 141:
#line 393 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2534 "src/parser.tab.cpp"
    break;

  case 142:
#line 394 "src/parser.y"
                                                                        {(yyval.top) = new BitXor_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2540 "src/parser.tab.cpp"
    break;

  case 143:
#line 398 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2546 "src/parser.tab.cpp"
    break;

  case 144:
#line 399 "src/parser.y"
                                                                        {(yyval.top) = new BitAnd_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2552 "src/parser.tab.cpp"
    break;

  case 145:
#line 404 "src/parser.y"
                                                                        {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 2558 "src/parser.tab.cpp"
    break;

  case 146:
#line 405 "src/parser.y"
                                                                        {(yyval.list) = add_to_list((yyvsp[-1].list), (yyvsp[0].top));}
#line 2564 "src/parser.tab.cpp"
    break;

  case 147:
#line 409 "src/parser.y"
                                                                              {(yyval.top) = new Case_Mips((yyvsp[-2].top), (yyvsp[0].top));}
#line 2570 "src/parser.tab.cpp"
    break;

  case 148:
#line 410 "src/parser.y"
                                                                              {(yyval.top) = new Default_Mips((yyvsp[0].top));}
#line 2576 "src/parser.tab.cpp"
    break;

  case 149:
#line 417 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[-1].top);}
#line 2582 "src/parser.tab.cpp"
    break;

  case 150:
#line 421 "src/parser.y"
                                                                        {(yyval.top) = new Selection_statement_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 2588 "src/parser.tab.cpp"
    break;

  case 151:
#line 422 "src/parser.y"
                                                                        {(yyval.top) = new Selection_statement_Mips((yyvsp[-4].top), (yyvsp[-2].top), (yyvsp[0].top));}
#line 2594 "src/parser.tab.cpp"
    break;

  case 152:
#line 423 "src/parser.y"
                                                                        {(yyval.top) = new Switch_Mips((yyvsp[-2].top), (yyvsp[0].top));}
#line 2600 "src/parser.tab.cpp"
    break;

  case 153:
#line 427 "src/parser.y"
                                                                                    { (yyval.top) = new While_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 2606 "src/parser.tab.cpp"
    break;

  case 154:
#line 429 "src/parser.y"
                                                                                    {(yyval.top) = new For_Mips((yyvsp[-3].top),(yyvsp[-2].top),(yyvsp[0].top));}
#line 2612 "src/parser.tab.cpp"
    break;

  case 155:
#line 430 "src/parser.y"
                                                                                    {(yyval.top) = new For_Mips((yyvsp[-4].top),(yyvsp[-3].top),(yyvsp[-2].top),(yyvsp[0].top));}
#line 2618 "src/parser.tab.cpp"
    break;

  case 156:
#line 434 "src/parser.y"
                                                                         { (yyval.top) = new Return_Mips();}
#line 2624 "src/parser.tab.cpp"
    break;

  case 157:
#line 435 "src/parser.y"
                                                                         { (yyval.top) = new Break_Mips();}
#line 2630 "src/parser.tab.cpp"
    break;

  case 158:
#line 436 "src/parser.y"
                                                                         { (yyval.top) = new Continuous_Mips();}
#line 2636 "src/parser.tab.cpp"
    break;

  case 159:
#line 437 "src/parser.y"
                                                                         { (yyval.top) = new Return_Mips((yyvsp[-1].top));}
#line 2642 "src/parser.tab.cpp"
    break;


#line 2646 "src/parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 443 "src/parser.y"


NodePtr g_root;

const NodePtr parseAST(std::string filename)
{
  yyin = fopen(filename.c_str(), "r");
  std::cerr << "#" << " opening input file: " << std::endl;
  if(yyin == NULL){
    std::cerr << "#Couldn't open input file: " << filename << std::endl;
    exit(1);
  }
  std::cerr <<"#open successfully" << std::endl;
  g_root=NULL;
  yyparse(); 

  std::cerr <<"#lexer pass" << std::endl;
  return g_root;
}

/*
make c_compiler
bin/c_compiler -S compiler_tests/my_test/test1.c -o test_program.s


make bin/c_compiler -B
bin/c_compiler -S compiler_tests/array/declare_global.c -o test_program.s
mips-linux-gnu-gcc -mfp32 -o test_program.o -c test_program.s
mips-linux-gnu-gcc -mfp32 -static -o test_program test_program.o compiler_tests/array/declare_global_driver.c
qemu-mips test_program
*/
