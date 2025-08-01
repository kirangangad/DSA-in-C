#include<stdio.h>
#include<stdlib.h>        
#define MAXSIZE 20        
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
int priority(char ch)
{
      switch(ch)
      {
	  case '(':return 0;
	  case '+':
	  case  '-':return 1;
	  case '*':
	  case '/':
	  case '%':return 2;
	  case '^':
         case '$':return 3;

      }//switch
      return 0;
}
int stacktop(STACK *s)
{
     return s->data[s->top];
}
void convert(char infix[20], char postfix[20])
{
       int i,j=0;
       char ch,ch1;
       STACK s;
       initstack(&s);                           
       for(i=0;infix[i]!='\0';i++)
       {
	     ch=infix[i];
	     switch(ch)
	     {
		    case '(': push(&s,ch);
			      break;
		    case '+':
		    case '-':
		    case '*':
		    case '/':
		    case '%':
		    case '^':   if(isEmpty(&s))
				   push(&s,ch);
				else
				{
				     while(priority(stacktop(&s)) >= priority(ch))
					  postfix[j++]=pop(&s);
				     push(&s,ch);
				}//else
				break;
		  case ')':while((ch1=pop(&s))!='(')

			       postfix[j++]=ch1;
			   break;
		   default:postfix[j++]=ch;
	     }//switch       
       }//for
       while(!isEmpty(&s))
	     postfix[j++]=pop(&s);
       postfix[j]='\0';   //terminate postfix string
}
int main()
{
	  char infix[20],postfix[20];
	  printf("\nEnter the infix expression\n");
	  scanf("%s",infix);
	  convert(infix,postfix);
	  printf("\n converted expression is %s\n",postfix);
	  return 0;
}












