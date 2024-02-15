#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int key;
    enum Color color;
    struct Node *left, *right;
};

struct Node *createNode(int key, enum Color color)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->color = color;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *constructTreeUtil(char *str, int *index)
{
    if (str[*index] == '(' && str[*index + 1] == ')')
    {
        *index += 2; // Move past "()"
        return NULL;
    }

    // while(str[*index] == '(' || str[*index] == ')')
    //     (*index)++;

    

    // Parse the key value
    int value = 0;
    while (str[*index] >= '0' && str[*index] <= '9')
    {
        value = value * 10 + (str[*index] - '0');
        (*index)++;
    }

    // Create a node with the parsed value
    struct Node *node = createNode(value, BLACK);

    // Parse color
    if (str[*index] == 'R')
    {
        node->color = RED;
        (*index)++;
    }
    else if (str[*index] == 'B')
    {
        node->color = BLACK;
        (*index)++;
    }

    // Parse left child
    if (str[*index] == '(')
    {
        (*index)++;
        node->left = constructTreeUtil(str, index);
    }

    // Parse right child
    if (str[*index] == '(')
    {
        (*index)++;
        node->right = constructTreeUtil(str, index);
    }

    // Move past ')'
    (*index)++;

    return node;
}

struct Node *constructTree(char *str)
{
    int index = 0;

    // printf("%s", str);
    return constructTreeUtil(str, &index);
}

void inorderTraversal(struct Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        printf("(%d, %s) ", root->key, root->color == RED ? "RED" : "BLACK");
        inorderTraversal(root->right);
    }
}

void freeTree(struct Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int checkRedBlackProperties(struct Node *node, int *blackCount, int currentBlackCount)
{
    if (node == NULL)
    {
        if (*blackCount == -1)
            *blackCount = currentBlackCount;
        else
        {
            if (*blackCount != currentBlackCount)
                return 0;
        }
        return 1;
    }

    // adjacent red nodes
    if (node->color == RED)
    {
        if (node->left != NULL && node->left->color == RED)
            return 0;
        if (node->right != NULL && node->right->color == RED)
            return 0;
    }

    if (node->color == BLACK)
        currentBlackCount++;
    return checkRedBlackProperties(node->left, blackCount, currentBlackCount) &&
           checkRedBlackProperties(node->right, blackCount, currentBlackCount);
}

bool isRedBlackTree(struct Node *root)
{
    if (root == NULL)
        return 1;

    if (root->color != RED && root->color != BLACK)
        return 0;

    if (root->color != BLACK)
        return 0;

    int blackCount = -1;
    return checkRedBlackProperties(root, &blackCount, 0);
}

void print(struct Node *root)
{
    if (root == NULL)
    {
        printf("( ) ");
        return;
    }
    printf("( ");

    printf("%d ", root->key);

    if (root->color == RED)
        printf("R ");
    else
        printf("B ");

    print(root->left);
    print(root->right);

    printf(") ");
}

char *removeSpaces(char *s)
{
    int i = 0, j = 0;
    while (s[i])
    {
        if (s[i] != ' ')
            s[j++] = s[i];
        i++;
    }
    s[j] = '\0';
    return s;
}

char* cleanStr(char* str)
{
    // remove all '()' from the string
    // remove '(' from starting of the string, and ')' from the end of the string

    int s = 0, i = 1;

    while(str[i])
    {
        if(str[i] == '(' && str[i+1] == ')')
        {
            i += 2;
        }
        else
        {
            str[s++] = str[i++];
        }
    }

    str[s] = '\0';
}

int main()
{
    char parenthesis[1000];
    fgets(parenthesis, sizeof(parenthesis), stdin);

    parenthesis[strlen(parenthesis) - 1] = '\0';


    char *str = removeSpaces(parenthesis);
    str = cleanStr(str);
    // printf("||%s||", parenthesis);
    // printf("||%s||\n\n", str);

    struct Node *root = constructTree(parenthesis);

    // inorderTraversal(root);
    // printf("\n");

    // print(root);
    // printf("\n");

    if (isRedBlackTree(root))
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
