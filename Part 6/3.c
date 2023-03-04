#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head=NULL, *tail=NULL;

int main()
{
    int n, i, data1, temp1;
    struct node *cur, *prv, *temp, *index;

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

    printf("Before swapping the node keys: \n");
    temp=head;
    for (temp; temp->next!=NULL; temp=temp->next){
        printf("%d -> ", temp->data);
    }
    printf("%d", temp->data);

    temp=head;
    index=head->next;
    
    for (i=0; i<(n/2); i++){
        if (temp->data>index->data){
            temp1=temp->data;
            temp->data=index->data;
            index->data=temp1;
        }

        temp=temp->next->next;
        index=index->next->next;
    } 

    printf("\n\n");

    printf("After swapping the node keys: \n");
    temp=head;
    for (temp; temp->next!=NULL; temp=temp->next){
        printf("%d -> ", temp->data);
    }
    printf("%d", temp->data);

    return 0;
}