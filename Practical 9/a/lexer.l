%{
#include <stdio.h>
int word = 0;
int line = 0;
int space = 0;
int tab = 0;
%}

%%
[A-Za-z0-9]+ { word++; }
\n { line++; }
[ ] { space++; }
\t { tab++; }
%%

int main() {
    extern FILE *yyin;
    yyin = fopen("basic.txt", "r");
    if (!yyin) {
        printf("Error opening file.\n");
        return 1;
    }
    yylex();
    printf("Words: %d\nLines: %d\nSpaces: %d\nTabs: %d\n", word, line, space, tab);
    fclose(yyin);
    return 0;
}

int yywrap() {
    return 1;
}
