#include<stdio.h>
void get(int a[20],int n);
void display(int a[20],int n);
int main()
{
		
	int a[20],n;
	printf("\nEnter no of elements");
	scanf("%d",&n);
	get(a,n);
	display(a,n);
	return 0;
}
void get(int a[20],int n)
{
	int i;  
	printf("\nEnter array elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void display(int a[20],int n)
{
	int i;	
	printf("\array elements are...\n");
	for(i=0;i<n;i++)
		printf("%d    ",a[i]);
}






