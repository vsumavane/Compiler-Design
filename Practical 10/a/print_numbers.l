
%{
#include<stdio.h>
#include<stdlib.h> // Include this header for atoi function
%}

%%
[0-9]+ { printf("%s\n", yytext); } // Match one or more digits
.      ; // Ignore any other character
%%

int yywrap() {
    return 1;
}

int main() {
    extern FILE *yyin;
    yyin = fopen("basic.txt", "r");
    yylex();
    fclose(yyin); // Close the file
    return 0;
}
