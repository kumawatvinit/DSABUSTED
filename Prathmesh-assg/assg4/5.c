
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 1001

struct node
{
    int k;
    int weight;
    struct node *next;
};

typedef struct node *node;

node create_node(int x)
{
    node temp;
    temp = (node)malloc(sizeof(struct node));
    temp->k = x;
    temp->next = NULL;
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
    return temp;
}

int adjacencyMatrixFromListmakeegregewrge[MAX_SIZE][MAX_SIZE];
int visitedTillNowNoNeedTovisitAb[MAX_SIZE];
int queueehrgirewr[MAX_SIZE];
int fronterh4th24tht5hewh = -1, rearethrejrjmthmtyjry = -1;

void enqueue(int node)
{
    if (fronterh4th24tht5hewh == -1 && rearethrejrjmthmtyjry == -1)
    {
        fronterh4th24tht5hewh = rearethrejrjmthmtyjry = 0;
    }
    else
    {
        rearethrejrjmthmtyjry++;
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
    queueehrgirewr[rearethrejrjmthmtyjry] = node;
}

int dequeue()
{
    int node = queueehrgirewr[fronterh4th24tht5hewh];
    if (fronterh4th24tht5hewh == rearethrejrjmthmtyjry)
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
        fronterh4th24tht5hewh = rearethrejrjmthmtyjry = -1;
    }
    else
    {
        fronterh4th24tht5hewh++;
    }
    return node;
}

int *Dijkstra(node grh[], int v, int source)
{
    int *in_tree;
    in_tree = (int *)malloc(v * (sizeof(int)));
    int *dis;
    dis = (int *)malloc(v * (sizeof(int)));
    int *par;
    par = (int *)malloc(v * (sizeof(int)));
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

    for (int i = 0; i < v; ++i)
    {
        dis[i] = INT_MAX;
        in_tree[i] = 0;
        par[i] = -1;
    }
    dis[source] = 0;
    int pre = source;
    while (in_tree[pre] == 0)
    {
        in_tree[pre] = 1;
        node temp = grh[pre];
        int x, weight;
        while (temp != NULL)
        {
            x = temp->k;
            weight = temp->weight;
            if (dis[x] > dis[pre] + weight)
            {
                dis[x] = dis[pre] + weight;
                par[x] = pre;
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
            temp = temp->next;
        }
        pre = 0;
        int dist = INT_MAX;
        for (int i = 0; i < v; i++)
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
            if ((in_tree[i] == 0) && (dist > dis[i]))
            {
                dist = dis[i];
                pre = i;
            }
        }
    }
    return dis;
}

int main()
{
    char c, ch;
    int n, temp, key;
    scanf("%d", &n);
    node *edg;
    node curr, s;
    int flag;
    edg = (node *)malloc(n * sizeof(node));
    for (int i = 0; i < n; ++i)
        edg[i] = NULL;
    int n_edg = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%c", &temp, &c);
        if (c == '\n')
            continue;
        do
        {
            scanf("%d%c", &key, &c);
            if (edg[temp] == NULL)
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
                curr = create_node(key);
                edg[temp] = curr;
            }
            else
            {
                curr->next = create_node(key);
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
                curr = curr->next;
            }

        } while (c != '\n');
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d%c", &temp, &c);
        if (c == '\n')
            continue;
        curr = edg[temp];
        do
        {
            scanf("%d%c", &key, &c);
            ++n_edg;
            curr->weight = key;
            curr = curr->next;
        } while (c != '\n');
    }
    int *dis, temp_2;
    char str[5];
    while (1)
    {
        scanf("%s", str);
        if (str[1] == 't')
        {
            return 0;
        }
        if (str[0] == 'a')
        {
            scanf("%d", &temp);
            dis = Dijkstra(edg, n, temp);
            for (int i = 0; i < n; ++i)
            {
                if (dis[i] != INT_MAX)
                    printf("%d ", dis[i]);
                else
                {
                    printf("INF ");
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
            }
            printf("\n");
        }
        else
        {
            scanf("%d %d", &temp, &temp_2);
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
            dis = Dijkstra(edg, n, temp);
            if (dis[temp_2] != INT_MAX)
                printf("%d\n", dis[temp_2]);
            else
                printf("UNREACHABLE\n");
        }
    }
}