#include<iostream>
using namespace std;

class BtreeNode
{
    int *keys;
    int n;
    int t;
    BtreeNode** C;
    bool leaf;

public:
    BtreeNode(int _t, bool _leaf) {
        t = _t;
        leaf = _leaf;
        
        keys = new int[2*t-1];
        C = new BtreeNode* [2*t];

        n=0;
    }

    void traverse()
    {
        int i=0;

        for(i=0; i<n; i++)
        {
            if(leaf==false) {
                C[i]->traverse();
            }
            cout << keys[i] << " ";
        }

        if(leaf==false) {
            C[i]->traverse();
        }
    }

    BtreeNode* search(int k)
    {
        int i=0;

        while(i<n && k>keys[i]) {
            i++;
        }
        if(i<n && k==keys[i]) {
            return this;
        }

        if(leaf==false) {
            return C[i]->search(k);
        }
        else {
            return NULL;
        }
    }

    void insertNonFull(int k);
    void splitChild(int i, BtreeNode *y);

    friend class Btree;
};

class Btree 
{   
    BtreeNode* root;
    int t;

public:

    Btree(int _t)
    {
        root = NULL;
        t = _t;
    }

    void traverse()
    {
        if(root)
        {
            root->traverse();
        }
    }

    BtreeNode* search(int k)
    {
        return (root? root->search(k) : NULL);
    }

    void insert(int k);
    
};

void BtreeNode:: insertNonFull(int k)
{
    int i=n-1;
    // if leaf node, 
        // then shifts keys to right 
        // insert
        // n++
    if(leaf)
    {
        while(i>=0 && keys[i]>k) {
            keys[i+1] = keys[i];
            i--;
        }

        keys[i+1] = k;
        n++;
    }

    // else 
    // check which child to go in
        // if C[i] is full 
            //  split
            // then select correct child
        
        // insert 
    else 
    {
        while(i>=0 && keys[i]>k) {
            i--;
        }

        if(C[i+1]->n == 2*t-1)
        {
            splitChild(i+1, C[i+1]);

            if(keys[i+1] < k){
                i++;
            }
        }

        C[i+1]->insertNonFull(k);
    }
}

void BtreeNode:: splitChild(int i, BtreeNode* y)
{
    BtreeNode* z = new BtreeNode(y->t, y->leaf);
    z->n = t-1;

    // copy keys
    for(int j=0; j<t-1; j++) {
        z->keys[j] = y->keys[j+t];
    }

    // copy children's
    if(leaf==false) 
    {
        for(int j=0; j<t; j++) {
            z->C[j] = y->C[j+t];
        }
    }

    // reduce y->n
    y->n = t-1;

    // shift keys of curr node by 1
    for(int j=n-1; j>=i; j--) {
        keys[j+1] = keys[j];
    }

    // move child's too
    for(int j=n; j>=i+1; j--) {
        C[j+1] = C[j];
    }

    // move one key up
    keys[i] = y->keys[t-1];

    // make z, child of this
    C[i+1] = z;

    // increase count of keys
    n++;

}

void Btree:: insert(int k)
{
    // if root is null
    if(root == NULL)
    {
        root = new BtreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
        
    }
    else 
    {
        // root is full
        // then split, make new nodes, connect, set evrything
        if(root->n == 2*t-1)
        {
            BtreeNode *s = new BtreeNode(t, false);
            s->C[0] = root;

            s->splitChild(0, root);

            /*
              []
            []  []
            */
           
            // which child to go in
            int i=0;
            if(s->keys[0] < k) {
                i++;
            }
            s->C[i]->insertNonFull(k);

            root = s;
        }

        // else simply insert
        else {
            root->insertNonFull(k);
        }
    }

}

int main()
{
    Btree t(3);
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);
    t.insert(70);
    t.insert(80);
    t.insert(90);
    t.insert(110);
    t.insert(120);
    t.insert(130);
    t.insert(140);
    t.insert(150);
    t.insert(160);

    cout << "Print: ";
    t.traverse();
    cout << endl;

    cout << "110: ";
    if(t.search(110)) {
        cout << "Present" << endl;
    }
    else {
        cout << "Absent" << endl;
    }

    cout << "175: ";
    if(t.search(175)) {
        cout << "Present" << endl;
    }
    else {
        cout << "Absent" << endl;
    }




    return 0;
}