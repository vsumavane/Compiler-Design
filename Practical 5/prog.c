#include<stdio.h>

char c[10];
int input = 0; // Declare and initialize input as an integer

void E();
void EPRIME();

int main() {
    printf("Enter a String: ");
    scanf("%s", c);
    E();
    if (c[input] == '$') // Use input as an index to access characters in the array
        printf("Valid String\n");
    else
        printf("Invalid String\n");
    return 0;
}

void E() {
    if (c[input] == 'i') {
        input++;
        EPRIME();
    }
}

void EPRIME() {
    if (c[input] == '+') {
        input++;
        if (c[input] == 'i') {
            input++;
            EPRIME();
        }
    }
    // 'else' is not needed here, as the function returns in case of '+' or any other character
}
