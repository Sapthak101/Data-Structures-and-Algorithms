#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *next;
};
typedef struct 
{
    struct node *top;
}Stack;
void check(Stack *);
void display_content(Stack *);
int push(Stack *, int);
int pop(Stack *, int *);
void init(Stack *);

int main()
{
    Stack s1;
    int data, choice, k;
    char ch;

    init(&s1);
    do
    {
        printf("\n\nStack Operation: \n");
        printf("1. Check if the stack is empty or not\n");
        printf("2. Display the contents of the stack\n");
        printf("3. Push\n");
        printf("4. Pop\n\n\n");

        printf("Please enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                check(&s1);
                
                break;
            }
            case 2:
            {   
                display_content(&s1);

                break;
            }
            case 3:
            {
                int k, val;
                printf("Enter the value you want to enter into the stack: ");
                scanf("%d", &data);
                k=push(&s1, data);

                if (k==1)
                    printf("The push operation is not sucessful\n");
                else
                    printf("The push operation is sucessful\n");

                break;
            }
            case 4:
            {
                k=pop(&s1, &data);

                if (k==1)
                    printf("The pop operation is not sucessful\n");
                else
                {
                    printf("The pop operation is sucessful\n");
                    printf("The popped value is %d\n", data);
                }
                break;
            }
        }

        printf("Do you want to continue (Y/N): ");
        scanf("%s", &ch);
    }while(ch=='Y');

    return 0;

}

void check(Stack *s)
{
    if (s->top==NULL)
        printf("The stack is empty\n");
    else 
        printf("The stack is not empty\n");
}

void display_content(Stack *s)
{
    if (s->top==NULL)
        printf("Nothing to display\n");
    else
    {
        struct node *temp;

        temp=s->top;

        for (temp; temp!=NULL; temp=temp->next)
        {
            printf("|__%d__|\n", temp->val);
        }
    }
}

int push(Stack *s, int val1)
{
    struct node *cur;

    cur=(struct node*)malloc(sizeof(struct node));
    if (cur==NULL)
    {
        printf("Overflow\n");
        return 1;
    }
    cur->val=val1;
    cur->next=s->top;
    s->top=cur;
    return 0;
}

int pop(Stack *s, int *data)
{
    if (s->top==NULL)
    {
        printf("Underflow\n");
        return 1;
    }
    struct node *ptr;
    ptr=s->top;
    s->top=(s->top)->next;
    *data=ptr->val;
    free(ptr);
    return 0;
}

void init(Stack *s)
{
    s->top=NULL;
}