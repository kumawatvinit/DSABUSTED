#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// custom data type for tree building
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to construct the tree from a string
struct Node* constructTree(char s[], int* start) {
    // Assuming there is/are no negative character/characters in the string
    if (s[*start] == '\0' || *start >= strlen(s))
        return NULL;

    // constructing a number from the continuous digits
    int num = 0;
    while (s[*start] != '\0' && s[*start] != '(' && s[*start] != ')') {
        int num_here = (int)(s[*start] - '0');
        num = num * 10 + num_here;
        (*start)++;
    }

    // creating a node from the constructed number from above loop
    struct Node* root = NULL;
    if (num > 0)
        root = createNode(num);

    // As soon as we see the first right parenthesis from the current node
    // we start to construct the tree in the left
    if (s[*start] != '\0' && s[*start] == '(') {
        (*start)++;
        root->left = constructTree(s, start);
    }
    if (s[*start] != '\0' && s[*start] == ')') {
        (*start)++;
        return root;
    }

    // As soon as we see the second right parenthesis from the current node
    // we start to construct the tree in the right
    if (s[*start] != '\0' && s[*start] == '(') {
        (*start)++;
        root->right = constructTree(s, start);
    }
    if (s[*start] != '\0' && s[*start] == ')')
        (*start)++;
    return root;
}

// Function to perform preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int height(struct Node* node)
{
    if (node == NULL)
        return 0;
    else {
         
        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        // Use the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printCurrentLevel(struct Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void Levelordertraversal(struct Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}


void rightViewUtil(struct Node* root, int level, int* max_level)
{
    // Base Case
    if (root == NULL)
        return;
 
    // If this is the last Node of its level
    if (*max_level < level) {
        printf("%d ", root->data);
        *max_level = level;
    }
 
    // Recur for right subtree first, then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
 
// A wrapper over rightViewUtil()
void RightView(struct Node* root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}


struct Info {
    int max;
    int min;
    int isBST;
    int sum;
    int currmax;
};

struct Info MaxSumBSTUtil(struct Node* root, int* maxsum) {
    if (root == NULL)
        return (struct Info){INT_MIN, INT_MAX, 1, 0, 0};

    if (root->left == NULL && root->right == NULL) {
        *maxsum = (*maxsum > root->data) ? *maxsum : root->data;
        return (struct Info){root->data, root->data, 1, root->data, *maxsum};
    }

    struct Info L = MaxSumBSTUtil(root->left, maxsum);
    struct Info R = MaxSumBSTUtil(root->right, maxsum);

    struct Info BST;

    if (L.isBST && R.isBST && L.max < root->data && R.min > root->data) {
        BST.max = (root->data > (L.max > R.max ? L.max : R.max)) ? root->data : (L.max > R.max ? L.max : R.max);
        BST.min = (root->data < (L.min < R.min ? L.min : R.min)) ? root->data : (L.min < R.min ? L.min : R.min);

        *maxsum = (*maxsum > (R.sum + root->data + L.sum)) ? *maxsum : (R.sum + root->data + L.sum);
        BST.sum = R.sum + root->data + L.sum;

        BST.currmax = *maxsum;
        BST.isBST = 1;
        return BST;
    }

    BST.isBST = 0;
    BST.currmax = *maxsum;
    BST.sum = R.sum + root->data + L.sum;

    return BST;
}

int MaximumSumBst(struct Node* root) {
    int maxsum = INT_MIN;
    return MaxSumBSTUtil(root, &maxsum).currmax;
}


struct node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}

int main() {
    char s[100];
    // char s[] = "4(2(3)(1))(6(5))";
    scanf("%s", s);
    int start = 0;
    struct Node* root = constructTree(s, &start);
    
    char op;
    while (1) {
        scanf("%c", &op);

        switch (op) {
            case 'l':
                Levelordertraversal(root);
                printf("\n");
                break;
            case 'm':
                printf("%d\n", MaximumSumBst(root));
                break;
            case 'r':
                RightView(root);
                printf("\n");
                break;
            case 'e': 
                return 0;
        }
    }

    return 0;
}
