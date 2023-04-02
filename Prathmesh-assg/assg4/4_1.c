#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int **adjMatrix = (int **) malloc(n * sizeof(int *)); 
    for(int i = 0; i < n; i++) {
        adjMatrix[i] = (int *) malloc(n * sizeof(int)); 
    }


    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        printf("%d ", i);

        for(int j=0; j<n; j++) {
            if(adjMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }

        printf("\n");
    }

    // free the memory
    for(int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
