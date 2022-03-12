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
#define YYLAST   468

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

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
      63,    64,    73,    74,    70,    75,     2,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    69,
      81,    71,    80,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    84,    68,    76,     2,     2,     2,
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
       0,    65,    65,    69,    70,    74,    75,    80,    87,    96,
     112,   117,   118,   119,   122,   123,   126,   129,   133,   134,
     135,   136,   141,   142,   147,   148,   160,   161,   167,   178,
     179,   180,   181,   182,   186,   187,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   211,   212,
     214,   216,   217,   221,   222,   223,   224,   225,   226,   231,
     232,   233,   236,   237,   242,   243,   247,   248,   249,   257,
     258,   259,   265,   266,   267,   268,   273,   278,   279,   280,
     284,   285,   286,   287,   288,   291,   292,   293,   297,   298,
     302,   303,   307,   308,   311,   312,   315,   316,   320,   321,
     326,   327,   331,   332,   336,   337,   338,   342,   344,   345,
     349,   352
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
  "']'", "'{'", "'}'", "';'", "','", "'='", "'&'", "'*'", "'+'", "'-'",
  "'~'", "'!'", "'/'", "'%'", "'>'", "'<'", "'?'", "':'", "'|'", "'^'",
  "$accept", "ROOT", "Translation_unit", "External_declaration",
  "Function_definition", "Declaration_specifiers", "Type_specifier",
  "Declarator", "Direct_declarator", "Constant_expression",
  "Compound_statement", "Declaration_list", "Declaration",
  "Init_declarator", "Initializer", "Statement", "Expression",
  "Assignment_expression", "Unary_expression", "Unary_operator",
  "Postfix_expression", "Argument_expression_list", "Primary_expression",
  "Additive_expression", "Multiplicative_expression", "Cast_expression",
  "Shift_expression", "Relational_expression", "Equality_expression",
  "Conditional_expression", "Logical_or_expression",
  "Logical_and_expression", "Or_expression", "Xor_expression",
  "And_expression", "Statement_list", "Expression_statement",
  "Selection_statement", "Iteration_statement", "Jump_statemnet", YY_NULLPTR
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
     315,   316,   317,    40,    41,    91,    93,   123,   125,    59,
      44,    61,    38,    42,    43,    45,   126,    33,    47,    37,
      62,    60,    63,    58,   124,    94
};
# endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,   -83,    43,    -7,   -83,   -83,     4,   -83,   -83,   -83,
     -83,   -83,     8,   -83,   -27,    -9,   -16,     0,   108,   391,
     -83,     5,    55,   -83,   -83,   -83,   -83,   -83,   391,   391,
     391,    -8,     9,    42,    54,   128,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,     4,   -83,   181,   -83,   -83,   -32,
     -83,   278,   391,     7,   -83,   -17,   -54,   -83,   110,     6,
     126,   -83,   -14,    41,    53,    40,    68,   206,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,    84,   -83,   -83,   -83,
     -83,   -83,   391,   391,   391,   219,   -83,    75,    87,   -83,
     -83,   279,   -83,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   -83,   -83,   -83,   311,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   -83,   -83,
     -83,   -48,   -41,   -38,   219,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -37,   -54,   -54,   -83,   -83,   -83,   -17,   -17,   110,
     110,   110,   110,     6,     6,    41,   -55,    53,    40,    68,
     126,   304,   304,   304,   318,   -83,   391,   391,   101,   -83,
     -83,   304,   -29,   -83,   -83,   304,   -83,   304,   -83,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,     0,     2,     3,     5,     0,     8,     6,     1,
       4,    11,     0,    24,    26,    10,     0,     0,     0,     0,
       7,     0,     0,    25,    12,    66,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,    18,   102,    53,    54,
      55,    56,    57,    58,     0,    29,     0,    22,   100,     0,
      34,    76,     0,    48,    59,    77,    69,    72,    80,    85,
      98,    47,    88,    90,    92,    94,    96,     0,    30,    31,
      32,    33,    27,    28,    13,    15,     0,    76,    17,    52,
      49,    50,     0,     0,     0,     0,   110,     0,    26,    20,
      23,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    62,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,   101,
      14,     0,     0,     0,     0,   111,    21,    35,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    36,    60,
      64,     0,    70,    71,    73,    74,    75,    78,    79,    83,
      84,    81,    82,    86,    87,    91,     0,    93,    95,    97,
      99,     0,     0,     0,     0,    61,     0,     0,   104,   106,
     107,     0,     0,    65,    89,     0,   108,     0,   105,   109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -83,   157,   -83,   -10,   -83,    -5,   -83,   -83,
     148,   -83,    -4,   -83,   -83,   -61,   -33,   -19,   -18,   -83,
     -83,   -83,   -83,    37,    44,    36,   -71,    47,    38,   -21,
     -83,    49,    45,    48,    46,   132,   -82,   -83,   -83,   -83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,     7,    14,    15,    76,
      45,    46,     8,    16,    72,    48,    49,    50,    51,    52,
      53,   151,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      73,    78,    87,   134,    77,   122,   129,    17,    44,    11,
      79,    80,    81,    11,    47,    93,   171,   106,   107,   111,
     116,   117,    93,   172,   112,   113,   173,   175,   177,    93,
     129,     1,    93,   176,    77,   187,    44,    92,    93,    88,
      18,    93,    90,     9,    19,   159,   160,   161,   162,   131,
     132,   133,   174,    23,    21,    82,    22,   109,   110,   124,
      25,    26,    27,    28,    24,    29,    30,    12,   123,    74,
     108,    12,    83,    13,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   118,   119,   105,   150,
     166,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    84,    77,    77,    77,    77,
     178,   179,   180,    25,    26,    27,    28,    85,    29,    30,
     186,    75,   114,   115,   188,   126,   189,    38,    39,    40,
      41,    42,    43,    25,    26,    27,    28,   125,    29,    30,
     127,   182,   120,   121,   135,    93,     1,   154,   155,   156,
     130,   157,   158,   152,   153,   185,   184,   183,    19,    77,
      10,    31,    20,    32,    33,   170,    34,   163,   164,   167,
      35,   165,   169,   168,     0,    18,    36,    37,    91,     0,
      38,    39,    40,    41,    42,    43,    25,    26,    27,    28,
       0,    29,    30,     0,     0,     0,     0,    86,     0,     0,
      38,    39,    40,    41,    42,    43,     0,     0,     0,     0,
       0,    25,    26,    27,    28,     0,    29,    30,     0,     1,
       0,     0,     0,     0,    25,    26,    27,    28,     0,    29,
      30,     0,     0,     0,    31,     0,    32,    33,     0,    34,
       0,     0,     0,    35,     0,     0,     0,     0,    18,    89,
      37,     0,     0,    38,    39,    40,    41,    42,    43,    31,
       0,    32,    33,     0,    34,     0,     0,     0,    35,     0,
       0,     0,     0,    18,   128,    37,     0,     0,    38,    39,
      40,    41,    42,    43,    25,    26,    27,    28,    37,    29,
      30,    38,    39,    40,    41,    42,    43,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,    25,
      26,    27,    28,     0,    29,    30,    25,    26,    27,    28,
       0,    29,    30,    25,    26,    27,    28,     0,    29,    30,
       0,     0,    31,     0,    32,    33,     0,    34,     0,     0,
       0,    35,     0,     0,     0,     0,    18,   136,    37,   104,
       0,    38,    39,    40,    41,    42,    43,    31,     0,    32,
      33,     0,    34,     0,     0,     0,    35,     0,     0,     0,
       0,    18,     0,    37,     0,   149,    38,    39,    40,    41,
      42,    43,   181,    38,    39,    40,    41,    42,    43,     0,
      38,    39,    40,    41,    42,    43,    25,    26,    27,    28,
       0,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,    43
};

static const yytype_int16 yycheck[] =
{
      19,    22,    35,    85,    22,    19,    67,    12,    18,     5,
      28,    29,    30,     5,    18,    70,    64,    10,    11,    73,
      14,    15,    70,    64,    78,    79,    64,    64,    83,    70,
      91,    38,    70,    70,    52,    64,    46,    69,    70,    44,
      67,    70,    46,     0,    71,   116,   117,   118,   119,    82,
      83,    84,   134,    69,    63,    63,    65,    74,    75,    18,
       5,     6,     7,     8,    64,    10,    11,    63,    82,    64,
      63,    63,    63,    69,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    80,    81,    52,   108,
     123,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    63,   124,   125,   126,   127,
     171,   172,   173,     5,     6,     7,     8,    63,    10,    11,
     181,    66,    12,    13,   185,    85,   187,    72,    73,    74,
      75,    76,    77,     5,     6,     7,     8,    84,    10,    11,
      72,   174,    16,    17,    69,    70,    38,   111,   112,   113,
      66,   114,   115,   109,   110,    54,   177,   176,    71,   177,
       3,    53,    14,    55,    56,   127,    58,   120,   121,   124,
      62,   122,   126,   125,    -1,    67,    68,    69,    46,    -1,
      72,    73,    74,    75,    76,    77,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,    -1,    10,    11,    -1,    38,
      -1,    -1,    -1,    -1,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    53,    -1,    55,    56,    -1,    58,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    73,    74,    75,    76,    77,    53,
      -1,    55,    56,    -1,    58,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    73,
      74,    75,    76,    77,     5,     6,     7,     8,    69,    10,
      11,    72,    73,    74,    75,    76,    77,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,     5,
       6,     7,     8,    -1,    10,    11,     5,     6,     7,     8,
      -1,    10,    11,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    53,    -1,    55,    56,    -1,    58,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    71,
      -1,    72,    73,    74,    75,    76,    77,    53,    -1,    55,
      56,    -1,    58,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    64,    72,    73,    74,    75,
      76,    77,    64,    72,    73,    74,    75,    76,    77,    -1,
      72,    73,    74,    75,    76,    77,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    87,    88,    89,    90,    91,    92,    98,     0,
      89,     5,    63,    69,    93,    94,    99,    93,    67,    71,
      96,    63,    65,    69,    64,     5,     6,     7,     8,    10,
      11,    53,    55,    56,    58,    62,    68,    69,    72,    73,
      74,    75,    76,    77,    91,    96,    97,    98,   101,   102,
     103,   104,   105,   106,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   100,   103,    64,    66,    95,   104,   115,   104,
     104,   104,    63,    63,    63,    63,    69,   102,    93,    68,
      98,   121,    69,    70,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    71,   111,    10,    11,    63,    74,
      75,    73,    78,    79,    12,    13,    14,    15,    80,    81,
      16,    17,    19,    82,    18,    84,    85,    72,    68,   101,
      66,   102,   102,   102,   122,    69,    68,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,    64,
     103,   107,   110,   110,   111,   111,   111,   109,   109,   112,
     112,   112,   112,   113,   113,   117,   102,   118,   119,   120,
     114,    64,    64,    64,   122,    64,    70,    83,   101,   101,
     101,    64,   102,   103,   115,    54,   101,    64,   101,   101
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    90,    91,    92,
      93,    94,    94,    94,    94,    94,    94,    95,    96,    96,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   106,
     106,   106,   106,   106,   107,   107,   108,   108,   108,   109,
     109,   109,   110,   110,   110,   110,   111,   112,   112,   112,
     113,   113,   113,   113,   113,   114,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   123,   124,   124,   124,
     125,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     1,
       1,     1,     3,     3,     4,     3,     3,     1,     2,     3,
       3,     4,     1,     2,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     2,     2,     1,     3,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     3,     1,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     1,     2,     5,     7,     5,     5,     6,     7,
       2,     3
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
#line 65 "src/parser.y"
                     { g_root = new Root_Mips(*(yyvsp[0].list));}
#line 1593 "src/parser.tab.cpp"
    break;

  case 3:
#line 69 "src/parser.y"
                                                                    {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1599 "src/parser.tab.cpp"
    break;

  case 4:
#line 70 "src/parser.y"
                                                                    {(yyval.list) = add_to_list((yyvsp[-1].list),(yyvsp[0].top));}
#line 1605 "src/parser.tab.cpp"
    break;

  case 5:
#line 74 "src/parser.y"
                                                                    {(yyval.top) = (yyvsp[0].top);}
#line 1611 "src/parser.tab.cpp"
    break;

  case 6:
#line 75 "src/parser.y"
                                                                    {(yyval.top) = (yyvsp[0].top);}
#line 1617 "src/parser.tab.cpp"
    break;

  case 7:
#line 80 "src/parser.y"
                                                                     {std::cout << std::endl; std::cout <<"Parser "<< "77" << " Function" << std::endl;(yyval.top) = new Function(new Declaration_Mips((yyvsp[-2].top), (yyvsp[-1].top)), (yyvsp[0].top));}
#line 1623 "src/parser.tab.cpp"
    break;

  case 8:
#line 87 "src/parser.y"
                                                                     {(yyval.top) = new Type_Mips(*(yyvsp[0].string));}
#line 1629 "src/parser.tab.cpp"
    break;

  case 9:
#line 96 "src/parser.y"
                                                                           {std::cout<< std::endl; std::cout<< "Parser" << " 96 " << "int detected "<< std::endl; (yyval.string) = new std::string("INT");  std::cout<< "int detected"<< std::endl;}
#line 1635 "src/parser.tab.cpp"
    break;

  case 10:
#line 112 "src/parser.y"
                                                                            {std::cout <<"gg" << std::endl; (yyval.top) = (yyvsp[0].top);}
#line 1641 "src/parser.tab.cpp"
    break;

  case 11:
#line 117 "src/parser.y"
                                                                            {std::cout << std::endl;std::cout <<"Parser "<< "114" << " IDENTIFIER" << std::endl; (yyval.top) = new Identifier_Mips(*(yyvsp[0].string));}
#line 1647 "src/parser.tab.cpp"
    break;

  case 12:
#line 118 "src/parser.y"
                                                                            {std::cerr << " Diclerator_Mips Unsupported" << std::endl;}
#line 1653 "src/parser.tab.cpp"
    break;

  case 13:
#line 119 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "116" << " Function_Declarator" << std::endl; (yyval.top) = new Function_Declarator_Mips((yyvsp[-2].top));}
#line 1659 "src/parser.tab.cpp"
    break;

  case 17:
#line 129 "src/parser.y"
                                                                      {(yyval.top) = (yyvsp[0].top);}
#line 1665 "src/parser.tab.cpp"
    break;

  case 18:
#line 133 "src/parser.y"
                                                                      {(yyval.top) = new Compound_statement_Mips();}
#line 1671 "src/parser.tab.cpp"
    break;

  case 19:
#line 134 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "131" << " Compound_statement_Statement  " << std::endl; (yyval.top) = new Compound_statement_Mips(*(yyvsp[-1].list));std::cout<< "compond work" << std::endl;}
#line 1677 "src/parser.tab.cpp"
    break;

  case 20:
#line 135 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "132" << " Compound_statement_Declaration" << std::endl; (yyval.top) = new Compound_statement_Mips(*(yyvsp[-1].list)); std::cout<< "compond work" << std::endl;}
#line 1683 "src/parser.tab.cpp"
    break;

  case 21:
#line 136 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "133" << " Compound_statement_Declaration_AND_Statement" << std::endl;(yyval.top) = new Compound_statement_Mips(*(yyvsp[-2].list), *(yyvsp[-1].list)); std::cout<< "compond work" << std::endl;}
#line 1689 "src/parser.tab.cpp"
    break;

  case 22:
#line 141 "src/parser.y"
                                                                            {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1695 "src/parser.tab.cpp"
    break;

  case 23:
#line 142 "src/parser.y"
                                                                            {(yyval.list) = add_to_list((yyvsp[-1].list),(yyvsp[0].top));}
#line 1701 "src/parser.tab.cpp"
    break;

  case 24:
#line 147 "src/parser.y"
                                                                            {std::cerr << "Unsupported" << std::endl;}
#line 1707 "src/parser.tab.cpp"
    break;

  case 25:
#line 148 "src/parser.y"
                                                                            {(yyval.top) = new Declaration_Mips((yyvsp[-2].top), (yyvsp[-1].top));}
#line 1713 "src/parser.tab.cpp"
    break;

  case 26:
#line 160 "src/parser.y"
                                                                            {(yyval.top) = (yyvsp[0].top);}
#line 1719 "src/parser.tab.cpp"
    break;

  case 27:
#line 161 "src/parser.y"
                                                                            {std::cout << std::endl;std::cout <<"Parser "<< "158" << " Init_Declarator" << std::endl;(yyval.top) = new Init_Declarator_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 1725 "src/parser.tab.cpp"
    break;

  case 28:
#line 167 "src/parser.y"
                                                                            {(yyval.top) = (yyvsp[0].top);}
#line 1731 "src/parser.tab.cpp"
    break;

  case 29:
#line 178 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "175" << " CompoundStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1737 "src/parser.tab.cpp"
    break;

  case 30:
#line 179 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "176" << " ExpressionStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1743 "src/parser.tab.cpp"
    break;

  case 31:
#line 180 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "177" << " SelectionStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1749 "src/parser.tab.cpp"
    break;

  case 32:
#line 181 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "178" << " IterationStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1755 "src/parser.tab.cpp"
    break;

  case 33:
#line 182 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "179" << " JumpStatement" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1761 "src/parser.tab.cpp"
    break;

  case 34:
#line 186 "src/parser.y"
                                                                      {std::cout << std::endl;std::cout <<"Parser "<< "183" << " Expression" << std::endl; (yyval.top) = (yyvsp[0].top);}
#line 1767 "src/parser.tab.cpp"
    break;

  case 35:
#line 187 "src/parser.y"
                                                                      {std::cerr << "Unsupported" << std::endl;}
#line 1773 "src/parser.tab.cpp"
    break;

  case 36:
#line 193 "src/parser.y"
                                                                       {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 1779 "src/parser.tab.cpp"
    break;

  case 37:
#line 194 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Multiplication_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1785 "src/parser.tab.cpp"
    break;

  case 38:
#line 195 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Division_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1791 "src/parser.tab.cpp"
    break;

  case 39:
#line 196 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Mod_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1797 "src/parser.tab.cpp"
    break;

  case 40:
#line 197 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Addition_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1803 "src/parser.tab.cpp"
    break;

  case 41:
#line 198 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Subtraction_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1809 "src/parser.tab.cpp"
    break;

  case 42:
#line 199 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Left_Shift_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1815 "src/parser.tab.cpp"
    break;

  case 43:
#line 200 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new Right_Shift_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1821 "src/parser.tab.cpp"
    break;

  case 44:
#line 201 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new BitAnd_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1827 "src/parser.tab.cpp"
    break;

  case 45:
#line 202 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new BitXor_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1833 "src/parser.tab.cpp"
    break;

  case 46:
#line 203 "src/parser.y"
                                                                             {(yyval.top) = new Assignment_Expression_Mips((yyvsp[-2].top), new BitOr_MIPS((yyvsp[-2].top), (yyvsp[0].top)));}
#line 1839 "src/parser.tab.cpp"
    break;

  case 47:
#line 204 "src/parser.y"
                                                                       {(yyval.top) = (yyvsp[0].top);}
#line 1845 "src/parser.tab.cpp"
    break;

  case 48:
#line 211 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "209" << " Unary_expression" << std::endl; (yyval.top) = (yyvsp[0].top);}
#line 1851 "src/parser.tab.cpp"
    break;

  case 49:
#line 212 "src/parser.y"
                                                                              {(yyval.top) = new Pre_Increment_MIPS((yyvsp[0].top));}
#line 1857 "src/parser.tab.cpp"
    break;

  case 50:
#line 214 "src/parser.y"
                                                                        {(yyval.top) = new Pre_Decrement_MIPS((yyvsp[0].top));}
#line 1863 "src/parser.tab.cpp"
    break;

  case 51:
#line 216 "src/parser.y"
                                                                        {std::cout << "Unsupported 3" << std::endl;}
#line 1869 "src/parser.tab.cpp"
    break;

  case 52:
#line 217 "src/parser.y"
                                                                        {std::cout << "Unsupported 4" << std::endl;}
#line 1875 "src/parser.tab.cpp"
    break;

  case 53:
#line 221 "src/parser.y"
                                                                              {(yyval.string) = new std::string("&");}
#line 1881 "src/parser.tab.cpp"
    break;

  case 54:
#line 222 "src/parser.y"
                                                                              {(yyval.string) = new std::string("*");}
#line 1887 "src/parser.tab.cpp"
    break;

  case 55:
#line 223 "src/parser.y"
                                                                              {(yyval.string) = new std::string("+");}
#line 1893 "src/parser.tab.cpp"
    break;

  case 56:
#line 224 "src/parser.y"
                                                                              {(yyval.string) = new std::string("-");}
#line 1899 "src/parser.tab.cpp"
    break;

  case 57:
#line 225 "src/parser.y"
                                                                              {(yyval.string) = new std::string("~");}
#line 1905 "src/parser.tab.cpp"
    break;

  case 58:
#line 226 "src/parser.y"
                                                                              {(yyval.string) = new std::string("!");}
#line 1911 "src/parser.tab.cpp"
    break;

  case 59:
#line 231 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "213" << " Primary" << std::endl;(yyval.top) = (yyvsp[0].top);}
#line 1917 "src/parser.tab.cpp"
    break;

  case 60:
#line 232 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "211" << " FunctionCall" << std::endl; (yyval.top) = new FunctionCall_Mips((yyvsp[-2].top));std::cout << "FunctionCall Done" << std::endl;}
#line 1923 "src/parser.tab.cpp"
    break;

  case 61:
#line 233 "src/parser.y"
                                                                              {(yyval.top) = new FunctionCall_Mips((yyvsp[-3].top), *(yyvsp[-1].list));}
#line 1929 "src/parser.tab.cpp"
    break;

  case 62:
#line 236 "src/parser.y"
                                                                              {(yyval.top) = new Post_Increment_MIPS((yyvsp[-1].top));}
#line 1935 "src/parser.tab.cpp"
    break;

  case 63:
#line 237 "src/parser.y"
                                                                              {(yyval.top) = new Post_Decrement_MIPS((yyvsp[-1].top));}
#line 1941 "src/parser.tab.cpp"
    break;

  case 64:
#line 242 "src/parser.y"
                                                                              {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 1947 "src/parser.tab.cpp"
    break;

  case 65:
#line 243 "src/parser.y"
                                                                              {(yyval.list) = add_to_list((yyvsp[-2].list), (yyvsp[0].top));}
#line 1953 "src/parser.tab.cpp"
    break;

  case 66:
#line 247 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "226" << " IDENTIFIER" << std::endl; (yyval.top) = new Identifier_Mips(*(yyvsp[0].string));}
#line 1959 "src/parser.tab.cpp"
    break;

  case 67:
#line 248 "src/parser.y"
                                                                              {std::cout << std::endl;std::cout <<"Parser "<< "227" << " INI_CONSTANT" << std::endl;(yyval.top) = new Int_Constant_Mips((yyvsp[0].int_number));}
#line 1965 "src/parser.tab.cpp"
    break;

  case 68:
#line 249 "src/parser.y"
                                                                              {std::cerr << "Unsupported" << std::endl;}
#line 1971 "src/parser.tab.cpp"
    break;

  case 69:
#line 257 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 1977 "src/parser.tab.cpp"
    break;

  case 70:
#line 258 "src/parser.y"
                                                                        {std::cout << std::endl;std::cout <<"Parser "<< "240" << " Addition" << std::endl; (yyval.top) = new Addition_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 1983 "src/parser.tab.cpp"
    break;

  case 71:
#line 259 "src/parser.y"
                                                                        {(yyval.top) = new Subtraction_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 1989 "src/parser.tab.cpp"
    break;

  case 72:
#line 265 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 1995 "src/parser.tab.cpp"
    break;

  case 73:
#line 266 "src/parser.y"
                                                                        {(yyval.top) = new Multiplication_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2001 "src/parser.tab.cpp"
    break;

  case 74:
#line 267 "src/parser.y"
                                                                        {(yyval.top) = new Division_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2007 "src/parser.tab.cpp"
    break;

  case 75:
#line 268 "src/parser.y"
                                                                        {(yyval.top) = new Mod_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2013 "src/parser.tab.cpp"
    break;

  case 76:
#line 273 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2019 "src/parser.tab.cpp"
    break;

  case 77:
#line 278 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2025 "src/parser.tab.cpp"
    break;

  case 78:
#line 279 "src/parser.y"
                                                                        {(yyval.top) = new Left_Shift_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2031 "src/parser.tab.cpp"
    break;

  case 79:
#line 280 "src/parser.y"
                                                                        {(yyval.top) = new Right_Shift_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2037 "src/parser.tab.cpp"
    break;

  case 80:
#line 284 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2043 "src/parser.tab.cpp"
    break;

  case 81:
#line 285 "src/parser.y"
                                                                        {(yyval.top) = new Greater_Than_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2049 "src/parser.tab.cpp"
    break;

  case 82:
#line 286 "src/parser.y"
                                                                        {std::cout << std::endl;std::cout <<"Parser "<< "285" << " Smaller Than" << std::endl;(yyval.top) = new Less_Than_MIPS((yyvsp[-2].top),(yyvsp[0].top));std::cout <<"done" << std::endl;}
#line 2055 "src/parser.tab.cpp"
    break;

  case 83:
#line 287 "src/parser.y"
                                                                        {(yyval.top) = new Less_Than_Equal_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2061 "src/parser.tab.cpp"
    break;

  case 84:
#line 288 "src/parser.y"
                                                                        {(yyval.top) = new Greater_Than_Equal_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2067 "src/parser.tab.cpp"
    break;

  case 85:
#line 291 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2073 "src/parser.tab.cpp"
    break;

  case 86:
#line 292 "src/parser.y"
                                                                        {(yyval.top) = new Equal_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2079 "src/parser.tab.cpp"
    break;

  case 87:
#line 293 "src/parser.y"
                                                                        {(yyval.top) = new NotEqual_MIPS((yyvsp[-2].top),(yyvsp[0].top));}
#line 2085 "src/parser.tab.cpp"
    break;

  case 88:
#line 297 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2091 "src/parser.tab.cpp"
    break;

  case 89:
#line 298 "src/parser.y"
                                                                        {std::cerr << "Unsupported" << std::endl;}
#line 2097 "src/parser.tab.cpp"
    break;

  case 90:
#line 302 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2103 "src/parser.tab.cpp"
    break;

  case 91:
#line 303 "src/parser.y"
                                                                        {(yyval.top) = new LogicOr_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2109 "src/parser.tab.cpp"
    break;

  case 92:
#line 307 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2115 "src/parser.tab.cpp"
    break;

  case 93:
#line 308 "src/parser.y"
                                                                        {(yyval.top) = new LogicAnd_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2121 "src/parser.tab.cpp"
    break;

  case 94:
#line 311 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2127 "src/parser.tab.cpp"
    break;

  case 95:
#line 312 "src/parser.y"
                                                                        {(yyval.top) = new BitOr_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2133 "src/parser.tab.cpp"
    break;

  case 96:
#line 315 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2139 "src/parser.tab.cpp"
    break;

  case 97:
#line 316 "src/parser.y"
                                                                        {(yyval.top) = new BitXor_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2145 "src/parser.tab.cpp"
    break;

  case 98:
#line 320 "src/parser.y"
                                                                        {(yyval.top) = (yyvsp[0].top);}
#line 2151 "src/parser.tab.cpp"
    break;

  case 99:
#line 321 "src/parser.y"
                                                                        {(yyval.top) = new BitAnd_MIPS((yyvsp[-2].top), (yyvsp[0].top));}
#line 2157 "src/parser.tab.cpp"
    break;

  case 100:
#line 326 "src/parser.y"
                                                                        {(yyval.list) = build_new_list((yyvsp[0].top));}
#line 2163 "src/parser.tab.cpp"
    break;

  case 101:
#line 327 "src/parser.y"
                                                                        {(yyval.list) = add_to_list((yyvsp[-1].list), (yyvsp[0].top));}
#line 2169 "src/parser.tab.cpp"
    break;

  case 102:
#line 331 "src/parser.y"
                                                                        {std::cout << std::endl;std::cout <<"Parser "<< "314" << ";" << std::endl;}
#line 2175 "src/parser.tab.cpp"
    break;

  case 103:
#line 332 "src/parser.y"
                                                                        {std::cout << std::endl;std::cout <<"Parser "<< "314" << " Expression;" << std::endl; (yyval.top) = (yyvsp[-1].top);}
#line 2181 "src/parser.tab.cpp"
    break;

  case 104:
#line 336 "src/parser.y"
                                                                        {(yyval.top) = new Selection_statement_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 2187 "src/parser.tab.cpp"
    break;

  case 105:
#line 337 "src/parser.y"
                                                                        {(yyval.top) = new Selection_statement_Mips((yyvsp[-4].top), (yyvsp[-2].top), (yyvsp[0].top));}
#line 2193 "src/parser.tab.cpp"
    break;

  case 106:
#line 338 "src/parser.y"
                                                                        {std::cerr << "Unsupported" << std::endl;}
#line 2199 "src/parser.tab.cpp"
    break;

  case 107:
#line 342 "src/parser.y"
                                                                                    {std::cout << std::endl;std::cout <<"Parser "<< "324" << " While" << std::endl; (yyval.top) = new While_Mips((yyvsp[-2].top),(yyvsp[0].top));}
#line 2205 "src/parser.tab.cpp"
    break;

  case 108:
#line 344 "src/parser.y"
                                                                                    {std::cout << std::endl;std::cout <<"Parser "<< "343" << " FOR(Expression_statement Expression_statement)" << std::endl;(yyval.top) = new For_Mips((yyvsp[-3].top),(yyvsp[-2].top),(yyvsp[0].top));}
#line 2211 "src/parser.tab.cpp"
    break;

  case 109:
#line 345 "src/parser.y"
                                                                                    {std::cout << std::endl;std::cout <<"Parser "<< "344" << " FOR(Expression_statement Expression_statement Expression)" << std::endl;(yyval.top) = new For_Mips((yyvsp[-4].top),(yyvsp[-3].top),(yyvsp[-2].top),(yyvsp[0].top));}
#line 2217 "src/parser.tab.cpp"
    break;

  case 110:
#line 349 "src/parser.y"
                                                                         {std::cout <<"Parser "<< "RETURN;" << std::endl; (yyval.top) = new Return_Mips();}
#line 2223 "src/parser.tab.cpp"
    break;

  case 111:
#line 352 "src/parser.y"
                                                                         {std::cout<<std::endl;std::cout <<"Parser "<< "331"<<" RETURN EXPRESSION;" << std::endl; (yyval.top) = new Return_Mips((yyvsp[-1].top));}
#line 2229 "src/parser.tab.cpp"
    break;


#line 2233 "src/parser.tab.cpp"

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
#line 361 "src/parser.y"


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
