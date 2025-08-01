#include<stdio.h>
#include<malloc.h>
typedef struct node  
{     				
    int info;					   
    struct node *next;                       
}NODE;                                        
NODE *top;
void init()
{
     top=NULL;
}
int IsEmpty()
{
     if(top==NULL)
         return 1;
      else
         return 0;
} 
void push(int ele)
{
     NODE *newnode;
     newnode = (NODE *)malloc(sizeof(NODE));
     newnode->info=ele;
     newnode->next = top;
     top=newnode;  	
}
int pop()
{
     int ele;
     NODE *temp;
     temp=top;
     top=top->next;
     ele=temp->info;
     free(temp);
     return ele;
} 
int main()
{
    int ch,ele;
    init();
     do
     {
             printf("\n1: Push");
             printf("\n2:  Pop");
             printf("\nEnter your choice");
             scanf("%d",&ch);
             switch(ch)
             {
                   case 1: 
 					printf("\nEnter element");
                                   scanf("%d",&ele);
                                   push(ele);
                                
                          break;
			case 2:
                                if(IsEmpty())
                                     printf("\nStack underflow");
                                 else
					{
                                        ele=pop();
                                        printf("\nPopped element is:%d",ele);
                                    }
                          break;
              }//switch
     }while(ch!=0);
     return 0;
}



