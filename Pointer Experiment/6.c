#include<stdio.h>
int main()
{
    int *ptr;

    *ptr=1100;
    *(ptr+1)=108;

    printf("%d\n", *ptr);
    printf("%d\n", *(ptr+1));

    return 0;
}