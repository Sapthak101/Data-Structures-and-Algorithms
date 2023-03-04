#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void task1_node_traversing(struct node *h);
void task2_list_empty_or_not(struct node *h);
void task3_node_insertion(struct node **h, int x);
void task4_node_deletion_pos(struct node **h, int x);
void task5_node_deletion_key(struct node **h, int x);
void task6_node_count(struct node *h);
void task7_node_searching(int x);

int main()
{
    int n, choice, key, i, pos, pos1, val;
    struct node *cur, *ptr;

    printf("\n\n");
    printf("Node Creation ");
    printf("\n");

    printf("Enter the number of nodes that you want to create: ");
    scanf("%d", &n);

    if (n>0)
    {
        for (i=0; i<n; i++)
        {
            printf("Node: %d\n", i+1);

            cur=(struct node *)malloc(sizeof(struct node));
            if (cur!=NULL){
                printf("Enter the value for the node: ");
                scanf("%d", &cur->data);

                cur->next=NULL;

                if (head==NULL){
                    head=cur;
                    cur->next=head;
                    ptr=head;
                }

                else{
                    cur->next=head;
                    ptr->next=cur;
                    ptr=cur;
                }
            } 
            else
                printf("Enough space is not available\n");
        }
    }
    else
    {
        task2_list_empty_or_not(head);
        printf("Node creation declined\n");
        return 0;
    }

    do
    {
    printf("\n\n");
    printf("...........................................................\n");
    printf("Enter 1 to traverse the list \n");
    printf("Enter 2 to check if the list is empty or not \n");
    printf("Enter 3 to insert a node at the certain position ");
    printf("                                   \n");
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
                task1_node_traversing(head);
                break;
            }
            case 2:{
                printf("Checking whether the list is empty or not\n\n");
                task2_list_empty_or_not(head);
                break;
            }      
            case 3:{
                printf("\n\nNode indexing is done from '''1''' onwards following a cyclic manner \n\n");
                printf("Enter the position in which you want to insert the data: \n");
                scanf("%d", &pos);
                task3_node_insertion(&head, pos);
                task1_node_traversing(head);
                break;
            }    
            case 4:{
                printf("Enter the position in which you want to delete the node: \n");
                scanf("%d", &pos1);
                task4_node_deletion_pos(&head, pos1);
                task1_node_traversing(head);
                break;
            }      
            case 5:{
                int x;
                printf("\n\nNode indexing is done from '''1''' onwards in a cyclic manner \n\n");
                printf("Enter the node data that you want to delete: \n");
                scanf("%d", &val);
                task5_node_deletion_key(&head, val);
                task1_node_traversing(head);
                break;
            }              
            case 6:{
                task6_node_count(head);
                break;
            }
            case 7:{
                int val;
                printf("Enter the value that you want to search\n");
                scanf("%d", &val);
                task7_node_searching(val);
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
 
void task1_node_traversing(struct node *h)
{
    struct node *ptr2;

    ptr2=h;

    if (h!=NULL)
    {
        while (ptr2->next!=head){
            printf("Data-> %d, ", ptr2->data);
            ptr2=ptr2->next;
        }
        printf("Data-> %d", ptr2->data);
        printf("\n\n");
    }
    else
        printf("The list is empty\n");
}

void task2_list_empty_or_not(struct node *h)
{
    if (h==NULL)
        printf("The list is empty\n");
    else
        printf("The list is not empty\n");
}

void task3_node_insertion(struct node **h, int x)
{
    int data1, i;
    struct node *cur, *temp;

    printf("Enter the node data: \n");
    scanf("%d", &data1);

    cur=(struct node *)malloc(sizeof(struct node));
    if (cur!=NULL){
        cur->next=NULL;
        cur->data=data1;

        if (*h==NULL){
            *h=cur;
            cur->next=cur;
        }
        else if (x==1){
            temp=*h;

            while (temp->next!=*h){
                temp=temp->next;
            }

            cur->next=*h;
            *h=cur;
            temp->next=cur;
        }
        else{
            temp=*h;
            i=1;

            while (i<x-1){
                temp=temp->next;
                i++;
            }
            if ((temp->next)!=head)
            {
                cur->next=temp->next;
                temp->next=cur;
            }
            else
            {
                cur->next=temp->next;
                temp->next=cur;
                head=cur;
            }
        }
    }
    else
        printf("Enough space is not avalibale\n");
}

void task4_node_deletion_pos(struct node **h, int x){
    if (*h==NULL){
        printf("There are no nodes created\n");
    }
    else if (x==1){
        struct node *temp, *ptr;

        temp=ptr=*h;

        while ((temp->next)!=*h){
            temp=temp->next;
        }
        
        temp->next=ptr->next;
        *h=ptr->next;
        free(ptr);
    }
    else{
        struct node *prv, *temp;
        int i=1;

        temp=*h;

        while (i<x){
            prv=temp;
            temp=temp->next;
            i++;
        }
        if ((prv->next)!=*h)
        {
            prv->next=temp->next;
            free(temp);
        }
        else
        {
            prv->next=temp->next;
            free(temp);
            *h=prv->next;
        }
    }
}

void task5_node_deletion_key(struct node **h, int key){

    struct node *ptr, *prv;

    if (*h==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        ptr=*h;
        while (ptr->data!=key && ptr->next!=head){
            prv=ptr;
            ptr=ptr->next;
        }
        if (ptr->next==*h && ptr->data!=key){
            printf("Data not found\n");
        }
        else if ((*h)==(*h)->next){
            *h=NULL;
            free(ptr);
        }
        else if (ptr==*h){
            struct node *temp=*h;

            while (temp->next!=(*h)){
                temp=temp->next;
            }
            *h=ptr->next;
            temp->next=*h;
            free(ptr);
        }
        else{
            prv->next=ptr->next;
            free(ptr);
        }
    }
}

void task6_node_count(struct node *h)
{
    int count=0;
    struct node *ptr=h;
    do
    {
        count++;
        ptr=ptr->next;
    } while (ptr!=head);

    printf("The number of nodes is %d\n", count);
}

void task7_node_searching(int x)
{
    struct node *ptr;
    int flag=0;

    ptr=head;
    do
    {
        if (ptr->data==x)
            flag=1;
        ptr=ptr->next;
    } while (ptr!=head);

    if (flag==1)
        printf("The value %d is found\n", x);
    else
        printf("The value %d is not found\n", x);
}