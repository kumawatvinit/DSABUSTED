#include<iostream>
using namespace std;

int main()
{
    /*
1.  NULL Pointers
        Pointer that is pointing to nothing, if we don't have 
        the address to be assigned to a pointer, we can use NULL

        e.g. int *p = NULL

2.  Double Pointers
        Pointer to a pointer

        e.g. int a=10;
            int *p = &a;
            int **q =&p;

3.  Void Pointers
        A generic pointer, it has no associated type with it.
        A void pointer can hold an address of any type and can 
        be typecasted to any type.
        It Can't be dereferenced, can be done using typecasting

        e.g. void *p;
        int i = 10;
        p = &i;


4.  Wild Pointers
        A pointer behaves like a wild pointer when declared but 
        not initialized. So they point to random memory location.

        e.g. int *ptr;


5.  Dangling Pointers
        Pointer pointing to a memory location that has been freed(or deleted)

    a) Function call
        int *fun() {
            int x = 10;
            return &x;
        }
        void main() {
            int *p = fun();
            // p points to something which is not valid anymore
        }

    b) Deallocation of memory

        int *p = (int *)malloc(sizeof(int));
        free(p);
        // p became dangling pointer

        p = NULL; // p is no more dangling

    c) Variable goes out of scope

        int *ptr;
        ....some code
        {
            int ch;
            ptr = &ch;
        }
        ...
        // Ptr is dangling pointer now
    */

/*
    int *p = 0;
    int a = 10;
    *p = a;
    // Error, assigning 10 to location 0, which may or may not exist!
    cout << *p << endl;
*/
/*
    int b[] = {1,2,3,4};
    int *q = b;  
    
    // int *q = b++;
    // expression must be a modifiable lvalue
    

    cout << *q << endl;
*/

    char b[] = "xyz";
    char *c = &b[0];

    cout << c << endl;
    // c stores the starting address of array b(not of it's values)
    // so the entire array will be printed.

    return 0;
}