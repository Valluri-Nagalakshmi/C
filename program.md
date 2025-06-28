
#  C Programs 

This document includes all C source codes from arrays, strings, bitwise operations, pointers, and linked list examples.

---
# Arrays

## Read n number of values in an array and display them in reverse order

```c
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

	

```

---

## Min and max elements in array

```c
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

```

---

##  Nonrepeating element in the array

```c
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


```

---

## Odd and even elements count in the array

```c
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

```

---

## Reverse the array

```c
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

```

---

## Find the second largest element in the given array

```c
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


```

---
# Bitwise operators

## Print binary number of the given number

```c

#include <stdio.h>

int main()
{
   int num;
   printf("enter the value of num:");
   scanf("%x",&num);
   printf("the binary form of the given number is:");
   for(int i=31;i>=0;i--)
   {
       if(num&(1<<i))
       {
           printf("1");
       }
       else{
           printf("0");
       }
    }
    printf("\n");
}


```

---
# Linked list

## Delete a node from the linked list

```c
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *phead = NULL;

void createnode(int n)
{
	struct node *pnew,*ptemp;
	int i=0;
	while(i<n){	
		pnew = (struct node *) malloc (sizeof(struct node));
		if(pnew == NULL)
			printf("malloc error\n");
		scanf("%d",&pnew->data);
		pnew->next = NULL;
		if(phead == NULL)
			phead = ptemp = pnew;
		else
		{
			ptemp->next = pnew;
			ptemp = pnew;
		}
		i++;
	}
}

void display(void){
        struct node *ptemp;
        ptemp = phead;
        while(ptemp != NULL)
        {
         printf("%d->",ptemp->data);
         ptemp=ptemp->next;
         }
         printf("NULL\n");
}

// delete a node from the head
void deletion_head()
{
	struct node *ptemp;
	ptemp = phead;
	phead = phead->next;
	free(ptemp);
	ptemp = NULL;
}

// delete a node from the end
void deletion_end()
{
	struct node *ptemp1,*ptemp2;
	ptemp1 = ptemp2 =phead;
	while(ptemp1->next!=NULL)
	{
		ptemp2 = ptemp1;
		ptemp1 = ptemp1->next;
	}
	ptemp2->next = NULL;
	free(ptemp1);
	ptemp1 = NULL;
}

// delete a node from given position
void deletion_mid(int p)
{
	struct node *ptemp1,*ptemp2;
	ptemp1 = ptemp2 =phead;
	int i=0;
	while(i<(p-1))
	{
		ptemp2 =ptemp1;
		ptemp1 = ptemp1->next;
		i++;
	}
	ptemp2->next = ptemp1->next;
	free(ptemp1);
	ptemp1 = NULL;
}

int main()
{
	int n,p;
	printf("enter number of nodes and position:");
	scanf("%d %d",&n,&p);
	createnode(n);
	display();
	deletion_head();
	display();
	deletion_end();	
	display();
	deletion_mid(p);
	display();
}

```

---

## Insert a node in the linked list

```c
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *phead = NULL;
void createnode(int n){
    struct node *pnew, *ptemp;
    int i=0;
    while(i<n){
        pnew = (struct node *) malloc (sizeof(struct node));
        if(pnew == NULL)
            printf("malloc error\n");
        scanf("%d", &pnew->data);
        pnew-> next = NULL;

        if(phead == NULL)
            phead = ptemp = pnew;
        else{
            ptemp->next = pnew;
            ptemp = pnew;
        }


        i++;
    }
}
/*
void display(int n){
    struct node *ptemp;
    ptemp = phead;
    int i=0;
    while(i<n){
    printf("%d->",ptemp->data);
    ptemp=ptemp->next;
    i++;
    }
    printf("NULL\n");
}
*/
// insert a node at beginning of the linked list 
void insertion_head(){
	struct node *pnew;
	pnew = (struct node *) malloc (sizeof(struct node));
	if(pnew == NULL)
		printf("malloc error\n");
	scanf("%d",&pnew->data);
	pnew->next = NULL;
	if(phead == NULL)
		phead = pnew;
	else{
	pnew->next = phead;
	phead = pnew;
}	
}

// insert a node at the end of the linked list
void insertion_end(){
        struct node *pnew, *ptemp;
        pnew = (struct node *) malloc (sizeof(struct node));
        if(pnew == NULL)
                printf("malloc error\n");
        scanf("%d",&pnew->data);
        pnew->next = NULL;
	if(phead == NULL)
		phead = pnew;
	ptemp = phead;
	while(ptemp->next != NULL){
		ptemp = ptemp->next;
	}
        ptemp->next = pnew;
      	ptemp = pnew;	
	
}

// insert a node at the given position in the linked list
void insertion_mid(int p){
	int i=0;
	struct node *pnew,*ptemp;
	pnew = (struct node *)malloc(sizeof(struct node));
	if(pnew == NULL)
		printf("malloc error");
	scanf("%d",&pnew->data);
	pnew->next = NULL;
	if(phead == NULL)
		phead = pnew;
	ptemp = phead;
	while(i < (p-1))
	{
		ptemp = ptemp->next;
		i++;
		//printf("hello 2\n");
	}
	//printf("hello\n");
	pnew->next = ptemp->next;
	ptemp->next = pnew;
}

void display(void){
        struct node *ptemp;
        ptemp = phead;
        while(ptemp != NULL)
        {
         printf("%d->",ptemp->data);                                                                                             
	 ptemp=ptemp->next;
         }
         printf("NULL\n");
}


int main()
{
    int n,p;
    printf("enter list of nodes and position:");
    scanf("%d %d",&n,&p);
    createnode(n);
    display();
    insertion_head();
    display();
    insertion_end();
    display();
    insertion_mid(p);
    display();
}

```

---

## Create a linked list

```c
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *phead = NULL;
void createnode(int n){
    struct node *pnew, *ptemp;
    int i=0;
    while(i<n){
        pnew = (struct node *) malloc (sizeof(struct node));
        if(pnew == NULL)
            printf("malloc error\n");
        scanf("%d", &pnew->data);
        pnew-> next = NULL;
        
        if(phead == NULL)
            phead = ptemp = pnew;
        else{
            ptemp->next = pnew;
            ptemp = pnew;
        }
        i++;
    }
}
/*
void display(int n){
    struct node *ptemp;
    ptemp = phead;
    int i=0;
    while(i<n){
    printf("%d->",ptemp->data);
    ptemp=ptemp->next;
    i++;
    }
    printf("NULL\n");
}

*/
 void display(void){
 	struct node *ptemp;
	ptemp = phead;
	while(ptemp != NULL)
	{
	 printf("%d->",ptemp->data);                                                                                            
	 ptemp=ptemp->next;
	 }
	 printf("NULL\n");
}


int main()
{
    int n;
    printf("enter list of nodes:");
    scanf("%d",&n);
    createnode(n);
    display();
    
}

```

---

## Insert a node in the middle of the linked list

```c
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *phead = NULL;

void createnode(int n){
	struct node *pnew,*ptemp;
	int i=0;
	while(i<n)
	{
		pnew = (struct node *) malloc (sizeof(struct node));
		if(pnew == NULL)
			printf("malloc error\n");
		scanf("%d",&pnew->data);
		pnew->next = NULL;
		if(phead == NULL)
			phead = ptemp = pnew;
		else{
			ptemp->next = pnew;
			ptemp = pnew;
		}
		i++;
	}
}

void insertnode(int n){
	struct node *pnew,*ptemp;
	pnew = (struct node*) malloc (sizeof(struct node));
	if(pnew == NULL)
		printf("malloc error\n");
	scanf("%d",&pnew->data);
	pnew->next = NULL;
	if(phead == NULL)
		phead = pnew;
	ptemp = phead;
	int i=0;
	while(i<(n/2))
	{
		ptemp = ptemp->next;
		i++;
	}
	pnew->next = ptemp->next;
	ptemp->next = pnew;
}

void display()
{
	struct node *ptemp;
	ptemp = phead;
	while(ptemp!=NULL)
	{
		printf("%d->",ptemp->data);
		ptemp=ptemp->next;
	
	}
	printf("NULL\n");
}

int main()
{
	int n;
	printf("enter the number of nodes:");
	scanf("%d",&n);
	createnode(n);
	display();
	insertnode(n);
	display();
}



```

---

## check whether the linked list is palindrome or not

```c
#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node *next;
};

struct node *phead = NULL;

void createnode(int n){
        struct node *pnew, *ptemp;
        int i=0;
        while(i<n){
                pnew = (struct node *) malloc (sizeof(struct node));
                if(pnew == NULL)
                        perror("malloc error\n");
                scanf("%d",&pnew->data);
                pnew->next = NULL;
                if(phead == NULL)
                        phead = ptemp = pnew;
                else{
                        ptemp->next = pnew;
                        ptemp = pnew;
                }
                i++;
        }
}

void display(){
        struct node *ptemp;
        ptemp = phead;
        while(ptemp != NULL)
        {
                printf("%d->",ptemp->data);
                ptemp = ptemp->next;
        }
        printf("NULL\n");
}

int palindrome_list(){
	struct node *ptemp = phead;
	int arr[100], count =0;
	while(ptemp!=NULL){
		arr[count++]=ptemp->data;
		ptemp=ptemp->next;
	}
	int i=0,j=count-1;
	while(i<j){
		if(arr[i]!=arr[j])
			return 0;
		i++;
		j--;
	return 1;
	}
}

int main()
{
        int n;
        printf("enter number nodes:");
        scanf("%d",&n);
        createnode(n);
        display();
        if(palindrome_list())
		printf("palindrome list\n");
	else
		printf("not palindrome list\n");	
        display();

        return 0;
}

```

---

##  reverse a linked list

```c
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *phead = NULL;

void createnode(int n){
	struct node *pnew, *ptemp;
	int i=0;
	while(i<n){
		pnew = (struct node *) malloc (sizeof(struct node));
		if(pnew == NULL)
			perror("malloc error\n");
		scanf("%d",&pnew->data);
		pnew->next = NULL;
		if(phead == NULL)
			phead = ptemp = pnew;
		else{
			ptemp->next = pnew;
			ptemp = pnew;
		}
		i++;
	}
}

void display(){
	struct node *ptemp;
	ptemp = phead;
	while(ptemp != NULL)
	{ 
		printf("%d->",ptemp->data);
	        ptemp = ptemp->next;
	}
	printf("NULL\n");
}

void reverse_list()
{
	struct node *prev, *pcurr, *pnext;
	prev = pnext = NULL;
	pcurr = phead;
	while(pcurr!=NULL)
	{
		pnext = pcurr->next;
		pcurr->next = prev;
		prev = pcurr;
		pcurr = pnext;
	}
	phead = prev;
}

int main()
{
	int n;
	printf("enter number nodes:");
	scanf("%d",&n);
	createnode(n);
	display();
	reverse_list();
	display();
	return 0;
}
		


```

---

##  sort a linked list

```c
#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node *next;
};

struct node *phead = NULL;

void createnode(int n){
        struct node *pnew, *ptemp;
        int i=0;
        while(i<n){
                pnew = (struct node *) malloc (sizeof(struct node));
                if(pnew == NULL)
                        perror("malloc error\n");
                scanf("%d",&pnew->data);
                pnew->next = NULL;
                if(phead == NULL)
                        phead = ptemp = pnew;
                else{
                        ptemp->next = pnew;
                        ptemp = pnew;
                }
                i++;
        }
}

void display(){
        struct node *ptemp;
        ptemp = phead;
        while(ptemp != NULL)
        {
                printf("%d->",ptemp->data);
                ptemp = ptemp->next;
        }
        printf("NULL\n");
}

void sort_list(){
	struct node *ptemp1, *ptemp2;
	int temp;
	for(ptemp1 = phead; ptemp1!= NULL; ptemp1=ptemp1->next){
		for(ptemp2 = ptemp1->next; ptemp2!= NULL; ptemp2=ptemp2->next){
			if(ptemp1->data > ptemp2->data){
				temp = ptemp1->data;
				ptemp1->data = ptemp2->data;
				ptemp2->data = temp;
			}
		}
	}
}

int main()
{
        int n;
        printf("enter number nodes:");
        scanf("%d",&n);
        createnode(n);
        display();
        sort_list();
        display();
        return 0;
}

```

---
# Pointers
## print the value and address of array elements by subscripting a pointer variable

```c
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

```

---

## print postfix/prefix increment/decrement in a pointer variable of base type int*

```c
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

```

---
# Strings
## count the total number of vowels or consonants in a string

```c
// Write a program in C to count the total number of vowels or consonants in a string.

#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	int vowels=0,consonant=0;
	printf("enter a string:");
	fgets(str,sizeof(str),stdin);
	for(int i=0; str[i] != '\0';i++){
		 if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
			vowels++;
		}
		else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			consonant++;
		}
	}
	printf("the number of vowels in the string are:%d\n",vowels);
	printf("the number of consonants in the string are:%d\n",consonant);
	return 0;
}

```

---

## sort a string array in ascending order.


```c
//to sort a string array in ascending order.

#include<stdio.h>
#include<string.h>

void sort_string(char str[]){
	int i,j;
	char temp;
	//int len = strlen(str);

	for(i=0;str[i]!='\0';i++){
		if(str[i] == '\n'){
			str[i] = '\0';
			break;
		}
	}
	int len = strlen(str);
	for(i=0;i<len-1;i++){
		for(j=i+1;j<len;j++){
			if(str[i]>str[j]){
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			}
		}
	}
	printf("sorted string: %s\n", str);
}
int main()
{
	char str[100];
	printf("enter the string:");
	fgets(str,sizeof(str),stdin);

	sort_string(str);
	return 0;
}


```

---

##  maximum number of characters in a string

```c
// program in C to find the maximum number of characters in a string

#include<stdio.h>
#include<string.h>

void max_char(char str[]){
	int freq[256] = {0};
	int max = 0;
	char max_char;

	for(int i=0;str[i]!='\0';i++){
		if(str[i]=='\n')
			continue;
		freq[(unsigned char)str[i]]++;

		if(freq[(unsigned char)str[i]]>max){
			max = freq[(unsigned char)str[i]];
			max_char = str[i];
		}
	}
	printf("charater %c occured the most %d times.\n", max_char,max);
}

int main()
{
	char str[100];
	printf("enter a string:");
	fgets(str, sizeof(str), stdin);

	max_char(str);
	return 0;
}

```

---

##  revese a string 

```c
#include<stdio.h>
#include<string.h>

void reverse_str(char str[])
{
	int i,len,temp;
	len = strlen(str);


```

---
