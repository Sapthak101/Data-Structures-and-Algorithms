#include<stdio.h>
int main()
{
    int a[100], b[100];
    int n, i, j, k=0;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    
    printf("Enter the array elements: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (j=n-1; j>=0; j--)
    {
        b[k++]=a[j];
    } 

    printf("The reverse array is \n");
    for (i=0; i<n; i++)
    {
        printf("%d \n", b[i]);
    }

    return 0;
}