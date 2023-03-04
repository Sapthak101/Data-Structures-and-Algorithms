#include<stdio.h>
#define MAX 10000

void insertion_sort(int *a, int size);

int main()
{
    int a[MAX], size;

    printf("Enter the array size: ");
    scanf("%d", &size);

    printf("Enter the array elements: ");
    for (int i=0; i<size; i++)
        scanf("%d", &a[i]);

    insertion_sort(a, size);

    printf("Displaying the array elements: ");
    for (int i=0; i<size; i++)
        printf("%d ", a[i]);    

    return 0;
}

void insertion_sort(int *a, int size)
{
    int temp, j=0;

    for(int i=1; i<size; i++)
    {
        temp=a[i];
        for (j=i-1; j>=0; j--)
        {
            if (a[j]<temp)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=temp;
    }
}