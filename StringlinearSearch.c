//linear search
#include<stdio.h>
#include<string.h>
int search(char a[10][20], int n,char key[20])
{       
       int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i],key)==0)
			return i;
	}
	return -1;
}
int main()
{
	int i,n,ans;
	char a[10][20],key[20];
       printf("\nEnter number of elements");
	scanf("%d",&n);
	printf("\nEnter array elements");
	for(i=0;i<n;i++)
		//a[i]=rand()%100;  //random no generator
		scanf("%s",a[i]);
	printf("\n  Array is.......\n");
	for(i=0;i<n;i++)
		printf("%s\t",a[i]);
	printf("\nEnter key to search");
	scanf("%s",key);
	ans=search(a,n,key);
	if(ans==-1)
		printf("\nelement does not exist\n");
	else
		printf("\nElement is present at %d position\n",ans);
	
	return 0;
}//main






















