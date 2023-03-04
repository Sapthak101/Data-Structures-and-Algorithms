#include<stdio.h>
#include<stdlib.h>

struct node{
    double data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void task1(int y);

int main()
{
    int n, choice, key, i;
    struct node *cur;
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

    struct node *ptr, *ptr2;
    double x;
    int count=0;

    for (ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        x=ptr->data;
        for (ptr2=head; ptr2!=NULL; ptr2=ptr2->next)
        {
            if (ptr2->data==x)
            {
                count++;
            }
        }
        printf("The occurance of %.2lf is %d\n", x, count);
        count=0;
    }

    return 0;
}