%{
#include<stdio.h>
%}

%%
"<"([^>]+)>{printf("%s ", yytext);} // Match HTML tags enclosed in <>
.     ; // Ignore any other character
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

