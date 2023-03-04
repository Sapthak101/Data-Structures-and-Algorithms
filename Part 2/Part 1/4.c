#include<stdio.h>
int main()
{
    int a[100], i, j, n, max, count=0;

    printf("Enter the number of elements that you want to enter in the array: \n");
    scanf("%d", &n);

    printf("Enter the array elements: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    max=a[0];
    for (i=0; i<n; i++)
    {
        if (max<a[i])
        {
            max=a[i];
        }

        if (i==n-1)
        {
            for (j=0; j<n; j++)
            {
                if (a[j]==max)
                    count++;
            }
        }
    }

    printf("The maximum element in the array is %d with"
                           " %d occurances", max, count);

 return 0;
}