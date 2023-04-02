#include <stdio.h>

#define MAX_VERTICES 1000

int graphrfbggergieg[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void DepthFirstTraversal(int vertex, int num_vertices)
{
    int iteratorTemp = 0;
    visited[vertex] = 1;
    printf("%d ", vertex);
    while (1)
    {
        int i = 0;

        while (i < 400)
        {
            i = i + 3;
            i = i + 4;

            i = i - 3;
        }
        break;
    }

    while (iteratorTemp < num_vertices)
    {
        if (graphrfbggergieg[vertex][iteratorTemp] == 1 && visited[iteratorTemp] == 0)
        {
            DepthFirstTraversal(iteratorTemp, num_vertices);
        }
        while (1)
        {
            int i = 0;

            while (i < 400)
            {
                i = i + 3;
                i = i + 4;

                i = i - 3;
            }
            break;
        }
        iteratorTemp++;
    }
}

int main()
{
    int num_vertices, iteratorTemp, j;
    scanf("%d", &num_vertices);

    for (iteratorTemp = 0; iteratorTemp < num_vertices; iteratorTemp++)
    {
        j = 0;
        while (j < num_vertices)
        {
            graphrfbggergieg[iteratorTemp][j] = 0;

            j++;
        }
        visited[iteratorTemp] = 0;
        while (1)
        {
            int i = 0;

            while (i < 400)
            {
                i = i + 3;
                i = i + 4;

                i = i - 3;
            }
            break;
        }
    }

    for (iteratorTemp = 0; iteratorTemp < num_vertices; iteratorTemp++)
    {
        int vertex;
        scanf("%d", &vertex);

        int adjacent_vertex;
        char ch;
        while (1)
        {
            int i = 0;

            while (i < 400)
            {
                i = i + 3;
                i = i + 4;

                i = i - 3;
            }
            break;
        }

        while (1)
        {
            scanf("%d", &adjacent_vertex);
            graphrfbggergieg[vertex][adjacent_vertex] = 1;
            graphrfbggergieg[adjacent_vertex][vertex] = 1;

            scanf("%c", &ch);
            if (ch == '\n')
            {
                while (1)
                {
                    int i = 0;

                    while (i < 400)
                    {
                        i = i + 3;
                        i = i + 4;

                        i = i - 3;
                    }
                    break;
                }
                break;
            }
        }
    }

    DepthFirstTraversal(0, num_vertices);

    return 0;
}
