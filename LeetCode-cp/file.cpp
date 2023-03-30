#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, k, b;
    ll s;

    int q;
    cin >> q;

    while(q--)
    {
        cin >> n >> k >> b >> s;

        // ll *arr = new ll[n, 0];
        vector<ll> arr(n);


        if((s/k) >= b)
        {
            arr[0] = b*k + (((s-b*k)<=(k-1))? s-b*k: k-1);
            s-=arr[0];

            // cout <<"arr[0] : " << arr[0] << "|";

            int i=1;
            while(s>0 && i<n)
            {
                if(s >= (k-1))
                {
                    arr[i++] = k-1;
                }
                else {
                    arr[i++] = s;
                }

                s-= arr[i-1];
                // cout << "arr[" << i-1 << "] : " << arr[i-1] << "|";
            }

            if(s!=0) {
                cout << "-1" << endl;
            }
        }
        else
        {
            // cout << "n : " << n << ",k : " << k << ",b : " << b << ",s : " << s << ", s/k: " << s/k << ", b : " << b << ", s/k >= b" << (s/k >= b) << endl;

            cout << "-1" << endl;
        }

        if(s==0) {
            // cout << endl;
            for(int j=0; j<n; j++)
            {
                cout << arr[j]<< " ";
            }
            cout << endl;
        }
        // delete(arr);

        // cout << "\ns : " << s << endl;
    }

    return 0;
}