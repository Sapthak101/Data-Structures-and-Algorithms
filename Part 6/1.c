#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head=NULL;

int main()
{
    int n, i, j, data1, temp1;
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

    printf("\n\n");

    temp=head;
    index=head->next;
    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){
            if ((temp->data)>(index->data)){
                temp1=temp->data;
                temp->data=index->data;
                index->data=temp1;
            }
            index=index->next;
        }
        temp=temp->next;
        index=temp->next;
    }

    temp=head;
    index=head->next;
    prv=head;
    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){
            if (temp->data==index->data){
                prv->next=index->next;
                free(index);
                index=prv;
            }
            prv=index;
            index=index->next;
        }
        prv=temp=temp->next;
        index=temp->next;
    }
    
    printf("The circular linked list after deleting the duplicates and keeping it in a sorted order: \n");
    temp=head;
    for (temp; temp->next!=head; temp=temp->next){
        printf("%d -> ", temp->data);
    }
    printf("%d", temp->data);

    return 0;
}