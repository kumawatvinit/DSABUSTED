#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n, int *swaps) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swaps)++;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int swaps = 0;
    bubbleSort(arr, n, &swaps);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n%d\n", swaps);

    free(arr);

    return 0;
}
