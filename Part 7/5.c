#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

int main()
{
    int n, i, j, k;
    struct node *cur, *temp;

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
        scanf("%d", &cur->data);
        cur->next=NULL;
        if (head==NULL){
            tail=head=cur;
        }
        else{
            tail->next=cur;
            tail=cur;
        }
    }

    printf("\n\n");

    struct node *t=head;
    printf("\nThe linked list of data forward direction:  ");
    while (t->next!=NULL)
    {
        printf("%d -> ",t->data);
        t=t->next;
    }
    printf("%d \n", t->data);

    printf("Printing the linked list in the reverse order (implementing double linked list)\n");
    temp=head;
    k=n;
    for (i=0; i<n; i++)
    {
        for (j=0; j<k-1; j++)
        {
            temp=temp->next;
        }
        k--;
        if (temp!=head)
            printf("%d-> ", temp->data);
        temp=head;
    }
    printf("%d", temp->data);

    return 0;
}

