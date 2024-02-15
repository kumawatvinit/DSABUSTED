#include <stdio.h>
#include <stdlib.h>

int isPresent(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1; 
        }
    }
    return 0;
}

void printUnion(int arr1[], int m, int arr2[], int n) {
    int printed[1000] = {0}; 
    int flag = 1;

    for (int i = 0; i < m; i++) {
        
        if (!isPresent(printed, m + n, arr1[i])) {
            printf("%d ", arr1[i]);
            flag = 0;
            printed[i] = arr1[i];
        }
    }
    // Traverse arr2
    for (int i = 0; i < n; i++) {
        
        if (!isPresent(printed, m + n, arr2[i])) {
            printf("%d ", arr2[i]);
            flag = 0;
            printed[m + i] = arr2[i];
        }
    }

    if(flag) printf("-1");
}

void intersection(int a[], int m, int b[], int n) {
    int printed[1000] = {0}; 
    int flag = 1;

    for (int i = 0; i < m; i++) {
       
        if (isPresent(b, n, a[i]) && !isPresent(printed, m, a[i])) {
            printf("%d ", a[i]);
            flag = 0;
            printed[i] = a[i];
        }
    }

    if(flag) printf("-1");
}

void setDiff(int a[], int m, int b[], int n) {
    int printed[1000] = {0};
    int flag = 1;

    for (int i = 0; i < m; i++) {
        if (!isPresent(b, n, a[i]) && !isPresent(printed, m, a[i])) {
            printf("%d ", a[i]);
            flag = 0;
            printed[i] = a[i];
        }
    }

    if(flag) printf("-1");
}


int main()
{
    int m, n;
    scanf("%d%d", &m,&n);

    
    int *a, *b;
    a = (int*)malloc(m * sizeof(int));
    b = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    char op;
    while (1) {
        scanf("%c", &op);
        char first, second;

        switch (op) {
            case 'u':
                // char first, second;
                scanf(" %c %c", &first, &second);
                
                if(first == 'A') printUnion(a, m, b, n);
                else printUnion(b, n, a, m);

                printf("\n");
                break;
            case 'i':
                // char first, second;
                scanf(" %c %c", &first, &second);
                
                if(first == 'A') intersection(a, m, b, n);
                else intersection(b, n, a, m);

                printf("\n");
                break;
            case 's':
                // char first, second;
                scanf(" %c %c", &first, &second);
                
                if(first == 'A') setDiff(a, m, b, n);
                else setDiff(b, n, a, m);

                printf("\n");
                break;
            case 'e': 
                return 0;
        }
    }

    return 0;
}