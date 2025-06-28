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
