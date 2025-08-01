//linear search
#include<stdio.h>
struct employee
{
	int id;
	char name[30];
	int sal;
};
int search(struct employee a[], int n,int key)
{       
       int i;
	for(i=0;i<n;i++)
	{
		if(a[i].id==key)
			return i;
	}
	return -1;
}

int main()
{
	struct employee a[20];	
	int i,n,key,ans;
	printf("\nEnter number of elements");
	scanf("%d",&n);
	printf("\nEnter employee details\n");
	for(i=0;i<n;i++)
	scanf("%d %s %d",&a[i].id,a[i].name,&a[i].sal);
	printf("\n  Array is.......\n");
	for(i=0;i<n;i++)
	printf("\n%d\t%s\t%d ",a[i].id,a[i].name,a[i].sal);
	printf("Enter the key to search");
	scanf("%d",&key);
	ans=search(a,n,key);
	if(ans==-1)
		printf("\nelement does not exist\n");
	else
       {
		printf("\nElement is present at %d position",ans);
       printf("\n empname is %s and salary is %d\n",a[ans].name,a[ans].sal);
	}
	return 0;
}//main





























