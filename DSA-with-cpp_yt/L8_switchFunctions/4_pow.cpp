#include <iostream>

using namespace std;

int power(int a, int b)
{
    int ans=1;

    for(int i=0; i<b; i++)
    ans*=a;

    return ans;
}

int main()
{
    // pow(a,b)

    int a, b, ans=1;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;

    cout << "pow(a,b) : " << power(a,b) << endl;
}
