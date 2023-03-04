#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void task1_traversing(struct node *h);
void task2_empty_or_not(struct node *h);
void task3_insert(struct node **h, int x);
void task4_delete_pos(struct node **h, int x);
void task5_delete_key(struct node **h, int x);
void task6_count(struct node *h);
void task7_search(int x);

int main()
{
    int n, choice, key, i, pos, pos1;
    struct node *cur;

    printf("\n\n");
    printf("Node Creation ");
    printf("\n");

    printf("Enter the number of nodes that you "
    " want to create: ");
    scanf("%d", &n);

    if (n>0)
    {
        for (i=0; i<n; i++)
        {
            printf("Node: %d\n", i+1);
            cur=(struct node *)malloc(sizeof(struct node));
            if (cur!=NULL)
            {
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
            else
                printf("Enough space not available\n");
        }
    }
    else
    {
        task1_traversing(head);
        printf("Node entry declined");
        return 0;
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
    printf("Enter 5 to delete a node for the given key \n");
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
                task1_traversing(head);
                break;
            }
            case 2:{
                printf("Checking whether the list is empty or not\n\n");
                task2_empty_or_not(head);
                break;
            }          
            case 3:{
                printf("\n\nNode indexing is done from '''1''' onwards \n\n");
                printf("Enter the position in which you want to insert the data: \n");
                scanf("%d", &pos);
                task3_insert(&head, pos);
                task1_traversing(head);
                break;
            }
            case 4:{
                int x;
                printf("\n\nNode indexing is done from '''1''' onwards \n\n");
                printf("Enter the postion in which you want to delete the node: ");
                scanf("%d", &pos1);
                task4_delete_pos(&head, pos1);
                task1_traversing(head);
                break;
            }    
            case 5:{
                int key;
                printf("Enter the value that you want to delete: ");
                scanf("%d", &key);
                task5_delete_key(&head, key);
                task1_traversing(head);
                break;
            }                
            case 6:{
                task6_count(head);
                break;
            }
            case 7:{
                int val;
                printf("Enter the value that you want to search\n");
                scanf("%d", &val);
                task7_search(val);
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

void task1_traversing(struct node *h)
{
    struct node *ptr=h;

    while (ptr->next!=NULL)
    {
        printf("Data-> %d, ", ptr->data);
        ptr=ptr->next;
    }
    printf("Data-> %d\n", ptr->data);
}

void task2_empty_or_not(struct node *h)
{
    if (h==NULL)
        printf("The list is empty\n");
    else    
        printf("The list is not empty\n");
}

void task3_insert(struct node **h, int x)
{   
    int n;

    printf("Enter your desired data (Real Number): ");
    scanf("%d", &n);

    struct node *cur, *ptr;
    cur=(struct node *)malloc(sizeof(struct node));
    
    if (cur!=NULL)
    {
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
    else
    {
        printf("Enough space not available\n");
    }
}

void task4_delete_pos(struct node **h, int x)
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

void task5_delete_key(struct node **h, int x)
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

void task6_count(struct node *h)
{
    int count=0;
    for (h; h!=NULL; h=h->next)
    {
        count++;
    }
    printf("The number of nodes is %d\n", count);
}

void task7_search(int x)
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
    if (ptr==NULL) 
        printf("The number is not found\n");
}