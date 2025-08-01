//static circular queue
#include<stdio.h>
#define MAX 5                        
typedef struct                    
{
    int data[MAX];
    int rear,front;
}QUEUE;

void init(QUEUE *s)
{
     s->rear=s->front=MAX-1;
}
int IsFull(QUEUE *s)
{
     if((s->rear +1)%MAX == s->front)
         return 1;
      else
         return 0;
} 
int IsEmpty(QUEUE *s)
{
     if(s->front==s->rear)
         return 1;
      else
         return 0;
} 
void addq(QUEUE *s,int ele)
{
     s->rear=(s->rear+1) %MAX;
     s->data[s->rear]=ele;
}
int deleteq(QUEUE *s)
{
     int ele;
     s->front=(s->front+1)%MAX;
     ele=s->data[s->front];
     return ele;
}
int main()
{
    QUEUE s;
    int ch,ele;
    init(&s);
     do
     {
             printf("\n1: AddQ");
             printf("\n2:  DeleteQ");
             printf("\nEnter your choice");
             scanf("%d",&ch);
             switch(ch)
             {
                   case 1: if(IsFull(&s))
                                 printf("\nQUEUE overflow");
                            else
                               {
 					printf("\nEnter element");
                                   scanf("%d",&ele);
                                   addq(&s,ele);
                               } 
                          break;
			case 2:
                                if(IsEmpty(&s))
                                     printf("\nQUEUE underflow");
                                 else
                                    {
                                        ele=deleteq(&s);
                                        printf("\ndeleted element is:%d",ele);
                                    }
                          break;
              }//switch
     }while(ch!=0);
     return 0;
}











