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
