// Linear search for int array
#include<stdio.h>
void get(int a[20],int n);
void display(int a[20],int n);
int lsearch(int a[20],int n,int key);
int main()
{
	int a[20],i,n,key,ans;
	printf("Enter no of elements");
	scanf("%d",&n);
	get(a,n);
	display(a,n);
       printf("\enter key to search");
       scanf("%d",&key);
       ans=lsearch(a,n,key);     //function call
       if(ans==-1)
		printf("\n Element does not exist\n");
	else
		printf("\n element is present at %d position\n",ans);
	return 0;
}
void get(int a[20],int n)
{
      int i;	
      printf("\nEnter array elements\n");
	for(i=0;i<n;i++)
	{
		
		scanf("%d",&a[i]);
	}
}
void display(int a[20],int n)
{
	int i;
        for(i=0;i<n;i++)
		printf("%d   ",a[i]);
}
int lsearch(int a[20],int n,int key)
{
	int i;       
	for(i=0;i<n;i++)
  	{
		if(a[i]==key)
                    return i;
       }//for
       return -1;
 }  








