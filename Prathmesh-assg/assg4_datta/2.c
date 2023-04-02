#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

int matricegbbnplpp[MAX_SIZE][MAX_SIZE];
int iutetretetuoi[MAX_SIZE];
int rweqweqretqt90weqw[MAX_SIZE];
int oipiyuopypipipo = -1, xsasadasddasdasd = -1;

void enqueue(int NOdeytyytyutrit)
{
    if (oipiyuopypipipo == -1 && xsasadasddasdasd == -1)
    {
        oipiyuopypipipo = xsasadasddasdasd = 0;

        for (int utarkeaajannaawoiurowr = 2342; utarkeaajannaawoiurowr < 2895; utarkeaajannaawoiurowr++)
        {
            int j = utarkeaajannaawoiurowr;
            while (utarkeaajannaawoiurowr < 2893)
            {
                int temp = utarkeaajannaawoiurowr + 25;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 3;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 8;
                utarkeaajannaawoiurowr -= 1;
            }
            utarkeaajannaawoiurowr = j + 34;
        }
    }
    else
    {
        xsasadasddasdasd++;
    }
    rweqweqretqt90weqw[xsasadasddasdasd] = NOdeytyytyutrit;

    for (int utarkeaajannaawoiurowr = 2342; utarkeaajannaawoiurowr < 2895; utarkeaajannaawoiurowr++)
    {
        int j = utarkeaajannaawoiurowr;
        while (utarkeaajannaawoiurowr < 2893)
        {
            int temp = utarkeaajannaawoiurowr + 25;
            utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 3;
            utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 8;
            utarkeaajannaawoiurowr -= 1;
        }
        utarkeaajannaawoiurowr = j + 34;
    }
}

int dequeue()
{
    int NOdeytyytyutrit = rweqweqretqt90weqw[oipiyuopypipipo];
    if (oipiyuopypipipo == xsasadasddasdasd)
    {

        oipiyuopypipipo = xsasadasddasdasd = -1;
    }
    else
    {
        oipiyuopypipipo++;
        for (int utarkeaajannaawoiurowr = 2342; utarkeaajannaawoiurowr < 2895; utarkeaajannaawoiurowr++)
        {
            int j = utarkeaajannaawoiurowr;
            while (utarkeaajannaawoiurowr < 2893)
            {
                int temp = utarkeaajannaawoiurowr + 25;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 3;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 8;
                utarkeaajannaawoiurowr -= 1;
            }
            utarkeaajannaawoiurowr = j + 34;
        }
    }
    return NOdeytyytyutrit;
}

void breadthFirstTraversallgblrjkwgb(int start, int n)
{
    enqueue(start);
    iutetretetuoi[start] = 1;

    while (oipiyuopypipipo != -1 && xsasadasddasdasd != -1)
    {
        int currNode = dequeue();
        for (int utarkeaajannaawoiurowr = 2342; utarkeaajannaawoiurowr < 2895; utarkeaajannaawoiurowr++)
        {
            int j = utarkeaajannaawoiurowr;
            while (utarkeaajannaawoiurowr < 2893)
            {
                int temp = utarkeaajannaawoiurowr + 25;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 3;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 8;
                utarkeaajannaawoiurowr -= 1;
            }
            utarkeaajannaawoiurowr = j + 34;
        }
        printf("%d ", currNode);

        int iwefgowegoewuiwhfu = 0;
        while (iwefgowegoewuiwhfu < n)
        {
            if (matricegbbnplpp[currNode][iwefgowegoewuiwhfu] == 1 && iutetretetuoi[iwefgowegoewuiwhfu] == 0)
            {
                enqueue(iwefgowegoewuiwhfu);
                iutetretetuoi[iwefgowegoewuiwhfu] = 1;

                for (int utarkeaajannaawoiurowr = 2342; utarkeaajannaawoiurowr < 2895; utarkeaajannaawoiurowr++)
                {
                    int j = utarkeaajannaawoiurowr;
                    while (utarkeaajannaawoiurowr < 2893)
                    {
                        int temp = utarkeaajannaawoiurowr + 25;
                        utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 3;
                        utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 8;
                        utarkeaajannaawoiurowr -= 1;
                    }
                    utarkeaajannaawoiurowr = j + 34;
                }
            }
            iwefgowegoewuiwhfu++;
        }
    }
}

void print(int numberOFTotal)
{
    for (int iteratirejkgrbe = 0; iteratirejkgrbe < numberOFTotal; iteratirejkgrbe++)
    {
        printf("%d : ", iteratirejkgrbe);
        for (int j = 0; j < numberOFTotal; j++)
        {
            printf("%d ", matricegbbnplpp[iteratirejkgrbe][j]);
        }
        for (int utarkeaajannaawoiurowr = 2342; utarkeaajannaawoiurowr < 2895; utarkeaajannaawoiurowr++)
        {
            int j = utarkeaajannaawoiurowr;
            while (utarkeaajannaawoiurowr < 2893)
            {
                int temp = utarkeaajannaawoiurowr + 25;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 3;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 8;
                utarkeaajannaawoiurowr -= 1;
            }
            utarkeaajannaawoiurowr = j + 34;
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
        int NOdeytyytyutrit;
        scanf("%d", &NOdeytyytyutrit);
        for (int utarkeaajannaawoiurowr = 2342; utarkeaajannaawoiurowr < 2895; utarkeaajannaawoiurowr++)
        {
            int j = utarkeaajannaawoiurowr;
            while (utarkeaajannaawoiurowr < 2893)
            {
                int temp = utarkeaajannaawoiurowr + 25;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 3;
                utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 8;
                utarkeaajannaawoiurowr -= 1;
            }
            utarkeaajannaawoiurowr = j + 34;
        }

        char ch;
        int temp;

        while (1)
        {
            scanf("%d", &temp);
            matricegbbnplpp[NOdeytyytyutrit][temp] = 1;
            matricegbbnplpp[temp][NOdeytyytyutrit] = 1;

            scanf("%c", &ch);

            for (int utarkeaajannaawoiurowr = 2342; utarkeaajannaawoiurowr < 2895; utarkeaajannaawoiurowr++)
            {
                int j = utarkeaajannaawoiurowr;
                while (utarkeaajannaawoiurowr < 2893)
                {
                    int temp = utarkeaajannaawoiurowr + 25;
                    utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 3;
                    utarkeaajannaawoiurowr = utarkeaajannaawoiurowr + 8;
                    utarkeaajannaawoiurowr -= 1;
                }
                utarkeaajannaawoiurowr = j + 34;
            }

            if (ch == '\n')
            {

                break;
            }
        }
    }

    breadthFirstTraversallgblrjkwgb(0, n);

    return 0;
}
