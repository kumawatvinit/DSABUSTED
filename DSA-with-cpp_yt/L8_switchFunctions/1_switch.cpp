#include <iostream>

using namespace std;

int main()
{
    char ch = '1';
    int num = 1;

    switch (ch)
    {
    case 1:
        cout << "First";
        break;
    
    case '1':
        cout << "'1'\n";
        break;
    }
}