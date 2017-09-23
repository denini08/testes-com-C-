%{
#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about: http://aquamentus.com/flex_bison.html
//https://stackoverflow.com/questions/1014619/how-to-solve-bison-warning-has-no-declared-type?rq=1
// pag 60 do livro
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

	int mostrar();

%}

%token PARENTESE_A
%token PARENTESE_F
%token FLOAT
%token INT
%token KW_MAIS
%token KW_MENOS
%token KW_VEZES
%token KW_DIVISAO

%type <inteiro> INT 
%type <decimal> FLOAT numero exp
%union {
	int inteiro;
	float decimal;
}
%left KW_MAIS KW_MENOS
%left KW_VEZES KW_DIVISAO
 
%%


exp :exp KW_MAIS exp { $$= $1 + $3;cout << $1 << " + " << $3 << " = " << $1 + $3 << endl;}
		| exp KW_MENOS exp { $$= $1 - $3;cout << $1 << " - " << $3 << " = " << $1 - $3 << endl; }
		| exp KW_VEZES exp { $$= $1 * $3;cout << $1 << " * " << $3 << " = " << $1 * $3 << endl; }
		| exp KW_DIVISAO exp { $$= $1 / $3;cout << $1 << " / " << $3 << " = " << $1 / $3 << endl; }
		| PARENTESE_A exp PARENTESE_F { $$ = $2; }
		| numero {$$= $1; }
		;

numero:INT {$$= $1;}
		| FLOAT {$$ = $1;}
		;
%%

int main(int, char**) {
	yyin = fopen("entrada.txt", "r");
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	return 0;
	//system("pause");
	
}
int mostrar(){
	printf("aeeeeesdasdas");
	return 0;
}

void yyerror(const char *s) {
	cout << "Erro: " << s << endl;
	// might as well halt now:
	exit(-1);
}
