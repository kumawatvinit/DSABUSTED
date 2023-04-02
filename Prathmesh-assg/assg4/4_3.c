#include <stdio.h>

#define MAX_VERTICES 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void DFS(int vertex, int num_vertices) {
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(i, num_vertices);
        }
    }
}

int main() {
    int num_vertices, i, j;
    scanf("%d", &num_vertices);

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    for (i = 0; i < num_vertices; i++) {
        int vertex;
        scanf("%d", &vertex);

        int adjacent_vertex;
        char ch;

        while(1)
        {
            scanf("%d", &adjacent_vertex);
            graph[vertex][adjacent_vertex] = 1;
            graph[adjacent_vertex][vertex] = 1; 

            scanf("%c", &ch);
            if(ch == '\n')
            {
                break;
            }
        }
    }

    DFS(0, num_vertices);

    return 0;
}
