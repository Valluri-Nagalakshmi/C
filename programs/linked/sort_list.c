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
