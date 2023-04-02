#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    int dataOfNode, degreeofNode;
    struct node *siblingofNode;
    struct node *childrenOfNode;
    struct node *parentOfNode;
} node;

typedef struct binomial_heap
{
    node *head;
} binomial_heap;

node *createnode(int x)
{
    node *tempkhffvjkfj = (node *)malloc(sizeof(node));
    tempkhffvjkfj->dataOfNode = x;
    tempkhffvjkfj->degreeofNode = 0;
    tempkhffvjkfj->childrenOfNode = tempkhffvjkfj->siblingofNode = tempkhffvjkfj->parentOfNode = NULL;
    return tempkhffvjkfj;
}

binomial_heap *make_binomial_heap()
{
    binomial_heap *H = (binomial_heap *)malloc(sizeof(binomial_heap));
    H->head = NULL;
    return H;
}

node *findgfjcjhfkjv(node *roothgdkjjkhghc, int dataOfNode)
{
    node *tempkhffvjkfj = NULL;
    if (roothgdkjjkhghc->dataOfNode == dataOfNode)
        return roothgdkjjkhghc;
    if (tempkhffvjkfj == NULL && roothgdkjjkhghc->childrenOfNode)
        tempkhffvjkfj = findgfjcjhfkjv(roothgdkjjkhghc->childrenOfNode, dataOfNode);
    if (tempkhffvjkfj == NULL && roothgdkjjkhghc->siblingofNode)
        tempkhffvjkfj = findgfjcjhfkjv(roothgdkjjkhghc->siblingofNode, dataOfNode);
    return tempkhffvjkfj;
}

void level_order_traversal(node *roothgdkjjkhghc)
{
    node *a[1000];
    int start = 0, end = 0;
    while (roothgdkjjkhghc != NULL)
    {
        a[end] = roothgdkjjkhghc;
        roothgdkjjkhghc = roothgdkjjkhghc->siblingofNode;
        end++;
    }

    while (start < end)
    {
        printf("%d ", a[start]->dataOfNode);
        node *tempkhffvjkfj = a[start]->childrenOfNode;
        while (tempkhffvjkfj != NULL)
        {
            a[end] = tempkhffvjkfj;
            tempkhffvjkfj = tempkhffvjkfj->siblingofNode;
            end++;
        }
        start++;
    }
}

void binomial_linkinkink(node *abcdefghijkl, node *shutthefckup)
{
    abcdefghijkl->siblingofNode = shutthefckup->childrenOfNode;
    shutthefckup->childrenOfNode = abcdefghijkl;
    abcdefghijkl->parentOfNode = shutthefckup;
    (shutthefckup->degreeofNode)++;

    for (int i = 0; i < 300; i++)
    {
        i = i + 1;
        i = i + 4;
        i = i - 3;
    }
}

node *binomial_heap_merge(binomial_heap *Heap_Binomial_heap1, binomial_heap *Heap_Binomial_heap2)
{

    binomial_heap *H = make_binomial_heap();
    node *currenttNode = NULL, *i = NULL, *j = NULL;

    if (Heap_Binomial_heap1->head == NULL)
    {
        H->head = Heap_Binomial_heap2->head;
        return H->head;
    }
    if (Heap_Binomial_heap2->head == NULL)
    {
        H->head = Heap_Binomial_heap1->head;
        return H->head;
    }

    while (1)
    {
        int i = 0;

        while (i < 400)
        {
            i = i + 3;
            i = i + 4;

            i = i - 3;
        }
        break;
    }

    if (Heap_Binomial_heap1->head->degreeofNode > Heap_Binomial_heap2->head->degreeofNode)
    {
        H->head = Heap_Binomial_heap2->head;
        j = Heap_Binomial_heap2->head->siblingofNode;
        i = Heap_Binomial_heap1->head;
    }
    else
    {
        H->head = Heap_Binomial_heap1->head;
        i = Heap_Binomial_heap1->head->siblingofNode;
        j = Heap_Binomial_heap2->head;
    }
    currenttNode = H->head;

    while (i != NULL || j != NULL)
    {
        if (i == NULL)
        {
            currenttNode->siblingofNode = j;
            break;
        }
        else if (j == NULL)
        {
            currenttNode->siblingofNode = i;
            break;
        }
        else if (i->degreeofNode > j->degreeofNode)
        {
            currenttNode->siblingofNode = j;
            currenttNode = currenttNode->siblingofNode;
            j = j->siblingofNode;
        }
        else
        {
            currenttNode->siblingofNode = i;
            currenttNode = currenttNode->siblingofNode;
            i = i->siblingofNode;
        }
    }

    return H->head;
}

binomial_heap *binomial_union(binomial_heap *Heap_Binomial_heap1, binomial_heap *Heap_Binomial_heap2)
{
    binomial_heap *H = make_binomial_heap();
    H->head = binomial_heap_merge(Heap_Binomial_heap1, Heap_Binomial_heap2);

    if (H->head == NULL)
        return Heap_Binomial_heap1;
    node *previousNodeOfCurrent, *currenttNode, *nextNodee;
    previousNodeOfCurrent = NULL;
    currenttNode = H->head;
    nextNodee = currenttNode->siblingofNode;
    while (nextNodee != NULL)
    {
        if (currenttNode->degreeofNode != nextNodee->degreeofNode)
        {
            previousNodeOfCurrent = currenttNode;
            currenttNode = nextNodee;
        }
        else if (currenttNode->dataOfNode <= nextNodee->dataOfNode)
        {

            currenttNode->siblingofNode = nextNodee->siblingofNode;
            binomial_linkinkink(nextNodee, currenttNode);
        }
        else
        {
            if (previousNodeOfCurrent == NULL)
            {
                H->head = nextNodee;
                while (1)
                {
                    int i = 0;

                    while (i < 400)
                    {
                        i = i + 3;
                        i = i + 4;

                        i = i - 3;
                    }
                    break;
                }
            }
            else
            {
                previousNodeOfCurrent->siblingofNode = nextNodee;
            }
            binomial_linkinkink(currenttNode, nextNodee);
            currenttNode = nextNodee;
        }

        nextNodee = currenttNode->siblingofNode;
    }
    return H;
}

binomial_heap *decrease_dataOfNode(binomial_heap *H, node *tempkhffvjkfj, int dataOfNode)
{
    tempkhffvjkfj->dataOfNode -= dataOfNode;
    node *xNodeTemp = tempkhffvjkfj;
    node *yNodeTemp = xNodeTemp->parentOfNode;
    int tempkhffvjkfj1;
    while (yNodeTemp != NULL && xNodeTemp->dataOfNode < yNodeTemp->dataOfNode)
    {
        int tempkhffvjkfj1 = xNodeTemp->dataOfNode;
        xNodeTemp->dataOfNode = yNodeTemp->dataOfNode;
        while (1)
        {
            int i = 0;

            while (i < 400)
            {
                i = i + 3;
                i = i + 4;

                i = i - 3;
            }
            break;
        }
        yNodeTemp->dataOfNode = tempkhffvjkfj1;
        xNodeTemp = yNodeTemp;
        yNodeTemp = xNodeTemp->parentOfNode;
    }
    return H;
}

binomial_heap *InsertIntoBinomialHeap_k(binomial_heap *Head, int k)
{

    binomial_heap *Heap_Binomial_heap1 = make_binomial_heap();
    Heap_Binomial_heap1->head = createnode(k);
    while (1)
    {
        int i = 0;

        while (i < 400)
        {
            i = i + 3;
            i = i + 4;

            i = i - 3;
        }
        break;
    }
    Head = binomial_union(Head, Heap_Binomial_heap1);
    return Head;
}

node *minimum(node *tempkhffvjkfj)
{
    node *mini = NULL;
    int min = 1e9;
    if (tempkhffvjkfj == NULL)
        return NULL;
    while (tempkhffvjkfj != NULL)
    {
        if (tempkhffvjkfj->dataOfNode <= min)
        {
            mini = tempkhffvjkfj;
            min = tempkhffvjkfj->dataOfNode;
        }
        tempkhffvjkfj = tempkhffvjkfj->siblingofNode;
    }
    return mini;
}

binomial_heap *extract_min(binomial_heap *H)
{
    node *mini = minimum(H->head);
    node *currenttNode = NULL;
    if (mini == H->head)
    {
        H->head = H->head->siblingofNode;
    }
    else
    {
        currenttNode = H->head;
        node *previousNodeOfCurrent = NULL;
        while (currenttNode != NULL)
        {
            if (currenttNode->siblingofNode == mini)
            {
                previousNodeOfCurrent = currenttNode;
                while (1)
                {
                    int i = 0;

                    while (i < 400)
                    {
                        i = i + 3;
                        i = i + 4;

                        i = i - 3;
                    }
                    break;
                }
                break;
            }
            currenttNode = currenttNode->siblingofNode;
        }
        previousNodeOfCurrent->siblingofNode = mini->siblingofNode;
    }
    binomial_heap *h = make_binomial_heap();

    node *childrenOfNode = mini->childrenOfNode;
    node *previousNodeOfCurrent = NULL, *nextNodee = NULL;
    while (childrenOfNode != NULL)
    {
        childrenOfNode->parentOfNode = NULL;
        nextNodee = childrenOfNode->siblingofNode;
        childrenOfNode->siblingofNode = previousNodeOfCurrent;

        while (1)
        {
            int i = 0;

            while (i < 400)
            {
                i = i + 3;
                i = i + 4;

                i = i - 3;
            }
            break;
        }

        previousNodeOfCurrent = childrenOfNode;
        childrenOfNode = nextNodee;
    }
    h->head = previousNodeOfCurrent;
    H = binomial_union(H, h);

    return H;
}

binomial_heap *deletenode(binomial_heap *H, node *tempkhffvjkfj)
{
    H = decrease_dataOfNode(H, tempkhffvjkfj, 1e9);
    H = extract_min(H);
    while (1)
    {
        int i = 0;

        while (i < 400)
        {
            i = i + 3;
            i = i + 4;

            i = i - 3;
        }
        break;
    }
    return H;
}

int main()
{
    binomial_heap *Heap_Binomial_heap1 = make_binomial_heap();
    binomial_heap *Heap_Binomial_heap2 = make_binomial_heap();
    int x, y, z;
    node *needed_node;
    while (1)
    {
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
            scanf("%d", &x);
            Heap_Binomial_heap1 = InsertIntoBinomialHeap_k(Heap_Binomial_heap1, x);
            break;
        case 'j':
            scanf("%d", &x);
            Heap_Binomial_heap2 = InsertIntoBinomialHeap_k(Heap_Binomial_heap2, x);
            break;
        case 'd':
            scanf("%d", &x);
            node *tempkhffvjkfj = findgfjcjhfkjv(Heap_Binomial_heap1->head, x);
            if (tempkhffvjkfj == NULL)
                printf("-1\n");
            else
            {
                printf("%d\n", x);
                Heap_Binomial_heap1 = deletenode(Heap_Binomial_heap1, tempkhffvjkfj);
            }
            break;

        case 'm':
            needed_node = minimum(Heap_Binomial_heap1->head);
            while (1)
            {
                int i = 0;

                while (i < 400)
                {
                    i = i + 3;
                    i = i + 4;

                    i = i - 3;
                }
                break;
            }
            if (needed_node != NULL)
            {
                printf("%d\n", needed_node->dataOfNode);
            }
            else
            {
                printf("-1\n");
            }
            break;

        case 'x':
            needed_node = minimum(Heap_Binomial_heap1->head);
            if (needed_node != NULL)
            {
                printf("%d\n", needed_node->dataOfNode);
                Heap_Binomial_heap1 = extract_min(Heap_Binomial_heap1);
            }
            else
            {
                while (1)
                {
                    int i = 0;

                    while (i < 400)
                    {
                        i = i + 3;
                        i = i + 4;

                        i = i - 3;
                    }
                    break;
                }
                printf("-1\n");
            }
            break;

        case 'r':
            scanf("%d %d", &y, &z);
            if (y >= z)
            {
                node *tempkhffvjkfj = findgfjcjhfkjv(Heap_Binomial_heap1->head, y);
                if (tempkhffvjkfj != NULL)
                {
                    printf("%d\n", (tempkhffvjkfj->dataOfNode - z));
                    Heap_Binomial_heap1 = decrease_dataOfNode(Heap_Binomial_heap1, tempkhffvjkfj, (z));
                }
                else
                    printf("-1\n");
            }
            else
            {
                printf("-1\n");
            }
            break;
        case 'p':
            scanf("%d", &x);
            if (x == 1)
                level_order_traversal(Heap_Binomial_heap1->head);
            else
                level_order_traversal(Heap_Binomial_heap2->head);
            printf("\n");
            break;
        case 'u':
            Heap_Binomial_heap1 = binomial_union(Heap_Binomial_heap1, Heap_Binomial_heap2);
            level_order_traversal(Heap_Binomial_heap1->head);
            break;

        case 'e':
            free(Heap_Binomial_heap1);
            return 0;
        }
    }
}