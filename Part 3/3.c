#include<stdio.h>
#include<stdlib.h>

int main()
{
   int row, col, i, j, count;
   int **b;

   printf("Enter a square matrix: \n");
   printf("Enter the number of rows\n");
   scanf("%d",&row);

   printf("Enter the number of Columns\n");
   scanf("%d",&col);

   if (row==col)
      {
      b=malloc(row*sizeof(int *));

      for (i=0; i<col; i++)
      {
         b[i]=(int *)malloc(col*sizeof(int));
      }

      printf("Enter Element of Matrix: \n");
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
   
      for(i = 0; i < row; i++)
      {
         for(j = 0; j < col; j++)
         {
            if(b[i][j] == 0)
               count++;
         }
      }
      
      if(((float)count/(row * col))*100>=50.0)
         printf("Matrix is a sparse matrix \n");
      else
         printf("Matrix is not sparse matrix\n");

      for (i=0; i<row; i++)
      {
         free(b[i]);
      }

      free(b);
      }
   else
      printf("The entered matrix is not a square matrix: \n");

    return 0;
}