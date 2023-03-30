#include <stdio.h>
#include <stdlib.h>

int leftChild(int idx) {
    return 2 * idx + 1;
}

int rightChild(int idx) {
    return 2 * idx + 2;
}

void max_heapify(int arr[], int n, int i) {
    int largest = i;  
    int left = leftChild(i);
    int right = rightChild(i);


    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        max_heapify(arr, n, largest);
    }
}

void build_max_heap(int arr[], int n) {
    int idx = (n / 2) - 1;

    for (; idx >= 0; idx--) {
        max_heapify(arr, n, idx);
    }
}

void print_k_largest(int arr[], int n, int k) {
    build_max_heap(arr, n);

    int idx;
    for (idx = n - 1; (idx >= n - k) && (idx>=0); idx--) {
        printf("%d ", arr[0]);  
        arr[0] = arr[idx];  
        max_heapify(arr, idx, 0);  
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k, itr;
        scanf("%d", &n);

        int *arr = (int *)malloc(n * sizeof(int));

        for (itr = 0; itr < n; itr++) {
            scanf("%d", &arr[itr]);
        }

        scanf("%d", &k);

        print_k_largest(arr, n, k);

        free(arr);
    }

    return 0;
}
