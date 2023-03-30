#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char** a, char** b)
{
    char *t = *a;
    *a = *b;
    *b = t;
}

int compareStrings(char* a, char* b)    // a<b|| =>1, a>b=>0
{
    int i=0;

    while(1)
    {
        if(a[i]<b[i] || a[i]=='\0') return 1;
        else if(a[i]>b[i] || b[i]=='\0') return 0;

        i++;
        // j++;
    }

    return 1;
}

void sortNames(char ** arr, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(compareStrings(arr[i], arr[j]) == 0) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void printNames(char** arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%s\n", arr[i]);
    }
}

int main()
{
    int n, size=1000;
    scanf("%d\n", &n);

    char* *arr = (char * *)malloc(n*sizeof(char *));

    for(int i=0; i<n; i++)
    {
        arr[i] = (char *)malloc(size*sizeof(char));
    }

    int j=0;
    for(int i=0; i<n; i++)
    {
        fgets(arr[i], size, stdin);
        int ww = strlen(arr[i]);
        arr[i][ww-1] = '\0';
        // j=0;
        // while(arr[i][j]!='\n') j++;

        // arr[j-1] = '\0';
    }

    // printf("Before...\n\n");
    // printNames(arr, n);

    sortNames(arr,n);

    // printf("After...\n\n");
    printNames(arr, n);

    return 0;
}

/*
5
Manoj Kumar
Ranjan Ram
Alok Ravi
Akash Singh
Alan Thomas
*/