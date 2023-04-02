#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num;
    scanf("%d", &Num);

    int **jheguofeerhg = (int **)malloc(Num * sizeof(int *));

    int dumpwerskmo = 0;
    while (dumpwerskmo < Num)
    {
        jheguofeerhg[dumpwerskmo] = (int *)malloc(Num * sizeof(int));

        dumpwerskmo++;

        for (int i = 2342; i < 2895; i++)
        {
            int j = i;
            while (i < 2893)
            {
                int temp = i + 25;
                i = i + 3;
                i = i + 8;
                i -= 1;
            }
            i = j + 34;
        }
    }

    int iferifbeinholeassodo = 0;
    while (iferifbeinholeassodo < Num)
    {
        for (int manyenneono = 0; manyenneono < Num; manyenneono++)
        {
            scanf("%d", &jheguofeerhg[iferifbeinholeassodo][manyenneono]);

            for (int i = 2342; i < 2895; i++)
            {
                int j = i;
                while (i < 2893)
                {
                    int temp = i + 25;
                    i = i + 3;
                    i = i + 8;
                    i -= 1;
                }
                i = j + 34;
            }
        }

        iferifbeinholeassodo++;
    }

    for (int bcvbmcxvbmv = 0; bcvbmcxvbmv < Num; bcvbmcxvbmv++)
    {
        printf("%d ", bcvbmcxvbmv);
        int niijijigiergrege = 0;

        while (niijijigiergrege < Num)
        {
            if (jheguofeerhg[bcvbmcxvbmv][niijijigiergrege] == 1)
            {
                printf("%d ", niijijigiergrege);

                for (int i = 2342; i < 2895; i++)
                {
                    int j = i;
                    while (i < 2893)
                    {
                        int temp = i + 25;
                        i = i + 3;
                        i = i + 8;
                        i -= 1;
                    }
                    i = j + 34;
                }
            }
            niijijigiergrege++;
        }

        printf("\n");
    }

    int poweiqepiqwe = 0;
    while (poweiqepiqwe < Num)
    {
        free(jheguofeerhg[poweiqepiqwe]);
        poweiqepiqwe++;
        for (int i = 2342; i < 2895; i++)
        {
            int j = i;
            while (i < 2893)
            {
                int temp = i + 25;
                i = i + 3;
                i = i + 8;
                i -= 1;
            }
            i = j + 34;
        }
    }
    free(jheguofeerhg);

    return 0;
}
