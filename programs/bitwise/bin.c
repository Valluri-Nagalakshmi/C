
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

