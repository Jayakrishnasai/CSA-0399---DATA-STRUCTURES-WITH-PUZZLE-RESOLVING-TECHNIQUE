#include<stdio.h>
int main()
{
	int i,n;
	int factorial=1;
	printf("Enter the number =");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		factorial*=i;
	}
	printf("Factorial of %d is=%d",n,factorial);
	return 0;
}