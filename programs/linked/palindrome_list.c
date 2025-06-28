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
