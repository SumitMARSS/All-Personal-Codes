%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include <ctype.h>


    int create_Var          = 1;
    int If_Lable_Counter    = 1;
    int For_Label_Counter   = 1;
    int While_Lable_Counter = 1;
    int output=1;

    
    char Myvar[50];
    char Mynum[50];
    char sign[50];


    extern int yylex();
    extern FILE *yyin;
    extern FILE *yyout;
    /* prints grammar violation message */
    void yyerror(char *msg);

%}

%start Program

%union{
    int labelCounter;
    char relo[500];
    char id[500];
    char num[500];
    char arithP[500];
    char arithD[500];
    char nonTerminal[500];
}

%token <num> NUM
%token <id> ID
%token <labelCounter> IF ELSE WHILE FOR IN RANGE
%token <relo>  RELOP
%token <arithP> ARITHP
%token <arithD> ARITHD
%token lparen rparen

%type <nonTerminal>  block stmts stmt  optexpr IDs expr rel add term power factor 

/* Precedence Operator */

%right '='
%right "**"
%left  RELOP
%left  '-' '+'
%left  '*' '/'
%left  UMINUS 

%%

Program : block                       { ; }
        ;

block   : '{' stmts '}'               { printf("\n"); }
        | stmts                       { printf("\n"); }
        ;

stmts   : stmts  stmt                 { ; }
        | %empty                      
        ;


stmt    : optexpr ';'	              { printf(";\n"); }
        | expr    ';'	              { printf(""); }

        |IF                           { printf("%d.)IF_BEGIN_%d:\n", output,$1=If_Lable_Counter++);output++; printf("\n"); }
        '('                           { printf("%d.)IF_CONDITION_%d:\n", output, $1); output++;printf("\n"); }
        expr ')'                      { printf("%d.)ifTrue (%s) goto ELSE_CODE_%d;\n", output, $5, $1);output++; printf("%d.)goto IF_CODE_%d;\n",output, $1);output++; printf("\n"); }
                                      { printf("%d.)IF_CODE_%d:\n", output, $1);output++; }
        stmt                          { printf("%d.)goto ELSE_END_%d;\n", output, $1); output++;}

        |ELSE                         { printf("%d.)ELSE_CODE_%d:\n", output, $1);output++; } 
        stmt                          { printf("%d.)ELSE_END_%d:\n", output, $1); output++;printf("\n"); } 

        |FOR                          { printf("%d.)FOR_BEGIN_%d:\n", output, $1=For_Label_Counter++);output++; }
          optexpr                     { ; }
          IN                           
          RANGE

          '('                               
          optexpr                         
          ')'                         { printf("%d.)FOR_CONDITION_%d:\n", output, $1); output++;sprintf($3, "t%d", create_Var++); printf("%d.)%s = %s < %s;\n",output, $3, Myvar, Mynum); output++; }
                                      { printf("%d.)ifFalse (%s) goto FOR_END_%d;\n", output, $3, $1);  output++;printf("%d.)goto FOR_CODE_%d:\n",output, $1);output++; 
                                        printf("%d.)FOR_STEP_%d:\n", output, $1); output++;  sprintf($3, "t%d", create_Var++);   printf("%d.)%s = %s + 1;\n",output, $3, Myvar);output++; 
                                        printf("%d.)%s = %s;\n", output, Myvar,$3);output++; printf("%d.)goto FOR_CONDITION_%d:\n",output, $1);output++;   printf("%d.)FOR_CODE_%d:\n",output, $1); output++; }                                                            
          stmt                         
                                      { printf("%d.)goto FOR_STEP_%d;\n", output, $1);output++; printf("%d.)FOR_END_%d:\n",output, $1); output++;}

        |WHILE                        { printf("%d.)WHILE_BEGIN_%d:\n", output, $1=While_Lable_Counter++);output++; printf("\n"); } 
        '('                           { printf("%d.)WHILE_CONDITION_%d:\n", output, $1);output++; printf("\n"); }
        expr ')'                      { printf("%d.)ifFalse (%s) goto WHILE_END_%d;\n", output, $5, $1); output++;printf("%d.)goto WHILE_CODE_%d;\n",output, $1);output++; printf("}\n"); printf("%d.)WHILE_CODE_%d:\n",output, $1); output++;} 
        stmt                          { printf("%d.)goto WHILE_CONDITION_%d;\n", output, $1); output++;printf("\n"); printf("%d.)WHILE_END_%d:\n",output, $1);output++; }
        |block                        
        ;

optexpr:    
        expr                         { strcpy($$, $1); }
        | ID                         { strcpy($$, $1); printf("%d.)%s = 0;\n",output, $1);output++; strcpy(Myvar, $1);}
        | NUM                        { strcpy($$, $1); strcpy(Mynum, $1);}
        |%empty                      { ; }
        ;

IDs     : IDs ',' ID	             { sprintf($$, "%d.)%s, %s",output, $1, $3); output++;}
	| IDs ',' ID '=' expr	         { sprintf($$, "%d.)%s, %s = %s",output, $1, $3, $5);output++; }
	| ID			                 { sprintf($$, "%d.)%s",output,$1);output++;}
	| ID '=' expr	                 { sprintf($$, "%d.)%s = %s",output, $1, $3);output++; }
	;

expr    : ID '=' expr               { strcpy($$, $3); printf("%s = %s;\n", $1, $3); }
        | ID lparen ID rparen '=' expr { strcpy($$, $6); printf("%s[%s] = %s;\n", $1, $3,$6); }
        | ID lparen expr rparen '=' expr { strcpy($$, $6); printf("%s[%s] = %s;\n", $1, $3,$6); }
        | rel                       { strcpy($$, $1); }
        ;

rel     : rel RELOP add             { sprintf($$, "t%d", create_Var++) ;printf("%d.)%s = %s %s %s;\n",output, $$, $1, $2, $3); output++;}
        | add                       { strcpy($$, $1);}
        ;

add     : add '+' term              { sprintf($$, "t%d", create_Var++); printf("%d.)%s = %s + %s;\n",output, $$, $1, $3);output++; }
        | add '-' term              { sprintf($$, "t%d", create_Var++); printf("%d.)%s = %s - %s;\n",output, $$, $1, $3);output++; }
        | term                      { strcpy($$, $1);}
        ;

term    : term '*' power           { sprintf($$, "t%d", create_Var++) ;printf("%d.)%s = %s * %s;\n",output, $$, $1, $3);output++; }
        | term '/' power           { sprintf($$, "t%d", create_Var++) ;printf("%d.)%s = %s / %s;\n",output, $$, $1, $3);output++; }
        | term ARITHD power        { sprintf($$, "t%d", create_Var++) ;printf("%d.)%s = %s // %s;\n",output, $$, $1, $3);output++; }
        | term '%' power           { sprintf($$, "t%d", create_Var++) ;printf("%d.)%s = %s % %s;\n",output, $$, $1, $3);output++; }
        | power                    { strcpy($$, $1); }
        ;

power   : factor ARITHP power      { sprintf($$, "%d.)t%d",output, create_Var++); output++;printf("%d.)%s = %s ** %s;\n",output, $$, $1, $3);output++; }
        | factor                   { strcpy($$, $1); }
        ;

factor  : '(' expr ')'             { strcpy($$, $2); }
        | '-' factor               { strcpy(sign,"-"); strcat(sign,$2); strcpy($$, sign); }
        | NUM                      { strcpy($$, $1);}
        | ID                       { strcpy($$, $1);}
        | ID lparen ID rparen      { strcpy(sign, $1);strcat(sign,"[");strcat(sign,$3);strcat(sign,"]");strcpy($$, sign); }
        | ID lparen NUM rparen      { strcpy(sign, $1);strcat(sign,"[");strcat(sign,$3);strcat(sign,"]");strcpy($$, sign); }
        ;
%%

void yyerror(char *msg) {
    fprintf(stderr,"%s\n",msg);
    exit(1);
}

int yywrap() {
    return 1;
}

int main() {
   yyparse();
}