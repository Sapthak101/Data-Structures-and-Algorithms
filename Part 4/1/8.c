#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prv;
    struct node *next;
    double data;
} *head =NULL, *tail=NULL;

struct node2{
    struct node2 *prv;
    struct node2 *next;
    double data;
} *head2 =NULL, *tail2=NULL;

int main()
{
    struct node *cur, *ptr;
    struct node2 *cur2, *ptr2;
    int n, i, count=0;

    printf("Enter the number of nodes that you want to enter: ");
    scanf("%d", &n);

    printf("\n\nEnter List Elements from 0 to 9\n\n");

    for (i=0; i<n; i++)
    {
        cur=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data for Node %d= ", i+1);
        scanf("%lf", &cur->data);
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

    for (ptr=tail; ptr!=NULL; ptr=ptr->prv)
    {
        cur2=(struct node2 *)malloc(sizeof(struct node2));
        cur2->data=ptr->data;
        cur2->next=cur2->prv=NULL;

        if (head2==NULL)
        {
            tail2=head2=cur2;
        }
        else
        {
            cur2->prv=tail2;
            tail2->next=cur2;
            tail2=cur2;
        }
    }

    for (ptr2=head2; ptr2!=NULL; ptr2=ptr2->next)
    {
        printf("%.2lf ", ptr2->data);
    }

    for (i=0; i<n; i++)
    {   
        ptr=head;
        ptr2=head2;

        if (ptr2->data==ptr->data)
        {
            count++;
        }

        ptr=ptr->next;
        ptr2=ptr2->next;
    }

    if (count==n)
        printf("\nThe list is pallindrome\n");
    else
        printf("The list is not pallindrome");

    return 0;
}