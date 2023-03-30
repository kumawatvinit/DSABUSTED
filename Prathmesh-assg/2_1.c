#include<stdio.h>


int main()
{
    char arr[1001];

    scanf("%s", &arr);

    int temp[26] = {0};
    int i=0;

    while(arr[i] != '\0')
    {
        temp[arr[i]-'a']++;
        i++;
    }

    long int mul=1;
    for(i=0; i<26; i++)
    {
        if(temp[i]!=0)
        {
            mul*=temp[i];
        }
    }

    printf("%d", mul);
}