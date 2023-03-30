#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int top;
	int size;
	int* array;
}stack;


void createStack(stack *s, int size)
{
	s->size = size;
	s->top = -1;
	s->array = (int*)malloc(s->size * sizeof(int));
}

int Stack_Full(stack * s)
{
	return s->top == s->size - 1;
}

int Stack_Empty(stack* s)
{
	return s->top == -1;
}

void push(stack* s, int x)
{
	if (Stack_Full(s))
    {
        printf("Full\n");
        return;
    }
		
	s->array[++s->top] = x;
}

int pop(stack * s)
{
	// if (Stack_Empty(s))
	// 	return -1;
	return s->array[s->top--];
}

void print(stack *s) 
{
    for(int i=0; i<=s->top; i++)
    {
        printf("%d ", s->array[i]);
    }
    printf("\n");
}

int main()
{
    int n, x;
    scanf("%d", &n);
	stack s;

    createStack(&s,n);

	char ch;

    while(1)
    {
        scanf("%c", &ch);

        switch (ch)
        {
        case 'i':
            scanf("%d", &x);
            push(&s, x);
            break;
        
        case 'd':
            scanf("%d", &x);
            
            for(int i=0; i<x; i++) 
            {
                if (Stack_Empty(&s)) {
                    printf("Empty ");
                }
                else {
                    printf("%d ", pop(&s));
                }
                
            }
            printf("\n");
            break;
        
        case 'f':
            if(Stack_Full(&s)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
            break;

        case 'e':
            if(Stack_Empty(&s)) {
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
