#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prv;
    struct node *next;
    double data;
} *head =NULL, *tail=NULL;

void task1(struct node **h, int x);

int main()
{
    struct node *cur, *ptr;
    int n, i, pos;

    printf("\n\nEnter the number of nodes that you want to enter: ");
    scanf("%d", &n);

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

        printf("Enter the node position from which you want the node to inverse: ");
        scanf("%d", &pos);

    if (pos>=1 && pos<=n)
    {
        task1(&head, pos);
    }
    else
        printf("The entered position is invalid");
}

void task1(struct node **h, int x)
{
    struct node *ptr, *v;
    int i=1;

    if (*h==NULL)
    {
        printf("The list is empty\n");
    }
    else 
    {
        ptr=*h;

        while (i<x) 
        {
            if (ptr==NULL)
                break;
            else
            {
                v=ptr;
                ptr=ptr->next;
                i++;
            }
        }
    }

    printf("\n\nPrinting the nodes in the revere order: \n");
    while (i<=x && ptr!=NULL)
    {
        printf("Data= %.2lf | Address= %u | Previous Addresss= %u | Next Address= %u\n", 
                                                     ptr->data, ptr, ptr->prv, ptr->next);
        ptr=ptr->prv;

        i--;
    }
}