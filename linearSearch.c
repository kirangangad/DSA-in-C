//linear search
#include<stdio.h>

int search(int a[], int n,int key)
{       
       int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			return i;
	}
	return -1;
}
int main()
{
	int a[20],i,n,key,ans;
	 printf("\nEnter number of elements");
	scanf("%d",&n);
	printf("\nEnter array elements");
	for(i=0;i<n;i++)
		//a[i]=rand()%100;  //random no generator
		scanf("%d",&a[i]);
	printf("\n Generated Array is.......\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\nEnter key to search");
	scanf("%d",&key);
	ans=search(a,n,key);
	if(ans==-1)
		printf("\nelement does not exist\n");
	else
		printf("\nElement is present at %d position\n",ans);
	
	return 0;
}//main




















