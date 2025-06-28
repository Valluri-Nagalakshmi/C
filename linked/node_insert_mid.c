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


