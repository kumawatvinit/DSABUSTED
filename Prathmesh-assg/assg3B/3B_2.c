#include <stdio.h>
#include <stdlib.h>

void simpleMakeSet(int val, int *parent)
{
    parent[val] = val;
}

void rankMakeSet(int val, int *parent, int *rank)
{
    parent[val] = val;
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
    rank[val] = 0;
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

int simpleFindSet(int val, int *parent, int *no_find_set)
{
    (*no_find_set)++;
    if (val == parent[val])
        return val;
    return simpleFindSet(parent[val], parent, no_find_set);
}

int compressFindSet(int val, int *parent, int *no_find_set)
{
    (*no_find_set)++;
    if (val == parent[val])
        return val;
    return parent[val] = compressFindSet(parent[val], parent, no_find_set);

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

int simpleUnionSetsWithoutCompress(int a, int b, int *parent, int *no_find_set)
{
    a = simpleFindSet(a, parent, no_find_set);

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

    b = simpleFindSet(b, parent, no_find_set);

    if (a != b)
        parent[b] = a;
    return a;
}

int simpleUnionSetsWithCompress(int a, int b, int *parent, int *no_find_set)
{
    a = compressFindSet(a, parent, no_find_set);
    b = compressFindSet(b, parent, no_find_set);
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

    if (a != b)
        parent[b] = a;
    return a;
}

int rankUnionSetsWithoutCompress(int a, int b, int *parent, int *rank, int *no_find_set)
{
    a = simpleFindSet(a, parent, no_find_set);
    b = simpleFindSet(b, parent, no_find_set);

    if (a == b)
        return a;
    if (rank[a] < rank[b])
    {
        parent[a] = b;
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
        return b;
    }

    if (rank[a] == rank[b])
        rank[a]++;
    parent[b] = a;

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

    return a;
}

int rankUnionSetsWithCompress(int a, int b, int *parent, int *rank, int *no_find_set)
{
    a = compressFindSet(a, parent, no_find_set);
    b = compressFindSet(b, parent, no_find_set);

    if (a == b)
        return a;
    if (rank[a] < rank[b])
    {
        parent[a] = b;
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

        return b;
    }

    if (rank[a] == rank[b])
        rank[a]++;
    parent[b] = a;
    return a;
}

int main()
{

    int withoutRankWithoutCompressed[10001];
    int withoutRankWithCompressed[10001];
    int rankWithoutCompressed[10001];
    int rankWithoutCompressedRank[10001];
    int RankCompressed[10001];
    int rankCompressedRank[10001];

    for (int i = 0; i < 10001; i++)
    {
        withoutRankWithoutCompressed[i] = -1;
        withoutRankWithCompressed[i] = -1;
        rankWithoutCompressed[i] = -1;
        RankCompressed[i] = -1;
    }
    int wrwcVal = 0;
    int wrcVal = 0;
    int rwcVal = 0;
    int rcVal = 0;

    while (1)
    {
        char ch;
        scanf(" %c", &ch);
        if (ch == 'm')
        {
            int val;
            scanf("%d", &val);
            if (withoutRankWithoutCompressed[val] != -1)
                printf("-1\n");
            else
            {
                printf("%d\n", val);
                simpleMakeSet(val, withoutRankWithoutCompressed);
                simpleMakeSet(val, withoutRankWithCompressed);
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
                rankMakeSet(val, rankWithoutCompressed, rankWithoutCompressedRank);
                rankMakeSet(val, RankCompressed, rankCompressedRank);
            }
        }
        else if (ch == 'u')
        {
            int a, b;
            scanf("%d %d", &a, &b);
            if ((withoutRankWithoutCompressed[a] == -1) || (withoutRankWithoutCompressed[b] == -1))
                printf("-1\n");
            else
            {
                int p = simpleUnionSetsWithoutCompress(a, b, withoutRankWithoutCompressed, &wrwcVal);
                int q = simpleUnionSetsWithCompress(a, b, withoutRankWithCompressed, &wrcVal);
                int r = rankUnionSetsWithoutCompress(a, b, rankWithoutCompressed, rankWithoutCompressedRank, &rwcVal);
                int s = rankUnionSetsWithCompress(a, b, RankCompressed, rankCompressedRank, &rcVal);
                printf("%d %d %d %d\n", p, r, q, s);
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
        else if (ch == 'f')
        {
            int val;
            scanf("%d", &val);
            if (withoutRankWithoutCompressed[val] == -1)
                printf("-1\n");
            else
            {
                int p = simpleFindSet(val, withoutRankWithoutCompressed, &wrwcVal);
                int q = compressFindSet(val, withoutRankWithCompressed, &wrcVal);
                int r = simpleFindSet(val, rankWithoutCompressed, &rwcVal);
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
                int s = compressFindSet(val, RankCompressed, &rcVal);
                printf("%d %d %d %d\n", p, r, q, s);
            }
        }
        else
        {
            printf("%d %d %d %d\n", wrwcVal, rwcVal, wrcVal, rcVal);
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
    }
}