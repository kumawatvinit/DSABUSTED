#include <stdio.h>
#include <stdlib.h>

struct rope {
    int data;
    struct rope *nextRope;
};

struct rope *CreateNewRope(int data) {
    struct rope *temp = (struct rope *)malloc(sizeof(struct rope));
    temp->data = data;
    temp->nextRope = NULL;
    return temp;
}

void insertRope(struct rope **head, int data) {
    struct rope *temp = CreateNewRope(data);

    if (*head == NULL || data < (*head)->data) {
        temp->nextRope = *head;
        *head = temp;
    } else {
        struct rope *curr = *head;
        while (curr->nextRope != NULL && curr->nextRope->data < data) {
            curr = curr->nextRope;
        }
        temp->nextRope = curr->nextRope;
        curr->nextRope = temp;
    }
}

int extractMinRope(struct rope **head) {
    if (*head == NULL) {
        return -1;  
    }
    int data = (*head)->data;
    struct rope *temp = *head;
    *head = (*head)->nextRope;
    free(temp);
    return data;
}

int connectRopes(int arr[], int n) {
    struct rope *pq = NULL;  // Priority queue
    int i, cost = 0;

    for (i = 0; i < n; i++) {
        insertRope(&pq, arr[i]);
    }

    // Combine the ropes until only one rope remains
    while (pq != NULL && pq->nextRope != NULL) {
        int a = extractMinRope(&pq);
        int b = extractMinRope(&pq);
        int c = a + b;
        cost += c;
        insertRope(&pq, c);
    }

    return cost;
}

int main() {
    int n, i;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int total_cost = connectRopes(arr, n);
    printf("%d\n", total_cost);

    free(arr);
    return 0;
}
