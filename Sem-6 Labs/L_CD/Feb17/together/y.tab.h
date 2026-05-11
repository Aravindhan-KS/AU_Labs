#define INT 257
#define FLOAT 258
#define FOR 259
#define NUM 260
#define FNUM 261
#define ID 262
#define LT 263
#define GT 264
#define LE 265
#define GE 266
#define EQ 267
#define NE 268
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {

    int ival;

    float fval;

    char *str;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
