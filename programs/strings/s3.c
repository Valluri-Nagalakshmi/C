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
