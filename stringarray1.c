#include<stdio.h>
#include<string.h>
void get(char a[10][20],int n);
void display(char a[10][20],int n);
int lsearch(char a[10][20],int n,char key[20]);
int main()
{
	int i,n,ans;
       char a[10][20],key[20];
	printf("Enter no of elements");
	scanf("%d",&n);
	get(a,n);
	display(a,n);
       printf("\enter key to search");
       scanf("%s",&key);
       ans=lsearch(a,n,key);
       if(ans==-1)
		printf("\n Element does not exist\n");
	else
		printf("\n element is present at %d position\n",ans);
	return 0;
}
void get(char a[10][20],int n)
{
      int i;	
      printf("\nEnter array elements\n");
	for(i=0;i<n;i++)
		scanf("%s",&a[i]);
}
void display(char a[10][20],int n)
{
	int i;
        for(i=0;i<n;i++)
		printf("%s   ",a[i]);
}
int lsearch(char a[10][20],int n,char key[20])
{
       int i;
       for(i=0;i<n;i++)
  	{
		if(strcmp(a[i],key)==0)
                    return i;
       }//for
       return -1;
 }








