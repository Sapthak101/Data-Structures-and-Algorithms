#include<stdio.h>

int main()
{
	int n, t, a=0;
    
	printf("Enter number of integers in array :");
	scanf("%d",&n);

	int arr[n];

	printf("enter the integers :");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("\nEnter the number to be searched :");
	scanf("%d",&t);

	for(int j=0;j<n;j++)
	{
		if(arr[j]==t)
		{
			printf("the element is present\n");
			a++;
            break;
		}
	}
	if(a==0)
	{
		printf("the element is not present \n");
	}

	return 0;
}