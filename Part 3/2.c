#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void additionpoly(int *a, int *b, int c, int d);
int main()
{
    int x, i, x1;
    int *ptr, *ptr1;

    printf("Enter the details of polymonial-1\n");
    printf("Enter the order of the polynomial-1: \n");
    scanf("%d", &x);

    ptr=(int *)calloc(x, sizeof(int));

    printf("Enter the details of polymonial-2\n");
    printf("Enter the order of the polynomial-2: \n");
    scanf("%d", &x1);

    ptr1=(int *)calloc(x1, sizeof(int));

    printf("Enter the %d coefficients of polynomial-1 : \n", x+1);
    for (i=x; i>=0; i--)
    {
        scanf("%d", ptr+i);
    }

    printf("Enter the %d coefficients of polynomial-2 : \n", x1+1);
    for (i=x1; i>=0; i--)
    {
        scanf("%d", ptr1+i);
    }

    printf("The Polynomial-1 is: \n");
    for (i=x; i>=0; i--)
    {
        printf(" %d x X^%d ", *(ptr+i), i);
            if (i!=0)
                printf(" + ");
    }

    printf("\n");

    printf("The Polynomial-2 is: \n");
    for (i=x1; i>=0; i--)
    {
        printf(" %d x X^%d ", *(ptr1+i), i);
            if (i!=0)
                printf(" + ");
    }

    printf("\n");

    additionpoly(ptr, ptr1, x, x1);

    return 0;
}

void additionpoly(int *a, int *b, int c, int d)
{
    int i, e;
    int *ptr2;
    
    if (c>d)
        {
            e=c;
        }
    else if (d>c)
        {
            e=d;
        }
    else
        {
            e=c;
        }

    ptr2=(int *)calloc(e, sizeof(int));

    for (i=e; i>=0; i--)
    {
        *(ptr2+i)=*(a+i)+*(b+i);
    }

    printf("The addition of the two polynomials is: \n");
    for (i=e; i>=0; i--)
    {
        printf(" %d x X^%d ", *(ptr2+i), i);
        if (i!=0)
            printf(" + ");
    }

    free(a);
    free(b);
    free(ptr2);
}