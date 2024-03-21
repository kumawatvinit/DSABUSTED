#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Graph
{
    int V;
    int adj[MAX_NODES][MAX_NODES];
};

void initGraph(struct Graph *G, int V)
{
    G->V = V;
    for (int i = 0; i <= V; ++i)
    {
        for (int j = 0; j <= V; ++j)
        {
            G->adj[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *G, int u, int v)
{
    G->adj[u][v] = 1;
    G->adj[v][u] = 1;
}

void dfs(struct Graph *G, int v, int visited[])
{
    visited[v] = 1;
    for (int i = 1; i < G->V; ++i)
    {
        if (G->adj[v][i] && !visited[i])
        {
            dfs(G, i, visited);
        }
    }
}

int noOfConnectedComponents(struct Graph *G)
{
    int visited[MAX_NODES] = {0};
    int components = 0;
    for (int i = 1; i < G->V; ++i)
    {
        if (!visited[i])
        {
            dfs(G, i, visited);
            components++;
        }
    }
    return components;
}

int dfsComponentSize(struct Graph *G, int v, int visited[])
{
    visited[v] = 1;
    int size = 1;
    for (int i = 1; i < G->V; ++i)
    {
        if (G->adj[v][i] && !visited[i])
        {
            size += dfsComponentSize(G, i, visited);
        }
    }
    return size;
}

void sizeOfComponents(struct Graph *G)
{
    int visited[MAX_NODES] = {0};
    for (int i = 1; i < G->V; ++i)
    {
        if (!visited[i])
        {
            int size = dfsComponentSize(G, i, visited);
            printf("%d ", size);
        }
    }
    printf("\n");
}

int dfsBridges(struct Graph *G, int v, int visited[], int parent[], int disc[], int low[], int *time)
{
    visited[v] = 1;
    disc[v] = low[v] = ++(*time);
    int ans = 0;

    for (int i = 1; i < G->V; ++i)
    {
        if (G->adj[v][i])
        {
            if (!visited[i])
            {
                parent[i] = v;
                ans += dfsBridges(G, i, visited, parent, disc, low, time);
                low[v] = (low[v] < low[i]) ? low[v] : low[i];
                if (low[i] > disc[v])
                {
                    ans += 1;
                }
            }
            else if (i != parent[v])
            {
                low[v] = (low[v] < disc[i]) ? low[v] : disc[i];
            }
        }
    }

    return ans;
}

void noOfBridges(struct Graph *G)
{
    int visited[MAX_NODES] = {0};
    int parent[MAX_NODES] = {-1};
    int disc[MAX_NODES], low[MAX_NODES];
    int time = 0;
    int ans = 0;

    for (int i = 1; i < G->V; ++i)
    {
        if (!visited[i])
        {
            ans += dfsBridges(G, i, visited, parent, disc, low, &time);
        }
    }

    printf("%d\n", ans);
}

void dfsArticulationPoints(struct Graph *G, int v, int visited[], int disc[], int low[], int *time, int parent, int ap[])
{
    int children = 0;
    visited[v] = 1;
    disc[v] = low[v] = ++(*time);

    for (int i = 1; i < G->V; ++i)
    {
        if (G->adj[v][i])
        {
            if (!visited[i])
            {
                children++;

                dfsArticulationPoints(G, i, visited, disc, low, time, v, ap);
                low[v] = (low[v] < low[i]) ? low[v] : low[i];
                
                if (parent != -1 && low[i] >= disc[v]) {
                    ap[v] = 1; // Non-root vertex
                }
            }
            else if (i != parent)
            {
                low[v] = (low[v] < disc[i]) ? low[v] : disc[i];
            }
        }
    }
    if (parent == -1 && children > 1)
    {
        ap[v] = 1; // Root with multiple children
    }
}

void noOfArticulationPoints(struct Graph *G)
{
    int visited[MAX_NODES] = {0};
    int disc[MAX_NODES] = {0}, low[MAX_NODES], parent[MAX_NODES] = {-1};
    int ap[MAX_NODES] = {0};
    int time = 0;

    for (int i = 1; i < G->V; ++i)
    {
        if (!visited[i])
        {
            dfsArticulationPoints(G, i, visited, disc, low, &time, -1, ap);
        }
    }

    int count = 0;
    for (int i = 1; i < G->V; ++i)
    {
        if (ap[i]) {
            count++;
        }
    }
    printf("%d\n", count);
}

void printAdj(struct Graph *G)
{
    printf("Start:\n");
    for (int i = 0; i < G->V; ++i)
    {
        for (int j = 0; j < G->V; ++j)
        {
            printf("%d ", G->adj[i][j]);
        }
        printf("\n");
    }
    printf("End\n");
}

int main()
{
    int m;
    scanf("%d", &m);

    struct Graph G;
    initGraph(&G, m + 1);

    for (int i = 0; i < m; ++i)
    {
        char ch;
        int u, v;
        scanf("%d", &u);

        scanf("%c", &ch);
        while (ch != '\n')
        {
            scanf("%d%c", &v, &ch);
            addEdge(&G, u, v);
        }
    }

    char choice;
    while (1)
    {
        scanf("%c", &choice);
        if (choice == 't')
        {
            break;
        }
        switch (choice)
        {
        case 'n':
            printf("%d\n", noOfConnectedComponents(&G));
            break;
        case 's':
            sizeOfComponents(&G);
            break;
        case 'b':
            noOfBridges(&G);
            break;
        case 'a':
            noOfArticulationPoints(&G);
            break;
        }
    }

    return 0;
}
