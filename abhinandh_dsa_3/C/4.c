#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primaryHash(int key, int N)
{
    return key % N;
}

int secondaryHash(int key, int R)
{
    return R - (key % R);
}

void linearProbing(int keys[], int n, int tableSize)
{
    int *table = (int *)malloc(tableSize * sizeof(int));
    if (table == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int collisions = 0;
    for (int i = 0; i < tableSize; i++)
        table[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int index = primaryHash(keys[i], tableSize);
        while (table[index] != -1)
        {
            collisions++;
            index = (index + 1) % tableSize;
        }
        table[index] = keys[i];
        printf("%d ", index);
    }
    printf("\n%d\n", collisions);

    free(table);
}

void quadraticProbing(int keys[], int n, int tableSize)
{
    int *table = (int *)malloc(tableSize * sizeof(int));
    if (table == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int collisions = 0;
    for (int i = 0; i < tableSize; i++)
        table[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int index = primaryHash(keys[i], tableSize);
        int step = 1;
        while (table[index] != -1)
        {
            collisions++;
            index = (primaryHash(keys[i], tableSize) + step * step) % tableSize;
            step++;
        }
        table[index] = keys[i];
        printf("%d ", index);
    }
    printf("\n%d\n", collisions);

    free(table);
}

int isPrime(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int getMaximumPrimeLessThanN(int n)
{
    for (int i = n - 1; i >= 2; i--)
    {
        if (isPrime(i))
            return i;
    }
    return 2;
}

void doubleHashing(int keys[], int n, int tableSize)
{
    int *table = (int *)malloc(tableSize * sizeof(int));
    if (table == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int collisions = 0;
    for (int i = 0; i < tableSize; i++)
        table[i] = -1;

    int R = getMaximumPrimeLessThanN(tableSize);

    for (int i = 0; i < n; i++)
    {
        int index = primaryHash(keys[i], tableSize);
        int step = secondaryHash(keys[i], R);
        int j = 1;
        while (table[index] != -1)
        {
            collisions++;
            index = (primaryHash(keys[i], tableSize) + j * step) % tableSize;
            j++;
        }
        table[index] = keys[i];
        printf("%d ", index);
    }
    printf("\n%d\n", collisions);

    free(table);
}

int main()
{
    int tableSize;
    scanf("%d", &tableSize);

    int keys[1000] = {0};
    int input, n = 0;
    char ch = ' ';


    while (ch == ' ')
    {
        scanf("%d", &input);
        scanf("%c", &ch);
        keys[n++] = input;
    }

    // printf("%d\n", n);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", keys[i]);
    // }
    // printf("\n");

    linearProbing(keys, n, tableSize);

    quadraticProbing(keys, n, tableSize);

    doubleHashing(keys, n, tableSize);

    // free(keys);

    return 0;
}
