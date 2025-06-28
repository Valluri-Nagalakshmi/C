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

