/*#include<stdio.h>
int min_max(int arr[],int n){
	int min,max,i;
	min = max = arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]<min)
			min = arr[i];
		if(arr[i]>max)
			max = arr[i];
	}
	printf("the mininmum element is:%d\n",min);
	printf("the maximum element is:%d\n",max);
}

int main()
{
	int arr[100], n;
	printf("enter the number of elements:");
	scanf("%d",&n);
	printf("enter the array elements:");
	for(int i=0;i<n; i++){
		scanf("%d",&arr[i]);
	}
	min_max(arr,n);
	return 0;
}*/

//using pointers
#include<stdio.h>
int min_max(int arr[], int n, int *min, int *max){
	*min = *max = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i] < *min)
			*min = arr[i];
		if(arr[i] > *max)
			*max = arr[i];
	}
}
int main(){
	int arr[100], n, min, max;
        printf("enter the number of elements:");
        scanf("%d",&n);
        printf("enter the array elements:");
        for(int i=0;i<n; i++){
                scanf("%d",&arr[i]);
        }
        min_max(arr,n,&min,&max);
	printf("the mininmum element is:%d\n",min);
        printf("the maximum element is:%d\n",max);
} 
