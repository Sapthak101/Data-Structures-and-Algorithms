#include<stdio.h>
#define MAX 100000

void sort1(int *a, int *b, int *c, int num);
void sort2(int *a, int *b, int *c, int num);
void sort3(int *a, int *b, int *c, int num);

int main()
{
    int num, a[MAX], b[MAX], c[MAX];
    
    printf("Enter the number of dates to be entered: ");
    scanf("%d", &num);
    
    printf("Enter the dates: \n");
    for (int i=0; i<num; i++)
    {
        scanf("%d %d %d", a+i, b+i, c+i);
    }
    sort1(a, b, c, num);
    sort2(a, b, c, num);
    sort3(a, b, c, num);
    
    printf("THe dates in the sorted order: \n");
    for (int i=0; i<num; i++)
    {
        printf("%d %d %d\n", *(a+i), *(b+i), *(c+i));
    }

    return 0;
}

void sort1(int *a, int *b, int *c, int num)
{
    for (int i=0; i<num; i++)
    {
        for (int j=i+1; j<num; j++)
        {
            int temp;
            if (c[i]>c[j])
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;

                temp=b[i];
                b[i]=b[j];
                b[j]=temp;

                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void sort2(int *a, int *b, int *c, int num)
{
    for (int i=0; i<num; i++)
    {
        for (int j=i+1; j<num; j++)
        {
            if (c[i]==c[j])
            {
                int temp;
                if (b[i]>b[j])
                {
                    temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;

                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
}

void sort3(int *a, int *b, int *c, int num)
{
    for (int i=0; i<num; i++)
    {
        for (int j=i+1; j<num; j++)
        {   
            if (c[i]==c[j] && b[i]==b[j])
            {
                int temp;
                if (a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
}