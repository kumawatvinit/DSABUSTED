#include <iostream>

using namespace std;

int main()
{
    int amount=0;
    int rs100=0, rs20=0, rs1=0;

    cout << "Enter total amount : ";
    cin >> amount;

    switch (1)
    {
    case 1:
        rs100 = amount/100;
        amount%=100;
        cout << "100 Rupee notes : " << rs100 << endl;
    
    case 2:
        rs20 = amount/20;
        amount%=20;
        cout << "20 Rupee notes : " << rs20 << endl;

    case 3:
        rs1 = amount;
        cout << "1 Rupee notes : " << rs1 << endl;
    }

}