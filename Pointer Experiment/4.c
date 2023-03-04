#include<stdio.h>
int main()
{

    int b=50;
    int *a[3];
                                                            
    *a=&b;
    printf("%d\n", **a);
    printf("%u\n", *a);
    printf("%u\n", *(a+1));
    printf("%u\n", *(a+2));
    
    printf("%d\n ");

    /*
    *(*(a+1))=108;
    *(*(a+2))=104;
*/
    /*
    printf("%d\n", &a[1]);
    printf("%d", &a[2]);
    */
}