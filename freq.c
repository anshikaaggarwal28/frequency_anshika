#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_LEN];
    int count[MAX_WORDS] = {0};
    int i, j, k = 0, found;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    for (i = 0; paragraph[i]; i++) {
        if (ispunct(paragraph[i]))
            paragraph[i] = ' ';
        paragraph[i] = tolower(paragraph[i]);
    }

    char *token = strtok(paragraph, " \n\t");
    while (token != NULL) {
        found = 0;
        for (i = 0; i < k; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[k], token);
            count[k] = 1;
            k++;
        }
        token = strtok(NULL, " \n\t");
    }

    printf("\nWord Frequencies:\n");
    for (i = 0; i < k; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}

