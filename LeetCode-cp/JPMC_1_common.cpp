#include<bits/stdc++.h>
using namespace std;


string getWinners(string colors)
{
    int n = 0, m = 0;
    int wcnt = 0, bcnt = 0;

    for(int i=1; i<colors.size(); i++)
    {
        if(colors[i] == colors[i-1])
        {
            if(colors[i] == 'w') {
                wcnt++;
            }
            else {
                bcnt++;
            }
        }
        else {
            if(wcnt>1) {
                n+= wcnt-1;
            }
            if(bcnt>1) {
                m+= bcnt-1;
            }

            wcnt = 0;
            bcnt = 0;
        }
    }

    if(wcnt > 1) {
        n+= wcnt-1;
    }
    if(bcnt>1) {
        m+= bcnt-1;
    }

    if(n>m)
    {
        return "wendy";
    }
    return "bob";
}


int main()
{
    // string s = "wwwbb";
    string s = "wwwbbbbwww";

    cout << getWinners(s);

    return 0;
}