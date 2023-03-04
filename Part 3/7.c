#include<stdio.h>
#include<stdlib.h>

void occur(int *a, int b);
int main()
{
    int *a, n, i;

    printf("Enter the number of element that you want to enter in the array: \n");
    scanf("%d", &n);

    a=(int*)malloc(n*sizeof(int));

    printf("Enter the array elements: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }

    occur(a, n);
    
    free(a);
    return 0;
}
void occur(int *a, int b)
{
    int i, j, count;

    for (i=0; i<b; i++)
    {
        for (j=0; j<b; j++)
        {
            if (*(a+i)==*(a+j))
            {
                printf("\n");
                count++;
            }
        }
        printf("The occurance of %d in the array is %d", *(a+i), 
        count);
        count=0;
    }
}

