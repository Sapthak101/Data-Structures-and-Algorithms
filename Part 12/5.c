#include<stdio.h>
void quicksort(double x[20],int first,int last)
{
      int pivot,j,i;
      double temp;
      if(first<last)
      {
            pivot=first;
            i=first;
            j=last;

            while(i<j)
            {
                  while(x[i]<=x[pivot]&&i<last)
                        i++;
                  while(x[j]>x[pivot])
                        j--;
                  if(i<j)
                  {
                        temp=x[i];
                        x[i]=x[j];
                        x[j]=temp;
                  }
            }
            temp=x[pivot];
            x[pivot]=x[j];
            x[j]=temp;
            quicksort(x,first,j-1);
            quicksort(x,j+1,last);
      }
}
int main()
{
      double x[20];
      int size,i;
      printf("\tQuick sort\n");
      printf("-----------------------------------\n");
      printf(" How many numbers you want to sort?: ");
      scanf("%d",&size);
      printf("\n Enter %d elements: \n",size);
      for(i=0;i<size;i++)
            scanf("%lf",&x[i]);
      quicksort(x,0,size-1);
      printf("\n Sorted elements after applying quick sort: \n\n");
      for(i=0;i<size;i++)
            printf(" %.2lf",x[i]);
      return 0;
}