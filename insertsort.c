#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int a[],int n)
{
	int j,i,key,count;
	for(j=1;j<n;j++)
	{
                count=0;
		key=a[j];		
		for(i=j-1;i>=0;i--)
		{
                       count++;
			if(a[i] > key)
			{
				a[i+1]=a[i];
			}
			else
				break;
		}
		a[i+1]=key;
                printf("\ncount is: %d",count);  
	}  
}
int main()
{
	int a[20],i,n;
	printf("\nEnter number of elements");
	scanf("%d",&n);
	printf("\nEnter array elements");
	for(i=0;i<n;i++)
              //a[i]=rand()%100;   //random number generation
		scanf("%d",&a[i]);
       printf("\nUnsorted array is....\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	insertion_sort(a,n);
	printf("\nsorted array is....\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;
}//main
   








           
               








