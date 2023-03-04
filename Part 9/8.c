//delete side pqueue
#include<stdio.h>
#define MAX 10000

struct pridata
{
    int val;
    int pri;
};
typedef struct PQueue
{
    int front, rear;
    struct pridata data[MAX];
}pqueue;

void init (pqueue *q);
int enqueue(pqueue *q, int val, int pri);
int dequeue(pqueue *q, int *val, int *pri);
void display(pqueue *q);
void empty_or_not(pqueue *q);

int main()
{
    int choice;
    char choice1;

    pqueue q1;
    init(&q1);
    do
    {
        printf("Priority Queue (Deletion side) Operation: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Displaying queue contents\n");
        printf("4. Checking if the queue is empty or not\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int val, pri;
                printf("Enter the value and priority for the enqueue operation: ");
                scanf("%d", &val, &pri);
                enqueue(&q1, val, pri);
                break; 
            }
            case 2:
            { 
                int val, k, pri;
                dequeue(&q1, &val, &pri);
                printf("The popped value is");
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

void init(pqueue *q)
{
    q->front=q->rear=-1;
}

int enqueue(pqueue *q, int val, int pri)
{
    if (q->rear==MAX-1)
    {
        printf("Overflow\n");
        return 1;
    }
    else if (q->rear==-1)
    {
        q->front=q->rear=0;
        q->data[q->rear].val=val;
        q->data[q->rear].pri=pri;
    }
    else
    {
        q->rear++;
        q->data[q->rear].val=val;
        q->data[q->rear].pri=pri;
    }
}

int dequeue(pqueue *q, int *val, int *pri)
{
    if (q->front==-1)
    {
        printf("Underflow\n");
        return 1;
    }
    else if (q->front==q->rear)
    {
        *val=q->data[q->rear].val;
        *pri=q->data[q->rear].pri;
        q->front=q->rear=-1;
    }
    else
    {
        int i;
        int min=q->front;
        for (i=q->front+1; i<=q->rear; i++)
        {
            if (q->data[i].pri<q->data[min].pri)
                min=i;
        }
        *val=q->data[min].val;
        *pri=q->data[min].pri;
        q->data[min]=q->data[q->rear];
        q->rear--;
        return 0;
    }
    return 0;
}

void display(pqueue *q)
{
    int i;
    for (i=q->front; i<=q->rear; i++)
        printf("%d ", q->data[i].val);
    printf("\n");
    for (i=q->front; i<=q->rear; i++)
        printf("%d ", q->data[i].pri);
}

void empty_or_not(pqueue *q)
{
    if (q->front==-1)
        printf("The priority queue is empty\n");
    else
        printf("The priority queue is not empty\n");
}