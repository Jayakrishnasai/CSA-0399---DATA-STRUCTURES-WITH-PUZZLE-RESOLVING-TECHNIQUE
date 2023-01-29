#include<stdio.h>
int main() 
{
	int n=10;
	int a[n];
	int even=0,odd=0,i;
	printf("Enter the number of elements of Array =");
	scanf("%d",&n);
	printf("Enter the elements in the array: ",n);
	for(i=0; i<n; i++) 
	{
		scanf("%d",&a[i]);
	}
	printf("Even numbers are: ");
	for(int i=0; i<n; i++) 
	{
		if(a[i]%2==0)
			printf("%d ",a[i]);
	}
	printf("\nOdd numbers are: ");
	for(int i=0; i<n; i++) 
	{
		if(a[i]%2==1)
			printf("%d ",a[i]);
	}
	return 0;
}