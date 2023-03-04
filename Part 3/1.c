#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int x, i;
    float y, sum;
    int *ptr;

    printf("Enter the order of the polynomial: \n");
    scanf("%d", &x);

    ptr=(int*)calloc(x, sizeof(int));

    printf("Enter the value of of the variable: \n");
    scanf("%f", &y);

    printf("Enter the %d coefficients: \n", x+1);
    for (i=0; i<=x; i++)
    {
        scanf("%d", ptr+i);
    }

    for (i=0; i<=x; i++)
    {
        sum=sum+(*(ptr+i))*(pow(y,(x-i)));
    }

    printf("The Polynomial is: \n");
    for (i=0; i<=x; i++)
    {
        printf(" %d x X^%d ", *(ptr+i), x-i);
            if (i!=x)
                printf(" + ");
    }

    printf("\n");

    printf("Putting X= %.2f\n", y);
    for (i=0; i<=x; i++)
    {
        printf(" %d x %.2f^%d ", *(ptr+i), y, x-i);
            if (i!=x)
                printf(" + ");
    }

    printf("\nThe polynomial value on putting x = %.2f is %.2f", y, sum);

    free(ptr);
    
    return 0;
}