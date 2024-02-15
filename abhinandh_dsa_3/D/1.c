#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node *newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

int getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node *AVL_insert(Node *node, int key, int *ll, int *rr)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = AVL_insert(node->left, key, ll, rr);
    else if (key > node->key)
        node->right = AVL_insert(node->right, key, ll, rr);
    else
        return node;

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) {
        *rr += 1;
        return rightRotate(node);
    }
        

    if (balance < -1 && key > node->right->key) {
        *ll += 1;
        return leftRotate(node);
    }
        

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        *ll += 1;
        *rr += 1;
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        *ll += 1;
        *rr += 1;
        return leftRotate(node);
    }

    return node;
}

int search(Node* root, int key) 
{
    if (root == NULL) return 0;
    if (root->key == key) return 1;
    if (root->key < key) return search(root->right, key);
    return search(root->left, key);

}

void AVL_find(Node *root, int key)
{
    if (root == NULL) return;
    
    printf("%d ", root->key);

    if (root->key < key) AVL_find(root->right, key);
    else AVL_find(root->left, key);
}

void AVL_preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        AVL_preorder(root->left);
        AVL_preorder(root->right);
    }
}

void AVL_cal(Node *node)
{
    // if (node == NULL)
    //     return;

    // printf("%d %d ", getBalance(node->left), getBalance(node->right));

    // AVL_cal(node->left);
    // AVL_cal(node->right);
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    Node *root = NULL;
    char operation;
    int key;

    int ll = 0, rr = 0;

    while (1)
    {
        scanf("%c", &operation);

        if (operation == 'e')
        {
            break;
        }
        else if (operation == 'i')
        {
            scanf("%d", &key);
            root = AVL_insert(root, key, &ll, &rr);
        }
        else if (operation == 'x')
        {
            scanf("%d", &key);
            int result = search(root, key);


            if (result) {
                AVL_find(root, key);
                printf("\n");
            }
            else
                printf("-1\n");
        }
        else if (operation == 'p')
        {
            AVL_preorder(root);
            printf("\n");
        }
        else if (operation == 's')
        {
            AVL_cal(root);
            printf("%d %d\n", ll, rr);
        }
    }

    freeTree(root);

    return 0;
}
