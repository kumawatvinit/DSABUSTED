#include<iostream>
using namespace std;

char * initializeINTAL()
{
    char* arr = (char *)malloc(1001*sizeof(char));

    for(int i=0; i<1001; i++) {
        arr[i] = '0';
    }
    arr[1000] = '\0';

    return arr;
}

int compareINTAL(char* a, char* b)
{
    int a_size = 0, b_size = 0, i = 0;

    while(a[i] == '0') i++;

    while(a[i++] != '\0') {
        a_size++;
    }
    i=0;
    while(b[i] == '0') i++;

    while(b[i++] != '\0') {
        b_size++;
    }

    if(a_size > b_size) {
        return 1;
    }
    else if(a_size < b_size) {
        return -1;
    }

    // Moving i to non-zero character, remember a_size and b_size are equal
    i=0;
    int j=0;
    while(a[i] == '0') i++;
    while(a[j] == '0') j++;

    while(i<a_size && j<a_size)
    {
        if(a[i]>b[j]) {
            return 1;
        }
        else if(a[i]<b[j]) {
            return -1;
        }
        i++;
    }

    return 0;
}

char* addINTALs(char* a, char* b)
{
    int a_size = 0, b_size = 0, i = 0, j=0;

    while(a[i++] != '\0');
    a_size = i-1;
    i=0;
    while(b[i++] != '\0');
    b_size = i-1;

    i = a_size-1, j = b_size-1;

    // int size = (a_size>b_size)? a_size: b_size;
    int size = 1000;
    char* result = initializeINTAL();
    // char* result = (char *)malloc((size+2)*sizeof(char));
    
    // size++;
    int k = size-1;
    // result[k--] = '\0';
    int carry=0, sum=0;
    int ap = 0, bp = 0;

    while(k >= 0)
    {
        if(i>=0)
        ap = a[i--] - '0';
        else ap = 0;
        if(j>=0)
        bp = b[j--] - '0';
        else bp = 0;

        
        sum = ap + bp + carry;

        result[k--] = sum%10 + '0';
        carry = sum/10;
    }
    // result[k] = '\0';

    // while(*result == '0')
    // result++;
    return result;
}

char* subINTALs(char* a, char* b)
{
    if(compareINTAL(a,b)==-1)
    swap(a,b);
    
    else if(compareINTAL(a,b)==0) {
        char* result = (char *)malloc(2*sizeof(char));
        result[0] = '0';
        result[1] = '\0';

        return result;
    }
    
    int ap=0, bp=0, i=0;
    
    while(a[i++] != '\0');
    int a_size = i-1;
     
    i=0;
    while(b[i++] != '\0');
    int b_size = i-1;

    char* result = (char *)malloc((a_size+1)*sizeof(char));

    i = a_size-1;
    int k = a_size, j=b_size-1, sub=0, borrow = 0;
    result[k--] = '\0';

    while(i>=0)
    {
        if(i>=0)
        ap = a[i--] - '0';
        else ap = 0;
        if(j>=0)
        bp = b[j--] - '0';
        else bp = 0;

        if(borrow) {
            if(ap==0) ap = 9;
            else {
                ap--;
                borrow=0;
            }
        }

        if(ap<bp) {
            borrow=1;
            ap = ap + borrow*10;
        }

        sub = ap-bp;

        result[k--] = sub + '0';
    }
     
    
    while(*result == '0')
    result++;

    if(*result == '\0') result--;
    return result;
}

int size_no(char *a)
{
    int i=0;
    while(a[i++]!='\0');

    return i-1;
}

char * mulINTALS(char* a, char *b) 
{
    char* result = initializeINTAL();

    // If a=0
    while(a[0]=='0') a++;
    if(a[0]=='\0') {
        result[0] = '0';
        result[1] = '\0';

        return result;
    }
    
    // If a=0
    while(b[0]=='0') b++;
    if(b[0]=='\0') {
        result[0] = '0';
        result[1] = '\0';

        return result;
    }

    // If one of them is 1, then return other
    if(a[0]=='1' && a[1]=='\0') return b;
    if(b[0]=='1' && b[1]=='\0') return a;

    int a_size = size_no(a);
    int b_size = size_no(b);

    if(a_size<b_size) {
        swap(a,b);
        swap(a_size, b_size);
    }

    int i = a_size-1, j = b_size-1, k = 999, mul=0, carry=0;
    

    while(j>=0)
    {
        k = 999 - (b_size-1-j);
        carry=0;
        i = a_size-1;
        while(i>=0)
        {
            mul = (a[i]-'0')*(b[j]-'0') + carry + result[k] - '0';
            carry = mul/10;


            result[k] = (mul%10) + '0';
            k--;
            i--;
        }

        while(carry)
        {
            result[k--] = (carry%10) + '0';
            carry/=10;
        }
        j--;
    }

    while(*result == '0')
    result++;

    if(*result == '\0') result--;

    return result;
}

char* fibonacciINTAL(unsigned int n)
{
    char* a = initializeINTAL();
    a[0] = '0'; a[1] = '\0';

    char* b = initializeINTAL();
    b[0] = '1'; b[1] = '\0';

    if(n<1) {
        cout << "Enter value greater than ";
        return a;
    }
    if(n==1) return a;
    if(n==2) return b;

    char* temp = initializeINTAL();
    
    for(int i=3; i<=n; i++)
    {
        temp = addINTALs(a,b);
        free(a);

        a = b;
        b = temp;
    }

    free(a);
    return b;
}

void printINTAL(char *ans)
{
    while(*ans == '0')
    ans++;

    if(*ans == '\0') ans--;

    // cout << ans << ", size: " << size_no(ans) << endl;
    cout << ans << endl;
}

char* char_n(int n)
{
    char* ans = initializeINTAL();
    int i = 999;

    while(n>0)
    {
        ans[i--] = n%10 + '0';
        n/=10;
    }

    return ans;
}

char* factorialINTAL(unsigned int n)
{
    char* result = initializeINTAL();
    result[999] = '1';

    if(n==0 || n==1) {
        return result;
    }

/*
    char* num = initializeINTAL();
    num[999] = '1';

    char* temp;
    char* tmp = initializeINTAL();
    tmp[999] = '1';

    // cout << "result :";
    // printINTAL(result);
    // cout << "num :";
    // printINTAL(num);
    // cout << "tmp :";
    // printINTAL(tmp);
    // cout << "\n\n";

    for(int i=2; i<=n; i++)
    {
        temp = addINTALs(num, tmp);
        // cout <<"temp : ";
        // printINTAL(temp);
        // cout << ", ";

        num = temp;
        // cout <<"num : ";
        // printINTAL(num);
        // cout << ", ";
        temp = mulINTALS(num, result);

        free(result);

        result = temp;
        // cout <<"result : ";
        // printINTAL(result);
        // cout << ", ";
    }

    free(num);
    return result;
    */

    return mulINTALS(factorialINTAL(n-1),char_n(n));
}

int main()
{
    char *ch = initializeINTAL();

    // cout << ch << endl;

    char a[] = {'1', '9', '3', '\0'};
    char b[] = {'2', '3', '\0'};

    char c[] = {'2','2','3','\0'};
    char d[] = {'0','1','2','3','\0'};
    char e[] = {'3','1','0','3','\0'};
    char f[] = {'1','0','9','\0'};
    char g[] = {'9','\0'};

    char A[] = {'1','0','0','0','\0'};
    char B[] = {'1','\0'};
    char C[] = {'0','0','0','\0'};
    char D[] = {'0','\0'};

    char big[] = {'3','1','0','3','4','1','0','2','3','1','6','2','3','9','2','3','5','1','4','7','\0'};
    char small[] = {'7','4','1','3','9','1','0','3','3','1','6','2','3','9','2','3','5','1','4','7','\0'};

    
// /*
    cout << "1 : ";
    printINTAL(factorialINTAL(1));
    cout << "2 : ";
    printINTAL(factorialINTAL(2));
    cout << "4 : ";
    printINTAL(factorialINTAL(4));
    cout << "5 : ";
    printINTAL(factorialINTAL(5));
    cout << "10 : ";
    printINTAL(factorialINTAL(10));

    // char m[] = {'1', '2', '\0'};
    // char n[] = {'1', '3', '\0'};

    // cout << mulINTALS(factorialINTAL(11),n) << endl;

    cout << "12 : ";
    printINTAL(factorialINTAL(12));
    cout << "13 : ";
    printINTAL(factorialINTAL(14));
    cout << "15 : ";
    printINTAL(factorialINTAL(15));
    cout << "50 : ";
    printINTAL(factorialINTAL(50));
    cout << "100 : ";
    printINTAL(factorialINTAL(100));
    cout << "150 : ";
    printINTAL(factorialINTAL(150));

/*
    cout << endl << endl;
    cout << "0 : ";
    printINTAL(fibonacciINTAL(0));
    cout << "1 : ";
    printINTAL(fibonacciINTAL(1)) ;
    cout << "2 : ";
    printINTAL(fibonacciINTAL(2)) ;
    cout << "3 : ";
    printINTAL(fibonacciINTAL(3)) ;
    cout << "4 : ";
    printINTAL(fibonacciINTAL(4)) ;
    cout << "5 : ";
    printINTAL(fibonacciINTAL(5)) ;
    cout << "6 : ";
    printINTAL(fibonacciINTAL(6)) ;
    cout << "7 : ";
    printINTAL(fibonacciINTAL(7)) ;
    cout << "8 : ";
    printINTAL(fibonacciINTAL(8)) ;
    cout << "9 : ";
    printINTAL(fibonacciINTAL(9)) ;
    cout << "10 : ";
    printINTAL(fibonacciINTAL(10));
    cout << "45 : ";
    printINTAL(fibonacciINTAL(45));
    cout << "102 : ";
    printINTAL(fibonacciINTAL(102));
    cout << "103 : ";
    printINTAL(fibonacciINTAL(103));
    cout << "459 : ";
    printINTAL(fibonacciINTAL(459));
    cout << "460 : ";
    printINTAL(fibonacciINTAL(460));
    cout << "500 : ";
    printINTAL(fibonacciINTAL(500));
    cout << "983 : ";
    printINTAL(fibonacciINTAL(983));

// /*
    cout << endl << endl;
    cout << A << "x" << B << ": " << mulINTALS(A,B) << endl;
    cout << f << "x" << g << ": " << mulINTALS(f,g) << endl;
    cout << a << "x" << b << ": " << mulINTALS(a,b) << endl;
    cout << a << "x" << d << ": " << mulINTALS(a,d) << endl;
    cout << c << "x" << d << ": " << mulINTALS(c,d) << endl;
    cout << A << "x" << C << ": " << mulINTALS(A,C) << endl;
    cout << B << "x" << C << ": " << mulINTALS(B,C) << endl;
    cout << C << "x" << D << ": " << mulINTALS(D,C) << endl << endl;

    cout << big << "x" << small << ": " << mulINTALS(big,small) << endl;

// /*
    cout << a << ", " << b << "-> " << compareINTAL(a,b) << endl;
    cout << a << ", " << d << "-> " << compareINTAL(a,d) << endl;
    cout << c << ", " << d << "-> " << compareINTAL(c,d) << endl;
    cout << d << ", " << c << "-> " << compareINTAL(d,c) << endl;



    cout << c << " + " << d << ": " << addINTALs(c,d) << endl;
    cout << c << " + " << a << ": " << addINTALs(c,a) << endl;
    cout << a << " + " << b << ": " << addINTALs(b,a) << endl;


    cout << endl << c << " - " << d << ": " << subINTALs(c,d) << endl;
    cout << c << " - " << a << ": " << subINTALs(c,a) << endl;
    cout << a << " - " << b << ": " << subINTALs(a,b) << endl;
    cout << b << " - " << a << ": " << subINTALs(b,a) << endl;
    cout << e << " - " << f << ": " << subINTALs(e,f) << endl;
    cout << e << " - " << g << ": " << subINTALs(e,g) << endl;

    cout << endl << A << " - " << B << ": " << subINTALs(A,B) << endl;
    cout << A << " - " << A << ": " << subINTALs(A,A) << endl;
*/

    return 0;
}