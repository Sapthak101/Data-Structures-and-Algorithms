#include<stdio.h>

struct data
{
    int real;
    int imaginary; 
};

 void complex(struct data x, struct data y);

int main()
{
    struct data n1, n2;

    printf("Enter the integer part of the complex number: \n");
    printf("Enter the first complex number \n");
    scanf("%d %d", &n1.real, &n1.imaginary);

    printf("Enter the second complex number: \n");
    scanf("%d %d", &n2.real, &n2.imaginary);

    complex(n1, n2);

    return 0;
}

void complex(struct data x, struct data y)
{
    int a, b;

    a=x.real+y.real;
    b=x.imaginary+y.imaginary;

    printf("The addition of the entered complex number is %d+%di", a, b);
}