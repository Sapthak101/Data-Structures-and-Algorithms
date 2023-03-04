#include<stdio.h>
int main()
{
    int a[100];
    int i, n;

    printf("Enter the number of elements that you want to enter in the array: \n");
    scanf("%d", &n);

    printf("Enter the array elements: \n");
    for (i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("The Even numbers followed by the Odd numbers: \n");
    for (i=0; i<n; i++)
    {
        if (a[i]%2==0)
            printf("%d ", a[i]);
    }

    for (i=0; i<n; i++)
    {
        if ((a[i]%2)!=0)
            printf("%d ", a[i]);
    }

    return 0;
}