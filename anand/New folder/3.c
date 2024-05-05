#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 101


typedef struct {
    char name[MAX_NAME_LENGTH];
    int price;
} Product;


void selectionSort(Product *arr, int n) {
    int i, j, min_idx;
    Product temp;


    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j].price < arr[min_idx].price) {
                min_idx = j;
            }
        }
        
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    Product *products = (Product *)malloc(n * sizeof(Product));

    
    for (int i = 0; i < n; i++) {
        fgets(products[i].name, MAX_NAME_LENGTH, stdin);

        if (products[i].name[strlen(products[i].name) - 1] == '\n') {
            products[i].name[strlen(products[i].name) - 1] = '\0';
        }
        scanf("%d", &products[i].price);
        getchar();
    }

    selectionSort(products, n);

    for (int i = 0; i < n; i++) {
        printf("%s ", products[i].name);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", products[i].price);
    }

    free(products);

    return 0;
}
