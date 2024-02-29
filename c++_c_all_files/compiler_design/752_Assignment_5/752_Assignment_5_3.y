%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token ZERO ONES 
%token END

%start Input
%%

Input:
     | Input Line   
;
Line:
     END
     | Expression   END {printf("Result1 : %f\n",$1);}
 ;
 Expression:
     ZERO {$$=0;}
 |ONES {$$=1;}  
|Expression ZERO {$$=$1*2;}
|Expression ONES { $$=$1*2+1;}
;
%%

int main(){
    yyparse();
    return 0;
}
void yyerror(char *s){
    printf("\n -> Error : %s\n",s);
}
