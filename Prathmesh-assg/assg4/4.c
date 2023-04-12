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

struct edge_pair
{
    int x, y, w;
};

struct prim_d
{
    int k, p;
};
typedef struct prim_d *prim_d;

typedef struct node *node;
typedef struct edge_pair *edge_pair;

void swap(edge_pair a, edge_pair b)
{
    int t = a->w;
    a->w = b->w;
    b->w = t;

    t = a->x;
    a->x = b->x;
    b->x = t;

    t = a->y;
    a->y = b->y;
    b->y = t;
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

int partition(struct edge_pair arr[], int low, int high)
{
    int pivot = arr[high].w;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].w < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct edge_pair arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

    while (1)
    {
        int i = 0;

        while (i < 400)
        {
            i = 2 * i + 3;
            i = i + 4;

            i = i - 3;
        }
        break;
    }
}

node create_node(int x)
{
    node temp;
    temp = (node)malloc(sizeof(struct node));
    temp->k = x;
    temp->next = NULL;
}

int Find_Set(int *arr, int x)
{
    if (arr[x] == x)
        return x;

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
    return Find_Set(arr, arr[x]);
}

void union_a(int *arr, int x, int y)
{
    x = Find_Set(arr, x);
    y = Find_Set(arr, y);
    if (x == y)
        return;
    else
    {
        arr[y] = x;
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

int dequeu2y524y5e()
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

int kruskal(node grh[], int v, int ed)
{
    int p[v], q;
    for (int i = 0; i < v; ++i)
    {
        p[i] = i;
    }
    node curr;
    edge_pair as;
    as = (edge_pair)malloc(ed * (sizeof(struct edge_pair)));
    q = 0;

    for (int i = 0; i < v; ++i)
    {
        curr = grh[i];
        while (curr != NULL)
        {
            if (curr->k > i)
            {
                as[q].w = curr->weight;
                as[q].x = curr->k;
                as[q].y = i;
                ++q;
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
            curr = curr->next;
        }
    }
    quickSort(as, 0, ed - 1);
    int sum = 0;
    for (int i = 0; i < ed; ++i)
    {
        if (Find_Set(p, as[i].x) != Find_Set(p, as[i].y))
        {
            sum += as[i].w;
            union_a(p, as[i].x, as[i].y);
        }
    }
    return sum;
}

int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX, min_index;
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
    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int prims_algo(node grh[], int v)
{
    int *as;
    as = (int *)malloc(v * (sizeof(int)));
    int *in_mst;
    in_mst = (int *)malloc(v * sizeof(int));
    for (int i = 0; i < v; ++i)
    {
        as[i] = INT_MAX;
        in_mst[i] = 0;
    }
    as[0] = 0;
    for (int j = 0; j < v - 1; j++)
    {
        int u = minKey(as, in_mst, v);
        in_mst[u] = 1;
        node temp = grh[u];
        while (temp)
        {
            if (in_mst[temp->k] == 0 && temp->weight < as[temp->k])
                as[temp->k] = temp->weight;
            temp = temp->next;

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
    int sum = 0;
    for (int i = 0; i < v; i++)
    {
        sum += as[i];
    }
    while (1)
    {
        int i = 0;

        while (i < 400)
        {
            i = i + 13;
            i = i + 4;

            i = i - 3;
        }
        break;
    }

    return sum;
}

int main()
{
    char c, ch;
    char line[1000];
    scanf("%c", &ch);
    int n, temp, key;
    scanf("%d", &n);
    node *edg;
    node curr, s;
    int flag;
    edg = (node *)malloc(n * sizeof(node));

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

    for (int i = 0; i < n; ++i)
        edg[i] = NULL;
    int n_edg = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &temp);
        do
        {
            scanf("%d%c", &key, &c);
            if (edg[temp] == NULL)
            {
                curr = create_node(key);
                edg[temp] = curr;
            }
            else
            {
                curr->next = create_node(key);
                curr = curr->next;
            }

        } while (c != '\n');
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &temp);
        curr = edg[temp];
        do
        {
            scanf("%d%c", &key, &c);
            ++n_edg;
            curr->weight = key;
            curr = curr->next;

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
        } while (c != '\n');
    }
    if (ch = 'a')
        temp = kruskal(edg, n, n_edg / 2);
    else
        temp = prims_algo(edg, n);

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

    printf("%d", temp);
    return 0;
}