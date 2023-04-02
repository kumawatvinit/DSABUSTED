#include <stdio.h>
#include <stdlib.h>

int main()
{
    int TotalNumber;
    scanf("%d", &TotalNumber);

    int **adjacencyMatrixFromListmakeegregewrge = (int **)malloc(TotalNumber * sizeof(int *));
    for (int iteratorrr = 0; iteratorrr < TotalNumber; iteratorrr++)
    {
        adjacencyMatrixFromListmakeegregewrge[iteratorrr] = (int *)malloc(TotalNumber * sizeof(int));
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

    for (int iteratorrrrwrggreg = 0; iteratorrrrwrggreg < TotalNumber; iteratorrrrwrggreg++)
    {
        for (int jerktherkhgerg4 = 0; jerktherkhgerg4 < TotalNumber; jerktherkhgerg4++)
        {
            scanf("%d", &adjacencyMatrixFromListmakeegregewrge[iteratorrrrwrggreg][jerktherkhgerg4]);
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

    for (int ifsdugfkhrejhg = 0; ifsdugfkhrejhg < TotalNumber; ifsdugfkhrejhg++)
    {
        printf("%d ", ifsdugfkhrejhg);

        for (int jegbwuwebergnpiugnepnrgeergp = 0; jegbwuwebergnpiugnepnrgeergp < TotalNumber; jegbwuwebergnpiugnepnrgeergp++)
        {
            if (adjacencyMatrixFromListmakeegregewrge[ifsdugfkhrejhg][jegbwuwebergnpiugnepnrgeergp] == 1)
            {
                printf("%d ", jegbwuwebergnpiugnepnrgeergp);
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

        printf("\n");
    }

    // free the memory
    for (int irjghervwenfnncpwefwnfeiri = 0; irjghervwenfnncpwefwnfeiri < TotalNumber; irjghervwenfnncpwefwnfeiri++)
    {
        free(adjacencyMatrixFromListmakeegregewrge[irjghervwenfnncpwefwnfeiri]);
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
    free(adjacencyMatrixFromListmakeegregewrge);

    return 0;
}
