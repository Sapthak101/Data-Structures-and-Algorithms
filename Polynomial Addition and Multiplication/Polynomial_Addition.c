#include<stdio.h>
#include<stdlib.h>

struct node {
    int exp;
    int cof;    
    struct node *next;
};

void create (struct node **h);
void join (struct node **h1, struct node *h2);
void simplify (struct node **h1);
void display(struct node **h);

int main()
{
    struct node *h1, *h2;

    create (&h1);
    create (&h2);
    join (&h1, h2);
    simplify (&h1);
    display (&h1);

    return 0;
}

void create (struct node **h)
{
    int n, i;
    struct node *cur, *ptr;

    printf("Enter the number of elementary expressions you want to create: \n");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        cur=malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent part: \n");
        scanf("%d %d", &cur->cof, &cur->exp);
        cur->next=NULL;

        if (*h==NULL)
        {
            *h=cur;
            ptr=cur;
        }
        else
        {
            ptr->next=cur;
            ptr=cur;
        }
    }
}

void join(struct node **h1, struct node *h2)
{
    if (*h1==NULL)
        *h1=h2;
    else
    {
        struct node *ptr; 
        for (ptr=*h1; ptr->next!=NULL; ptr=ptr->next);
        ptr->next=h2;
    }
}

void simplify (struct node **h1)
{
    struct node *ptr, *ptr1, *prev;

    ptr=*h1;

    for (ptr=*h1; ptr!=NULL; ptr=ptr->next)
    {
        prev=ptr;
        ptr1=ptr->next;

        while (ptr1!=NULL)
        {
            if (ptr1->exp==ptr->exp)
            {
                ptr->cof+=ptr1->cof;
                prev->next=ptr1->next;
                free(ptr1);
                ptr1=prev;
            }
            prev=ptr1;
            ptr1=ptr1->next;
        }
    }
}

void display(struct node **h1)
{
    struct node *temp;

    temp=*h1;

    printf("Polynomial Addition: ");

    printf("Printing the exponent part: \n");
    for (temp; (temp->next)!=NULL; temp=temp->next)
    {
        printf("%d ", temp->exp);
    }

    printf("\n\n");
    temp=*h1;

    printf("Printing the coefficient part: \n");
    for (temp; (temp->next)!=NULL; temp=temp->next)
    {
        printf("%d ", temp->cof);
    }
}