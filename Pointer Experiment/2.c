#include<stdio.h>
int main()
{
    int a;
    int *ptr;

    ptr=&a;
    *ptr=100;
    
    printf("%u\n", *ptr);
    printf("%d\n", *ptr);
    printf("%d\n", a);

    return 0;
}