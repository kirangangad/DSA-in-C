#include<stdio.h>
#include<malloc.h>
 typedef struct node
{
    int info;
    struct node *next;
}NODE;
NODE *start,*newnode,*temp;
NODE *create(NODE *start)
{
      int n,i;
	printf("enter no of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(NODE *)malloc(sizeof(NODE));
		printf("Enter data");
		scanf("%d",&newnode->info);
		newnode->next=NULL;
		if(start==NULL)
			start=temp=newnode;   //first node
		else
		{
			temp->next=newnode;
			temp=newnode;
		}//else
	}//for
	return start;
}
void display(NODE *start)
{
	for(temp=start;temp!=NULL;temp=temp->next)
		printf("\n%d\t%u ",temp->info,temp->next);
}
int search(NODE *start, int key)
{
	int i;
	for(temp=start,i=1;temp!=NULL;temp=temp->next,i++)
	{
		if(temp->info == key)
			return i; 
	}
       return -1; 
}
int main()
{
	start=NULL;
	int ch,key,ans;
       do
	{
       	printf("\n 1: create");
		printf("\n 2: display");
		printf("\n 3: search");
		printf("\n Enter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
   	
			case 1:start=create(start);
				break;
			case 2:display(start);
				break;
			case 3:printf("\nEnter key to search");
				scanf("%d",&key);
				ans=search(start,key);
				if(ans==-1)
					printf("\n Element does not exist");
				else
	printf("\n element found at %d position",ans);
				break;
			
		}//switch
	}while(ch!=0);
	return 0;
}

















 
