#include<stdio.h>
#define MAX 5
typedef struct 
{
    int data[MAX];
    int top;
}STACK;
void init(STACK *s)
{
     s->top=-1;
}
int IsFull(STACK *s)
{
     if(s->top == MAX-1)
         return 1;
      else
         return 0;
} 
int IsEmpty(STACK *s)
{
     if(s->top==-1)
         return 1;
      else
         return 0;
} 
void push(STACK *s,int ele)
{
     s->top++;
     s->data[s->top]=ele;
}
int pop(STACK *s)
{
     int ele;
     ele=s->data[s->top];  
     s->top--;
     return ele;
} 
int main()
{
    STACK s;
    int ch,ele;
    init(&s);
     do
     {
             printf("\n1: Push");
             printf("\n2:  Pop");
             printf("\nEnter your choice");
             scanf("%d",&ch);
             switch(ch)
             {
                   case 1: if(IsFull(&s))
                                 printf("\nStack overflow");
                            else
                               {
 					printf("\nEnter element");
                                   scanf("%d",&ele);
                                   push(&s,ele);
                               } 
                          break;
			case 2:
                                if(IsEmpty(&s))
                                     printf("\nStack underflow");
                                 else
                                    {
                                        ele=pop(&s);
                                        printf("\nPopped element is:%d",ele);
                                    }
                          break;
              }//switch
     }while(ch!=0);
     return 0;


























































}
