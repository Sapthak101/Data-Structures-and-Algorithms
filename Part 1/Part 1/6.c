#include<stdio.h>
int main()
{
    int n, i, j, next;
    int a[100];

    printf("Enter the number of elements that you want to enter in the array: \n");
    scanf("%d", &n);

    printf("Enter the array elements: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("The NGE of the given array is given below: \n");
    for (i=0; i<n; i++)
    {
        next=-1;
        for (j=i+1; j<n; j++)
        {
            if (a[i]<a[j])
            {      
                next=a[j];
                break;
            } 
        }
        printf("%d ", next);
    }                                  
                                                        
    return 0;
}