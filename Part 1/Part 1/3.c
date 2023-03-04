#include<stdio.h>
int main()
{
    int n, first, last, middle, num, i;
    int a[100];

    printf("Enter the number of elements that you want to enter: \n");
    scanf("%d", &n);

    printf("Enter the number of elements: \n");
    for (i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    printf("Enter the number that you want to search: \n");
    scanf("%d", &num);

    first=0;
    last=n-1;
    middle=(first+last)/2;
    
    while(first<=last)
    {
        if (a[middle]<num)
            first=middle+1;
        else if (a[middle]==num)
        {
            printf("The number is found at location %d", middle+1);
            break;
        }
        else 
            last=middle-1;      
    
        middle=(first+last)/2;
    }
   if (first>last)
        printf("The number does not exist");

    return 0;
}