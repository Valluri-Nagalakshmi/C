#include<stdio.h>
int second_largest(int arr[],int n){
	int first,second,i;
	if(n<2){
		printf("array should contain more than 2 elemnets\n");
		return -1;
	}
	first = second = -1;
	for(i=0;i<n;i++){
		if(arr[i]>first){
			second=first;
			first=arr[i];
		}
		else if((arr[i]>second)&&(arr[i]!=first)){
			second = arr[i];
		}
	}
	return second;
}
int main(){
	int arr[100],n,i,res;
	printf("enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	res = second_largest(arr,n);
	printf("%d is the second largest element\n",res);
	return 0;
}

