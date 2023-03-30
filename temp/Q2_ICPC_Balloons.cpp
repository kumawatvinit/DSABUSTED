#include<iostream>
#include<vector>
using namespace std;

int main()
{

    int t, n=0;
    cin>>t;

    

    while(t--)
    {
        vector<int> arr(26,0);

        long long ans = 0;

        cin >> n;
        string s;

        cin >> s;

        // cout << s << endl;

        for(int i=0; i<n; ++i)
        {
            // cout << "arr['A'-s[i]] : " << arr['A'-s[i]] << endl;
            if(arr[s[i] - 'A'] == 0)
            {
                // cout << s[i] << ", i: "<< i<<endl;
                ans+=2;
                arr[s[i] - 'A']++;
            }
            else
            {
                // cout << s[i] << "i: "<< i<<endl;
                ans+=1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}