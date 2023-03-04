#include<stdio.h>
int main()
{
    int a=50;
    int *ptr=&a;
    float *ptr2;

    ptr2=(float *) ptr;

    printf("%d\n", *ptr);
    printf("%lf\n", *ptr2);

    *ptr2=60;

    printf("%lf\n", *ptr2);
    printf("%d\n", *ptr);

    printf("%u\n", ptr);
    printf("%u\n", ptr2);

    return 0;
}