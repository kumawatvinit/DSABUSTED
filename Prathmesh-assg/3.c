#include<stdio.h>
#include<stdlib.h>

void lower(char *arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        if(arr[i]>='A' && arr[i]<='Z')
        {
            arr[i]+=32;
        }
    }
}

void palindrome(char *arr, int n)
{
    for(int i=0; i<n/2; ++i)
    {
        if(arr[i] != arr[n-1-i])
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main()
{

    char arr[10000];

    scanf("%[^\n]s", &arr);

    int i=0;
    while(arr[i]!='\0' && arr[i]!='\n')
    {
        i++;
    }

    lower(arr, i);
    palindrome(arr, i);
    
    return 0;
}