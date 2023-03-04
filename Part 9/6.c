#include<stdio.h>
#define MAX 10000

typedef struct C_DQueue
{
    int data[MAX];
    int front, rear;
} dqueue;

void init(dqueue *q);
int enqueue(dqueue *q, int val, int side);
int dequeue(dqueue *q, int *val);
void display(dqueue *q);
void empty_or_not(dqueue *q);

int main()
{
    int choice, choice2;
    char choice1;

    dqueue q1;
    init(&q1);
    do
    {
        printf("Output restricted circular DQueue Operation: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Displaying queue contents\n");
        printf("4. Checking if the queue is empty or not\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int val;

                printf("0: Front sided enqueue\n1: Rear sided qnqueue\n");
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
                if (k==1)
                    printf("The dequeued value is %d", val);
                break;
            }
            case 3:
            {
                display(&q1);
                break;
            }
            case 4:
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

void init(dqueue *q)
{
    q->front=q->rear=-1;
}

int enqueue(dqueue *q, int val, int side)
{
    if (q->front==(q->rear+1)%MAX)
    {
        printf("Overflow\n");
        return 1;
    }   
    else if (q->front==-1)
    {
        q->front=q->rear=0;
        q->data[q->rear]=val;
    }
    else if (side==0)
    {
        q->front=(q->front+MAX-1)%MAX;
        q->data[q->front]=val;
    }
    else
    {
        q->rear=(q->rear+1)%MAX;
        q->data[q->rear]=val;
    }
}
int dequeue(dqueue *q, int *val)
{
    if (q->front==-1)
    {
        printf("Underflow\n");
        return 1;
    }
    else if (q->front==q->rear)
    {
        *val=q->data[q->front];
        q->front=q->rear=-1;
    }
    else
    {
        *val=q->data[q->front];
        q->front=(q->front+1)%MAX;
    }
}
void display(dqueue *q)
{
    int i;
    for (i=q->front; i!=q->rear; i=(i+1)%MAX)
        printf("%d ", q->data[i]);
    printf("%d\n", q->data[i]);
}
void empty_or_not(dqueue *q)
{
    if (q->rear==-1)
        printf("The output restricted dqueue is empty\n");
    else
        printf("The output restricted dqueue is not empty\n");
}