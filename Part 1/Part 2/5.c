#include<stdio.h>
int main()
{
    int n, i, j, n1, k;
    int a[100][100], temp;

    printf("Enter the dimension of the array: \n");
    scanf("%d %d", &n, &n1);

    printf("The elements of A: \n");
    for (i=0; i<n1; i++)
    {
        for (j=0; j<n; j++)
        {
            scanf("%d", &a[j][i]);
        }
    }
    for (k=0; k<n1; k++)
    {
        for (i=0; i<n-1; i++)
        {
            for (j=0; j<(n-i)-1; j++)
            {
                if (a[j][k]>a[j+1][k])
                {
                    temp=a[j+1][k];
                    a[j+1][k]=a[j][k];
                    a[j][k]=temp;
                }
            }
        }
    }

    for (k=0; k<n; k++)
    {
        for (i=0; i<n1-1; i++)
        {
            for (j=0; j<(n1-i)-1; j++)
            {
                if (a[k][j]<a[k][j+1])
                {
                    temp=a[k][j+1];
                    a[k][j+1]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
    }

    printf("The sorted array: \n");
    for (i=0; i<n1; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }

    return 0;
}