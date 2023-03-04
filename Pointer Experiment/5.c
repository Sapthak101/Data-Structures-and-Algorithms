#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a=50;
    int **ptr2=(int * *)malloc(4*sizeof(int *));
    
    *(ptr2+0)=(int *)malloc(4*sizeof(int));
    *(*(ptr2)+1)=50;
    printf("%d\n", ptr2);
    printf("%d\n", ptr2+1);
    printf("%d", ptr2[0][1]);
}


