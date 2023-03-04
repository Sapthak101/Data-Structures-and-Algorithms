#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*start=NULL,*last=NULL;

void create();
void forward_traverse();
void backward_traverse();
int check();
void insert();
void delete();
void delete_key();
void node_count();
void search_element();

int main()
{
int c,n=1;

while (n==1)
{
    printf("1. Create a doubly linked list\n");
    printf("2. Traverse the list forward\n");
    printf("3. Traverse the list backward\n");
    printf("4. Checking if the linked list is empty or not\n");
    printf("5. Insert a node at the beginning/any position/end\n");
    printf("6. Delete a node at the beginning/any position/end\n");
    printf("7. Delete a node for the given key\n");
    printf("8. Count the total number of nodes\n");
    printf("9. Search for an element in the linked list\n");
    scanf("%d",&c);

    switch (c)
    {
        case 1:
        {
            create();
            break;
        }
        case 2:
        {
            forward_traverse();
            break;
        }
        case 3:
        {
            backward_traverse();
            break;
        }
        case 4:
        {
            int r;
            r=check();
            break;
        }
        case 5:
        {
            insert();
            break;
        }
        case 6:
        {
            delete();
            break;
        }
        case 7:
        {
            delete_key();
            break;
        }
        case 8:
        {
            node_count();
            break;
        }
        case 9:
        {
            search_element();
            break;
        }
        default:
            exit(0);
    }
    printf("\nPress 1 to continune || 0 to exit: ");
    scanf("%d",&n);
    if(n==0 || n!=1) 
        exit(0);

}

}

void create()
{
    int k,n=1;
    while (n==1)
    {
        struct node *p;
        p=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data of node: ");
        scanf("%d",&k);
        p->data=k;
        p->next=NULL;
        p->prev=NULL;
        if(start==NULL){
            start=p;
            last=p;
        }else{
            last->next =p;
            p->prev=last;
            last=p;
        }  
        printf("Press 1 to continue create function|| 0  to exit: ");
        scanf("%d",&n);
        
    }
    
}

void forward_traverse()
{
    struct node *t=start;
    printf("\nThe list of data forward direction:  ");
    while (t->next!=NULL)
    {
        printf("%d -> ",t->data);
        t=t->next;
    }
    printf("%d ", t->data);
}

void backward_traverse()
{
    struct node *t=last;
    printf("\nThe list of data backward direction:  ");
    while (t->prev!=NULL)
    {
        printf("%d -> ",t->data);
        t=t->prev;
    }
    printf("%d ", t->data);
}

int check()
{
    if(start!=NULL)  
    {
        printf("The list is not empty\n");
        return 1; 
    }
    else
    {
        printf("The list is empty\n");
        return 0;
    }
}

void insert()
{
    struct node *ptr;
    int data1, pos;

    ptr=(struct node *)malloc(sizeof(struct node));

    printf("Enter the node data: ");
    scanf("%d", &data1);

    printf("Enter the node position: ");
    scanf("%d", &pos);

    ptr->data=data1;
    ptr->prev=NULL;
    ptr->next=NULL;

    if (start==NULL)
    {
        start=ptr;
    }
    else if (pos==1 && start!=NULL)
    {
        ptr->next=start;
        ptr->prev=NULL;
        ptr->next->prev=ptr;
        start=ptr;
    }
    else
    {     
        struct node *temp;
        int i;

        temp=start;
        for (i=1; (i<pos && (temp->next)!=NULL); i++)
            temp=temp->next;

        if (i==pos)
        {
            temp->prev->next=ptr;
            ptr->prev=temp->prev;
            ptr->next=temp;
            temp->prev=ptr;
        }
        else if (i<pos)
        {
            ptr->prev=temp;
            ptr->next=temp->next;
            temp->next=ptr;
        }
    }

    forward_traverse();
}

void delete()
{
    struct node *temp;
    int pos, i;

    printf("Enter the node position: ");
    scanf("%d", &pos);

    temp=start;
    if (start==NULL)
    {
        printf("The double linked list is empty");
    }
    else
    {
        for (i=1; (i<pos && (temp->next)!=NULL); i++)
            temp=temp->next;

        if (temp==start && temp->next==NULL)
        {
            free(temp);
            start=NULL;
            printf("The linked list is empty");
        }
        else
        {   
            if (temp==start)
            {
                start=temp->next;
                temp->next->prev=NULL;
                free(temp);
            }
            else if (temp->next==NULL)
            {
                temp->prev->next=NULL;
                last=temp->prev;
                free(temp);
            }
            else
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
            }
        }
    }

    forward_traverse();
}

void delete_key()
{
    struct node *temp;
    int data, flag=0;
    temp=start;
    static int count=0;

    printf("Enter the value that you want to delete: ");
    scanf("%d", &data);
    do
    {
        flag=0;
        temp=start;

        for (temp; temp!=NULL; temp=temp->next)
        {
            if (temp->data==data)
            {
                flag=1;
                count++;
                break;
            }
        }

        if (flag==1)
        {
            if (temp==start && temp->next==NULL)
            {
                free(temp);
                start=NULL;
            }
            else
            {
                if (temp==start)
                {
                    start=temp->next;
                    temp->next->prev=NULL;
                    free(temp);
                }
                else if (temp->next==NULL)
                {
                    temp->prev->next=NULL;
                    last=temp->prev;
                    free(temp);
                }
                else
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    free(temp);
                }
            }
        }

    } while (flag!=0);

    if (count==0)
        printf("The data is not found\n");

    forward_traverse();
}

void node_count()
{
    struct node *t=start;
    int count=0;

    while (t!=NULL)
    {
        count++;
        t=t->next;
    }
    printf("The total number of nodes in the linked list is: %d\n", count);
}

void search_element()
{
    struct node *t=start;
    int count=0, num, flag=0;

    printf("\nEnter an element you want to search: ");
    scanf("%d", &num);

    while (t!=NULL)
    {
        if (t->data==num)
        {
            flag=1;
            printf("The number %d is found", t->data);
            break;
        }
        t=t->next;
    }
    
    if (flag==0)
        printf("The number %d is not found\n", num);
}