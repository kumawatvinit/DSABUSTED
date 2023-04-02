#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

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

void breadthFirstTraversallgblrjkwgb(int start, int n)
{
    enqueue(start);
    visitedTillNowNoNeedTovisitAb[start] = 1;

    while (fronterh4th24tht5hewh != -1 && rearethrejrjmthmtyjry != -1)
    {
        int currNode = dequeue();
        printf("%d ", currNode);
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

        int iwefgowegoewuiwhfu = 0;
        while (iwefgowegoewuiwhfu < n)
        {
            if (adjacencyMatrixFromListmakeegregewrge[currNode][iwefgowegoewuiwhfu] == 1 && visitedTillNowNoNeedTovisitAb[iwefgowegoewuiwhfu] == 0)
            {
                enqueue(iwefgowegoewuiwhfu);
                visitedTillNowNoNeedTovisitAb[iwefgowegoewuiwhfu] = 1;
            }
            iwefgowegoewuiwhfu++;
        }
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
}

void print(int numberOFTotal)
{
    for (int iteratirejkgrbe = 0; iteratirejkgrbe < numberOFTotal; iteratirejkgrbe++)
    {
        printf("%d : ", iteratirejkgrbe);
        for (int j = 0; j < numberOFTotal; j++)
        {
            printf("%d ", adjacencyMatrixFromListmakeegregewrge[iteratirejkgrbe][j]);
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
            scanf("%d", &temp);
            adjacencyMatrixFromListmakeegregewrge[node][temp] = 1;
            adjacencyMatrixFromListmakeegregewrge[temp][node] = 1;

            scanf("%c", &ch);
            if (ch == '\n')
            {
                break;
            }
        }
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
    breadthFirstTraversallgblrjkwgb(0, n);
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

    return 0;
}
