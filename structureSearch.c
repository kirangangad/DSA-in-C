//linear search
#include<stdio.h>
struct employee
{
    int empno;
    char name[30];
    int age;
}; 
int search(struct employee a[], int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i].empno==key)
			return i;
	}
	return -1;
}
int main()
{
	int i,n,ans,key;
        struct employee a[10]; 
	printf("\nEnter number of elements");
	scanf("%d",&n);
	printf("\nEnter array elements emp no,name,age");
	for(i=0;i<n;i++)
		scanf("%d %s %d",&a[i].empno,&a[i].name,&a[i].age);
	printf("Enter empno to  search");
	scanf("%d",&key);
	ans=search(a,n,key);
	if(ans==-1)
		printf("\nelement does not exist");
	else
		printf("\nEmployee is present ,name is %s age is %d",a[ans].name,a[ans].age);
	return 0;


}//main


