#include <stdio.h>
#include <stdlib.h>

int findKthSmallest(int *arr, int n, int k) {
    if (k<1 || k > n) {
        return -1;
    }

    for (int i = 0; i < k; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    return arr[k - 1];
}

int main() {
    int n, k;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    printf("%d\n", findKthSmallest(arr, n, k));

    free(arr);

    return 0;
}
