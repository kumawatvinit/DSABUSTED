#include<bits/stdc++.h>

using namespace std;

char toLower(char ch)
{
    if(ch>='A' && ch<='Z') {
        ch+=32;
    }
    return ch;
}

// Decrypts the given ciphertext using the affine cipher with the given key
string affineDecrypt(const string& ciphertext, int a, int b) 
{

    // cout << a << ", b: " << b << endl << endl;
    // cout << ciphertext << endl;
  string plaintext;

  // Compute the modular inverse of a (the multiplicative inverse of a modulo 26)
  int a_inv = 0;
  for (int i = 0; i < 26; i++) {
    if ((a * i)%26 == 1) {
      a_inv = i;
      break;
    }
  }

    // cout << "a_inv: " << a_inv << " * ";

  // Decrypt each character of the ciphertext
  for (char c : ciphertext) {
    // Ignore non-alphabetic characters
    // if (!isalpha(c)) {
    //   plaintext += c;
    //   continue;
    // }

    // Decrypt the character
    char decrypted = (a_inv * (26 + toLower(c) - 'a' - b))%26 + 'A';
    // cout << "(toLower(c) - 'a' - b) : " << (toLower(c) - 'a' - b) << ", temp+'A' : " << (a_inv * (toLower(c) - 'a' - b))%26;
    // cout << ", " << decrypted << endl;
    plaintext += decrypted;
  }
    // cout << endl;
    // cout << plaintext << endl << endl;

  return plaintext;
}

int main()
{
    fstream input1, output1;
    string encrypted_msg;
    input1.open("file2.txt", ios::in);
    
    if(!input1)
    {
        cout << "No input file present of name file2.txt" << endl;
        return 0;
    } 
    else
    {
        char ch;
        while(1)
        {
            input1 >> ch;
            if(input1.eof()) {
                break;
            }
            encrypted_msg.push_back(ch);
        }
    }
    // cout << encrypted_msg << endl;


    int a[] = {1,3,5,7,9,11,15,17,19,21,23,25};
    int b[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    string plaintext;
    output1.open("output_file2_affine.txt",ios::out);

    for(int i=0; i<12; i++)
    {
        for(int j=0; j<26; j++)
        {
            plaintext = affineDecrypt(encrypted_msg, a[i], b[j]);

            output1 << plaintext << endl << endl;            
        }
    }
    input1.close();
    output1.close();

    return 0;
}