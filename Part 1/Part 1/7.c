#include<stdio.h>
void nonzero(int a[100][100], int c);
void lead(int a[100][100], int c);
void minor(int a[100][100], int c);
void diag(int a[100][100], int c);

int main()
{   
    int c, b, choice, i, j;
    int a[100][100];

    printf("Enter the size of the matrix : \n");
    scanf("%d", &c);

    printf("Enter the matrix elements: \n");
    for (i=0; i<c; i++)
    {
        for (j=0; j<c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter 1 for finding the number of non-zero elements in the matrix \n");
    printf("Enter 2 for finding the sum of the elements above the leading diagonal \n");
    printf("Enter 3 to display the elements below the minor diagonal \n");
    printf("Enter 4 to find the product of the diagonal elements \n");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
    {
        nonzero(a, c);
        break;
    }
    case 2:
    {
        lead(a, c);
        break;
    }
    case 3:
    {
        minor(a, c);
        break;
    }
    case 4:
    {
        diag(a, c);
        break;
    }
    default:
        printf("Invalid choice");
    }

    return 0;
}


void nonzero(int a[100][100], int c)
{
    int i, j, count=0;

    for (i=0; i<c; i++)
    {
        for (j=0; j<c; j++)
        {
            if (a[i][j]!=0)
                count++;
        }
    }
    printf("The number of non-zero elements is: %d", count);
}
void lead(int a[100][100], int c)
{
    int i, j, sum=0;

    for (i=0; i<c; i++)
    {
        for (j=0; j<c; j++)
        {
            if (j>i)
                sum=sum+a[i][j];
        }
    }
    printf("The sum of the elements above the leading diagonal is: %d", sum);
}

void minor(int a[100][100], int c)
{
    int i, j, sum=0;

    for (i=0; i<c; i++)
    {
        for (j=0; j<c; j++)
        {
            if (i+j>((c+1)-2))
                {
                sum=sum+a[i][j];
                printf("%d ", a[i][j]);
                }
        }
    }
    printf("\nThe sum of the elements below the minor diagonal is: %d", sum);
}

void diag(int a[100][100], int c)
{
    int i, j, sum=1, sum1=1;

    for (i=0; i<c; i++)
    {
        for (j=0; j<c; j++)
        {
            if (j==i)
                sum=sum*a[i][j];
        }
    }

    for (i=0; i<c; i++)
    {
        for (j=0; j<c; j++)
        {
            if (i+j==((c+1)-2))
                sum1=sum1*a[i][j];
        }
    }
    printf("The product of the diagonal elements is: %d", sum*sum1);
}