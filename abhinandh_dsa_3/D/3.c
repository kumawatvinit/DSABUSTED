#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct Node {
    int key;
    enum Color color;
    struct Node *left, *right, *parent;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->color = RED; // New node is always red
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void rotateLeft(struct Node** root, struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    if (y != NULL)
        y->parent = x->parent;
    if (x->parent == NULL)
        (*root) = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    if (x != NULL)
        x->parent = y;
}

void rotateRight(struct Node** root, struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    if (x != NULL)
        x->parent = y->parent;
    if (y->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    if (y != NULL)
        y->parent = x;
}

void fixViolation(struct Node** root, struct Node* newNode) {
    struct Node* parent = NULL;
    struct Node* grandparent = NULL;
    while ((newNode != *root) && (newNode->color != BLACK) && (newNode->parent->color == RED)) {
        parent = newNode->parent;
        grandparent = newNode->parent->parent;
        if (parent == grandparent->left) {
            struct Node* uncle = grandparent->right;
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            } else {
                if (newNode == parent->right) {
                    rotateLeft(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rotateRight(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                newNode = parent;
            }
        } else {
            struct Node* uncle = grandparent->left;
            if ((uncle != NULL) && (uncle->color == RED)) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            } else {
                if (newNode == parent->left) {
                    rotateRight(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rotateLeft(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                newNode = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(struct Node** root, int key) {
    struct Node* newNode = createNode(key);
    struct Node* current = (*root);
    struct Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (newNode->key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    newNode->parent = parent;
    if (parent == NULL)
        (*root) = newNode;
    else if (newNode->key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;
    fixViolation(root, newNode);
}

void printParenthesizedRepresentation(struct Node* root) {
    if (root == NULL) {
        printf("( ) ");
        return;
    }
    printf("( ");

    printf("%d ", root->key);

    if (root->color == RED)
        printf("R ");
    else
        printf("B ");

    printParenthesizedRepresentation(root->left);
    printParenthesizedRepresentation(root->right);

    printf(") ");
}


int main() {
    struct Node* root = NULL;
    int key;
    char choice;
    while (scanf("%d", &key)) {        
        insert(&root, key);
        printParenthesizedRepresentation(root);
        printf("\n");
    }
    return 0;
}
