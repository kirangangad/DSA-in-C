#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct stack
{
    int data[MAXSIZE];
    int top;
}STACK;
void initstack(STACK *s)
{
     s->top=-1;
}
void push(STACK *s, int num)
{
      s->top++;
      s->data[s->top]=num;
}
int pop(STACK *s)
{
      int ele;
      ele=s->data[s->top];
      s->top--;
      return ele;
}
int isEmpty(STACK *s)
{
      if(s->top==-1)
	  return 1;
      return 0;
}
int isFull(STACK *s)

{
      if(s->top==MAXSIZE-1)
	  return 1;
      return 0;
}
int evaluate(char postfix[20])
{
      STACK s;
      int value,i,opnd1,opnd2;
      initstack(&s);
      for(i=0;postfix[i]!='\0';i++)
      {
	  switch(postfix[i])
	  {
		case '+':opnd2=pop(&s);
		       opnd1=pop(&s);
		       push(&s,opnd1   + opnd2);
		       break;
	       case '-':opnd2=pop(&s);
		       opnd1=pop(&s);
		       push(&s,opnd1   - opnd2);
		       break;
	      case '*':opnd2=pop(&s);
		       opnd1=pop(&s);
		       push(&s,opnd1   * opnd2);
		       break;
	      case '/':opnd2=pop(&s);
		       opnd1=pop(&s);
		       push(&s,opnd1 / opnd2);
		       break;
	      default: printf("\nEnter the value of oprand %c",postfix[i]);
		       scanf("%d",&value);
		       push(&s,value);
	  }//switch
      }//for
      return  pop(&s);
}
int main()
{
   int ans;
   char postfix[20];
   printf("\n Enter postfix string");
   scanf("%s",postfix);
   ans=evaluate(postfix);
   printf("\n the result is         %d\n ",ans);

    return 0;
}
