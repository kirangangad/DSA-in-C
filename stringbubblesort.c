#include<stdio.h>
#include<string.h>
void bubble_sort(char a[10][20],int n)
{
	 int pass,i;
        char temp[20];
	for(pass=1;pass<n;pass++)
	{
		for(i=0;i<n-pass;i++)
		{
			if(strcmp(a[i],a[i+1]) >0)
			{
				strcpy(temp,a[i]);
				strcpy(a[i],a[i+1]);
				strcpy(a[i+1],temp);
			
			}
		}
	}
        
}
int main()
{
	int i,n;
        char a[10][20]; 
	printf("\nEnter number of elements");
	scanf("%d",&n);
	printf("\nEnter array elements");
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
	bubble_sort(a,n);
	printf("\nsorted array is....\n");
	for(i=0;i<n;i++)
		printf("%s\t",a[i]);
	return 0;
}//main


