#include <stdio.h>
#include <stdlib.h>

typedef struct AVLTree
{
    int key, value;
    struct AVLTree *left;
    struct AVLTree *right;
    int height;
} AVLTree;

AVLTree *newNode(int key, int value)
{
    AVLTree *node = (AVLTree *)malloc(sizeof(AVLTree));
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int height(AVLTree *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

AVLTree *rightRotate(AVLTree *y)
{
    AVLTree *x = y->left;
    AVLTree *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

AVLTree *leftRotate(AVLTree *x)
{
    AVLTree *y = x->right;
    AVLTree *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

int getBalance(AVLTree *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

AVLTree *insert(AVLTree *node, int key, int value)
{
    if (node == NULL)
        return newNode(key, value);

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else
    {
        node->value = value;
        return node;
    }

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int find(AVLTree *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->key == key)
    {
        printf("%d %d\n", root->key, root->value);
        return 1;
    }
    if (root->key < key)
        return find(root->right, key);
    else
        return find(root->left, key);
}

int printElements(AVLTree *root)
{
    if (root != NULL)
    {
        printElements(root->left);
        printf("%d ", root->key);
        printElements(root->right);
        return 1;
    }

    return 0;
}

int empty(AVLTree *root)
{
    if (root == NULL)
        return 1;
    return 0;
}

int size(AVLTree *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

void lower_bound(AVLTree *root, int key)
{
    // print a single (key-value) pair with smallest key greater than or equal to key
    // otherswise print -1

    AVLTree *current = root;
    AVLTree *successor = NULL;

    while (current != NULL)
    {
        if (current->key >= key)
        {
            successor = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (successor != NULL)
    {
        printf("%d %d\n", successor->key, successor->value);
    }
    else
    {
        printf("-1\n");
    }
}

void freeTree(AVLTree *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    AVLTree *root = NULL;
    char operation;
    int key, value;

    while (1)
    {
        scanf("%c", &operation);

        if (operation == 't')
        {
            break;
        }
        else if (operation == 'i')
        {
            scanf("%d%d", &key, &value);
            root = insert(root, key, value);
        }
        else if (operation == 'l')
        {
            scanf("%d", &key);
            lower_bound(root, key);
        }
        else if (operation == 'f')
        {
            scanf("%d", &key);
            int result = find(root, key);

            if (!result)
                printf("-1\n");
        }
        else if (operation == 's')
        {
            printf("%d\n", size(root));
        }
        else if (operation == 'e')
        {
            printf("%d\n", empty(root));
        }
        else if (operation == 'p')
        {
            printElements(root);
            printf("\n");
        }
    }

    freeTree(root);

    return 0;
}
