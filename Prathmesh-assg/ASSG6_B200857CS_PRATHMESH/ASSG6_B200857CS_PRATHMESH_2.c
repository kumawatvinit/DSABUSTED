#include <stdio.h>
#include <stdlib.h>


typedef struct stack {
	int data;
	struct stack* next;
}stack;

stack* Create_Node(int k)
{
	stack* stackNode = (stack *)malloc(sizeof(stack));

	stackNode->data = k;
	stackNode->next = NULL;

	return stackNode;
}

int Stack_Empty(stack** s)
{
	return !(*s);
}

void push(stack** s, int k)
{
	stack* stackNode = Create_Node(k);
	stackNode->next = *s;
	*s = stackNode;
}

int pop(stack** s)
{
	stack* temp = *s;
	*s = (*s)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int main()
{
	stack * s = NULL;
    int k;

	char ch;

    while(1)
    {
        scanf("%c", &ch);

        switch (ch)
        {
        case 'i':
            scanf("%d", &k);
            push(&s, k);
            break;
        
        case 'd':
            scanf("%d", &k);
            
            for(int i=0; i<k; i++) 
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
