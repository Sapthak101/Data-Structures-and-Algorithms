#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prv;
    struct node *next;
    int data;
} *head =NULL, *tail=NULL;

void task1(struct node *h);

int main()
{
    struct node *cur, *ptr;
    int n, i=0;

    printf("\n\nEnter the number of nodes that you want to enter: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        cur=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data for Node %d= ", i+1);
        scanf("%d", &cur->data);
        cur->next=cur->prv=NULL;

        if (head==NULL)
        {
            tail=head=cur;
        }
        else
        {
            cur->prv=tail;
            tail->next=cur;
            tail=cur;
        }
    }
    printf("\n\nList Traversing \n\n");
    task1(head);

    printf("\n\nPrinting the nodes in the revere order \n");
    ptr=tail;
    while (ptr->prv!=NULL)
    {
        printf("Data-> %d, ", ptr->data);
        ptr=ptr->prv;
    }
    printf("Data-> %d\n", ptr->data);

    return 0;
}

void task1(struct node *h)
{
    struct node *ptr=h;

    while (ptr->next!=NULL)
    {
        printf("Data-> %d, ", ptr->data);
        ptr=ptr->next;
    }
    printf("Data-> %d\n", ptr->data);
}