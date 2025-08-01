//Dynamic Queue
#include<stdio.h>
#include<malloc.h>
typedef struct node
{                             
      int info;
      struct node *next;
}NODE;
NODE *front,*rear,*newnode;
void init()
{
     front=rear=NULL;
}
int IsEmpty()
{
     if(front==NULL)
         return 1;
      else
         return 0;
} 
void addq(int ele)
{
            newnode=(NODE *)malloc(sizeof(NODE));
            newnode->info=ele;
            newnode->next=NULL;
            if(front==NULL)
                 front=rear=newnode;
             else
                {
                 rear->next=newnode;
                 rear=newnode;
                }
}
int deleteq()
{
     NODE *temp; 
     int ele;
     temp=front;
     ele=temp->info;
      front=front->next;
      free(temp); 
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


