#include<iostream>
using namespace std;

// Warning/Error: BAD practice
int& func(int a)
{
    int num = a;

    int &ans = num;

    return ans;
}

void update(int &n)
{
    n++;
}

int main()
{
    /*
    int i=5;

    int &j = i;

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl; 
    
    // /

    int n=6;
    cout << "Before " << n << endl;
    update(n);
    cout << "After " << n << endl;

    cout << func(5);

    // /*
        int n;
        cin >> n;

        int arr[n];
        BAD Practice!!!

        Size we will get to know at run time, we should have it at compile time
        This arr[n] memory will be allotted in stack not in heap

        But system don't know, how much memory is needed at compile time, then it may crash at run time
    // /

    int k;
    cin >> k;
    int* arr = new int[k];

    cout << "arr : " << arr << endl;
    cout << "&arr : " << &arr << endl;
    cout << "&arr[0] : " << &arr[0] << endl;

    int a[5];
    cout << "a : " << a << endl;
    cout << "&a : " << &a << endl;
    cout << "&a[0] : " << &a[0] << endl;
*/
    // case 1
   /* while (true)
    {
        int* m = new int;
        // Allocating 4+8 bytes of memory,
        // releasing 8 bytes every time, but heap memory isn't freed
        // after some time heap memory will be full...ERROR
    }
    */
    // case 2
    while (true)
    {
        int k = 6;
        // Creating and realising/freeing memory every time.
        // so for an instance,only 4byte is allocated in stack
    }
    


    return 0;
}