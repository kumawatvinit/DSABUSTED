#include<bits/stdc++.h>
using namespace std;

// /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// */

class Solution {
    void print(Node* head)
    {
        while(head) {
            cout << head->val << "\t";
            cout << head->next->val << "\n";

            head = head->next->next;
        }
    }

    void printLL(Node* head)
    {
        while(head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

public:
    Node* copyRandomList(Node* head) {
        Node* ans = head;
        Node* temp = head, *neww = NULL;
        
        // make new nodes, point their nexts to corresponding new node
        while(temp)
        {
            neww = new Node(temp->val);
            neww->next = temp->next;

            temp->next = neww;
            temp = neww->next;
        }
        //------done creating all nodes

        // print(head);

        temp = head;
        ans = head->next;
        neww = ans;

        // setting random pointers
        while(temp)
        {
            // set corresponding random pointer
            neww->random = temp->random? temp->random->next: NULL;

            // move
            temp = neww->next;
            neww->next = temp? temp->next: NULL;
        }

        temp = head;
        neww = head->next;
        // reset original LL
        while(temp)
        {
            temp->next = neww->next;
            temp = temp->next;

            neww->next = temp? temp->next: NULL;
            neww = neww->next;
        }

        printLL(head);
        printLL(ans);

        return ans;
    }
};

// [[7,null],[13,0],[11,4],[10,2],[1,0]]
Node* makeLL(Node* head)
{
    head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    return head;
}

void printLL(Node* head)
{
    while(head)
    {
        cout << head->val << ", Random: " << (head->random? head->random->val: 0) << endl;
        head = head->next;
    }
}


int main()
{
    Solution obj;
    Node* head;
    head = makeLL(head);
    // printLL(head);

    obj.copyRandomList(head);

    return 0;
}