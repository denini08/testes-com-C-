%{
#include <iostream>
#include "b.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
%}
%option noyywrap


%%
[ \t\n]         ;
0|[+-]?[0-9]+\.[0-9]+  { yylval.inteiro = atoi(yytext); return FLOAT; }
0|[+-]?[1-9][0-9]*  {yylval.decimal = atof(yytext); return INT ; }
"+"					{return KW_MAIS; }
"-"					{return KW_MENOS; }
"*"					{return Kw_VEZES; }
"/"					{return KW_DIVISAO; }
.					{printf("token nao indentificado: %s", yytext);  }
%%
