#include<stdio.h>
#include<stdlib.h>

int main()
{

    int n, k, x;

    scanf("%d%d",&n, &k);

    int *arr = (int *)malloc(n*sizeof(int));

    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    } 

    scanf("%d",&x);
    int count=0;

    for(int i=0; i<n; i+=k)
    {
        for(int j=i; j<i+k; j++)
        {
            if(arr[j]==x)
            {
                count++;
                break;
            }
        }
    }

    printf("%d", count);

    return 0;
}