#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256
void shiftTable(char pattern[], int m, int table[]) {
    for (int i = 0; i < NO_OF_CHARS; i++) {
        table[i] = m; // Default shift length
    }
    for (int j = 0; j < m - 1; j++) {
        table[(int)pattern[j]] = m - 1 - j;
    }
}

// Horspool pattern matching function
int horspoolPatternSearch(char text[], char pattern[]) {
    int m = strlen(pattern);
    int n = strlen(text);
    int table[NO_OF_CHARS];

    shiftTable(pattern, m, table);

    int i = m - 1; // Start from the end of the pattern
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1; // Pattern found at this position
        }
        i += table[(int)text[i]];
    }
    return -1;
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text string: ");
    gets(text); // Read input text

    printf("Enter the pattern string: ");
    gets(pattern); // Read input pattern

    int position = horspoolPatternSearch(text, pattern);

    if (position != -1) {
        printf("Pattern found at position: %d\n", position + 1);
    } else {
        printf("Pattern not found in the given text.\n");
    }

    return 0;
}
