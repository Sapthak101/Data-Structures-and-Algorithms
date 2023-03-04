#include<stdio.h>
#include<stdlib.h>

struct node {
    int exp;
    int cof;    
    struct node *next;
};

void create (struct node **h);
void multiply(struct node *h1, struct node *h2, struct node **h);
void simplify (struct node **h1);
void display(struct node **h);

int main()
{
    struct node *h1=NULL, *h2=NULL, *h=NULL;

    create (&h1);
    create (&h2);
    multiply (h1, h2, &h);
    simplify (&h);
    display (&h);

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

void multiply(struct node *h1, struct node *h2, struct node **h)
{
    struct node *ptr1, *ptr2, *cur, *ptr;

    for (ptr1=h1; ptr1!=NULL; ptr1=ptr1->next)
    {
        for (ptr2=h2; ptr2!=NULL; ptr2=ptr2->next)
        {
            cur=malloc(sizeof (struct node));
            cur->cof=ptr1->cof*ptr2->cof;
            cur->exp=ptr1->exp+ptr2->exp;
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
    
    printf("Polynomial Multiplication: \n");

    printf("Printing the exponent part: \n");
    for (temp; (temp->next)!=NULL; temp=temp->next)
    {
        printf("%d ", temp->exp);
    }
    printf("%d ", temp->exp);

    printf("\n\n");
    temp=*h1;

    printf("Printing the coefficient part: \n");
    for (temp; (temp->next)!=NULL; temp=temp->next)
    {
        printf("%d ", temp->cof);
    }
    printf("%d ", temp->cof);
}