/* Student: Kyle Netterville */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LENGTH 512

int get_number_strings(void) {
    int n = 0;

    printf("Enter a number of strings: ");
    fflush(stdout);
    if (scanf("%d", &n) != 1 || n <= 0) {
        return -1;
    }

    getchar();
    return n;
}

int comparing_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(void) {
    int n = get_number_strings();
    char **array;
    
    if (n <= 0) {
        printf("Invalid number of strings.\n");
        return 1;
    }
    printf("You chose to enter %d strings.\n", n);

    array = malloc(n * sizeof(char *));

    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    char buffer[1024];

    for (int i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);

            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
                len--;
            }

            if (len > MAX_CHAR_LENGTH) {
                buffer[MAX_CHAR_LENGTH] = '\0';
                len = MAX_CHAR_LENGTH;
            }

            array[i] = malloc((len + 1) * sizeof(char));
            if (array[i] == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }
            strcpy(array[i], buffer);
        }
    }

    qsort(array, n, sizeof(char *), comparing_strings);

    printf("\nSorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", array[i]);
    }

    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}