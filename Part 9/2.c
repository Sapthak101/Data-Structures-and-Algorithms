#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct Queue
{
    struct node *front;
    struct node *rear;
} queue;

void init(queue *q);
int enqueue(queue *q, int val);
int dequeue(queue *q, int *val);
int peek(queue *q, int *val);
void empty_or_not(queue *q);\
void display(queue *q);

int main()
{
    queue q1;
    init(&q1);

    int choice;
    char choice1;

    do
    {
        printf("Queue Operation: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Displaying queue contents\n");
        printf("5. Checking if the queue is empty or not\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int val, k;
                printf("Enter the value for the enqueue operation: ");
                scanf("%d", &val);
                k=enqueue(&q1, val);
                if (k==1)
                    printf("The operation cannot be done\n");

                break; 
            }
            case 2:
            { 
                int val, k;

                k=dequeue(&q1, &val);
                if (k==1)
                    printf("The operation cannot be done\n");
                else
                    printf("The value dequed is: %d\n", val);

                break;
            }
            case 3:
            {
                int val, k;
                k=peek(&q1, &val);
                if (k==1)
                    printf("The queue is empty\n");
                else
                    printf("The value in the first poition is %d\n", val);
                break;
            }
            case 4:
            {
                display(&q1);
                break;
            }
            case 5:
            {
                empty_or_not(&q1);
                break;
            }
            default: 
                printf("Invalid choice\n");
        }
    printf("\nDo you want to continue (Y/N): \n");
    scanf("%s", &choice1);
    }while(choice1=='Y');

    return 0;
}

void init(queue *q)
{
    q->front=q->rear=NULL;
}

int enqueue(queue *q, int v)
{
    struct node *cur= (struct node*)malloc(sizeof(struct node));
    if (cur==NULL)
    {
        printf("Overflow\n");
        return 1;
    }
    cur->data=v;
    cur->next=NULL;
 
    if (q->front==NULL)
        q->front=q->rear=cur;
    else
    {
        q->rear->next=cur;
        q->rear=cur;
    }
    return 0;
}

int dequeue(queue *q, int *v)
{
    if (q->front==NULL)
    {
        printf("Underflow\n");
        return 1;
    }
    else
    {
        struct node *ptr;

        ptr=q->front;
        *v=ptr->data;
        q->front=ptr->next;
        free(ptr);
    }
    return 0;
}

int peek(queue *q, int *val)
{
    if (q->front==NULL)
        return 1;
    else
    {
        *val=q->front->data;
        return 0;
    }
}

void display(queue *q)
{
    struct node *ptr=q->front;

    for (ptr; ptr!=NULL; ptr=ptr->next)
        printf("%d ", ptr->data);
}
void empty_or_not(queue *q)
{
    struct node *ptr=q->front;

    if (ptr==NULL)
        printf("The queue is empty\n");
    else
        printf("THe queue is not empty\n");
}