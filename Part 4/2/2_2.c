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
    int n, choice, key, i, pos, pos1, j, k;
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
    printf("Printing the linked list in the reverse order\n");
    temp=head;
    k=n;
    for (i=0; i<n; i++)
    {
        for (j=0; j<k-1; j++)
        {
            temp=temp->next;
        }
        k--;
        printf("Data-> %d ", temp->data);
        temp=head;
    }
}