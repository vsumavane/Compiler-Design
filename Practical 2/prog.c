#include <stdio.h>

int main() {
    char str[50];
    int vowels, digit, special, i, consonant;
    vowels = digit = special = consonant = 0;
    
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            vowels++;
        else if (str[i] >= '0' && str[i] <= '9')
            digit++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            consonant++;
        else if (str[i] >= 32 && str[i] <= 47 || str[i] >= 58 && str[i] <= 64 || str[i] >= 91 && str[i] <= 96)
            special++;
    }
    
    printf("Vowels: %d\n", vowels);
    printf("Digits: %d\n", digit);
    printf("Special characters: %d\n", special);
    
    return 0;
}
