%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token NUMBER
%token PLUS MINUS TIMES DIVIDE 
%token LEFT RIGHT
%token END

%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%left POWER

%start Input
%%

Input:
     | Input Line   
;
Line:
     END
     | Expression   END { printf("Result: %f\n",$$);}
 ;
 Expression:
     NUMBER { $$=$1; }
|Expression Expression PLUS {$$=$1+$2;}
|Expression Expression MINUS { $$=$1-$2; }
|Expression Expression TIMES { $$=$1*$2; }
|Expression Expression DIVIDE { $$=$1/$2; }
;
%%

int yyerror(char *s) {
  printf("%s\n", s);
}

int main() {
  if (yyparse())
     fprintf(stderr, "Successful parsing.\n");
  else
     fprintf(stderr, "error found.\n");
}
