#include<stdio.h>
int main()
{
    int a=6;
    int *ptr=&a;
    int **ptr2=&ptr;
    
    printf("%d\n", *ptr+1);
    printf("%d\n", ptr2);
    printf("%d\n", ptr2+1);
}