#include<stdio.h>
#define MAX 100000

typedef struct
{
    int data[MAX];
    int top;
}Stack;
int check(Stack *);
int display_content(Stack *);
int push(Stack *, int);
int pop(Stack *, int*);

int main()
{
    Stack s1;
    int choice;
    char ch;

    s1.top=-1;
    
    do
    {
        printf("\n\nStack Operation: \n");
        printf("1. Check if the stack is empty or not\n");
        printf("2. Display the contents of the stack\n");
        printf("3. Push\n");
        printf("4. Pop\n\n\n");

        printf("Please enter your choice: \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                check(&s1);

                break;
            }
            case 2:
            {
                if (s1.top!=-1)
                {
                    display_content(&s1);
                }
                else
                    printf("Nothing to display\n");
                break;
            }
            case 3:
            {
                int k, val;

                printf("Enter the value to push: ");
                scanf("%d", &val);
                k=push(&s1, val);

                if (k==1)
                    printf("The push operation not successful\n");
                else
                    printf("The push operation is successful\n");

                break;
            }
            case 4:
            {
                int k, val;

                k=pop(&s1, &val);

                if (k==1)
                    printf("The pop operation is not sucessful\n");
                else
                {
                    printf("The pop operation is sucessful\n");
                    printf("The value popped is %d\n", val);
                }
                break;
            }
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue (Y/N): ");
        scanf("%s", &ch);
    }while (ch=='Y');

    return 0;
}

int check(Stack *s)
{
    if (s->top==-1)
        printf("The Stack is empty\n");
    else
        printf("The Stack is not empty\n");
}

int display_content(Stack *s)
{
    int n=s->top, i;

    printf("The stack contents: \n");
    for (i=n; i>=0; i--)
    {
        printf("|__%d__|\n", s->data[i]);
    }
}

int push(Stack *s, int val1)
{
        if (s->top==MAX-1)
        {
            printf("Overflow\n");
            return 1;
        }
        s->top++;
        s->data[s->top]=val1;
        return 0;
}

int pop(Stack *s, int *val1)
{
    if (s->top==-1)
    {
        printf("Underflow\n");
        return 1;
    }

    *val1=s->data[s->top];
    s->top--;
    return 0;
}
