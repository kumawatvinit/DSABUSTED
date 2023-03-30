#include <stdio.h>
#include <stdlib.h>


typedef struct queue {
    int front, rear, size;
    int* arr;
}queue;

void Make_Queue(queue *q, int n)
{
    q->front = q->rear = 0;
    q->size = n;

    q->arr = (int *)malloc(n*sizeof(int));
}

void Enqueue(queue *q, int k)
{
    // check queue is full or not
    if (q->size == q->rear) {
        printf("Full\n");
        return;
    }
    // insert element at the rear
    else {
        q->arr[q->rear++] = k;
    }
}

int Dequeue(queue *q)
{
    // shift all the elements from index 2 till rear to the left by one
    int deleted=q->arr[0];
    for (int i = 0; i < q->rear - 1; i++) {
        q->arr[i] = q->arr[i + 1];
    }
    // decrement rear
    q->rear--;

    return deleted;
}

int QueueFull(queue *q)
{
    return q->rear == q->size;
}

int QueueEmpty(queue *q)
{
    return q->front==q->rear;
}

int main(void)
{
    int n,x;
    scanf("%d", &n);
    queue q;
    Make_Queue(&q,n);
    
    char ch;

    while(1)
    {
        scanf("%c", &ch);

        switch (ch)
        {
        case 'i':
            scanf("%d", &x);
            Enqueue(&q, x);
            break;
        
        case 'd':
            scanf("%d", &x);
            
            for(int i=0; i<x; i++) 
            {
                if (QueueEmpty(&q)) {
                    printf("Empty ");
                }
                else {
                    printf("%d ", Dequeue(&q));
                }
                
            }
            printf("\n");
            break;
        
        case 'f':
            if(QueueFull(&q)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
            break;

        case 'e':
            if(QueueEmpty(&q)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
            break;

        case 't':
            return 0;
            break;
        }
    }

    return 0;
}