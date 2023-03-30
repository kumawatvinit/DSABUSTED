#include<iostream>
using namespace std;
#define  PI  3.1416
#define  AREA(r)  (PI*(r)*(r))

/*
    MACROS
    #define PI 3.14
*/

/*
    Inline functions
        Are used to reduce the function calls overhead
        // !slightly reduces performance
*/




void func(int a, int b)
{
    a++;
    b++;

    cout << a << " " << b << endl;
}


// Function-like Macro definition
#define min(a, b) (((a) < (b)) ? (a) : (b))

int score = 15;
// BAD Practice, anybody can change it

void a(int& i)
{
    cout << score << " in a" << endl;
    cout << i;
}


void b(int &i)
{
    cout << score << " in b" << endl;
    cout << i;
}

/*  function body:
1 Line:     compiler maan jaayega   (inline banaayega)
2 lines:    compiler ki marzi
>3 lines of code: bhaag ja yaha se

It replaces the code, wherever it is being used.
*/

inline int getMax(int& a, int& b)
{
    return (a>b)? a: b;
}

// Default argument
/*
    It starts from rightmost perimeter

    void print(int n=3, int* arr, int start=1)
     xxx NOT ALLOWED!!!

    void print(int* arr, int n=3, int start=1) 
    ALLOWED
*/
void print(int* arr, int n, int start=0)
{
    for( ; start<n; start++)
    {
        cout << arr[start] << " ";
    }
    cout << endl;
}

int main()
{
    /*
    cout << score << " in main" << endl;
    int i=5;

    // a(i);
    // b(i);

    int a=1, b=2;
    int ans=0;
    cout << a << " " << b;

    ans = getMax(a,b);

    a = a+3;
    b = b+1;

    ans = getMax(a,b);
    cout << a << " " << b;

    */

    int arr[5] = {1,4,7,8,9};
    print(arr, 5, 3);
    print(arr, 5);

    cout << "min of 34 and 23: " << min(34,23) << endl;

    cout << AREA(5) << endl;

    return 0;
}