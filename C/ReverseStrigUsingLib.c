//Author: Bholenath Waghmode
// date: 2026/07/20    

// This program reverses a string in place using a pointer-based approach.
#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        // Swap characters at start and end
        char temp = *start;
        *start = *end;
        *end = temp;

        // Move pointers towards each other
        start++;
        end--;
    }
}


int main() {
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}