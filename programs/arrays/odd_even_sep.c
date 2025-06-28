#include<stdio.h>
int even_odd_elements(int arr[],int n){
       int even[100],odd[100];
       int even_count, odd_count;
       even_count = odd_count = 0;
       int i=0;
	for(i=0;i<n;i++){
		if(arr[i]%2==0){
			even[even_count] = arr[i];
			even_count++;
		}
		else{
			odd[odd_count] = arr[i];
			odd_count++;
		}
	}
	printf("the even number elements are:");
	for(i=0;i<even_count;i++)
	{
		printf("%d,", even[i]);
	}
	printf("\n");
	printf("the odd number elements are:");
	for(i=0;i<odd_count;i++)
	{
		printf("%d,", odd[i]);
	}
	printf("\n");
	printf("number of even numbers count is:%d\n",even_count);
	printf("number of odd numbers count is:%d\n", odd_count);
}

int main(){
	int arr[100],n;
	int i=0;
	printf("enter the number of elements in the array:");
	scanf("%d",&n);
	printf("enter the array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	even_odd_elements(arr,n);
	return 0;
}
