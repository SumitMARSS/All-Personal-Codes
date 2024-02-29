%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void yyerror(char *s);
int yylex(void);
#define MAX_LIMIT 256
char variables[MAX_LIMIT][MAX_LIMIT];
float values[MAX_LIMIT];
int i = -1;
%}

%union{
    char var[256];
    float val;
}

%token<var> VARIABLE
%token<val> NUMBER 
%token EQUAL LPAREN RPAREN
%token ADD SUB MUL DIV
%token END

%type<val> Expr

%left ADD SUB
%left MUL DIV

%start S

%%
S: S Nxt
|Nxt: VARIABLE EQUAL Expr END { int flag = 0; for(int j = 0; j < i+1; j++){ if(!strcmp(variables[j], $1)){ values[j] = $3; flag = 1; break; } } if(!flag){ i++; strcpy(variables[i], $1); values[i] = $3; } printf("OUTPUT => %s = %.2f\n",$1,$3); }
;

Expr: VARIABLE { int flag = 0; for(int j = 0;j < i+1; j++){ if(!strcmp(variables[j], $1)){ $$ = values[j]; flag = 1; break; } } if(!flag){ yyerror("variable not initialised\n"); return 0; } }
| NUMBER { $$ = $1; }
| Expr ADD Expr { $$ = $1 + $3; }
| Expr SUB Expr { $$ = $1 - $3; }
| Expr MUL Expr { $$ = $1 * $3; }
| Expr DIV Expr { $$ = $1 / $3; }
| LPAREN Expr RPAREN { $$ = ( $2 ); }
;
%%

int main(){
    yyparse();
    return 0;
}

void yyerror(char *s){
    printf("\n -> Error : %s\n",s);
}
