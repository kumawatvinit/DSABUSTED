#include<bits/stdc++.h>
using namespace std;

int main()
{
    // creation
    // key, value pair
    unordered_map<string, int> m;

    // Insertion
    // 1
    pair<string, int> p = make_pair("babbar", 4);
    m.insert(p);

    // 2
    pair<string, int> p2("Love", 2);
    m.insert(p2);

    // 3
    m["mera"] = 1;

    // What will happen
    m["mera"] = 2;
    // New key will be assigned to the existing "key"
    // For a single "key", there will be unique value/ENTRY

    // Search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;

    // Accessing a key, that doesn't exist
    // cout << m.at("unknownkey") << endl;

    // A entry will be created with value 0
    cout << m["unknownkey"] << endl;

    // This will print 0, since entry has been created in last line
    cout << m.at("unknownkey") << endl;

    // size
    cout << m.size() << endl;

    // Check presence, 0, 1
    cout << "Count bro: " << m.count("bro") << endl;
    cout << "Count Love: " << m.count("Love") << endl;

    // erase
    m.erase("Love");
    cout << "After earsing Love, m.size: " << m.size() << endl;

    // Traversing
    cout << "------------\n";
    cout << "Traverse: " << endl;
    for(auto i:m)
    {
        cout << i.first << " " << i.second << endl;
    }

    // Using Iterator
    unordered_map<string, int> :: iterator it = m.begin();
    cout << "------------\n";
    cout << "Traverse using iterator" << endl;

    while(it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    cout << "------------\n";




    return 0;
}

/*
    Unordered_map
        Using HashTable
        Insertion, deletion, searching : O(1)

    map
        BST 
        O(logn)
    

    Hash function
        hash code : will give a index
        compression fn : make index within range
*/