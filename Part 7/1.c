#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*start=NULL, *last=NULL;

void create();
void display();

int main()
{
    int c,n=1;

    while (n==1)
    {
        printf("1.Create a linked list \n2.Traverse / display the linked list\n");
        printf("Enter the  opertation you want to perform: ");
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
                display();
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

        printf("Press 1 to continue create function|| 0  to exit: ");
        scanf("%d",&n);
        
    }
    
}

void display()
{
    struct node *t=start;
    printf("\n Displaying the linked list: ");
    while (t->next!=NULL)
    {
        printf("%d -> ",t->data);
        t=t->next;
    }
    printf("%d ", t->data);
}