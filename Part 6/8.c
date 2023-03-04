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
    int n, choice, key, i, j, k, temp1, count=0;
    struct node *cur, *temp, *index, *prv, *temp2, *prv2;

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
    
    printf("Enter the value of k: ");
    scanf("%d", &k);

    temp=head;
    index=head;
    temp2=head;
    prv2=head;

    while (prv!=NULL)
    {
        
        for (i=0; i<(k/2); i++) 
        {
                for (j=0; (j<k-i-1); j++){
                    temp=temp->next;
                }

                temp1=index->data;
                index->data=temp->data;
                temp->data=temp1;

                temp=prv2;
                index=index->next;
                
                for (j=0; (j<k-i-1 && prv!=NULL); j++){
                    count++;
                    if (count==1)
                    {
                        temp2=temp2->next;
                        prv=temp2->next;
                    }
                }
        }
        
        temp=index=prv2=prv;
        count=0;
    }

    printf("\nNode data preview after swapping: \n");
    temp=head;
    for (temp; temp->next!=NULL; temp=temp->next){
        printf("%d -> ", temp->data);
    }
    printf("%d", temp->data);

    return 0;
}