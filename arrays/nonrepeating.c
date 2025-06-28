#include<stdio.h>
void non_repeating(int arr[],int n)
{
		int i,j,count;
		for(i=0;i<n;i++)
		{
			count = 0;
			for(j=0;j<n;j++)
			{
				if((arr[i] == arr[j]) && (i!=j))
					count++;
			}
			if(count == 0)
				printf("%d is non repeating element\n", arr[i]);
		}
}

int main()
{
	int arr[100],n;
	printf("enter the number of elements:");
	scanf("%d",&n);
	printf("enter the array elements:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	non_repeating(arr,n);
	return 0;
}

