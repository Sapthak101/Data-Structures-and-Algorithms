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
    int n, choice, key, i, j, k, temp1;
    struct node *cur, *temp, *index, *prv;

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

    printf("The node indexing is done fgrom ''''0'''' onwards: \n");
    printf("Enter the position: ");
    scanf("%d", &k);

    temp=head;
    for (i=0; i<k; i++)
    {
        temp=temp->next;
    }

    index=head;
    for (j=0; j<n-k-1; j++)
    {
        index=index->next;
    }

    temp1=temp->data;
    temp->data=index->data;
    index->data=temp1;

    printf("\nNode data preview after swapping: \n");
    temp=head;
    for (temp; temp->next!=NULL; temp=temp->next){
        printf("%d -> ", temp->data);
    }
    printf("%d", temp->data);

}