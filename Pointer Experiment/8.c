#include<stdio.h>
#include<stdlib.h>
void func1(int **p)
{
    *p=malloc(sizeof(int));
    printf("%d\n", *p);\
    printf("%d\n", **p=50);
}
int main()
{
    int *ptr;
    func1(&ptr);
    printf("%d\n", ptr);
    printf("%d\n", *ptr);

    return 0;
}