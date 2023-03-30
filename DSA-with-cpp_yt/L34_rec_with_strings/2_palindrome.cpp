#include<iostream>
using namespace std;

bool isPalindrome(string& s, int i)
{
    int n = s.size();

    if(i<n/2)
    {
        if(s[i]==s[n-1-i]) {
            return isPalindrome(s,i+1);
        }
        return false;
    }
    return true;
}

int main()
{
    string temp = "abbccbba";
    string temp2 = "bdddb";
    string temp3 = "bdbcb";

    if(isPalindrome(temp,0)) {
        cout << temp << " is a palindrome." << endl;
    } else {
        cout << temp << " is NOT a palindrome!" << endl;
    }
    
    if(isPalindrome(temp2,0)) {
        cout << temp2 << " is a palindrome." << endl;
    } else {
        cout << temp2 << " is NOT a palindrome!" << endl;
    }
    if(isPalindrome(temp3,0)) {
        cout << temp3 << " is a palindrome." << endl;
    } else {
        cout << temp3 << " is NOT a palindrome!" << endl;
    }


    return 0;
}