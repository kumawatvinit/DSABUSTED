// HILL CIPHER: 4*4
// key: CONNECTEDGRAPHIC

#include<bits/stdc++.h>
using namespace std;

string decrypt_hill_cipher(int secret_key[4][4], vector<int> cipher, int row)
{
    // check secret_key
    // cout << "secret key:\n";
    // for(int i=0; i<4; i++)
    // {
    //     for(int j=0; j<4; j++)
    //     {
    //         cout << secret_key[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;

    // cout << "cipher:\n";
    // for(auto i: cipher)
    // {
    //     cout << (char)(i+'A') << " ";
    // }
    // cout << endl << endl;
    // cout << "row: " << row << endl;

    int answer_matrix[row][4];
    string plaintext;
    int n = cipher.size();

    for(int i=0; i<=n-4; i+=4)
    {
        for(int j=0; j<4; j++)
        {
            answer_matrix[i/4][j] = cipher[i]*secret_key[0][j] + cipher[i+1]*secret_key[1][j] + cipher[i+2]*secret_key[2][j] + cipher[i+3]*secret_key[3][j];
            
            // cout << answer_matrix[i/4][j]  << endl;
            plaintext+= answer_matrix[i/4][j]%26 + 'A';
        }
    }

    // cout << plaintext;
    return plaintext;
}

int main()
{
    int secret_key[4][4] = {{24,18,20,15}, {5,3,21,11}, {19,1,4,20}, {16, 7, 10, 24}};
// File 1 contents:
// CCCYTWACWKYWSARTIBMHZAEKFGZPDGBFWKAFKELXCCGSDBTUBNLUGANEDJBRFDEOCCCYTMAKFBRYAOBUPHOFTWNP

    fstream input, output;
    string encrypted_msg;
    input.open("file1.txt", ios::in);
    
    if(!input)
    {
        cout << "No input file present of name file1.txt" << endl;
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
    output.open("output_file1_hill.txt",ios::out);

    vector<int> cipher;

    for(int i=0; i<encrypted_msg.size(); i++)
    {
        cipher.push_back(encrypted_msg[i]-'A');
    }

    int row = encrypted_msg.size()/4;
    
    string plaintext =  decrypt_hill_cipher(secret_key,cipher,row);

    output << plaintext; 

    input.close();
    output.close();

    return 0;
}