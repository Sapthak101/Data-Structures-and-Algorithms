#include<stdio.h>
int main()
{
    int n, i, j, e, b, c, d, count=0, count1=0, count2=0;
    int a[100], temp;

    printf("Enter the number of element that you want to enter: \n");
    scanf("%d", &n);

    printf("The elements of A: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the boundary conditions : \n");
    scanf("%d %d", &e, &b);

    for (i=0; i<n; i++)
    {
        if (e==a[i])
        {
            count++;
            c=i;
            break;
        }    
    }

    for (i=n-1; i>=0; i--)
    {
        if (b==a[i])
        {
            count1++;
            d=i;
            break;
        }
    }

    if (count>0 && count1>0)
    {
        printf("The number between the enclosed boundary is: \n");
        for (j=c; j<=d; j++)
        {
            printf("%d ", a[j]);
            count2++;
        }
    }
    else
    printf("Invalid boundary condition \n");
    printf("\nThe output is %d", count2);

    return 0;
}