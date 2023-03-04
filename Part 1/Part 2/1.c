#include<stdio.h>
int main()
{
    int n, i, j;
    int a[100], temp;

    printf("Enter the number of element that you want to enter: \n");
    scanf("%d", &n);

    printf("The elements of A: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }

    printf("The sorted array in the assending order \n");
    for (i=0; i<n; i++)
    {
        printf("%d\n", a[i]);
    }

    printf("The second smallest element of the array is: %d\n", a[1]);
    printf("The second largest element of the array is: %d\n", a[n-2]);

    return 0;
}