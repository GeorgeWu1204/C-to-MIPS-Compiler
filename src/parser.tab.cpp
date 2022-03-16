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
    IDENTIFIER = 260,
    INT_CONSTANT = 261,
    STRING_LITERAL = 262,
    SIZEOF = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPE_NAME = 285,
    TYPEDEF = 286,
    EXTERN = 287,
    STATIC = 288,
    AUTO = 289,
    REGISTER = 290,
    CHAR = 291,
    SHORT = 292,
    INT = 293,
    LONG = 294,
    SIGNED = 295,
    UNSIGNED = 296,
    FLOAT = 297,
    DOUBLE = 298,
    CONST = 299,
    VOLATILE = 300,
    VOID = 301,
    STRUCT = 302,
    UNION = 303,
    ENUM = 304,
    ELLIPSIS = 305,
    CASE = 306,
    DEFAULT = 307,
    IF = 308,
    ELSE = 309,
    SWITCH = 310,
    WHILE = 311,
    DO = 312,
    FOR = 313,
    GOTO = 314,
    CONTINUE = 315,
    BREAK = 316,
    RETURN = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "src/parser.y"

  NodePtr top;
  ListTypePtr list;
  //double double_number;
  int int_number;
  std::string *string;
  yytokentype token;
  //????

#line 209 "src/parser.tab.cpp"

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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

#define YYUNDEFTOK  2
#define YYMAXUTOK   317


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
       2,     2,     2,    77,     2,     2,     2,    79,    72,     2,
      63,    64,    73,    74,    67,    75,     2,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    70,
      81,    71,    80,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    84,    69,    76,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    71,    72,    76,    77,    82,    89,    98,
     114,   120,   121,   122,   125,   126,   127,   132,   136,   137,
     140,   150,   154,   155,   156,   157,   162,   163,   168,   169,
     175,   176,   181,   182,   187,   188,   189,   193,   194,   216,
     217,   218,   219,   220,   224,   225,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   248,   249,
     251,   253,   254,   258,   259,   260,   261,   262,   263,   268,
     269,   270,   273,   274,   275,   279,   280,   284,   285,   286,
     294,   295,   296,   302,   303,   304,   305,   310,   315,   316,
     317,   321,   322,   323,   324,   325,   328,   329,   330,   334,
     335,   339,   340,   344,   345,   348,   349,   352,   353,   357,
     358,   363,   364,   368,   369,   373,   374,   375,   379,   381,
     382,   386,   389
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANT", "FLOAT_CONSTANT",
  "IDENTIFIER", "INT_CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP",
  "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['",
  "']'", "','", "'{'", "'}'", "';'", "'='", "'&'", "'*'", "'+'", "'-'",
  "'~'", "'!'", "'/'", "'%'", "'>'", "'<'", "'?'", "':'", "'|'", "'^'",
  "$accept", "ROOT", "Translation_unit", "External_declaration",
  "Function_definition", "Declaration_specifiers", "Type_specifier",
  "Declarator", "Direct_declarator", "Parameter_type_list",
  "Parameter_list", "Parameter_declaration", "Constant_expression",
  "Compound_statement", "Declaration_list", "Declaration",
  "Init_declarator_list", "Init_declarator", "Initializer",
  "Initializer_list", "Statement", "Expression", "Assignment_expression",
  "Unary_expression", "Unary_operator", "Postfix_expression",
  "Argument_expression_list", "Primary_expression", "Additive_expression",
  "Multiplicative_expression", "Cast_expression", "Shift_expression",
  "Relational_expression", "Equality_expression", "Conditional_expression",
  "Logical_or_expression", "Logical_and_expression", "Or_expression",
  "Xor_expression", "And_expression", "Statement_list",
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
     315,   316,   317,    40,    41,    91,    93,    44,   123,   125,
      59,    61,    38,    42,    43,    45,   126,    33,    47,    37,
      62,    60,    63,    58,   124,    94
};
# endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,   -98,    32,   -13,   -98,   -98,     9,   -98,   -98,   -98,
     -98,   -98,    11,   -98,   -28,   -46,   -25,   -98,    -4,   140,
      56,   -98,   -18,   360,    11,   -98,   -98,   -98,   -98,   -98,
     154,   154,   154,   -10,    18,    48,    72,   368,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,     9,   -98,   180,   -98,
     -98,   -23,   -98,   464,   154,    12,   -98,   -26,   -52,   -98,
      45,    36,   104,   -98,    -6,   121,    57,    58,    91,   214,
     -98,   -98,   -98,   -98,    56,   -98,   -98,   -98,    11,   105,
     103,   -98,   -98,   106,   -98,   -98,   100,   -98,   -98,   -98,
     -98,   154,   154,   154,   376,   -98,   -15,   -98,   -98,   253,
     154,   -98,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   -98,   -98,   -98,   399,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   -98,   -98,   -98,
     -31,   -98,   -98,   -13,   -98,    -8,     1,    73,   376,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,    85,    88,   -52,   -52,   -98,
     -98,   -98,   -26,   -26,    45,    45,    45,    45,    36,    36,
     121,   -49,    57,    58,    91,   104,   326,   -98,   -98,   287,
     287,   287,   406,   -98,   154,   -98,   154,   -98,   -98,   119,
     -98,   -98,   287,    89,   -98,   -98,   287,   -98,   287,   -98,
     -98
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,     0,     2,     3,     5,     0,     8,     6,     1,
       4,    11,     0,    28,    32,    10,     0,    30,     0,     0,
       0,     7,     0,     0,     0,    29,    12,    77,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,    22,   113,
      63,    64,    65,    66,    67,    68,     0,    39,     0,    26,
     111,     0,    44,    87,     0,    58,    69,    88,    80,    83,
      91,    96,   109,    57,    99,   101,   103,   105,   107,     0,
      40,    41,    42,    43,     0,    33,    34,    13,     0,     0,
      17,    18,    15,     0,    87,    21,    32,    31,    62,    59,
      60,     0,     0,     0,     0,   121,     0,    24,    27,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,   112,    37,
       0,    20,    16,     0,    14,     0,     0,     0,     0,   122,
      25,    45,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    46,    70,    75,     0,     0,    81,    82,    84,
      85,    86,    89,    90,    94,    95,    92,    93,    97,    98,
     102,     0,   104,   106,   108,   110,     0,    35,    19,     0,
       0,     0,     0,    71,     0,    74,     0,    36,    38,   115,
     117,   118,     0,     0,    76,   100,     0,   119,     0,   116,
     120
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   -98,   173,   -98,    -7,   -98,    -5,   -98,   -98,
     -98,    37,   -98,   165,   -98,   -11,   -98,   157,   -68,   -98,
     -64,     2,   -20,   -21,   -98,   -98,   -98,   -98,    -1,    39,
     -51,   -97,    38,    46,   -19,   -98,    52,    51,    55,    62,
     144,   -70,   -98,   -98,   -98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,     7,    86,    15,    79,
      80,    81,    83,    47,    48,     8,    16,    17,    75,   140,
      50,    51,    52,    53,    54,    55,   165,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      76,    14,    84,   113,    85,   138,   139,    18,    49,    88,
      89,    90,    46,   131,    11,    78,    11,    22,   100,    23,
       1,   120,   114,   115,   148,     1,   121,   122,   174,   175,
     176,   177,     9,    84,   196,   138,   186,    98,   187,    96,
      19,    46,    24,    20,   100,    25,    77,   101,   118,   119,
     125,   126,   100,    91,    76,   149,   189,   123,   124,   100,
      26,    27,    28,    29,    30,   190,    31,    32,   100,   169,
     170,   171,    12,   141,    12,   116,   132,   117,   192,    13,
     151,    92,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   145,   146,   147,   164,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    93,    84,    84,    84,    84,   127,   128,   198,   166,
     129,   130,   172,   173,    74,   199,   200,   201,    40,    41,
      42,    43,    44,    45,   181,    94,    78,   191,   207,   133,
     100,   134,   209,   135,   210,    27,    28,    29,    30,   193,
      31,    32,   194,   208,   195,   100,   100,   167,   168,    27,
      28,    29,    30,   136,    31,    32,    76,   178,   179,   142,
     143,    20,   144,   206,   204,    84,    10,   205,     1,    21,
     188,    87,   185,   180,   182,    27,    28,    29,    30,   183,
      31,    32,    99,    33,   203,    34,    35,   184,    36,     0,
       0,     0,    37,     0,     0,     0,     0,     0,    19,    38,
      39,     0,    40,    41,    42,    43,    44,    45,     1,    27,
      28,    29,    30,     0,    31,    32,    40,    41,    42,    43,
      44,    45,     0,    33,     0,    34,    35,     0,    36,     0,
       0,     0,    37,     0,     0,     0,     0,     0,    19,    97,
      39,     0,    40,    41,    42,    43,    44,    45,    27,    28,
      29,    30,     0,    31,    32,     0,     0,    33,     0,    34,
      35,     0,    36,     0,     0,     0,    37,     0,     0,     0,
       0,     0,    19,   137,    39,     0,    40,    41,    42,    43,
      44,    45,    27,    28,    29,    30,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,    33,     0,    34,    35,
       0,    36,     0,     0,     0,    37,     0,     0,     0,     0,
       0,    19,   150,    39,     0,    40,    41,    42,    43,    44,
      45,    27,    28,    29,    30,     0,    31,    32,     0,     0,
      33,     0,    34,    35,     0,    36,     0,     0,     0,    37,
       0,     0,     0,     0,     0,    19,     0,    39,     0,    40,
      41,    42,    43,    44,    45,    27,    28,    29,    30,     0,
      31,    32,     0,    27,    28,    29,    30,     0,    31,    32,
       0,    27,    28,    29,    30,     0,    31,    32,     0,     0,
       0,     0,     0,     0,    74,   197,     0,     0,    40,    41,
      42,    43,    44,    45,    27,    28,    29,    30,     0,    31,
      32,    27,    28,    29,    30,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,    40,    41,    42,    43,    44,    45,    95,     0,
      40,    41,    42,    43,    44,    45,    39,     0,    40,    41,
      42,    43,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
     202,    40,    41,    42,    43,    44,    45,     0,    40,    41,
      42,    43,    44,    45,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112
};

static const yytype_int16 yycheck[] =
{
      20,     6,    23,    54,    23,    69,    74,    12,    19,    30,
      31,    32,    19,    19,     5,    22,     5,    63,    67,    65,
      38,    73,    10,    11,    94,    38,    78,    79,   125,   126,
     127,   128,     0,    54,    83,    99,    67,    48,    69,    37,
      68,    48,    67,    71,    67,    70,    64,    70,    74,    75,
      14,    15,    67,    63,    74,    70,    64,    12,    13,    67,
      64,     5,     6,     7,     8,    64,    10,    11,    67,   120,
     121,   122,    63,    78,    63,    63,    82,    65,   148,    70,
     100,    63,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    91,    92,    93,   116,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    63,   133,   134,   135,   136,    80,    81,   186,   117,
      16,    17,   123,   124,    68,   189,   190,   191,    72,    73,
      74,    75,    76,    77,   132,    63,   143,    64,   202,    18,
      67,    84,   206,    85,   208,     5,     6,     7,     8,    64,
      10,    11,    67,    64,    66,    67,    67,   118,   119,     5,
       6,     7,     8,    72,    10,    11,   186,   129,   130,    64,
      67,    71,    66,    54,   194,   196,     3,   196,    38,    14,
     143,    24,   136,   131,   133,     5,     6,     7,     8,   134,
      10,    11,    48,    53,   192,    55,    56,   135,    58,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    72,    73,    74,    75,    76,    77,    38,     5,
       6,     7,     8,    -1,    10,    11,    72,    73,    74,    75,
      76,    77,    -1,    53,    -1,    55,    56,    -1,    58,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    72,    73,    74,    75,    76,    77,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    53,    -1,    55,
      56,    -1,    58,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    77,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,
      -1,    58,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      53,    -1,    55,    56,    -1,    58,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      73,    74,    75,    76,    77,     5,     6,     7,     8,    -1,
      10,    11,    -1,     5,     6,     7,     8,    -1,    10,    11,
      -1,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    72,    73,
      74,    75,    76,    77,     5,     6,     7,     8,    -1,    10,
      11,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    70,    -1,
      72,    73,    74,    75,    76,    77,    70,    -1,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    72,    73,    74,    75,    76,    77,    -1,    72,    73,
      74,    75,    76,    77,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    87,    88,    89,    90,    91,    92,   101,     0,
      89,     5,    63,    70,    93,    94,   102,   103,    93,    68,
      71,    99,    63,    65,    67,    70,    64,     5,     6,     7,
       8,    10,    11,    53,    55,    56,    58,    62,    69,    70,
      72,    73,    74,    75,    76,    77,    91,    99,   100,   101,
     106,   107,   108,   109,   110,   111,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    68,   104,   108,    64,    91,    95,
      96,    97,    66,    98,   109,   120,    93,   103,   109,   109,
     109,    63,    63,    63,    63,    70,   107,    69,   101,   126,
      67,    70,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    71,   116,    10,    11,    63,    65,    74,    75,
      73,    78,    79,    12,    13,    14,    15,    80,    81,    16,
      17,    19,    82,    18,    84,    85,    72,    69,   106,   104,
     105,    93,    64,    67,    66,   107,   107,   107,   127,    70,
      69,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,    64,   108,   112,   107,   115,   115,   116,
     116,   116,   114,   114,   117,   117,   117,   117,   118,   118,
     122,   107,   123,   124,   125,   119,    67,    69,    97,    64,
      64,    64,   127,    64,    67,    66,    83,    69,   104,   106,
     106,   106,    64,   107,   108,   120,    54,   106,    64,   106,
     106
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    90,    91,    92,
      93,    94,    94,    94,    94,    94,    94,    95,    96,    96,
      97,    98,    99,    99,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   105,   105,   106,
     106,   106,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   109,   109,   110,   110,   110,   110,   110,   110,   111,
     111,   111,   111,   111,   111,   112,   112,   113,   113,   113,
     114,   114,   114,   115,   115,   115,   115,   116,   117,   117,
     117,   118,   118,   118,   118,   118,   119,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   128,   129,   129,
     129,   130,   130
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     1,
       1,     1,     3,     3,     4,     3,     4,     1,     1,     3,
       2,     1,     2,     3,     3,     4,     1,     2,     2,     3,
       1,     3,     1,     3,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     2,     2,     4,     1,     3,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     2,     5,     7,     5,     5,     6,
       7,     2,     3
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
#line 67 "src/parser.y"
                     { g_root = new Root_Mips(*(yyvsp[0].list));}
#line 1623 "src/parser.tab.cpp"
    break;

  case 3:
#line 71 "src/parser.y"
                                                                    {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1629 "src/parser.tab.cpp"
    break;

  case 4:
#line 72 "src/parser.y"
                                                                    {(yyval.list) = add_to_list((yyvsp[-1].list),(yyvsp[0].top));}
#line 1635 "src/parser.tab.cpp"
    break;

  case 5:
#line 76 "src/parser.y"
                                                                    {(yyval.top) = (yyvsp[0].top);}
#line 1641 "src/parser.tab.cpp"
    break;

  case 6:
#line 77 "src/parser.y"
                                                                    {std::cout << std::endl; std::cout <<"Parser "<< "76" << " Global" << std::endl;(yyval.top) = new Global_Declaration_Mips((yyvsp[0].top));std::cout << "done" << std::endl;}
#line 1647 "src/parser.tab.cpp"
    break;

  case 7:
#line 82 "src/parser.y"
                                                                     {std::cout << std::endl; std::cout <<"Parser "<< "81" << " Function" << std::endl;(yyval.top) = new Function(new Declaration_Mips((yyvsp[-2].top), (yyvsp[-1].top)), (yyvsp[0].top));std::cout << "done" << std::endl;}
#line 1653 "src/parser.tab.cpp"
    break;

  case 8:
#line 89 "src/parser.y"
                                                                     {(yyval.top) = new Type_Mips(*(yyvsp[0].string));}
#line 1659 "src/parser.tab.cpp"
    break;

  case 9:
#line 98 "src/parser.y"
                                                                           {std::cout<< std::endl; std::cout<< "Parser" << " 96 " << "int detected "<< std::endl; (yyval.string) = new std::string("INT");  std::cout<< "int detected"<< std::endl;}
#line 1665 "src/parser.tab.cpp"
    break;

  case 10:
#line 114 "src/parser.y"
                                                                            {std::cout <<"gg" << std::endl; (yyval.top) = (yyvsp[0].top);}
#line 1671 "src/parser.tab.cpp"
    break;

  case 11:
#line 120 "src/parser.y"
                                                                            {std::cout << std::endl;std::cout <<"Parser "<< "114" << " IDENTIFIER" << std::endl; (yyval.top) = new Identifier_Mips(*(yyvsp[0].string));}
#line 1677 "src/parser.tab.cpp"
    break;

  case 12:
#line 121 "src/parser.y"
                                                                            {std::cerr << " Diclerator_Mips Unsupported" << std::endl;}
#line 1683 "src/parser.tab.cpp"
    break;

  case 13:
#line 122 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "116" << " Function_Declarator" << std::endl; (yyval.top) = new Function_Declarator_Mips((yyvsp[-2].top));}
#line 1689 "src/parser.tab.cpp"
    break;

  case 14:
#line 125 "src/parser.y"
                                                                            {std::cout << std::endl;std::cout <<"Parser "<< "196" << " array_Declarator_with_param" << std::endl; (yyval.top) = new Declare_Array_Mips((yyvsp[-3].top), (yyvsp[-1].top));}
#line 1695 "src/parser.tab.cpp"
    break;

  case 15:
#line 126 "src/parser.y"
                                                                            {std::cout << std::endl;std::cout <<"Parser "<< "196" << " array_Declarator" << std::endl; (yyval.top) = new Declare_Array_Mips((yyvsp[-2].top));}
#line 1701 "src/parser.tab.cpp"
    break;

  case 16:
#line 127 "src/parser.y"
                                                                            {std::cout << std::endl;std::cout <<"Parser "<< "116" << " Function_Declarator_with_param" << std::endl; (yyval.top) = new Function_Declarator_Mips((yyvsp[-3].top), *(yyvsp[-1].list));}
#line 1707 "src/parser.tab.cpp"
    break;

  case 17:
#line 132 "src/parser.y"
                                                                            {(yyval.list) = (yyvsp[0].list);}
#line 1713 "src/parser.tab.cpp"
    break;

  case 18:
#line 136 "src/parser.y"
                                                                            {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1719 "src/parser.tab.cpp"
    break;

  case 19:
#line 137 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 1725 "src/parser.tab.cpp"
    break;

  case 20:
#line 140 "src/parser.y"
                                                                            {(yyval.top) = new Declaration_Mips((yyvsp[-1].top), (yyvsp[0].top));}
#line 1731 "src/parser.tab.cpp"
    break;

  case 21:
#line 150 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 1737 "src/parser.tab.cpp"
    break;

  case 22:
#line 154 "src/parser.y"
                                                                      {(yyval.top) = new Compound_statement_Mips();}
#line 1743 "src/parser.tab.cpp"
    break;

  case 23:
#line 155 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "131" << " Compound_statement_Statement  " << std::endl; (yyval.top) = new Compound_statement_Mips(*(yyvsp[-1].list));std::cout<< "compond work" << std::endl;}
#line 1749 "src/parser.tab.cpp"
    break;

  case 24:
#line 156 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "132" << " Compound_statement_Declaration" << std::endl; (yyval.top) = new Compound_statement_Mips(*(yyvsp[-1].list)); std::cout<< "compond work" << std::endl;}
#line 1755 "src/parser.tab.cpp"
    break;

  case 25:
#line 157 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "133" << " Compound_statement_Declaration_AND_Statement" << std::endl;(yyval.top) = new Compound_statement_Mips(*(yyvsp[-2].list), *(yyvsp[-1].list)); std::cout<< "compond work" << std::endl;}
#line 1761 "src/parser.tab.cpp"
    break;

  case 26:
#line 162 "src/parser.y"
                                                                            {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1767 "src/parser.tab.cpp"
    break;

  case 27:
#line 163 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-1].list),(yyvsp[0].top));}
#line 1773 "src/parser.tab.cpp"
    break;

  case 28:
#line 168 "src/parser.y"
                                                                            {std::cerr << "Unsupported" << std::endl;}
#line 1779 "src/parser.tab.cpp"
    break;

  case 29:
#line 169 "src/parser.y"
                                                                            {(yyval.top) = new Declaration_Mips((yyvsp[-2].top), *(yyvsp[-1].list));}
#line 1785 "src/parser.tab.cpp"
    break;

  case 30:
#line 175 "src/parser.y"
                                                                            {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1791 "src/parser.tab.cpp"
    break;

  case 31:
#line 176 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 1797 "src/parser.tab.cpp"
    break;

  case 32:
#line 181 "src/parser.y"
                                                                            {(yyval.top) = (yyvsp[0].top);}
#line 1803 "src/parser.tab.cpp"
    break;

  case 33:
#line 182 "src/parser.y"
                                                                            {std::cout << std::endl;std::cout <<"Parser "<< "158" << " Init_Declarator" << std::endl;(yyval.top) = new Init_Declarator_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 1809 "src/parser.tab.cpp"
    break;

  case 34:
#line 187 "src/parser.y"
                                                                            {(yyval.top) = (yyvsp[0].top);}
#line 1815 "src/parser.tab.cpp"
    break;

  case 35:
#line 188 "src/parser.y"
                                                                            {(yyval.top) = new Array_Initializer_Mips(*(yyvsp[-1].list));}
#line 1821 "src/parser.tab.cpp"
    break;

  case 36:
#line 189 "src/parser.y"
                                                                      {(yyval.top) = new Array_Initializer_Mips(*(yyvsp[-2].list));}
#line 1827 "src/parser.tab.cpp"
    break;

  case 37:
#line 193 "src/parser.y"
                                                                      {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1833 "src/parser.tab.cpp"
    break;

  case 38:
#line 194 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 1839 "src/parser.tab.cpp"
    break;

  case 39:
#line 216 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "175" << " CompoundStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1845 "src/parser.tab.cpp"
    break;

  case 40:
#line 217 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "176" << " ExpressionStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1851 "src/parser.tab.cpp"
    break;

  case 41:
#line 218 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "177" << " SelectionStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1857 "src/parser.tab.cpp"
    break;

  case 42:
#line 219 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "178" << " IterationStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1863 "src/parser.tab.cpp"
    break;

  case 43:
#line 220 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "179" << " JumpStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1869 "src/parser.tab.cpp"
    break;

  case 44:
#line 224 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "183" << "Assignement Expression" << std::endl; (yyval.top) = (yyvsp[0].top);}
#line 1875 "src/parser.tab.cpp"
    break;

  case 45:
#line 225 "src/parser.y"
                                                                      {std::cerr << "Unsupported" << std::endl;}
#line 1881 "src/parser.tab.cpp"
    break;

  case 46:
#line 230 "src/parser.y"
                                                                       {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 1887 "src/parser.tab.cpp"
    break;

  case 47:
#line 231 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Multiplication_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1893 "src/parser.tab.cpp"
    break;

  case 48:
#line 232 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Division_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1899 "src/parser.tab.cpp"
    break;

  case 49:
#line 233 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Mod_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1905 "src/parser.tab.cpp"
    break;

  case 50:
#line 234 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Addition_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1911 "src/parser.tab.cpp"
    break;

  case 51:
#line 235 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Subtraction_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1917 "src/parser.tab.cpp"
    break;

  case 52:
#line 236 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Left_Shift_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1923 "src/parser.tab.cpp"
    break;

  case 53:
#line 237 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Right_Shift_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1929 "src/parser.tab.cpp"
    break;

  case 54:
#line 238 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new BitAnd_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1935 "src/parser.tab.cpp"
    break;

  case 55:
#line 239 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new BitXor_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1941 "src/parser.tab.cpp"
    break;

  case 56:
#line 240 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new BitOr_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1947 "src/parser.tab.cpp"
    break;

  case 57:
#line 241 "src/parser.y"
                                                                       {(yyval.top) = (yyvsp[0].top);}
#line 1953 "src/parser.tab.cpp"
    break;

  case 58:
#line 248 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "209" << " Unary_expression" << std::endl; (yyval.top) = (yyvsp[0].top);}
#line 1959 "src/parser.tab.cpp"
    break;

  case 59:
#line 249 "src/parser.y"
                                                                              {(yyval.top) = new Pre_Increment_MIPS((yyvsp[0].top));}
#line 1965 "src/parser.tab.cpp"
    break;

  case 60:
#line 251 "src/parser.y"
                                                                        {(yyval.top) = new Pre_Decrement_MIPS((yyvsp[0].top));}
#line 1971 "src/parser.tab.cpp"
    break;

  case 61:
#line 253 "src/parser.y"
                                                                        {std::cout << "Unsupported 3" << std::endl;}
#line 1977 "src/parser.tab.cpp"
    break;

  case 62:
#line 254 "src/parser.y"
                                                                        {std::cout << "Unsupported 4" << std::endl;}
#line 1983 "src/parser.tab.cpp"
    break;

  case 63:
#line 258 "src/parser.y"
                                                                              {(yyval.string) = new std::string("&");}
#line 1989 "src/parser.tab.cpp"
    break;

  case 64:
#line 259 "src/parser.y"
                                                                              {(yyval.string) = new std::string("*");}
#line 1995 "src/parser.tab.cpp"
    break;

  case 65:
#line 260 "src/parser.y"
                                                                              {(yyval.string) = new std::string("+");}
#line 2001 "src/parser.tab.cpp"
    break;

  case 66:
#line 261 "src/parser.y"
                                                                              {(yyval.string) = new std::string("-");}
#line 2007 "src/parser.tab.cpp"
    break;

  case 67:
#line 262 "src/parser.y"
                                                                              {(yyval.string) = new std::string("~");}
#line 2013 "src/parser.tab.cpp"
    break;

  case 68:
#line 263 "src/parser.y"
                                                                              {(yyval.string) = new std::string("!");}
#line 2019 "src/parser.tab.cpp"
    break;

  case 69:
#line 268 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "213" << " Primary" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 2025 "src/parser.tab.cpp"
    break;

  case 70:
#line 269 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "211" << " FunctionCall" << std::endl; (yyval.top) = new FunctionCall_Mips((yyvsp[-2].top));std::cout << "FunctionCall Done" << std::endl;}
#line 2031 "src/parser.tab.cpp"
    break;

  case 71:
#line 270 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "211" << " FunctionCall with Param" << std::endl;(yyval.top) = new FunctionCall_Mips((yyvsp[-3].top), *(yyvsp[-1].list));}
#line 2037 "src/parser.tab.cpp"
    break;

  case 72:
#line 273 "src/parser.y"
                                                                              {(yyval.top) = new Post_Increment_MIPS((yyvsp[-1].top));}
#line 2043 "src/parser.tab.cpp"
    break;

  case 73:
#line 274 "src/parser.y"
                                                                              {(yyval.top) = new Post_Decrement_MIPS((yyvsp[-1].top));}
#line 2049 "src/parser.tab.cpp"
    break;

  case 74:
#line 275 "src/parser.y"
                                                                        {std::cout << std::endl;std::cout <<"Parser "<< "255" << "Array_Access_Mips" << std::endl;(yyval.top) = new Array_Access_Mips((yyvsp[-3].top), (yyvsp[-1].top));}
#line 2055 "src/parser.tab.cpp"
    break;

  case 75:
#line 279 "src/parser.y"
                                                                              {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 2061 "src/parser.tab.cpp"
    break;

  case 76:
#line 280 "src/parser.y"
                                                                              {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 2067 "src/parser.tab.cpp"
    break;

  case 77:
#line 284 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "226" << " IDENTIFIER" << std::endl; (yyval.top) = new Identifier_Mips(*(yyvsp[0].string));}
#line 2073 "src/parser.tab.cpp"
    break;

  case 78:
#line 285 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "227" << " INI_CONSTANT" << std::endl;(yyval.top) = new Int_Constant_Mips((yyvsp[0].int_number));}
#line 2079 "src/parser.tab.cpp"
    break;

  case 79:
#line 286 "src/parser.y"
                                                                              {std::cerr << "Unsupported" << std::endl;}
#line 2085 "src/parser.tab.cpp"
    break;

  case 80:
#line 294 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2091 "src/parser.tab.cpp"
    break;

  case 81:
#line 295 "src/parser.y"
                                                                        {std::cout << std::endl;std::cout <<"Parser "<< "240" << " Addition" << std::endl; (yyval.top) = new Addition_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2097 "src/parser.tab.cpp"
    break;

  case 82:
#line 296 "src/parser.y"
                                                                        {(yyval.top) = new Subtraction_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2103 "src/parser.tab.cpp"
    break;

  case 83:
#line 302 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2109 "src/parser.tab.cpp"
    break;

  case 84:
#line 303 "src/parser.y"
                                                                        {(yyval.top) = new Multiplication_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2115 "src/parser.tab.cpp"
    break;

  case 85:
#line 304 "src/parser.y"
                                                                        {(yyval.top) = new Division_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2121 "src/parser.tab.cpp"
    break;

  case 86:
#line 305 "src/parser.y"
                                                                        {(yyval.top) = new Mod_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2127 "src/parser.tab.cpp"
    break;

  case 87:
#line 310 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2133 "src/parser.tab.cpp"
    break;

  case 88:
#line 315 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2139 "src/parser.tab.cpp"
    break;

  case 89:
#line 316 "src/parser.y"
                                                                        {(yyval.top) = new Left_Shift_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2145 "src/parser.tab.cpp"
    break;

  case 90:
#line 317 "src/parser.y"
                                                                        {(yyval.top) = new Right_Shift_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2151 "src/parser.tab.cpp"
    break;

  case 91:
#line 321 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2157 "src/parser.tab.cpp"
    break;

  case 92:
#line 322 "src/parser.y"
                                                                        {(yyval.top) = new Greater_Than_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2163 "src/parser.tab.cpp"
    break;

  case 93:
#line 323 "src/parser.y"
                                                                        {std::cout << std::endl;std::cout <<"Parser "<< "285" << " Smaller Than" << std::endl;(yyval.top) = new Less_Than_MIPS((yyvsp[-2].top),(yyvsp[0].top));std::cout <<"done" << std::endl;}
#line 2169 "src/parser.tab.cpp"
    break;

  case 94:
#line 324 "src/parser.y"
                                                                        {(yyval.top) = new Less_Than_Equal_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2175 "src/parser.tab.cpp"
    break;

  case 95:
#line 325 "src/parser.y"
                                                                        {(yyval.top) = new Greater_Than_Equal_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2181 "src/parser.tab.cpp"
    break;

  case 96:
#line 328 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2187 "src/parser.tab.cpp"
    break;

  case 97:
#line 329 "src/parser.y"
                                                                        {(yyval.top) = new Equal_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2193 "src/parser.tab.cpp"
    break;

  case 98:
#line 330 "src/parser.y"
                                                                        {(yyval.top) = new NotEqual_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2199 "src/parser.tab.cpp"
    break;

  case 99:
#line 334 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2205 "src/parser.tab.cpp"
    break;

  case 100:
#line 335 "src/parser.y"
                                                                        {std::cerr << "Unsupported" << std::endl;}
#line 2211 "src/parser.tab.cpp"
    break;

  case 101:
#line 339 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2217 "src/parser.tab.cpp"
    break;

  case 102:
#line 340 "src/parser.y"
                                                                        {(yyval.top) = new LogicOr_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2223 "src/parser.tab.cpp"
    break;

  case 103:
#line 344 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2229 "src/parser.tab.cpp"
    break;

  case 104:
#line 345 "src/parser.y"
                                                                        {(yyval.top) = new LogicAnd_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2235 "src/parser.tab.cpp"
    break;

  case 105:
#line 348 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2241 "src/parser.tab.cpp"
    break;

  case 106:
#line 349 "src/parser.y"
                                                                        {(yyval.top) = new BitOr_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2247 "src/parser.tab.cpp"
    break;

  case 107:
#line 352 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2253 "src/parser.tab.cpp"
    break;

  case 108:
#line 353 "src/parser.y"
                                                                        {(yyval.top) = new BitXor_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2259 "src/parser.tab.cpp"
    break;

  case 109:
#line 357 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2265 "src/parser.tab.cpp"
    break;

  case 110:
#line 358 "src/parser.y"
                                                                        {(yyval.top) = new BitAnd_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2271 "src/parser.tab.cpp"
    break;

  case 111:
#line 363 "src/parser.y"
                                                                        {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 2277 "src/parser.tab.cpp"
    break;

  case 112:
#line 364 "src/parser.y"
                                                                        {(yyval.list) = add_to_list((yyvsp[-1].list), (yyvsp[0].top));}
#line 2283 "src/parser.tab.cpp"
    break;

  case 113:
#line 368 "src/parser.y"
                                                                        {std::cout << std::endl;std::cout <<"Parser "<< "314" << ";" << std::endl;}
#line 2289 "src/parser.tab.cpp"
    break;

  case 114:
#line 369 "src/parser.y"
                                                                        {std::cout << std::endl;std::cout <<"Parser "<< "314" << " Expression;" << std::endl; (yyval.top) = (yyvsp[-1].top);}
#line 2295 "src/parser.tab.cpp"
    break;

  case 115:
#line 373 "src/parser.y"
                                                                        {(yyval.top) = new Selection_statement_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 2301 "src/parser.tab.cpp"
    break;

  case 116:
#line 374 "src/parser.y"
                                                                        {(yyval.top) = new Selection_statement_Mips((yyvsp[-4].top), (yyvsp[-2].top), (yyvsp[0].top));}
#line 2307 "src/parser.tab.cpp"
    break;

  case 117:
#line 375 "src/parser.y"
                                                                        {std::cerr << "Unsupported" << std::endl;}
#line 2313 "src/parser.tab.cpp"
    break;

  case 118:
#line 379 "src/parser.y"
                                                                                    {std::cout << std::endl;std::cout <<"Parser "<< "324" << " While" << std::endl; (yyval.top) = new While_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 2319 "src/parser.tab.cpp"
    break;

  case 119:
#line 381 "src/parser.y"
                                                                                    {std::cout << std::endl;std::cout <<"Parser "<< "343" << " FOR(Expression_statement Expression_statement)" << std::endl;(yyval.top) = new For_Mips((yyvsp[-3].top),(yyvsp[-2].top),(yyvsp[0].top));}
#line 2325 "src/parser.tab.cpp"
    break;

  case 120:
#line 382 "src/parser.y"
                                                                                    {std::cout << std::endl;std::cout <<"Parser "<< "344" << " FOR(Expression_statement Expression_statement Expression)" << std::endl;(yyval.top) = new For_Mips((yyvsp[-4].top),(yyvsp[-3].top),(yyvsp[-2].top),(yyvsp[0].top));}
#line 2331 "src/parser.tab.cpp"
    break;

  case 121:
#line 386 "src/parser.y"
                                                                         {std::cout <<"Parser "<< "RETURN;" << std::endl; (yyval.top) = new Return_Mips();}
#line 2337 "src/parser.tab.cpp"
    break;

  case 122:
#line 389 "src/parser.y"
                                                                         {std::cout<<std::endl;std::cout <<"Parser "<< "331"<<" RETURN EXPRESSION;" << std::endl; (yyval.top) = new Return_Mips((yyvsp[-1].top));}
#line 2343 "src/parser.tab.cpp"
    break;


#line 2347 "src/parser.tab.cpp"

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
#line 395 "src/parser.y"


NodePtr g_root;

const NodePtr parseAST(std::string filename)
{
  yyin = fopen(filename.c_str(), "r");
  std::cout << " opening input file: " << std::endl;
  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << filename << std::endl;
    exit(1);
  }
  std::cout<<"open successfully" << std::endl;
  g_root=NULL;
  yyparse(); 

  std::cout<<"lexer pass" << std::endl;
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
