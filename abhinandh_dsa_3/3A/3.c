#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Graph
{
    int V;
    int **adj;
};

void printAllPaths(struct Graph *graph, int s, int d);
void printAllPathsUtil(struct Graph *graph, int u, int d, bool visited[], int path[], int path_index);

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph->adj[i] = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    graph->adj[src][dest] = 1;
}

void printAllPaths(struct Graph *graph, int s, int d)
{
    bool *visited = (bool *)malloc(graph->V * sizeof(bool));
    int *path = (int *)malloc(graph->V * sizeof(int));
    int path_index = 0;
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;
    printAllPathsUtil(graph, s, d, visited, path, path_index);
}

void printAllPathsUtil(struct Graph *graph, int u, int d, bool visited[], int path[], int path_index)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;
    if (u == d)
    {
        for (int i = 0; i < path_index; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    else
    {
        for (int i = 0; i < graph->V; i++)
        {
            if (graph->adj[u][i] && !visited[i])
                printAllPathsUtil(graph, i, d, visited, path, path_index);
        }
    }
    path_index--;
    visited[u] = false;
}

void dfs(struct Graph *graph, int vertex, bool *visited)
{
    visited[vertex] = true;
    for (int i = 0; i < graph->V; i++)
    {
        if (graph->adj[vertex][i] == 1 && !visited[i])
            dfs(graph, i, visited);
    }
}

bool isConnected(struct Graph *graph)
{
    bool *visited = (bool *)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;
    dfs(graph, 0, visited);
    for (int i = 0; i < graph->V; i++)
    {
        if (!visited[i])
        {
            free(visited);
            return false;
        }
    }
    free(visited);
    int edges = 0;
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            if (graph->adj[i][j] == 1)
                edges++;
        }
    }
    edges /= 2;
    return edges == (graph->V - 1);
}

int main()
{
    int n, u, v;
    scanf("%d", &n);
    struct Graph *graph = createGraph(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &u);
        char ch;
        scanf("%c", &ch);
        while (ch != '\n')
        {
            scanf("%d%c", &v, &ch);
            addEdge(graph, u, v);
        }
    }
    int src, dst;
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
        case 'a':
            scanf("%d %d", &src, &dst);
            printAllPaths(graph, src, dst);
            break;
        case 't':
            if (isConnected(graph))
                printf("1\n");
            else
                printf("-1\n");
            break;
        }
    }
    for (int i = 0; i < n; i++)
        free(graph->adj[i]);
    free(graph->adj);
    free(graph);
    return 0;
}
