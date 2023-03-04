#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head=NULL, *tail=NULL;

int main()
{
    int n, i, data1;
    struct node *cur, *prv, *temp;

    printf("Enter the number of nodes that you want to enter: \n");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        cur=(struct node *)malloc(sizeof(struct node));
        printf("Enter the node data: ");
        scanf("%d", &data1);

        cur->data=data1;
        cur->next=NULL;

        if (head==NULL){
            cur->next=NULL;
            head=tail=cur;
            prv=cur;
        }
        else{
            prv->next=cur;
            prv=tail=cur;
        }
    }

    printf("Node data preview: \n");
    temp=head;
    for (temp; temp->next!=NULL; temp=temp->next){
        printf("%d -> ", temp->data);
    }
    printf("%d", temp->data);

    printf("\n\n");

    if ((tail->next)==NULL){
        printf("It is a single linked list\n");

        tail->next=head;
    }

    printf("Address of the first node= %x\n", head);
    printf("Address of the next part of the last node is= %x", tail->next);
    printf("As the address of the first node and the next part of the last node is same ");
    printf("we can conclude that the nodes are now in a circular manner\n");

    return 0;
}
