#include<stdio.h>
int main()
{
    int a[100];
    int n, max, i, min, j;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    
    printf("Enter the array elements: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    max=a[0];
    for (i=0; i<n; i++)
    {
        if (a[i]>max)
            max=a[i];
    }
    printf("The maximum number in the array is %d \n", 
    max);

    min=a[0];
    for (j=0; j<n; j++)
    {
        if (a[j]<min)
            min=a[j];
    }
    printf("The minimum number in the array is %d \n", min);

    return 0;
}