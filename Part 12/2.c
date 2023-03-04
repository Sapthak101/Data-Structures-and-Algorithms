#include <stdio.h>
void selection_sort();
float a[30]; int n;
int main()
{
    int i;
    printf("\nEnter size of an array: ");
    scanf("%d", &n);
    printf("\nEnter elements of an array:\n");
    for(i=0; i<n; i++)
        scanf("%f", &a[i]);
    selection_sort();
    printf("\n\nAfter sorting:\n");
    for(i=0; i<n; i++)
        printf("\n%.2f", a[i]);
    return 0;
}
void selection_sort()
{
    int i, j, min; 
    float temp;
    for (i=0; i<n; i++)
    {
        min = i;
        for (j=i+1; j<n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}