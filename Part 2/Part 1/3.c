#include<stdio.h>
int main()
{
    int a[100];
    int b[100];
    int i, j=0, n;

    printf("Enter the number of array element: \n");
    scanf("%d", &n);

    printf("Enter the array elements: \n");
    for (i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("The multiplication between the previous and the next element: \n");
    printf("%d ", a[1]);
    for (i=1; i<n-1; i++)
    {
        b[j++]=a[i-1]*a[i+1];
    }

    for (j=0; j<n-2; j++)
        printf("%d ", b[j]);

    printf("%d", a[n-2]);

    return 0;
}