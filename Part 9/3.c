#include<stdio.h>
#define MAX 5

typedef struct CQueue
{
    int data[MAX];
    int front, rear;
} cqueue;

void init(cqueue *q);
int enqueue(cqueue *q, int v);
int dequeue(cqueue *q, int *v);
int peek(cqueue *q, int *val);
void display(cqueue *q);
void isempty(cqueue q);
void isfull(cqueue *q);

int main()
{
    int choice;
    char choice1;

    cqueue q1;
    init(&q1);
    do
    {
        printf("Circular Queue Operation: \n");
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

                printf("Enter the value for the enqueue operation: ");
                scanf("%d", &val);
                enqueue(&q1, val);
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

void init(cqueue *q)
{
    q->front=q->rear=-1;
}

int enqueue(cqueue *q, int v)
{
    if (q->front==(q->rear+1)%MAX)
    {
        printf("Overflow\n");
        return 1;
    }
    if (q->rear==-1)
    {
        q->front=q->rear=0;
        q->data[q->rear]=v;
    }
    else
    {
        q->rear=(q->rear+1)%MAX;
        q->data[q->rear]=v;
    }
    return 0;
}

int dequeue(cqueue *q, int *v)
{
    if (q->front==-1)
    {
        printf("Underflow\n");
        return 1;
    }
    if (q->front==q->rear)
    {
        *v=q->data[q->rear];
        q->front=q->rear=-1;
    }
    else
    {
        *v=q->data[q->front];
        q->front=(q->front+1)%MAX;
    }
    return 0;
}

int peek(cqueue *q, int *val)
{
    if (q->front==-1)
        return 1;
    else
        *val=q->data[q->front];
    return 0;
}

void display(cqueue *q)
{
    int i;
    
    for (i=q->front; i!=q->rear; i=(i+1)%MAX)
        printf("%d ", q->data[i]);
    printf("%d", q->data[i]);
}

void isempty(cqueue q)
{
    if (q.front==-1)
        printf("The cqueue is empty\n");
    else
        printf("The cqueue is not empty\n");
}

void isfull(cqueue *q)
{
    if (q->front==(q->rear+1)%MAX)
        printf("The cqueue is full\n");
    else
        printf("The cqueue is not full\n");
}

//circular queue by linked list is same as that of the normal queue using linked list
//and it is implemented using a circular linked list
// its main advantage is while handling system processes