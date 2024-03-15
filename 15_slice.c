#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int min(int a, int b)
{
    if(a <= b) return a;
    return b;
}

void slice(char str[],int n,int m){
   
    int size = strlen(str);

    char newstr[100];
    int newSize = m-n+2;
    int index = 0;

    m = min(m, size-1);

    for(int i=n;i<=m;i++){
        newstr[index]=str[i];

        index++;

    }
    
    newstr[index]='\0';

    printf("Trimmed string: %s\n", newstr);    

}


char * sliceReturn(char *str,int n,int m){
   
    int size = strlen(str);

    // char newstr[100];
    int newSize = m-n+2;
    // char newStr[m-n+2];
    int index = 0;

    char * newstr  = (char *) malloc(newSize*sizeof(char));
    
    // Integer array
    // int arr[100];
    // int *arr = (int *) malloc(100 * sizeof(int));
    // char newstr[100];

    m = min(m, size-1);

    for(int i=n;i<=m;i++){
        newstr[index]=str[i];

        index++;

    }
    
    newstr[index]='\0';

    // printf("Trimmed string: %s\n", newstr);    
    return newstr;

}

int main(){
    
    int n,m;
    char str[100];
    
    
    printf("Enter the string\n");
    fgets(str,100,stdin);

    str[strlen(str)-1] = '\0';
    // printf("Size: %d, Input: %s", strlen(str), str);

    printf("Enter first index n: ");
    scanf("%d",&n);

    printf("Enter last index m: ");
    scanf("%d",&m);

    slice(str,n,m);
    printf("From return slice function: %s|", sliceReturn(str, n, m));
    

    return 0;
}