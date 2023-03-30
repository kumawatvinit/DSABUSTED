#include<iostream>
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        
        int month = (date[5] - '0')*10 + date[6] - '0';
        int dt = (date[8]-'0')*10 + date[9]-'0';
        int year = (date[2]-'0')*10+(date[3]-'0');
        
        int ans = 0 ;
        
        if(month<=2) {
            ans = (month-1)*31 + dt;
        }
        else if(month<=8) {
            month-=3;
            int _31 = month/2 + month%2==1?1:0;
            int _30 = month - _31;
            
            ans  = 31+((year%4==0)?29: 28) + _31*31 + _30*30+dt;
        } else {
            month-=3;
            int _31 = month/2 + month%2==1?1:0;
            int _30 = month - _31;
            
            ans  = 31+((year%4==0)?29: 28) + _31*31 + _30*30+dt;
            
            month+= 3 - 7;
            _31 = month/2 + month%2==1?1:0;
            _30 = month - _31;
            
            ans+= _31*31 + _30*30;
        }
        
        return ans;
        
        
    }
};

int main()
{
    string str;
    // cout << "Enter date: ";
    cin >> str;

    Solution obj;

    cout << obj.dayOfYear(str) << endl;

    return 0;
}
/*
"2019-01-09"
"2019-02-10"
"2019-03-10"
"2019-05-10"
"2019-07-10"
"2019-08-10"
"2019-09-10"
"2019-12-10"
"2012-02-10"
"2008-12-10"
"2016-08-10"
"2016-09-10"
*/