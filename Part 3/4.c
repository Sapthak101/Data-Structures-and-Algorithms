#include<stdio.h>
#include<stdlib.h>
int main()
{
   int row, col, i, j, count;
   int **b, **a;
   
   printf("Enter the number of rows\n");
   scanf("%d",&row);

   printf("Enter the number of Columns\n");
   scanf("%d",&col);

   b=malloc(row*sizeof(int *));

   for (i=0; i<col; i++)
   {
      b[i]=(int *)malloc(col*sizeof(int));
   }

   printf("Enter Element of Matrix1\n");
   for(i = 0; i < row; i++)
   {
      for(j = 0; j < col; j++)
      {
         scanf("%d", &b[i][j]);
      }
   }
   printf("Elements are:\n");
   for(i = 0; i < row; i++)
   {
      for(j = 0; j < col; j++)
      {
         printf("%d\t",b[i][j]);
      }
      printf("\n");
   }
   
    a=malloc(row*sizeof(int *));

   for (i=0; i<col; i++)
   {
      a[i]=(int *)malloc(col*sizeof(int));
   }


    for (i=0; i<row; i++)
    {
       for(j=0; j<col; j++)
       {
           a[j][i]=b[i][j];
       }
    }
    printf("Transpose is= \n");
    for (i=0; i<col; i++)
    {
        printf("\t");
        for (j=0; j<row; j++)
        {
            printf("%d     ", a[i][j]);
        }
    printf("\n");
    }

   for (i=0; i<col; i++)
   {
      free(a[i]);
   }

   free(a);


   for (i=0; i<row; i++)
   {
      free(b[i]);
   }

   free(b);


    return 0;
}