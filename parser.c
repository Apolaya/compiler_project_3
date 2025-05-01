/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 11 "parser.y"


#include <string>
#include <cmath> 
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "values.h"
#include "listing.h"
#include "symbols.h"
#include "types.h"


int yylex();
void yyerror(const char* message);
double extract_element(CharPtr list_name, double subscript);

Symbols<double> scalars;
Symbols<vector<double>*> lists;
//projec4 symbol types 
Types find(Symbols<Types>& table, CharPtr identifier, string tableName);


Symbols<Types> symbols;
Symbols<Types> listTypes;


double result;

double* paramValues;
int paramIndex = -1; 




#line 110 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ELSIF = 3,                      /* ELSIF  */
  YYSYMBOL_ENDFOLD = 4,                    /* ENDFOLD  */
  YYSYMBOL_FOLD = 5,                       /* FOLD  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_THEN = 7,                       /* THEN  */
  YYSYMBOL_ENDIF = 8,                      /* ENDIF  */
  YYSYMBOL_BEGIN_ = 9,                     /* BEGIN_  */
  YYSYMBOL_CASE = 10,                      /* CASE  */
  YYSYMBOL_CHARACTER = 11,                 /* CHARACTER  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_END = 13,                       /* END  */
  YYSYMBOL_ENDSWITCH = 14,                 /* ENDSWITCH  */
  YYSYMBOL_FUNCTION = 15,                  /* FUNCTION  */
  YYSYMBOL_INTEGER = 16,                   /* INTEGER  */
  YYSYMBOL_IS = 17,                        /* IS  */
  YYSYMBOL_LIST = 18,                      /* LIST  */
  YYSYMBOL_OF = 19,                        /* OF  */
  YYSYMBOL_OTHERS = 20,                    /* OTHERS  */
  YYSYMBOL_RETURNS = 21,                   /* RETURNS  */
  YYSYMBOL_SWITCH = 22,                    /* SWITCH  */
  YYSYMBOL_WHEN = 23,                      /* WHEN  */
  YYSYMBOL_IDENTIFIER = 24,                /* IDENTIFIER  */
  YYSYMBOL_ADDOP = 25,                     /* ADDOP  */
  YYSYMBOL_MULOP = 26,                     /* MULOP  */
  YYSYMBOL_ANDOP = 27,                     /* ANDOP  */
  YYSYMBOL_RELOP = 28,                     /* RELOP  */
  YYSYMBOL_ARROW = 29,                     /* ARROW  */
  YYSYMBOL_REMOP = 30,                     /* REMOP  */
  YYSYMBOL_EXPOP = 31,                     /* EXPOP  */
  YYSYMBOL_NEGOP = 32,                     /* NEGOP  */
  YYSYMBOL_OROP = 33,                      /* OROP  */
  YYSYMBOL_NOTOP = 34,                     /* NOTOP  */
  YYSYMBOL_INT_LITERAL = 35,               /* INT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 36,              /* CHAR_LITERAL  */
  YYSYMBOL_HEX_LITERAL = 37,               /* HEX_LITERAL  */
  YYSYMBOL_REAL = 38,                      /* REAL  */
  YYSYMBOL_REAL_LITERAL = 39,              /* REAL_LITERAL  */
  YYSYMBOL_LEFT = 40,                      /* LEFT  */
  YYSYMBOL_RIGHT = 41,                     /* RIGHT  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_function = 48,                  /* function  */
  YYSYMBOL_function_header = 49,           /* function_header  */
  YYSYMBOL_parameters = 50,                /* parameters  */
  YYSYMBOL_parameter_list = 51,            /* parameter_list  */
  YYSYMBOL_parameter = 52,                 /* parameter  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_optional_variable = 54,         /* optional_variable  */
  YYSYMBOL_variable = 55,                  /* variable  */
  YYSYMBOL_list = 56,                      /* list  */
  YYSYMBOL_expressions = 57,               /* expressions  */
  YYSYMBOL_expressions_raw = 58,           /* expressions_raw  */
  YYSYMBOL_body = 59,                      /* body  */
  YYSYMBOL_statements = 60,                /* statements  */
  YYSYMBOL_statement_ = 61,                /* statement_  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_switch_statement = 63,          /* switch_statement  */
  YYSYMBOL_when_statement = 64,            /* when_statement  */
  YYSYMBOL_fold_statement = 65,            /* fold_statement  */
  YYSYMBOL_direction = 66,                 /* direction  */
  YYSYMBOL_operator = 67,                  /* operator  */
  YYSYMBOL_operand = 68,                   /* operand  */
  YYSYMBOL_if_statement = 69,              /* if_statement  */
  YYSYMBOL_elsif_clauses = 70,             /* elsif_clauses  */
  YYSYMBOL_elsif_clause = 71,              /* elsif_clause  */
  YYSYMBOL_optional_else = 72,             /* optional_else  */
  YYSYMBOL_cases = 73,                     /* cases  */
  YYSYMBOL_case = 74,                      /* case  */
  YYSYMBOL_condition = 75,                 /* condition  */
  YYSYMBOL_logical_and = 76,               /* logical_and  */
  YYSYMBOL_logical_not = 77,               /* logical_not  */
  YYSYMBOL_relation = 78,                  /* relation  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_term = 80,                      /* term  */
  YYSYMBOL_factor = 81,                    /* factor  */
  YYSYMBOL_primary = 82                    /* primary  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   426

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    42,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   113,   114,   117,   118,   121,   122,   123,
     126,   136,   137,   138,   142,   143,   144,   147,   152,   159,
     165,   168,   172,   178,   181,   182,   183,   186,   187,   190,
     191,   192,   193,   194,   197,   198,   204,   212,   218,   219,
     222,   222,   222,   225,   236,   242,   243,   246,   249,   250,
     254,   257,   260,   263,   264,   268,   269,   270,   273,   274,
     277,   278,   281,   282,   285,   288,   291,   294,   297,   300,
     301,   304,   305,   306,   307,   308,   309,   310,   314
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ELSIF", "ENDFOLD",
  "FOLD", "IF", "THEN", "ENDIF", "BEGIN_", "CASE", "CHARACTER", "ELSE",
  "END", "ENDSWITCH", "FUNCTION", "INTEGER", "IS", "LIST", "OF", "OTHERS",
  "RETURNS", "SWITCH", "WHEN", "IDENTIFIER", "ADDOP", "MULOP", "ANDOP",
  "RELOP", "ARROW", "REMOP", "EXPOP", "NEGOP", "OROP", "NOTOP",
  "INT_LITERAL", "CHAR_LITERAL", "HEX_LITERAL", "REAL", "REAL_LITERAL",
  "LEFT", "RIGHT", "';'", "','", "':'", "'('", "')'", "$accept",
  "function", "function_header", "parameters", "parameter_list",
  "parameter", "type", "optional_variable", "variable", "list",
  "expressions", "expressions_raw", "body", "statements", "statement_",
  "statement", "switch_statement", "when_statement", "fold_statement",
  "direction", "operator", "operand", "if_statement", "elsif_clauses",
  "elsif_clause", "optional_else", "cases", "case", "condition",
  "logical_and", "logical_not", "relation", "expression", "term", "factor",
  "primary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,   -18,    26,   -88,    69,   -88,    45,     8,    24,    57,
       6,   -88,   -88,   224,    38,   -88,   -88,   -88,    18,    18,
     -88,   118,    60,    89,   353,   367,   353,    49,   367,   -88,
     -88,   -88,   -88,   367,   249,   -88,   101,   -88,   -88,   -88,
     -88,   119,    51,   -88,   117,     7,   -88,   -88,   -88,   -88,
     104,   -88,   -88,   -88,   -88,    84,   353,   353,    65,   126,
     -88,   -88,   103,    54,   -13,   367,   -88,   -10,   114,   -88,
     -88,   367,   367,   367,   367,   142,   145,   -88,   -88,   -88,
     -88,   139,   -88,    78,    58,    16,   381,   353,   353,   367,
     -88,   367,    -9,   -88,   -88,    51,   -88,   -88,   -88,    18,
      52,   -88,   161,   -88,   115,   -88,   126,   -88,   119,   112,
      70,   -88,   149,   133,   -88,   105,     9,   -88,   147,   -88,
     367,   134,   -88,   353,   269,   -88,   170,   152,   153,    52,
     119,   367,   146,    73,   294,   -88,   314,   135,   148,   138,
     150,   119,   -88,    16,   339,   154,   163,   175,   -88,   367,
     204,   -88,   -88,   -88,   119
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    16,     0,     1,     0,     0,     0,     0,
       0,     7,    15,     0,     0,    14,     2,     4,     0,     0,
       9,     0,     0,     0,     0,     0,     0,    78,     0,    73,
      74,    76,    75,     0,     0,    25,     0,    33,    32,    31,
      30,    29,    65,    68,    69,     0,    12,    11,    13,    10,
       0,     8,    28,    38,    39,     0,     0,     0,     0,    57,
      59,    61,     0,     0,     0,     0,    71,     0,     0,    24,
      27,     0,     0,     0,     0,     0,     0,     3,    40,    41,
      42,     0,    60,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,    72,    23,    64,    66,    67,    70,     0,
       0,    43,     0,    62,     0,    55,    56,    58,    63,     0,
       0,    77,     0,     0,    37,    49,     0,    34,     0,    50,
       0,     0,    17,     0,     0,    45,     0,     0,     0,     0,
      36,     0,     0,     0,     0,    44,     0,     0,     0,     0,
      20,    22,    18,     0,     0,     0,     0,     0,    19,     0,
       0,    53,    28,    35,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   -88,   171,   -14,   -88,   -88,   -88,
     -88,   -88,   -88,   -77,   -31,   -87,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -22,   107,
     -45,   111,   -24,   120,    61,   173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     9,    10,    11,    49,     6,    15,   132,
     139,   140,    16,    34,    35,    36,    37,    38,    39,    55,
      81,   102,    40,   115,   125,   126,   109,   119,    58,    59,
      60,    61,    41,    42,    43,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    63,    62,    69,    64,    50,     4,    20,   104,    67,
     127,    82,     1,   113,    86,    71,    71,    22,    46,   -26,
      87,    23,    24,    47,   -26,    75,     5,    -6,   -26,    46,
      91,    76,    62,    84,    47,    83,    93,   111,    25,    26,
      27,    92,   138,   107,   128,    48,    12,   134,    28,    21,
      17,    29,    30,    31,    13,    32,    48,    23,    24,   144,
     146,    33,    62,    62,    62,   108,   150,   110,    18,    14,
       7,    90,    85,    69,    25,    26,    27,    72,    19,    71,
     143,    73,    45,    71,    28,   112,    89,    29,    30,    31,
      -5,    32,    86,     8,    65,    71,   130,    33,    87,    62,
      86,   133,    52,    69,    93,    86,    87,   141,   123,    78,
      79,    87,    80,    69,   120,    69,    22,   124,   -46,    69,
      23,    24,   116,   -46,   103,   154,   117,   -46,    71,    53,
      54,    89,   118,    96,    97,    98,   145,    25,    26,    27,
      23,    24,     8,    70,    71,   -26,    77,    28,    74,   -26,
      29,    30,    31,    88,    32,   -26,    94,    25,    26,    27,
      33,    99,   100,   101,    22,   114,   121,    28,    23,    24,
      29,    30,    31,   -52,    32,   122,   129,   -52,   135,   131,
      33,   136,   137,   -52,   148,    25,    26,    27,   142,   153,
     147,    95,    51,   149,   106,    28,   152,   105,    29,    30,
      31,    66,    32,     0,     0,    22,     0,   -47,    33,    23,
      24,     0,   -47,     0,     0,     0,   -47,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    25,    26,    27,    23,
      24,     0,     0,     0,     0,     0,    28,   -26,     0,    29,
      30,    31,     0,    32,     0,     0,    25,    26,    27,    33,
      22,     0,     0,     0,    23,    24,    28,     0,     0,    29,
      30,    31,    68,    32,     0,     0,     0,     0,     0,    33,
      22,    25,    26,    27,    23,    24,     0,   -26,     0,     0,
       0,    28,     0,     0,    29,    30,    31,     0,    32,     0,
       0,    25,    26,    27,    33,    22,     0,     0,     0,    23,
      24,    28,   -48,     0,    29,    30,    31,     0,    32,     0,
       0,     0,     0,     0,    33,    22,    25,    26,    27,    23,
      24,     0,     0,     0,     0,     0,    28,     0,     0,    29,
      30,    31,     0,    32,     0,     0,    25,    26,    27,    33,
      22,     0,     0,     0,    23,    24,    28,     0,     0,    29,
      30,    31,     0,    32,     0,     0,   -26,     0,     0,    33,
       0,    25,    26,    27,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,    29,    30,    31,    27,    32,     0,
       0,   151,     0,     0,    33,    28,     0,    56,    29,    30,
      31,    27,    32,     0,     0,     0,     0,     0,    57,    28,
       0,     0,    29,    30,    31,    27,    32,     0,     0,     0,
       0,     0,    33,    28,     0,     0,    29,    30,    31,     0,
      32,     0,     0,     0,     0,     0,    57
};

static const yytype_int16 yycheck[] =
{
      24,    25,    26,    34,    26,    19,    24,     1,    85,    33,
       1,    56,    15,   100,    27,    25,    25,     1,    11,     3,
      33,     5,     6,    16,     8,    18,     0,    21,    12,    11,
      43,    45,    56,    57,    16,    57,    46,    46,    22,    23,
      24,    65,   129,    88,    35,    38,     1,   124,    32,    43,
      42,    35,    36,    37,     9,    39,    38,     5,     6,   136,
     137,    45,    86,    87,    88,    89,   143,    91,    44,    24,
       1,    17,     7,   104,    22,    23,    24,    26,    21,    25,
       7,    30,    44,    25,    32,    99,    28,    35,    36,    37,
      21,    39,    27,    24,    45,    25,   120,    45,    33,   123,
      27,   123,    42,   134,    46,    27,    33,   131,     3,    25,
      26,    33,    28,   144,    44,   146,     1,    12,     3,   150,
       5,     6,    10,     8,    46,   149,    14,    12,    25,    40,
      41,    28,    20,    72,    73,    74,     1,    22,    23,    24,
       5,     6,    24,    42,    25,    10,    42,    32,    31,    14,
      35,    36,    37,    27,    39,    20,    42,    22,    23,    24,
      45,    19,    17,    24,     1,     4,    17,    32,     5,     6,
      35,    36,    37,    10,    39,    42,    29,    14,     8,    45,
      45,    29,    29,    20,    46,    22,    23,    24,    42,    14,
      42,    71,    21,    43,    87,    32,    42,    86,    35,    36,
      37,    28,    39,    -1,    -1,     1,    -1,     3,    45,     5,
       6,    -1,     8,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    22,    23,    24,     5,
       6,    -1,    -1,    -1,    -1,    -1,    32,    13,    -1,    35,
      36,    37,    -1,    39,    -1,    -1,    22,    23,    24,    45,
       1,    -1,    -1,    -1,     5,     6,    32,    -1,    -1,    35,
      36,    37,    13,    39,    -1,    -1,    -1,    -1,    -1,    45,
       1,    22,    23,    24,     5,     6,    -1,     8,    -1,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    -1,    39,    -1,
      -1,    22,    23,    24,    45,     1,    -1,    -1,    -1,     5,
       6,    32,     8,    -1,    35,    36,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,     1,    22,    23,    24,     5,
       6,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    -1,    39,    -1,    -1,    22,    23,    24,    45,
       1,    -1,    -1,    -1,     5,     6,    32,    -1,    -1,    35,
      36,    37,    -1,    39,    -1,    -1,    42,    -1,    -1,    45,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    24,    39,    -1,
      -1,    42,    -1,    -1,    45,    32,    -1,    34,    35,    36,
      37,    24,    39,    -1,    -1,    -1,    -1,    -1,    45,    32,
      -1,    -1,    35,    36,    37,    24,    39,    -1,    -1,    -1,
      -1,    -1,    45,    32,    -1,    -1,    35,    36,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    48,    49,    24,     0,    54,     1,    24,    50,
      51,    52,     1,     9,    24,    55,    59,    42,    44,    21,
       1,    43,     1,     5,     6,    22,    23,    24,    32,    35,
      36,    37,    39,    45,    60,    61,    62,    63,    64,    65,
      69,    79,    80,    81,    82,    44,    11,    16,    38,    53,
      53,    52,    42,    40,    41,    66,    34,    45,    75,    76,
      77,    78,    79,    79,    75,    45,    82,    79,    13,    61,
      42,    25,    26,    30,    31,    18,    53,    42,    25,    26,
      28,    67,    77,    75,    79,     7,    27,    33,    27,    28,
      17,    43,    79,    46,    42,    80,    81,    81,    81,    19,
      17,    24,    68,    46,    60,    78,    76,    77,    79,    73,
      79,    46,    53,    62,     4,    70,    10,    14,    20,    74,
      44,    17,    42,     3,    12,    71,    72,     1,    35,    29,
      79,    45,    56,    75,    60,     8,    29,    29,    62,    57,
      58,    79,    42,     7,    60,     1,    60,    42,    46,    43,
      60,    42,    42,    14,    79
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      52,    53,    53,    53,    54,    54,    54,    55,    55,    56,
      57,    58,    58,    59,    60,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    64,    65,    66,    66,
      67,    67,    67,    68,    69,    70,    70,    71,    72,    72,
      73,    73,    74,    74,    74,    75,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     6,     4,     0,     1,     1,     3,     2,
       3,     1,     1,     1,     2,     2,     0,     6,     8,     3,
       1,     3,     1,     4,     2,     1,     0,     2,     2,     1,
       1,     1,     1,     1,     5,     9,     6,     5,     1,     1,
       1,     1,     1,     1,     7,     2,     0,     4,     2,     0,
       2,     0,     4,     5,     5,     3,     3,     1,     3,     1,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     1,
       3,     2,     3,     1,     1,     1,     1,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* function: function_header optional_variable body  */
#line 110 "parser.y"
                                           { result = 0; }
#line 1608 "parser.tab.c"
    break;

  case 10: /* parameter: IDENTIFIER ':' type  */
#line 126 "parser.y"
                            {
		if (paramValues)
			scalars.insert((yyvsp[-2].iden), paramValues[paramIndex++]);
		else {
			appendError(GENERAL_SEMANTIC, "Missing parameter value for function.");
			scalars.insert((yyvsp[-2].iden), 0);
		}
	}
#line 1621 "parser.tab.c"
    break;

  case 11: /* type: INTEGER  */
#line 136 "parser.y"
                {(yyval.type) = INT_TYPE;}
#line 1627 "parser.tab.c"
    break;

  case 12: /* type: CHARACTER  */
#line 137 "parser.y"
                  {(yyval.type) = CHAR_TYPE;}
#line 1633 "parser.tab.c"
    break;

  case 13: /* type: REAL  */
#line 138 "parser.y"
             {(yyval.type) = REAL_TYPE;}
#line 1639 "parser.tab.c"
    break;

  case 17: /* variable: IDENTIFIER ':' type IS statement ';'  */
#line 148 "parser.y"
                        {
			checkAssignment((yyvsp[-3].type),(yyvsp[-1].type), "Variable Initialization");
			symbols.insert((yyvsp[-5].iden),(yyvsp[-3].type));
			}
#line 1648 "parser.tab.c"
    break;

  case 18: /* variable: IDENTIFIER ':' LIST OF type IS list ';'  */
#line 153 "parser.y"
                        {
			Types finalType = checkListDeclaration((yyvsp[-3].type), (yyvsp[-1].type));
			listTypes.insert((yyvsp[-7].iden), finalType);
			}
#line 1657 "parser.tab.c"
    break;

  case 19: /* list: '(' expressions ')'  */
#line 159 "parser.y"
                             {(yyval.type) = (yyvsp[-1].type);}
#line 1663 "parser.tab.c"
    break;

  case 20: /* expressions: expressions_raw  */
#line 165 "parser.y"
                        { (yyval.type) = checkList(*(yyvsp[0].typeList)); delete (yyvsp[0].typeList); }
#line 1669 "parser.tab.c"
    break;

  case 21: /* expressions_raw: expressions_raw ',' expression  */
#line 168 "parser.y"
                                       {
		(yyvsp[-2].typeList)->push_back((yyvsp[0].type));
		(yyval.typeList) = (yyvsp[-2].typeList);
	}
#line 1678 "parser.tab.c"
    break;

  case 22: /* expressions_raw: expression  */
#line 172 "parser.y"
                   {
		(yyval.typeList) = new vector<Types>();
		(yyval.typeList)->push_back((yyvsp[0].type));
	}
#line 1687 "parser.tab.c"
    break;

  case 23: /* body: BEGIN_ statements END ';'  */
#line 178 "parser.y"
                                  {(yyval.type)  = (yyvsp[-2].type);}
#line 1693 "parser.tab.c"
    break;

  case 24: /* statements: statements statement_  */
#line 181 "parser.y"
                              { (yyval.type) = (yyvsp[0].type) ;}
#line 1699 "parser.tab.c"
    break;

  case 25: /* statements: statement_  */
#line 182 "parser.y"
                   { (yyval.type) = (yyvsp[0].type);}
#line 1705 "parser.tab.c"
    break;

  case 26: /* statements: %empty  */
#line 183 "parser.y"
               {(yyval.type) = NONE;}
#line 1711 "parser.tab.c"
    break;

  case 28: /* statement_: error ';'  */
#line 187 "parser.y"
                   {(yyval.type) = MISMATCH;}
#line 1717 "parser.tab.c"
    break;

  case 34: /* switch_statement: SWITCH expression IS cases ENDSWITCH  */
#line 197 "parser.y"
                                         {(yyval.type) = checkSwitch((yyvsp[-3].type),(yyvsp[-1].type),NONE);}
#line 1723 "parser.tab.c"
    break;

  case 35: /* switch_statement: SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH  */
#line 198 "parser.y"
                                                                    {
								(yyval.type) = checkSwitch((yyvsp[-7].type), (yyvsp[-5].type), (yyvsp[-2].type));
								(yyval.type) = !isnan((yyvsp[-5].type)) ? (yyvsp[-5].type) : (yyvsp[-2].type);
								}
#line 1732 "parser.tab.c"
    break;

  case 36: /* when_statement: WHEN condition ',' expression ':' expression  */
#line 204 "parser.y"
                                                     {
							(yyval.type) = checkWhen((yyvsp[-2].type),(yyvsp[0].type));
							(yyval.type) = (yyvsp[-4].type) ? (yyvsp[-2].type) : (yyvsp[0].type);
							}
#line 1741 "parser.tab.c"
    break;

  case 37: /* fold_statement: FOLD direction operator operand ENDFOLD  */
#line 213 "parser.y"
    {
	(yyval.type) = INT_TYPE;
    }
#line 1749 "parser.tab.c"
    break;

  case 38: /* direction: LEFT  */
#line 218 "parser.y"
             { (yyval.value) = 0.0; }
#line 1755 "parser.tab.c"
    break;

  case 39: /* direction: RIGHT  */
#line 219 "parser.y"
              { (yyval.value) = 1.0; }
#line 1761 "parser.tab.c"
    break;

  case 43: /* operand: IDENTIFIER  */
#line 225 "parser.y"
               {
        vector<double>* lst;
        if (!lists.find((yyvsp[0].iden), lst)) {
            appendError(UNDECLARED_IDENTIFIER, (yyvsp[0].iden));
            (yyval.list) = new vector<double>();
        } else {
            (yyval.list) = lst;
        }
    }
#line 1775 "parser.tab.c"
    break;

  case 44: /* if_statement: IF condition THEN statements elsif_clauses optional_else ENDIF  */
#line 237 "parser.y"
    {
        (yyval.type) = checkIfStatement((yyvsp[-3].type),(yyvsp[-2].type),(yyvsp[-1].type));
    }
#line 1783 "parser.tab.c"
    break;

  case 45: /* elsif_clauses: elsif_clauses elsif_clause  */
#line 242 "parser.y"
                                   { (yyval.type) = (yyvsp[-1].type) != NONE ? (yyvsp[-1].type) : (yyvsp[0].type); }
#line 1789 "parser.tab.c"
    break;

  case 46: /* elsif_clauses: %empty  */
#line 243 "parser.y"
               { (yyval.type) = NONE; }
#line 1795 "parser.tab.c"
    break;

  case 47: /* elsif_clause: ELSIF condition THEN statements  */
#line 246 "parser.y"
                                        { (yyval.type) = (yyvsp[-2].type) != NONE ? (yyvsp[0].type) : NONE; }
#line 1801 "parser.tab.c"
    break;

  case 48: /* optional_else: ELSE statements  */
#line 249 "parser.y"
                        { (yyval.type) = (yyvsp[0].type); }
#line 1807 "parser.tab.c"
    break;

  case 49: /* optional_else: %empty  */
#line 250 "parser.y"
               { (yyval.type) = NONE; }
#line 1813 "parser.tab.c"
    break;

  case 50: /* cases: cases case  */
#line 254 "parser.y"
                   { 
			(yyval.type) = checkCases((yyvsp[-1].type),(yyvsp[0].type)) ;
			}
#line 1821 "parser.tab.c"
    break;

  case 51: /* cases: %empty  */
#line 257 "parser.y"
               {(yyval.type) = NONE;}
#line 1827 "parser.tab.c"
    break;

  case 52: /* case: CASE INT_LITERAL ARROW statements  */
#line 260 "parser.y"
                                          {
						(yyval.type) = (yyvsp[0].type) ;
						}
#line 1835 "parser.tab.c"
    break;

  case 55: /* condition: condition ANDOP relation  */
#line 268 "parser.y"
                                 {(yyval.type) = checkLogical((yyvsp[-2].type), (yyvsp[0].type));}
#line 1841 "parser.tab.c"
    break;

  case 56: /* condition: condition OROP logical_and  */
#line 269 "parser.y"
                                   {(yyval.type) = checkLogical((yyvsp[-2].type), (yyvsp[0].type)); }
#line 1847 "parser.tab.c"
    break;

  case 58: /* logical_and: logical_and ANDOP logical_not  */
#line 273 "parser.y"
                                      {(yyval.type) = checkLogical((yyvsp[-2].type),(yyvsp[0].type));}
#line 1853 "parser.tab.c"
    break;

  case 60: /* logical_not: NOTOP logical_not  */
#line 277 "parser.y"
                          {(yyval.type) = checkNot((yyvsp[0].type));}
#line 1859 "parser.tab.c"
    break;

  case 62: /* relation: '(' condition ')'  */
#line 281 "parser.y"
                          {(yyval.type) = (yyvsp[-1].type);}
#line 1865 "parser.tab.c"
    break;

  case 63: /* relation: expression RELOP expression  */
#line 282 "parser.y"
                                    {(yyval.type) = checkRelational((yyvsp[-2].type), (yyvsp[0].type));}
#line 1871 "parser.tab.c"
    break;

  case 64: /* expression: expression ADDOP term  */
#line 285 "parser.y"
                                {
				(yyval.type) = checkArithmetic((yyvsp[-2].type), (yyvsp[0].type) ) ;
				}
#line 1879 "parser.tab.c"
    break;

  case 66: /* term: term MULOP factor  */
#line 291 "parser.y"
                                {
				(yyval.type) = checkArithmetic((yyvsp[-2].type), (yyvsp[0].type));
				}
#line 1887 "parser.tab.c"
    break;

  case 67: /* term: term REMOP factor  */
#line 294 "parser.y"
                                {	
				(yyval.type) = checkRemainder((yyvsp[-2].type),(yyvsp[0].type));
				}
#line 1895 "parser.tab.c"
    break;

  case 70: /* factor: primary EXPOP factor  */
#line 301 "parser.y"
                         { (yyval.type) = checkExponentiation((yyvsp[-2].type), (yyvsp[0].type)) ;}
#line 1901 "parser.tab.c"
    break;

  case 71: /* primary: NEGOP primary  */
#line 304 "parser.y"
                            { (yyval.type) = checkNegation((yyvsp[0].type)); }
#line 1907 "parser.tab.c"
    break;

  case 72: /* primary: '(' expression ')'  */
#line 305 "parser.y"
                            { (yyval.type) = (yyvsp[-1].type); }
#line 1913 "parser.tab.c"
    break;

  case 73: /* primary: INT_LITERAL  */
#line 306 "parser.y"
                            { (yyval.type) = INT_TYPE; }
#line 1919 "parser.tab.c"
    break;

  case 74: /* primary: CHAR_LITERAL  */
#line 307 "parser.y"
                            { (yyval.type) = CHAR_TYPE; }
#line 1925 "parser.tab.c"
    break;

  case 75: /* primary: REAL_LITERAL  */
#line 308 "parser.y"
                            { (yyval.type) = REAL_TYPE; }
#line 1931 "parser.tab.c"
    break;

  case 76: /* primary: HEX_LITERAL  */
#line 309 "parser.y"
                            { (yyval.type) = INT_TYPE; }
#line 1937 "parser.tab.c"
    break;

  case 77: /* primary: IDENTIFIER '(' expression ')'  */
#line 310 "parser.y"
                                  {
      checkSubscript((yyvsp[-1].type));
      (yyval.type) = find(listTypes, (yyvsp[-3].iden), "List");
  }
#line 1946 "parser.tab.c"
    break;

  case 78: /* primary: IDENTIFIER  */
#line 314 "parser.y"
               {
		(yyval.type) = find(symbols, (yyvsp[0].iden), "Scalar");
    }
#line 1954 "parser.tab.c"
    break;


#line 1958 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 317 "parser.y"


void yyerror(const char* msg) {
	appendError(SYNTAX, msg);
}

double extract_element(CharPtr list_name, double subscript) {
	vector<double>* list; 
	if (lists.find(list_name, list))
		return (*list)[subscript];
	appendError(UNDECLARED_IDENTIFIER, list_name);
	return NONE;
}
int main(int argc, char *argv[]) {
	firstLine();

	if (argc > 1) {
		paramValues = new double[argc - 1];
		for (int i = 1; i < argc; i++)
			paramValues[i - 1] = atof(argv[i]);
		paramIndex = 0; 
	} else {
		paramValues = nullptr;
		paramIndex = 0;  
	}

	yyparse();

	if (getTotalErrors() == 0)
		printf("Result = %.2f\n", result);

	lastLine();
	delete[] paramValues;
	return 0;
}
