#include <stdio.h>
#include<stdlib.h>
int main()
{
  int i,j,n;
  int det=0;  
  int **b;
       printf("\n\nCalculate the determinant of a 3 x 3 matrix :\n");
       printf("-------------------------------------------------\n");  
   b=malloc(3*sizeof(int));

   for (i=0; i<3; i++)
   {
      b[i]=(int *)malloc(3*sizeof(int));
   }

	 printf("Input elements in the first matrix :\n");
       for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
	           printf("element - [%d],[%d] : ",i,j);
	           scanf("%d",(*(b+i)+j));
            }
        }  
	 printf("The matrix is :\n");
	 for(i=0;i<3;i++)
	 {
	   for(j=0;j<3 ;j++)
	     printf("%d",b[i][j]);
	    printf("\n");
	 }

  for(i=0;i<3;i++)
      det = det + (b[0][i]*(b[1][(i+1)%3]*b[2][(i+2)%3] - 
      b[1][(i+2)%3]*b[2][(i+1)%3]));

  printf("\nThe Determinant of the matrix is: %d\n\n",det);

  for (i=0; i<3; i++)
   {
      free(b[i]);
   }

   free(b);

  return 0;
}