#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(char data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 

int search(int *arr, int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int *in, int *pre, int inStrt, int inEnd) {
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    struct Node* node = newNode(pre[preIndex++]);

    printf("Node: %d\n", node->data);

    if (inStrt == inEnd)
        return node;

    int inIndex = search(in, inStrt, inEnd, node->data);

    if(inIndex == -1) {
        printf("Did not found %d\n", node->data);
        return NULL;
    }

    node->left = buildTree(in, pre, inStrt, inIndex - 1);
    node->right = buildTree(in, pre, inIndex + 1, inEnd);

    return node;
}

void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void ZIG_ZAG(struct Node* root) {
    if (root == NULL)
        return;

    struct Node** currentLevel = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    struct Node** nextLevel = (struct Node**)malloc(sizeof(struct Node*) * 1000);

    int currentLevelSize = 0, nextLevelSize = 0;
    int levelNo = 0;  // Start from level 0

    currentLevel[currentLevelSize++] = root;

    while (currentLevelSize > 0) {
        while (currentLevelSize > 0) {
            struct Node* tempNode = currentLevel[--currentLevelSize];

            printf("%d ", tempNode->data);

            if (levelNo % 2 == 0) {
                if (tempNode->left != NULL)
                    nextLevel[nextLevelSize++] = tempNode->left;
                if (tempNode->right != NULL)
                    nextLevel[nextLevelSize++] = tempNode->right;
            } else {
                if (tempNode->right != NULL)
                    nextLevel[nextLevelSize++] = tempNode->right;
                if (tempNode->left != NULL)
                    nextLevel[nextLevelSize++] = tempNode->left;
            }
        }

        struct Node** temp = currentLevel;
        currentLevel = nextLevel;
        nextLevel = temp;

        levelNo++;
    }

    free(currentLevel);
    free(nextLevel);

    printf("\n");
}


struct LevelInfo {
    int maxVal;
};


void Level_Max(struct Node* root) {
    if (root == NULL)
        return;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    int front = 0, rear = 0;

    queue[rear++] = root;

    struct LevelInfo* levelInfo = (struct LevelInfo*)malloc(sizeof(struct LevelInfo) * 1000);

    int level = 0;  // Current level

    while (front < rear) {
        int maxVal = -1e8;  
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; ++i) {
            struct Node* tempNode = queue[front++];

            if (tempNode->data > maxVal)
                maxVal = tempNode->data;

            if (tempNode->left != NULL)
                queue[rear++] = tempNode->left;

            if (tempNode->right != NULL)
                queue[rear++] = tempNode->right;
        }

        levelInfo[level].maxVal = maxVal;

        level++;
    }


    for (int i = 0; i < level; ++i) {
        printf("Maximum value at level %d: %d\n", i, levelInfo[i].maxVal);
    }

    printf("\n");

    free(queue);
    free(levelInfo);
}

int Diameter(struct Node* node) {
    if(!node) return 0;

    return 1 + max(Diameter(node->left), Diameter(node->right));
}

int Left_Leaf_Sum(struct Node* node) {
    if(!node) return 0;

    return (node->left? node->left->data: 0) + Left_Leaf_Sum(node->left) + Left_Leaf_Sum(node->right);
}

void postOrder(struct Node* node) {
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    scanf("%d", &n);

    
    int *in, *pre;
    in = (int*)malloc(n * sizeof(int));
    pre = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    // for(int i=0; i<n; i++) printf("%d ", in[i]);
    // printf("\n");

    // for(int i=0; i<n; i++) printf("%d ", pre[i]);
    // printf("\n\n");

    // _sleep(5000);

    struct Node* root = buildTree(in, pre, 0, n - 1);


    postOrder(root);
    printf("\n");

    char op;
    while (1) {
        scanf("%c", &op);

        switch (op) {
            case 'p':
                postOrder(root);
                printf("\n");
                break;
            case 'z':
                ZIG_ZAG(root);
                break;
            case 'm':
                Level_Max(root);
                break;
            case 'd':
                printf("%d\n", Diameter(root));
                break;
            case 's':
                printf("%d\n", Left_Leaf_Sum(root));
                break;
            case 'e': 
                return 0;
        }
    }

    return 0;
}