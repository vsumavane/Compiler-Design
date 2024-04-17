%{
#include <stdio.h>
int vowel = 0;
int consonant = 0;
%}

%%
[aAeEiIoOuU] { vowel++; }
[a-zA-Z] { consonant++; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the string: ");
    yylex();
    printf("Number of vowels: %d\n", vowel);
    printf("Number of consonants: %d\n", consonant);
    return 0;
}
