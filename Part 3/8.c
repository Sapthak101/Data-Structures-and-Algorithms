#include<stdio.h>
#include<stdlib.h>
int main()
{
   int row, col, i, j, count=0, count1=0, count2=0, count3=0;
   int **b;
   
   printf("Enter the number of rows\n");
   scanf("%d",&row);

   printf("Enter the number of Columns\n");
   scanf("%d",&col);

   if (col==row)
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

   for (i=0; i<row; i++)
   {
    for (j=0; j<col; j++)
    {
        if (i>j)
        {
            if (*(*(b+i)+j)==0)
              count++;
        }
    }
   }
   if (count==((col*row)-((col*row)/col))/2)
    printf("It is an upper trangular matrix\n");

   for (i=0; i<row; i++)
   {
    for (j=0; j<col; j++)
    {
        if (i<j)
        {
            if (*(*(b+i)+j)==0)
              count1++;
        }
    }
   }
   if (count1==((col*row)-((col*row)/col))/2)
    printf("It is a lower trangular matrix\n");

   for (i=0; i<row; i++)
   {
      for (j=0; j<col; j++)
      {
         if ((i==j) && ((*(*(b+i)+j))!=0))   
            count2++;           
      }
   }
   
   for (i=0; i<row; i++)
   {
      for (j=0; j<col; j++)
      {
         if ((i!=j) && ((*(*(b+i)+j))==0))  
            count3++;           
      }
   }

   if (count2+count3==col*row)
      printf("It is a tri diagonal matrix\n");

   if ((count1!=((col*row)-((col*row)/col))/2) && 
   (count!=((col*row)-((col*row)/col))/2) && (count2+count3==row*col)) 
      printf("It is a general matrix\n");
   } 
   else
    printf("Invalid Matrix");

    for (i=0; i<row; i++)
   {
      free(b[i]);
   }

   free(b);

   return 0;
}