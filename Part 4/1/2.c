#include<stdio.h>
#include<stdlib.h>

struct node{
    double data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void task1(double x);

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

    printf("Enter the data for which you want to find the occurance: ");
    scanf("%lf", &n1);

    task1(n1);

    return 0;
}

void task1(double x)
{
    struct node *ptr;
    double temp;
    int count=0, pos=0;

    for (ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        if (ptr->data==x)
        {
            temp=x;
            count++;
        }
    }
    if (count==0)
        printf("Data not found\n");
    else
    {
        printf("The number is found\n");
        printf("The data: %.2lf is found for %d occurances", x, count);
    }
}