%{
#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about: http://aquamentus.com/flex_bison.html
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);
%}

%token FLOAT
%token INT
%token KW_MAIS
%token KW_MENOS
%token Kw_VEZES
%token KW_DIVISAO

%union {
	int inteiro;
	float decimal;
}

%%


inicio : Numero Operacao Numero ;

Numero : FLOAT {cout << " "<< $1 << endl;} 
	   | INT ;

Operacao : KW_MAIS | KW_MENOS | KW_DIVISAO | Kw_VEZES;
	



%%

int main(int, char**) {
	yyin = fopen("entrada.txt", "r");
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}
