#include<stdio.h>
#include<stdlib.h>

void rotation(int *arr, int n)
{
    int temp = arr[0];

    for(int i=0; i<n-1; ++i)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

int main()
{

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    for(int i=0; i<n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int m;
    scanf("%d", &m);

    while(m--)
    {
        rotation(arr,n);
    }

    for(int i=0; i<n; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}