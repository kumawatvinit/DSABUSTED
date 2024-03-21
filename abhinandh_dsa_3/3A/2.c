#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

int isTopologicalSortPossible(int n, int **arr)
{
    int *indegree = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            count++;
        }
    }
    if (count != 1)
    {
        return 0;
    }
    return 1;
}

void dfs(int vertex, int n, int **arr, int *visited, int *stack)
{
    visited[vertex] = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[vertex][i] == 1 && visited[i] == 0)
        {
            dfs(i, n, arr, visited, stack);
        }
    }
    stack[++stack[0]] = vertex;
}

int **transpose(int n, int **arr)
{
    int **transposed = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        transposed[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposed[j][i] = arr[i][j];
        }
    }
    return transposed;
}

void dfsTranspose(int vertex, int n, int **arr, int *visited)
{
    visited[vertex] = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[vertex][i] == 1 && visited[i] == 0)
        {
            dfsTranspose(i, n, arr, visited);
        }
    }
}

int numberOfStronglyComponents(int n, int **arr)
{
    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int *stack = (int *)malloc((n + 1) * sizeof(int));
    stack[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, n, arr, visited, stack);
        }
    }
    int **transposed = transpose(n, arr);
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int count = 0;
    while (stack[0] > 0)
    {
        int vertex = stack[stack[0]--];
        if (visited[vertex] == 0)
        {
            dfsTranspose(vertex, n, transposed, visited);
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(transposed[i]);
    }
    free(transposed);
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    char choice;
    while (1)
    {
        scanf("%c", &choice);
        if (choice == 'x')
        {
            break;
        }
        switch (choice)
        {
        case 't':
            if (isTopologicalSortPossible(n, arr))
                printf("1\n");
            else
                printf("0\n");
            break;
        case 'c':
            printf("%d\n", numberOfStronglyComponents(n, arr));
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
