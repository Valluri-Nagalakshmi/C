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


void deletion_head()
{
	struct node *ptemp;
	ptemp = phead;
	phead = phead->next;
	free(ptemp);
	ptemp = NULL;
}

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
