// Write a C program to reverse all the vowels present in a given string. Return the newly created string.

#include <stdio.h>
#include <string.h>

int is_vowel(char c) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int num_vowels = sizeof(vowels) / sizeof(char);
    for (int i = 0; i < num_vowels; i++) {
        if (c == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

void reverse_vowels(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        if (is_vowel(str[left]) && is_vowel(str[right])) {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;
            right--;
        } else if (is_vowel(str[left])) {
            right--;
        } else if (is_vowel(str[right])) {
            left++;
        } else {
            left++;
            right--;
        }
    }
}

int main() {
    char *str;
    str = (char*)malloc(sizeof(char));
    printf("Enter a string: ");
    gets(str);
    // fgets(str, sizeof(str), stdin);
    reverse_vowels(str);
    printf("The reversed vowel string: %s", str);
    return 0;
}
