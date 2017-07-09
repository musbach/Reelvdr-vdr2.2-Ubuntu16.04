/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

#ifndef YY_DVDVM_DVDVMY_H_INCLUDED
# define YY_DVDVM_DVDVMY_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int dvdvmdebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM_TOK = 258,
     G_TOK = 259,
     S_TOK = 260,
     ID_TOK = 261,
     ANGLE_TOK = 262,
     AUDIO_TOK = 263,
     BREAK_TOK = 264,
     BUTTON_TOK = 265,
     CALL_TOK = 266,
     CELL_TOK = 267,
     CHAPTER_TOK = 268,
     CLOSEBRACE_TOK = 269,
     CLOSEPAREN_TOK = 270,
     COUNTER_TOK = 271,
     ELSE_TOK = 272,
     ENTRY_TOK = 273,
     EXIT_TOK = 274,
     FPC_TOK = 275,
     GOTO_TOK = 276,
     IF_TOK = 277,
     JUMP_TOK = 278,
     MENU_TOK = 279,
     NEXT_TOK = 280,
     OPENBRACE_TOK = 281,
     OPENPAREN_TOK = 282,
     PREV_TOK = 283,
     PROGRAM_TOK = 284,
     PTT_TOK = 285,
     REGION_TOK = 286,
     RESUME_TOK = 287,
     RND_TOK = 288,
     ROOT_TOK = 289,
     SET_TOK = 290,
     SUBTITLE_TOK = 291,
     TAIL_TOK = 292,
     TITLE_TOK = 293,
     TITLESET_TOK = 294,
     TOP_TOK = 295,
     VMGM_TOK = 296,
     BOR_TOK = 297,
     LOR_TOK = 298,
     XOR_TOK = 299,
     _OR_TOK = 300,
     BAND_TOK = 301,
     LAND_TOK = 302,
     _AND_TOK = 303,
     NOT_TOK = 304,
     NE_TOK = 305,
     EQ_TOK = 306,
     LT_TOK = 307,
     LE_TOK = 308,
     GT_TOK = 309,
     GE_TOK = 310,
     SUB_TOK = 311,
     ADD_TOK = 312,
     MOD_TOK = 313,
     DIV_TOK = 314,
     MUL_TOK = 315,
     ADDSET_TOK = 316,
     SUBSET_TOK = 317,
     MULSET_TOK = 318,
     DIVSET_TOK = 319,
     MODSET_TOK = 320,
     ANDSET_TOK = 321,
     ORSET_TOK = 322,
     XORSET_TOK = 323,
     SEMICOLON_TOK = 324,
     COLON_TOK = 325,
     ERROR_TOK = 326
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 88 "dvdvmy.y"

    unsigned int int_val;
    char *str_val;
    struct vm_statement *statement;


/* Line 2053 of yacc.c  */
#line 135 "dvdvmy.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE dvdvmlval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int dvdvmparse (void *YYPARSE_PARAM);
#else
int dvdvmparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int dvdvmparse (void);
#else
int dvdvmparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_DVDVM_DVDVMY_H_INCLUDED  */
