#include<stdio.h>
#include<stdlib.h>

struct node{
    double data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

struct node2{
    double data;
    struct node2 *next;
};
struct node2 *head2=NULL;
struct node2 *tail2=NULL;

void task1(int y);

int main()
{
    int n, choice, key, i;
    struct node *cur;
    struct node2 *cur2;
    double n1;

    printf("\n\n");
    printf("Node Creation ");
    printf("\n");

    printf("Enter the number of nodes that you want to create: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Node: %d\n", i+1);
        cur=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value for the node: ");
        scanf("%lf", &cur->data);
        cur->next=NULL;
        if (head==NULL){
            tail=head=cur;
        }
        else{
            tail->next=cur;
            tail=cur;
        }
    }

    struct node *ptr; 
    struct node2 *ptr2;

    printf("The modified linked list: \n");                                    
    for (ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        if ((int)ptr->data%2==0)
        {   
            cur2=(struct node2 *)malloc(sizeof(struct node2));
            cur2->data=ptr->data;
            cur2->next=NULL;
            if (head2==NULL){
            tail2=head2=cur2;
            }
            else{
                tail2->next=cur2;
                tail2=cur2;
            }
        }   
    }

    for (ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        if ((int)ptr->data%2!=0)
        {
            cur2=(struct node2 *)malloc(sizeof(struct node2));
            cur2->data=ptr->data;
            cur2->next=NULL;
            if (head==NULL){
            tail2=head2=cur2;
            }
            else{
                tail2->next=cur2;
                tail2=cur2;
            }
        }   
    }
    
    ptr2=head2;
    while (ptr2!=NULL)
    {
        printf("Data= %.2lf | Address= %u | Next Address= %u\n", ptr2->data, ptr2, ptr2->next);
        ptr2=ptr2->next;
    }

    return 0;
}