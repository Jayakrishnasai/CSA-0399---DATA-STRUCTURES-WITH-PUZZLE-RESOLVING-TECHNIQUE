#include<stdio.h>
int main()
{
	int a[3][3],b[3][3],mul[3][3];
	int rows,column,i,j,k;
	printf("Enter the number of rows =");
	scanf("%d",&rows);
	printf("Enter the number of column =");
	scanf("%d",&column);
	printf("Enter the matrix A =\n ");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<column;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the matrix B =\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<column;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("Multiplication of Matrix A & B is =\n");
    for(i=0;i<rows;i++)
	{
		for(j=0;j<column;j++)
		{
			mul[i][j]=0;
			for(k=0;k<column;k++)
			{
				mul[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<rows;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%d",mul[i][j]);
		}
		printf("\n");
	}
	return 0;
}