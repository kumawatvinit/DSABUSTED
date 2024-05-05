#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(char **arr, int n) {
    int i, j;
    char *key = (char *)malloc(101 * sizeof(char));
    for (i = 1; i < n; i++) {
        strcpy(key, arr[i]);
        j = i - 1;

        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j = j - 1;
        }
        strcpy(arr[j + 1], key);
    }
    free(key);
}

int main() {
    int n;
    
    scanf("%d", &n);
    getchar(); 


    char **books = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        books[i] = (char *)malloc(101 * sizeof(char));
        
        fgets(books[i], 101, stdin);
        
        if (books[i][strlen(books[i]) - 1] == '\n') {
            books[i][strlen(books[i]) - 1] = '\0';
        }
    }

    insertionSort(books, n);

    
    for (int i = 0; i < n; i++) {
        printf("%s\n", books[i]);
    }

    for (int i = 0; i < n; i++) {
        free(books[i]);
    }
    free(books);

    return 0;
}
