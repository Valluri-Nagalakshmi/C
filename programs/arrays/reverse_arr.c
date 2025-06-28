#include<stdio.h>

int reverse_array(int arr[], int n){
	int i=0,j=n-1,temp;
	while(i<j){
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	i++;
	j--;
	}
	printf("the array elements are:");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[100],n;
        printf("enter the number of elements:");
        scanf("%d",&n);
        for(i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
	reverse_arr(arr,n);
        return 0;
}
