#include <stdio.h>
int main() 
{   
    int c, first, last, middle, n, key, array[100]; 
    int temp, i, j;

    printf("Enter number of elements: \n"); 
    scanf("%d",&n); 

    printf("Enter %d integers: \n", n); 
    for (c = 0; c < n; c++)
    scanf("%d",&array[c]); 

    for (i=0; i<n-1; i++)
    {
        
        for (j=0; j<(n-i)-1; j++)
        if (array[j]>array[j+1])
        {
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
        }
    }

    printf("Enter value to find: \n"); 
    scanf("%d", &key);

first = 0; 
last = n - 1;
middle = (first+last)/2; 

    while (first <= last) 
    { 
        if (array[middle] < key)
	    first = middle + 1; 
    else if(array[middle] == key)
    { 
    	printf("%d found at location %d.\n", key, 	middle+1);
 	    break; 
    } 
    else 
        last = middle - 1;

    middle = (first + last)/2; 
    }

if (first > last)
 printf("Not found! %d is not present in the array.\n", key);

return 0; 
}