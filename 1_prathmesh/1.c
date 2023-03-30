#include<stdio.h>

long long POWER(int a, int b)
{
    long long ans=1;

    while(b--)
    {
        ans*= a;
    }

    return ans;
}

long long calculate(int a, int e)
{
    long long ans=0;

    while(a>0)
    {
        // printf("a: %d, e: %d, %d\n", a, e, POWER(a%10, e));
        ans+=POWER(a%10, e);
        a=a/10;
    }

    // printf("%d\n", ans);
    return ans;
}

int main()
{
    int n=0;
    int e=0;

    scanf("%d%d", &n, &e);

    // printf("%d\n", POWER(8, 5));
    // printf("%d\n", POWER(6, 5));
    // printf("%d\n", pow_ab(8, 5)+pow_ab(6, 5));
    printf("%lld\n", calculate(n, e));

    return 0;
}