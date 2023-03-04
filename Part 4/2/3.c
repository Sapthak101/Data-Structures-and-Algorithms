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
    int n, i, n1;

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
    
    printf("Enter the mth position: ");
    scanf("%d", &n1);

    if (n1>n || n1<1)
    {
        printf("The entered position is invalid");
    }
    else
    {
        i=1;
        ptr=tail;
        while (i<=n1 && ptr!=NULL)
        {
            if (i==n1)
            {
                printf("Data-> %d ", ptr->data);
                break;
            }

            ptr=ptr->prv;
            i++;
        }
    }

    return 0;
}