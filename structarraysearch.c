// Linear search for int array
#include<stdio.h>
struct student 
{
     int roll_no;
     char name[30];
};
void get(struct student a[20],int n);
void display(struct student a[20],int n);
int lsearch(struct student a[20],int n,int key);
int main()
{
	int i,n,key,ans;
       struct student a[20]; 
	printf("Enter no of elements");
	scanf("%d",&n);
	get(a,n);
	display(a,n);
       printf("\enter key to search");
       scanf("%d",&key);
       ans=lsearch(a,n,key);
       if(ans==-1)
		printf("\n Element does not exist");
	else
           {
		printf("\n element is present at %d position",ans);
printf("\n student name : %s",a[ans].name);
}//else
	return 0;
}
void get(struct student a[20],int n)
{
      int i;	
      printf("\nEnter no of students \n");
	for(i=0;i<n;i++)
	{
 		printf("\nEnter roll_no and name");
		scanf("%d%s",&a[i].roll_no,a[i].name);
	}
}
void display(struct student a[20],int n)
{
	int i;
	printf("\nStudent details are.....\n");
         for(i=0;i<n;i++)
		printf("\n%d \t%s  ",a[i].roll_no,a[i].name);
}
int lsearch(struct student a[20],int n,int key)
{
	int i;       
	for(i=0;i<n;i++)
  	{
		if(a[i].roll_no==key)
                    return i;
       }//for
       return -1;
 }

