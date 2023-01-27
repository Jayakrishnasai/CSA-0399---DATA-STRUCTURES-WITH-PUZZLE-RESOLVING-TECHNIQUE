#include <stdio.h>
int main()
{ 
int i,n,pos,ele,c,position,arr[100];
printf("Enter array size:");
scanf("%d",&n);
printf("Enter elements:");
for(i = 0; i < n; i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the position to be inserted:");
scanf("%d",&pos);
printf("Enter the element to be inserted:");
scanf("%d",&ele);
if(pos > n+1)
printf("Invalid Input");
else
for(i=n-1;i>=pos-1;i--)
arr[i+1] = arr[i];
arr[pos-1] = ele;
printf("Array after insertion is:\n");
for (i = 0; i <= n; i++)
printf("%d\n", arr[i]);
printf("Enter the position to be deleted:");
scanf("%d",&position);
if (position > n+1)
printf("\nDeletion not possible.\n");
else
for(c=position-1;c<n-1;c++)
arr[c] = arr[c+1];
printf("\nArray after deletion :\n");
for(c=0;c<n;c++)
printf("%d\n", arr[c]);
printf("displaying final array");
for(i=-1;i<n;i++)
printf("%d\n", arr[i]);
return 0;
}