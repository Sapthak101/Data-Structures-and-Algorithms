#include<stdio.h>
#include<stdlib.h>

struct node{
    double data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void task1(struct node *h);
void task2(struct node *h);
void task3(struct node **h, int x);
void task4(struct node **h, double x);
void task5(struct node **h, int x);
void task6(struct node *h);
void task7(double x);

int main()
{
    int n, choice, key, i, pos, pos1;
    struct node *cur;

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

    do
    {
    printf("\n\n");
    printf("...........................................................\n");
    printf("Enter 1 to traverse the list \n");
    printf("Enter 2 to check if the list is empty or not \n");
    printf("Enter 3 to insert a node at the certain position ");
    printf("at beginning/end/any position \n");
    printf("Enter 4 to delete a node at the certain position ");
    printf("at beginning/end/any position \n");
    printf("Enter 5 Delete a node for the given key \n");
    printf("Enter 6 to count the total number of nodes \n");
    printf("Enter 7 to search an element in the linked list \n");
    printf("............................................................\n");
    printf("\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    
        switch(choice)
        {
            case 1:{
                printf("List Traversing \n\n");
                task1(head);
                break;
            }
            case 2:{
                printf("Checking whether the list is empty or not\n\n");
                task2(head);
                break;
            }          
            case 3:{
                printf("\n\nNode indexing is done from '''1''' onwards \n\n");
                printf("Enter the position in which you want to insert the data: \n");
                scanf("%d", &pos);
                task3(&head, pos);
                task1(head);
                break;
            }
                    
            case 4:{
                double val;
                printf("Enter the value that you want to delete: ");
                scanf("%lf", &val);
                task4(&head, val);
                task1(head);
                break;
            }        
            case 5:{
                int x;
                printf("\n\nNode indexing is done from '''1''' onwards \n\n");
                printf("Enter the postion in which you want to delete the node: ");
                scanf("%d", &pos1);
                task5(&head, pos1);
                task1(head);
                break;
            }                  
            case 6:{
                task6(head);
                break;
            }
            case 7:{
                double val;
                printf("Enter the value that you want to search\n");
                scanf("%lf", &val);
                task7(val);
                break;
            }
            default :
                printf("The entered operation is invalid\n");
        }

        printf("Enter 1 to continue or any other number to exit: ");
        scanf("%d", &key);
    } while (key==1);
    
    return 0;
}

void task1(struct node *h)
{
    for (h; h!=NULL; h=h->next)
    {
        printf("Data= %.2lf | Address= %u | Next Address= %u\n", 
                                       h->data, h, h->next);
    }
}

void task2(struct node *h)
{
    if (h==NULL)
        printf("The list is empty\n");
    else    
        printf("The list is not empty\n");
}

void task3(struct node **h, int x)
{   
    double n;

    printf("Enter your desired data (Real Number): ");
    scanf("%lf", &n);

    struct node *cur, *ptr;
    cur=(struct node *)malloc(sizeof(struct node));
    cur->data=n;
    cur->next=NULL;

    if (*h==NULL)
    {
        *h=cur;
    }
    else if (x==1)
    {
        cur->next=*h;
        *h=cur;
    }
    else
    {
        int i=1;
        ptr=*h;
        while (i<x-1 && ptr->next!=NULL)
        {
            ptr=ptr->next;
            i++;
        }
        cur->next=ptr->next;
        ptr->next=cur;
    }
}

void task4(struct node **h, double x)
{
    struct node *ptr, *prv;

    if (*h==NULL)
    {
        printf("The list is empty\n");
    }
    else 
    {
        ptr=*h;
        while (ptr!=NULL)
        {
            if (ptr->data==x)
                break;
            else
            {
                prv=ptr;
                ptr=ptr->next;
            }
        }
        if (ptr==NULL)
        {
            printf("The data is not found\n");
        }
        else if (ptr==*h)
        {
            *h=ptr->next;
            free(ptr);
        }
        else
        {
            prv->next=ptr->next;
            free(ptr);
        }
    }
}

void task5(struct node **h, int x)
{
    struct node *ptr, *prv;
    int i=1;

    if (*h==NULL)
    {
        printf("The list is empty\n");
    }
    else 
    {
        ptr=*h;

        while (i<x) 
        {
            if (ptr==NULL)
                break;
            else
            {
                prv=ptr;
                ptr=ptr->next;
                i++;
            }
        }

        if (ptr==NULL)
        {
            printf("The data is not found\n");
        }
        else if (ptr==*h)
        {
            *h=ptr->next;
            free(ptr);
        }
        else
        {
            prv->next=ptr->next;
            free(ptr);
        }
    }
}

void task6(struct node *h)
{
    int count=0;
    for (h; h!=NULL; h=h->next)
    {
        count++;
    }
    printf("The number of nodes is %d\n", count);
}

void task7(double x)
{
    struct node *ptr;

    for (ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        if (ptr->data==x)
        {
            printf("The number is found\n");
            break;
        }
    }
}