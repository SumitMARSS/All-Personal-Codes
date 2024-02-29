%{
#include "752_Assignment_5_2.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}

digit [0-9]
integer {digit}+
real ({digit}+[.]{digit}*)|({digit}*[.]{digit}+)
exp ({integer}|{real})[eE]{integer}
exp2 ({integer}|{real})[eE][+-]{integer}
exp3 [+-]({integer}|{real})[eE][+-]{integer}
integer2 [+-]({integer}|{real})

%%
({integer}|{integer2}|{real}|{exp}|{exp2}|{exp3}) { yylval.val = atof(yytext); return NUMBER; }
"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"=" { return EQUAL; }
"(" { return LPAREN; }
")" { return RPAREN; }
"\n" { return END; }
[ \t]+ { /*ignore*/ }
[a-zA-Z_][^-+*/=.() \t\n]* { strcpy(yylval.var,yytext); return VARIABLE; }
%%
