#include<stdio.h>
#include<stdlib.h>
void biggest(int *num, int n, int big)  
{  
    if(n < 0)  
        printf("Biggest element is %d\n", big);  
    else  
    {  
        if(*num > big)  
            big = *num;  
  
        biggest(++num, --n, big);  
    }  
}  
  
int main()  
{  
    int *a, i;  
    int N;
    
    printf("Enter the number of array elements: \n");
    scanf("%d", &N);
    a=(int *)malloc(N*sizeof(int));

    printf("Enter %d integer numbers\n", N);  
    for(i = 0; i < N; i++)  
        scanf("%d", a+i);  
  
    biggest(a, N - 1, *(a+i));  
    
    free(a);
    return 0;  
} 