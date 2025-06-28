//Write a program to print postfix/prefix increment/decrement in a pointer variable of base type int*.
/*
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30};
    int *p = arr;

    printf("%d\n", *p++);
    printf("%d\n", *++p);
    printf("%d\n", *p--);
    printf("%d\n", *--p);

    return 0;
}
*/

#include<stdio.h>
int main(){
	int a;
	printf("enter the value of a:");
	scanf("%d",&a);
	int *p;
	p = &a;
	printf("%d\n",(*p)++);
	printf("%d\n",++(*p));
	printf("%d\n",(*p)--);
	printf("%d\n",--(*p));
	return 0;

}
