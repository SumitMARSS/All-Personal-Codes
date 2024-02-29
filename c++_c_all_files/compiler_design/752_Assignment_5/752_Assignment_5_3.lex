%{
#define YYSTYPE double
#include "752_Assignment_5_3.tab.h"
#include <stdlib.h>
#include <math.h>
%}
white [ \t]+
%%
{white} { }
"0" return ZERO;
"1" return ONES;
"\n" return END;
%%
