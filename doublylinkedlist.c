
//doubly linked list
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
      int info;
      struct node *prev,*next;
}NODE;
NODE *start,*temp,*newnode;
NODE *create(NODE *start)
{
      int n,i;
       printf("Enter no of nodes");
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
             newnode=(NODE *)malloc(sizeof(NODE));
             printf("Enter data");
	     scanf("%d",&newnode->info);
             newnode->prev=newnode->next=NULL;
             if(start==NULL)
		{
                  start=temp=newnode;
               }
             else
             {
                 temp->next=newnode;
                 newnode->prev=temp;
                 temp=newnode;
             } //else
       } //for
        return start;
}//create
void display(NODE *start)
{
    for(temp=start;temp!=NULL;temp=temp->next)
    {
printf("\n%u\t%d\t%u",temp->prev,temp->info,temp->next);
     }
     
}
NODE *InsertFirst(NODE *start)
{
              newnode=(NODE *)malloc(sizeof(NODE));
		printf("Enter data");
		scanf("%d",&newnode->info);
		newnode->next=newnode->prev=NULL;
		newnode->next=start;
	       start->prev=newnode;
              start=newnode;
		return start;
}

NODE *InsertLast(NODE *start)
{
              
      		newnode=(NODE *)malloc(sizeof(NODE));
		printf("Enter data");
		scanf("%d",&newnode->info);
		newnode->next=newnode->prev=NULL;
	for(temp=start;temp->next!= NULL; temp=temp->next);
		temp->next=newnode;
		newnode->prev=temp;
		return start;
}
NODE *InsertMiddle(NODE *start, int pos)
{
              int i=1;
		NODE *temp1;
		temp=start;
      		newnode=(NODE *)malloc(sizeof(NODE));
		printf("Enter data");
		scanf("%d",&newnode->info);
		newnode->next=newnode->prev=NULL;
		while(i<pos)
		{
			temp1=temp;			
			temp=temp->next;
			i++;
		}
		newnode->next=temp->next;
		temp->prev=newnode;
		temp1->next=newnode;
		newnode->prev=temp1;
		return start;

}
NODE *deleteFirst(NODE *start)
{
        temp=start;
        start=start->next;
        start->prev=NULL;
        free(temp);
	 return start; 
}
NODE *deleteMiddle(NODE *start, int pos)
{
       int i=1;
       NODE *temp1;
       temp=start;
       while(i<pos)
	{
             temp1=temp;
	      temp=temp->next;
             i=i+1;
        }
        temp->next->prev=temp1;
        temp1->next=temp->next;
        free(temp);	
        return start;
}
NODE *deleteLast(NODE *start)
{
        NODE *temp1;
        for(temp=start;temp->next!=NULL;temp=temp->next)
                 temp1=temp;
        temp1->next=NULL;
        free(temp);
        return start; 
}
int main()
{
	start=NULL;
	int ch,key,ans,pos;
       do
	{
       	printf("\n 1: create");
		printf("\n 2: display");
		printf("\n 3: insert at first position");
		printf("\n 4:insert in middle position");
		printf("\n 5:insert at the last position");
		printf("\n 6:delete first position");
		printf("\n 7:delete last position");
		printf("\n 8:delete middle position");
		printf("\n Enter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
   	
			case 1:start=create(start);
				break;
			case 2:display(start);
				break;
			case 3: 
					start=InsertFirst(start);
					break;	
			case 4: printf("\nenter position");
				scanf("%d",&pos);
				start=	InsertMiddle(start,pos);
				break;
			case 5: 
					start=InsertLast(start);
					break;	
case 6: 
					start=deleteFirst(start);
					break;	
case 7: 
					start=deleteLast(start);
					break;	
case 8: printf("\nenter position");
				scanf("%d",&pos);
				start=	deleteMiddle(start,pos);
				break;
		}//switch
	
	}while(ch!=0);   
     return 0;
}




