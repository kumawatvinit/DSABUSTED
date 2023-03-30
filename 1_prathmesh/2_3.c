#include<stdio.h>
#include<stdlib.h>

// arr[i]: [-1000, 1000]

int main()
{
    int n;

    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));

    int max1 = -10000, max2 = -10001;

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);

        if(arr[i]>max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(max2!=-10000 && arr[i]>max2)
        {
            max2 = arr[i];
        }
    }

    // printing all numbers except second largest element

    for(int i=0; i<n; i++)
    {
        if(arr[i] != max2)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}