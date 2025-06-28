//Write a program to print the value and address of array elements by subscripting a pointer variable

#include<stdio.h>

//int sub_pt(int *arr,int n){
int sub_pt(int arr[],int n){
	int *p;
	p = arr;
	for(int i=0;i<n;i++){
		printf("sub %d,%p\n",p[i],&p[i]); 		//subscript notation
		printf("poin %d,%p\n",*(p+i),(p+i));	//pointer notation
		printf("sub & poin %d,%p\n",*(p+i),&p[i]); 	//subscript and pointer notation
	}
}

int main(){
	int arr[100];
	int i,n;
	printf("enter the value of n:");
	scanf("%d",&n);
	printf("enter the elements of array:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sub_pt(arr,n);
	return 0;
}
