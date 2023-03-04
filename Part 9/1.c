#include<stdio.h>
#define MAX 100000

typedef struct queue1
{
    int data[MAX];
    int front;
    int rear;
} queue;

void init(queue *q);
int enqueue(queue *q, int v);
int dequeue(queue *q, int *v);
int peek(queue *q, int *val);
void display(queue q);
void isempty(queue q);
void isfull(queue q);

int main()
{
    int choice;
    char choice1;

    queue q1;
    init(&q1);
    do
    {
        printf("Queue Operation: \n");
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
                dequeue(&q1, &val);
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
                display(q1);
                break;
            }
            case 5:
            {
                isempty(q1);
                break;
            }
            case 6:
            {
                isfull(q1);
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
    q->front=-1;
    q->rear=-1;
}

int enqueue(queue *q, int v)
{
    if (q->rear==MAX-1)
    {
        printf("Overflow\n");
        return 1;
    }
    else if (q->rear==-1)
    {
        q->front=q->rear=0;
        q->data[q->rear]=v;
    }
    else
        q->data[++(q->rear)]=v;

    return 0;
}

int dequeue(queue *q, int *v)
{
    if (q->front==-1)
    {
        printf("Underflow\n");
        return 1;
    }
    else if (q->front==q->rear)
    {
        *v=q->data[q->front];
        q->front=q->rear=-1;
        return 0;
    }
    else
    {
        *v=q->data[q->front];
        q->front++;
        return 0;
    }
}

int peek(queue *q, int *val)
{
    if (q->front==-1)
        return 1;
    else
        *val=q->data[q->front];
    return 0;
}

void display(queue q)
{
    int i;

    for (i=q.front; i<=q.rear; i++)
    {
        printf("%d ", q.data[i]);
    }
}

void isempty(queue q)
{
    if (q.front==-1)
        printf("The queue is empty\n");
    else
        printf("The queue is not empty\n");
}

void isfull(queue q)
{
    if (q.rear==MAX-1)
        printf("The queue is full\n");
    else
        printf("The queue is not full\n");
}