#include<stdio.h>
int main()
{
    int *ptr, *ptr2;
    int a=50;

    ptr=&a;
    ptr2=&a;
    ptr=NULL;
    printf("%d", *ptr2);
}