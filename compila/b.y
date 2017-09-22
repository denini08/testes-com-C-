%{
#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about: http://aquamentus.com/flex_bison.html
//https://stackoverflow.com/questions/1014619/how-to-solve-bison-warning-has-no-declared-type?rq=1
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);
int mostrar();

%}

%token FLOAT
%token INT
%token KW_MAIS
%token KW_MENOS
%token KW_VEZES
%token KW_DIVISAO

%type <inteiro> INT 
%type <decimal> FLOAT numero

%union {
	int inteiro;
	float decimal;
}


%%


inicio : numero KW_MAIS numero { cout << $1 << " + " << $3 << " = " << $1 + $3 << endl;}
		| numero KW_MENOS numero { cout << $1 << " - " << $3 << " = " << $1 - $3 << endl; }
		| numero KW_VEZES numero { cout << $1 << " * " << $3 << " = " << $1 * $3 << endl; }
		| numero KW_DIVISAO numero { cout << $1 << " / " << $3 << " = " << $1 / $3 << endl; }
		;

numero: INT {$$= $1;}
		| FLOAT {$$ = $1;}
		;
%%

int main(int, char**) {
	yyin = fopen("entrada.txt", "r");
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}
int mostrar(){
	printf("aeeeeesdasdas");
	return 0;
}

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}
