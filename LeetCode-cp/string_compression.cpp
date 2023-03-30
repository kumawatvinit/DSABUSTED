#include<bits/stdc++.h>
using namespace std;

string getCompressedString(string &input) {
    int i=0, itr = 1;
    int count = 1;
    int size = input.size();
    string ans;
    ans+=input[i];
    
    while(itr < size)
    {
        if(input[i] == input[itr]) {
            count++;
        }
        else {
            if(count > 1) {
                input[++i] = char(count + '0');
                ans+=input[i];
                count = 1;
            }
            
            input[++i] = input[itr];
            ans+=input[i];
        }
        itr++;
    }
    if(count > 1) {
        input[++i] = char(count + '0');
        ans+=input[i];
    }
    
    input[++i] = '\0';
    // ans+= "\0";
    // string ans;

    return ans;
    
    // return input;
}

int main()
{
    string str = "aaabbcddeeeee";
    cout << getCompressedString(str) << endl;
    cout << str << endl;

    return 0;
}