#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, i, c, d, count=0, j, b, e, k;
    int a[100];

    printf("Enter the number of element: \n");
    scanf("%d", &n);

    printf("Enter the array elements: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the boundary condition: \n");
    scanf("%d %d", &e, &b);

    for (i=0; i<n; i++)
    {
        if (a[i]==e)
        {
            c=i;
            break;
        }
    }

    for (i=n-1; i>=0; i--)
    {
        if (a[i]==b)
        {
            d=i;
            break;
        }
    }

   for(i=c+1;i<d;i++)
   {
      for(j = c+1; j<d; j++)
      {
         if(a[i] == a[j])
         {
            for(k = j; k <d; k++)
            {
               a[k] = a[k+1];
            }
            j--;
            d--;
         }
      }
   }

   for (i=c+1; i<d; i++)
   {
        printf("%d ", a[i]);
   }

    printf("\nThe minimum length is: %d", count);

    return 0;           
}