#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {4, 435, 654, 34};

/*
    cout << "Address of first memory block is : " << arr << endl;
    cout << "Address of first element is : " << &arr[0] << endl;

    cout << "arr[0] : " << arr[0] << endl;
    cout << "*arr : " << *arr << endl;

    cout << "*arr+1 : " << *arr+1<< endl;
    cout << "*(arr+1) : " << *(arr+1)<< endl;

    cout << "*: value at, &: address of" << endl;

    cout << "arr[2] : " << arr[2] << endl;
    cout << "*(arr+2) : " << *(arr+2) << endl;

    cout << "2[arr] : " << 2[arr] << endl;
    cout << "*(2+arr) : " << *(2+arr) << endl;

    cout << "memory accessing out of array, arr[11] : " << arr[11] << endl;
*/

/*
    cout << sizeof(arr) << endl;
    int *ptr = arr;
    // int *ptr = &arr[0];
    cout << sizeof(ptr) << endl;
    cout << sizeof(*ptr) << endl;
    cout << sizeof(&ptr) << endl;
*/
/*
    int a[20] = {1,2,3,4};

    cout << &a[0] << endl;
    cout << &a << endl;
    cout << a << endl;

    int *ptr = &a[0];
    cout << ptr << endl;
    cout << (*ptr) << endl;
    cout << (&ptr) << endl;
*/
    /*
        Symbol table
        like a, arr will be mapped to an address in symbol table.

        Symbol table ka content -> cannot be changed
        arr = arr+1 //Not possible

        but p = p+1 //Allowed
    */
   
    // Character array

    cout << arr << endl;

    char ch[6] = "abcde";
    // prints entire string
    cout << ch << endl;

    char *c = &ch[0];
    // prints entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp;

    cout << temp << endl;   // z
    cout << p << endl;  // zabcde, it's stopping when it is getting null character

    

    return 0;
}