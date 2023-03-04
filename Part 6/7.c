#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head=NULL;

int main()
{
    int n, i, j, data, temp1;
    struct node *cur, *prv, *temp, *index;

    printf("Enter the number of nodes that you want to enter: \n");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        cur=(struct node *)malloc(sizeof(struct node));
        printf("Enter the node data: ");
        scanf("%d", &data);

        cur->data=data;
        cur->next=NULL;

        if (head==NULL){
            head=(cur->next)=prv=cur;
        }
        else{
            cur->next=prv->next;
            prv->next=cur;
            prv=cur;
        }
    }

    printf("Node data preview: \n");
    temp=head;
    for (temp; temp->next!=head; temp=temp->next){
        printf("%d -> ", temp->data);
    }
    printf("%d", temp->data);

    temp=head;
    index=head;
    for (i=0; i<((n/2)); i++) 
    {
            for (j=0; j<n-i-1; j++){
                temp=temp->next;
            }
            temp1=index->data;
            index->data=temp->data;
            temp->data=temp1;

            temp=head;
            index=index->next;
    }

    printf("\nNode data preview after swapping: \n");
    temp=head;
    for (temp; temp->next!=head; temp=temp->next){
        printf("%d -> ", temp->data);
    }
    printf("%d", temp->data);
} 