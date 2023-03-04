#include<stdio.h>

int main()
{
    int container[100], count=1, n, i;

    printf("Enter the number of array elements: \n");
    scanf("%d", &n);

    printf("Enter the array elements: \n");
    for (i=0; i<n; i++)
        scanf("%d", container+i);

    int hunt=1;

    while (count!=0)
    {
        for (i=0; i<n; i++)
        {
            if (container[i]==hunt)
            {
                hunt*=3;
                count++;
                break;
            }
            else
                count=0;
        }
    }
    printf("The hunt value is: %d", hunt);
}