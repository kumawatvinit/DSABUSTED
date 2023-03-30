#include <stdio.h>
#include <stdlib.h>


struct node
{
    int key;
    char color; 
    struct node *left, *right, *parent;
};


struct node *CreateNode(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->color = 'R'; // New node is always red
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}


void rotateLeft(struct node **root, struct node *curr)
{
    struct node *y = curr->right;
    curr->right = y->left;
    if (y->left != NULL)
        y->left->parent = curr;
    y->parent = curr->parent;
    if (curr->parent == NULL)
        *root = y;
    else if (curr == curr->parent->left)
        curr->parent->left = y;
    else
        curr->parent->right = y;
    y->left = curr;
    curr->parent = y;
}

void rotateRight(struct node **root, struct node *curr)
{
    struct node *y = curr->left;
    curr->left = y->right;
    if (y->right != NULL)
        y->right->parent = curr;
    y->parent = curr->parent;
    if (curr->parent == NULL)
        *root = y;
    else if (curr == curr->parent->right)
        curr->parent->right = y;
    else
        curr->parent->left = y;
    y->right = curr;
    curr->parent = y;
}

void fixInsertion(struct node **root, struct node *z)
{
    while (z->parent != NULL && z->parent->color == 'R')
    {
        if (z->parent == z->parent->parent->left)
        {
            struct node *y = z->parent->parent->right;
            if (y != NULL && y->color == 'R')
            {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    rotateLeft(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rotateRight(root, z->parent->parent);
            }
        }
        else
        {
            struct node *y = z->parent->parent->left;
            if (y != NULL && y->color == 'R')
            {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rotateRight(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rotateLeft(root, z->parent->parent);
            }
        }
    }
    (*root)->color = 'B'; // Root is always black
}


void InsertRedBlack(struct node **root, int key)
{
    
    struct node *z = CreateNode(key);
    
    struct node *y = NULL;
    struct node *curr = *root;
    while (curr != NULL)
    {
        y = curr;
        if (z->key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    z->parent = y;
    if (y == NULL)
        *root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    // Fix violations caused by insertion
    fixInsertion(root, z);
}

void printPreorder(struct node *root)
{
    printf("( ");
    if (root != NULL)
    {
        printf("%d %c ", root->key, root->color);
        printPreorder(root->left);        
        printPreorder(root->right);
    }
    printf(") ");
}

int main()
{
    struct node *root = NULL;
    char ch;
    int key = 0;
    while(1)
    {
        if (scanf("%d", &key) == 1) {
            InsertRedBlack(&root, key);
            printPreorder(root);
            // printf("key:_%d_", key);
            printf("\n");
        } else if (scanf("%c", &ch) == 1) {
            
            // printf("Key:_%d_, ch:_%c_\n", key, ch);
            if (ch == 't') {
                break;
            }
        }
    }
    return 0;
}
