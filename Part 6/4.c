#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head=NULL;

int main()
{
    int n, i, j, data1, count, count1, num;
    struct node *cur, *prv, *temp, *tail;

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
            head=(cur->next)=prv=tail=cur;
        }
        else{
            cur->next=prv->next;
            prv->next=cur;
            prv=tail=cur;
        }
    }

    temp=head;
    for (temp; temp->next!=head; temp=temp->next){
        count++;
    }
    count++;
    printf("Enter the total number of nodes: %d\n", count);

    printf("Enter the count value: \n");
    scanf("%d", &count1);

    if (count1<n){
        if (count>count1)
        {
            temp=head;
            num=count-count1;
            for (i=0; i<num; i++)
            {
                head=temp->next;
                prv=temp;
                temp=temp->next;
                free(prv);
            }
            head=temp;

            temp=head;
            tail->next=head;
            printf("The remaining nodes after deletion: \n");
            for (temp; temp->next!=head; temp=temp->next){
                printf("%d-> ", temp->data);
            }
            printf("%d", temp->data);
        }
        else
            printf("Further operation not required");
    }
    else
        printf("Invalid count");
        
    return 0;
}