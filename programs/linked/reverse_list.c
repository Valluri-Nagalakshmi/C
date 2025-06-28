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
		

