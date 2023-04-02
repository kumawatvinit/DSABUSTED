#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

int adjList[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int node)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = node;
}

int dequeue()
{
    int node = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return node;
}

void bfs(int start, int n)
{
    enqueue(start);
    visited[start] = 1;

    while (front != -1 && rear != -1)
    {
        int currNode = dequeue();
        printf("%d ", currNode);

        for (int i = 0; i < n; i++)
        {
            if (adjList[currNode][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void print(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d : ", i);
        for(int j=0; j<n; j++)
        {
            printf("%d ", adjList[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int node;
        scanf("%d", &node);

        char ch;
        int temp;

        while (1)
        {
            scanf("%d", &temp);
            adjList[node][temp] = 1;
            adjList[temp][node] = 1;
            
            scanf("%c", &ch);
            if(ch == '\n')
            {
                break;
            }
        }
    }
    // print(n);

    bfs(0, n);

    return 0;
}
