#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    int key, degree;
    struct node *sibling;
    struct node *child;
    struct node *parent;
} node;

typedef struct binomial_heap
{
    node *head;
} binomial_heap;

node *createnode(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->key = x;
    temp->degree = 0;
    temp->child = temp->sibling = temp->parent = NULL;
    return temp;
}

binomial_heap *make_binomial_heap()
{
    binomial_heap *H = (binomial_heap *)malloc(sizeof(binomial_heap));
    H->head = NULL;
    return H;
}

node *find(node *root, int key)
{
    node *temp = NULL;
    if (root->key == key)
        return root;
    if (temp == NULL && root->child)
        temp = find(root->child, key);
    if (temp == NULL && root->sibling)
        temp = find(root->sibling, key);
    return temp;
}

void level_order(node *root)
{
    node *a[1000];
    int start = 0, end = 0;
    while (root != NULL)
    {
        a[end] = root;
        root = root->sibling;
        end++;
    }

    while (start < end)
    {
        printf("%d ", a[start]->key);
        node *temp = a[start]->child;
        while (temp != NULL)
        {
            a[end] = temp;
            temp = temp->sibling;
            end++;
        }
        start++;
    }
}

void binomial_link(node *y, node *z)
{
    y->sibling = z->child;
    z->child = y;
    y->parent = z;
    (z->degree)++;
}

node *binomial_heap_merge(binomial_heap *H1, binomial_heap *H2)
{

    binomial_heap *H = make_binomial_heap();
    node *curr = NULL,*i=NULL,*j=NULL;

    if (H1->head == NULL)
    {
        H->head = H2->head;
        return H->head;
    }
    if (H2->head == NULL)
    {
        H->head = H1->head;
        return H->head;
    }

    if (H1->head->degree > H2->head->degree)
    {
        H->head = H2->head;
        j = H2->head->sibling;
        i = H1->head;
    }
    else
    {
        H->head = H1->head;
        i = H1->head->sibling;
        j = H2->head;
    }
    curr = H->head;

    while (i != NULL || j != NULL)
    {
        if (i == NULL)
        {
            curr->sibling = j;
            break;
        }
        else if (j == NULL)
        {
            curr->sibling = i;
            break;
        }
        else if (i->degree > j->degree)
        {
            curr->sibling = j;
            curr = curr->sibling;
            j = j->sibling;
        }
        else
        {
            curr->sibling = i;
            curr = curr->sibling;
            i = i->sibling;
        }
    }

    return H->head;
}

binomial_heap *binomial_union(binomial_heap *H1, binomial_heap *H2)
{
    binomial_heap *H = make_binomial_heap();
    H->head = binomial_heap_merge(H1, H2);

    if (H->head == NULL)
        return H1;
    node *prev, *curr, *next;
    prev = NULL;
    curr = H->head;
    next = curr->sibling;
    while (next != NULL)
    {
        if (curr->degree != next->degree)
        {
            prev = curr;
            curr = next;
        }
        else if (curr->key <= next->key)
        {

            curr->sibling = next->sibling;
            binomial_link(next, curr);
        }
        else
        {
            if (prev == NULL)
            {
                H->head = next;
            }
            else
            {
                prev->sibling = next;
            }
            binomial_link(curr, next);
            curr = next;
        }

        next = curr->sibling;
    }
    return H;
}

binomial_heap *decrease_key(binomial_heap *H, node *temp, int key)
{
    temp->key -= key;
    node *x = temp;
    node *y = x->parent;
    int temp1;
    while (y != NULL && x->key < y->key)
    {
        int temp1 = x->key;
        x->key = y->key;
        y->key = temp1;
        x = y;
        y = x->parent;
    }
    return H;
}

binomial_heap *insert(binomial_heap *H, int k)
{

    binomial_heap *H1 = make_binomial_heap();
    H1->head = createnode(k);
    H = binomial_union(H, H1);
    return H;
}

node *minimum(node *temp)
{
    node *mini = NULL;
    int min = 1e9;
    if (temp == NULL)
        return NULL;
    while (temp != NULL)
    {
        if (temp->key <= min)
        {
            mini = temp;
            min = temp->key;
        }
        temp = temp->sibling;
    }
    return mini;
}

binomial_heap *extract_min(binomial_heap *H)
{
    node *mini = minimum(H->head);
    node *curr = NULL;
    if (mini == H->head)
    {
        H->head = H->head->sibling;
    }
    else
    {
        curr = H->head;
        node *prev = NULL;
        while (curr != NULL)
        {
            if (curr->sibling == mini)
            {
                prev = curr;
                break;
            }
            curr = curr->sibling;
        }
        prev->sibling = mini->sibling;
    }
    binomial_heap *h = make_binomial_heap();

    node *child = mini->child;
    node *prev = NULL, *next = NULL;
    while (child != NULL)
    {
        child->parent = NULL;
        next = child->sibling;
        child->sibling = prev;

        prev = child;
        child = next;
    }
    h->head = prev;
    H = binomial_union(H, h);

    return H;
}

binomial_heap *deletenode(binomial_heap *H, node *temp)
{
    H = decrease_key(H, temp, 1e9);
    H = extract_min(H);
    return H;
}

int main()
{
    binomial_heap *H1 = make_binomial_heap();
    binomial_heap *H2 = make_binomial_heap();
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
            H1 = insert(H1, x);
            break;
        case 'j':
            scanf("%d", &x);
            H2 = insert(H2, x);
            break;
        case 'd':
            scanf("%d", &x);
            node *temp = find(H1->head, x);
            if (temp == NULL)
                printf("-1\n");
            else
            {
                printf("%d\n", x);
                H1 = deletenode(H1, temp);
            }
            break;

        case 'm':
            needed_node = minimum(H1->head);
            if (needed_node != NULL)
            {
                printf("%d\n", needed_node->key);
            }
            else
            {
                printf("-1\n");
            }
            break;

        case 'x':
            needed_node = minimum(H1->head);
            if (needed_node != NULL)
            {
                printf("%d\n", needed_node->key);
                H1 = extract_min(H1);
            }
            else
            {
                printf("-1\n");
            }
            break;

        case 'r':
            scanf("%d %d", &y, &z);
            if (y >= z)
            {
                node *temp = find(H1->head, y);
                if (temp != NULL)
                {
                    printf("%d\n", (temp->key - z));
                    H1 = decrease_key(H1, temp, (z));
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
            scanf("%d" , &x);
            if ( x == 1)
            level_order(H1->head);
            else
            level_order(H2->head);
            printf("\n");
            break;
        case 'u':
            H1 = binomial_union(H1,H2);
            level_order(H1->head);
            break;

        case 'e':
            free(H1);
            return 0;
        }
    }
}