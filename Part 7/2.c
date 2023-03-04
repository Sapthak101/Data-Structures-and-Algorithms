#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*start=NULL, *last=NULL;

void create();
void forward_traverse();
void reverse_traverse();

int main()
{
    int c,n=1;

    while (n==1)
    {
        printf("1.Create a linked list .\n2.Traverse the list in forward direction.\n");
        printf("3.Traverse the linked list in reverse direction.\n");
        printf("Enter the number which opertation you want: \n");
        scanf("%d",&c);

        switch (c)
        {
            case 1:
            {
                create();
                break;
            }
            case 2:
            {
                forward_traverse();
                break;
            }
            case 3:
            {
                reverse_traverse();
                break;
            }
            default:
                exit(0);
        }

        printf("\nPress 1 to continune || 0 to exit: ");
        scanf("%d",&n);

        if(n==0 || n!=1) 
            exit(0);

    }

    return 0;
}

void create()
{
    int k,n=1;

    while (n==1)
    {
        struct node *p=(struct node*)malloc(sizeof(struct node));

        printf("Enter the data of node: ");
        scanf("%d",&k);

        p->data=k;
        p->next=NULL;
        p->prev=NULL;

        if(start==NULL)
            {
                start=p;
                last=p;
            }
        else
            {
                last->next =p;
                p->prev=last;
                last=p;
            }  

        printf("Press 1 to continue create function || 0  to exit: ");
        scanf("%d",&n);
        
    }
    
}

void forward_traverse()
{
    struct node *t=start;
    printf("\nThe linked list of data forward direction:  ");
    while (t->next!=NULL)
    {
        printf("%d -> ",t->data);
        t=t->next;
    }
    printf("%d ", t->data);
}

void reverse_traverse()
{
    struct node *t=last;

    printf("\nThe list of data reverse direction:  ");
    while (t->prev!=NULL)
    {
        printf("%d -> ",t->data);
        t=t->prev;
    }
    printf("%d ", t->data);
}