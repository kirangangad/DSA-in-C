//Dynamic circular Queue  (using circular linked list)
#include<stdio.h>
#include<malloc.h>
typedef struct node
{                             
      int info;
      struct node *next;
}NODE;
NODE *rear,*newnode;
void init()
{
     rear=NULL;
}
int IsEmpty()
{
     if(rear==NULL)
         return 1;
      else
         return 0;
} 
void addq(int ele)
{
            newnode=(NODE *)malloc(sizeof(NODE));
            newnode->info=ele;
            newnode->next=NULL;
            if(rear==NULL)
             {
                 rear=newnode;
                 rear->next=rear;       //circular
             }  
             else
                {
                 newnode->next=rear->next; 
                 rear->next=newnode;
                 rear=newnode;
                }
}
int deleteq()
{
     NODE *front; 
     int ele;
     front=rear->next;   //first
     rear->next=front->next;
     ele=front->info;
      if(front==rear)       //single node
       {
          rear=NULL;
        }
      free(front);
        return ele;

} 
int main()
{
    int ch,ele;
    init();
     do
     {
             printf("\n1: AddQ");
             printf("\n2:  DeleteQ");
             printf("\nEnter your choice");
             scanf("%d",&ch);
             switch(ch)
             {
                   case 1: printf("\nEnter element");
                           scanf("%d",&ele);
                           addq(ele);
                                
                          break;
			case 2:
                                if(IsEmpty())
                                     printf("\nQUEUE underflow");
                                 else
                                    {
                                        ele=deleteq();
                                        printf("\ndeleted element is:%d",ele);
                                    }
                          break;
              }//switch
     }while(ch!=0);
     return 0;
}


