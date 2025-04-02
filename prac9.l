%option noyywrap
%{
    #include<stdio.h>
    #include "prac9.tab.h"
%}

%%
[i] {return I;}
[t] {return T;}
[a] {return A;}
[b] {return B;}
[e] {return E;}
[\n] {return NL;}
. {return yytext[0];}
%%

int yywrap() 
{
    return 1;
}
