#include<stdio.h>
#define MAX 10000

typedef struct I_DQueue
{
    int data[MAX];
    int rear, front;
} dqueue;

void init(dqueue *q);
int enqueue(dqueue *q, int val, int side);
int dequeue(dqueue *q, int *val);
int peek(dqueue *q, int *val);
void isempty(dqueue q);
void isfull(dqueue *q);
void display(dqueue *q);

int main()
{   
    int choice, choice2;
    char choice1;

    dqueue q1;
    init(&q1);
    do
    {
        printf("Output restricted DQueue Operation: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Displaying queue contents\n");
        printf("5. Checking if the queue is empty\n");
        printf("6. Checking if the queue is full\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int val;

                printf("0: Front sided enqueue\n1: Rear sided enqueue\n");
                scanf("%d", &choice2);

                printf("Enter the value for the enqueue operation: ");
                scanf("%d", &val);
                enqueue(&q1, val, choice2);

                break; 
            }
            case 2:
            { 
                int val, k;

                k=dequeue(&q1, &val);
                if (k==0)
                    printf("The dequeued value is %d", val);
                break;
            }
            case 3:
            {
                int val, k;
                k=peek(&q1, &val);
                if (k==1)
                    printf("The dqueue is empty\n");
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
                isempty(q1);
                break;
            }
            case 6:
            {
                isfull(&q1);
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

void init(dqueue *q)
{
    q->rear=q->front=-1;
}

int enqueue(dqueue *q, int val, int side)
{
    if (q->rear==MAX-1 && q->front==0)
    {
        printf("Overflow\n");
        return 1;
    }
    else if (q->rear==-1)
    {
        q->front=q->rear=0;
        q->data[q->rear]=val;
    }
    else if (side==0)
    {
        if (q->front==0)
        {
            printf("Front side insertion cannot be done\n");
            return 2;
        }
        else
            q->data[--q->front]=val;
    }
    else
    {
        if (q->rear==MAX-1)
        {
            printf("Rear side insertion cannot be done\n");
            return 3;
        }
        else
            q->data[++q->rear]=val;
    }
}

int dequeue(dqueue *q, int *val)
{
    if (q->front==-1)
    {
        printf("Underflow\n");
        return 1;
    }
    if (q->front==q->rear)
    {
        *val=q->data[q->front];
        q->front=q->rear=-1;
    }
    else
    {
        *val=q->data[q->front];
        ++q->front;
    }
    return 0;
}

int peek(dqueue *q, int *val)
{
    if (q->front==-1)
        return 1;
    else
        *val=q->data[q->front];
    return 0;
}

void display(dqueue *q)
{
    for (int i=q->front; i<=q->rear; i++)
        printf("%d ", q->data[i]);
}
void isempty(dqueue q)
{
    if (q.front==-1)
        printf("The dqueue is empty\n");
    else
        printf("The dqueue is not empty\n");
}

void isfull(dqueue *q)
{
    if (q->rear==MAX-1)
        printf("The dqueue is full\n");
    else
        printf("The dqueue is not full\n");
}