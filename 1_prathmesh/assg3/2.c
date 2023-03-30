#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct MinHeapNode
{
    int key;
};

struct MinHeap
{
    int capacity;
    int size;
    struct MinHeapNode **nodes;
};

struct MinHeapNode * createNode(int key)
{
    struct MinHeapNode *node = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    node->key = key;
    return node;
}


void swap(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap *minHeap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < minHeap->size && minHeap->nodes[left]->key < minHeap->nodes[smallest]->key)
    {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->nodes[right]->key < minHeap->nodes[smallest]->key)
    {
        smallest = right;
    }
    if (smallest != index)
    {
        swap(&minHeap->nodes[index], &minHeap->nodes[smallest]);
        minHeapify(minHeap, smallest);
    }
}


void extractMin(struct MinHeap *minHeap)
{
    if (minHeap->size == 0)
    {
        printf("-1\n");
        return;
    }
    struct MinHeapNode *minElement = minHeap->nodes[0];
    minHeap->nodes[0] = minHeap->nodes[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    free(minElement);
}

int decreaseKey(struct MinHeap *minHeap, int index, int newKey)
{
    if (newKey >= minHeap->nodes[index]->key)
    {
        printf("-1\n");
        return -1;
    }
    minHeap->nodes[index]->key = newKey;
    while (index > 0 && minHeap->nodes[index]->key < minHeap->nodes[(index - 1) / 2]->key)
    {
        swap(&minHeap->nodes[index], &minHeap->nodes[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    // printf("%d\n", newKey);
    return 1;
}

void delete(struct MinHeap *minHeap, int key)
{
    int deleteIndex = -1;
    for (int idx = 0; idx < minHeap->size; idx++)
    {
        if (minHeap->nodes[idx]->key == key)
        {
            deleteIndex = idx;
            break;
        }
    }
    if (deleteIndex == -1)
    {
        printf("-1\n");
        return;
    }
    decreaseKey(minHeap, deleteIndex, INT_MIN);
    extractMin(minHeap);
    printf("%d\n", key);
}


void findMin(struct MinHeap *minHeap)
{
    if (minHeap->size == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", minHeap->nodes[0]->key);
}

void insert(struct MinHeap *minHeap, int key)
{
    if (minHeap->size == minHeap->capacity)
    {
        printf("-1\n");
        return;
    }
    struct MinHeapNode *newNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    newNode->key = key;

    minHeap->size++;
    int idx = minHeap->size - 1;
    minHeap->nodes[idx] = newNode;
    while (idx > 0 && minHeap->nodes[idx]->key < minHeap->nodes[(idx - 1) / 2]->key)
    {
        swap(&minHeap->nodes[idx], &minHeap->nodes[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void printHeap(struct MinHeap *minHeap)
{
    // printf("Min Heap:\n");
    for (int idx = 0; idx < minHeap->size; idx++)
    {
        printf("%d ", minHeap->nodes[idx]->key);
    }
    printf("\n");
}

int search(struct MinHeap *minHeap, int key)
{
    int n = minHeap->size;
    for(int idx=0; idx<n; idx++)
    {
        if(minHeap->nodes[idx]->key == key) return idx;
    }
    return -1;
}

int main()
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    int key1, key2;
    char command;
    minHeap->capacity = 100000;
    minHeap->size = 0;
    minHeap->nodes = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));

    while (1)
    {
        scanf("%c", &command);
        // printf("Input: _%c_\n", command);

        if (command == 'e')
        {
            break;
        }
        switch(command)
        {
        case 'i':
            scanf("%d", &key1);
            insert(minHeap, key1);
            break;
        case 'd':
            scanf("%d", &key1);
            delete (minHeap, key1);
            break;
        case 'p':
            printHeap(minHeap);
            break;
        case 'x':
            extractMin(minHeap);
            printHeap(minHeap);
            break;
        case 'r':
            scanf("%d%d", &key1, &key2);
            int index = search(minHeap, key1);

            if(index == -1) {
                printf("-1\n");
            }
            else {
                if(decreaseKey(minHeap, index, key2) != -1)
                    printf("%d\n", key2);
            }
            break;
        case 'g':
            findMin(minHeap);
            break;
        }
    }
    free(minHeap);
    return 0;
}