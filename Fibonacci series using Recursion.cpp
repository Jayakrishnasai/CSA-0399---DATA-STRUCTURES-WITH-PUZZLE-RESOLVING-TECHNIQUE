#include<stdio.h>    
void printFibonacci(int n)
{    
    static int a=0,b=1,c;    
    if(n>0)
	{    
         c=a+b;    
         a=b;    
         b=c;    
         printf("%d ",c);    
         printFibonacci(n-1);    
    }    
}    
int main()
{    
    int n;    
    printf("Enter the number of elements: ");    
    scanf("%d",&n);    
    printf("Fibonacci Series: ");    
    printf("%d %d ",0,1);    
    printFibonacci(n-2);   
  return 0;  
 }    