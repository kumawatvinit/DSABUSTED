// For VIGENERE CIPHER:
// secret_key: INTEGRITY

#include<bits/stdc++.h>
using namespace std;


string decrypt(const string& encrypted_message, const string& secret_key)
{
    string plaintext = "";

    for (int i = 0; i < encrypted_message.size(); i++) {
        
        int temp = (encrypted_message[i] - secret_key[i % secret_key.size()] + 26)%26;
        plaintext += (temp + 'A');
    }

    return plaintext;
}

int main()
{
    fstream input, output;
    string encrypted_msg;
    input.open("file3.txt", ios::in);
    
    if(!input)
    {
        cout << "No input file present of name file2.txt" << endl;
        return 0;
    } 
    else
    {
        char ch;
        while(1)
        {
            input >> ch;
            if(input.eof()) {
                break;
            }
            encrypted_msg.push_back(ch);
        }
    }

    string plaintext;
    string secret_key = "INTEGRITY";
    output.open("output_file3_vigenere.txt",ios::out);

    plaintext =  decrypt(encrypted_msg, secret_key);

    output << plaintext; 

    input.close();
    output.close();

    return 0;
}