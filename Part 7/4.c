#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*start=NULL, *last=NULL;

void create();
void sort();
void dup_delete();
void display();

int main()
{
    create();
    sort();
    dup_delete();

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

void sort()
{
    int temp;
    struct node *ptr, *ptr2;

    ptr=start;
    ptr2=start->next;
    for (ptr; (ptr!=NULL && ptr2!=NULL); ptr=ptr->next)
    {
        for (ptr2; ptr2!=NULL; ptr2=ptr2->next)
        {
            if (ptr->data>ptr2->data)
            {
                temp=ptr->data;
                ptr->data=ptr2->data;
                ptr2->data=temp;
            }
        }
        ptr2=ptr->next;
    }
    
    display();
}

void dup_delete()
{
    struct node *ptr2, *temp, *ptr;

    ptr=start;
    ptr2=start->next;
    for (ptr; (ptr!=NULL && ptr2!=NULL); ptr=ptr->next)
    {
        for (ptr2; ptr2!=NULL; ptr2=ptr2->next)
        {
            if (ptr->data==ptr2->data)
            {
                if (ptr2->next!=NULL)
                {
                    temp=ptr2->prev;
                    ptr2->prev->next=ptr2->next;
                    ptr2->next->prev=ptr2->prev;
                    free(ptr2);
                    ptr2=temp;
                }
                else
                {

                    temp=ptr2->prev;
                    ptr2->prev->next=NULL;
                    free(ptr2);
                    ptr2=temp;
                }
            }
        }
        ptr2=ptr->next->next;
    }

    display();
}

void display()
{
    struct node *t=start;
    printf("\nThe sorted assending linked list after deleting all the duplicates:  ");
    while (t->next!=NULL)
    {
        printf("%d -> ",t->data);
        t=t->next;
    }
    printf("%d \n", t->data);
}