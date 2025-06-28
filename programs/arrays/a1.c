// read n number of values in an array and display them in reverse order

#include<stdio.h>
int main()
{
	int n,i;
	printf("enter the number elemnets in the array n:\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements in the array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the elementx stored in the array are:\n");
	for(i=0;i<n;i++){
		printf("the element %d:%d\n", i+1,arr[i]);
	}
	printf("the reverse of the array is:\n");
	for(i=n-1;i>=0;i--){
		printf("%d\n", arr[i]);
	}
	//printf("\n");
	return 0;
}

	
