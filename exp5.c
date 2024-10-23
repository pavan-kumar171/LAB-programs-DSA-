#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int i,top=-1,op1,op2,res,s[20];
char postfix[90],symb;
void push(int item)
{
s[++top]=item;
}
 int pop()
{
 int item;
 item=s[top--];
 return item;
 }
 
void main()
{
 printf("Enter a valid postfix expression:");
 scanf("%s",postfix);
 for(i=0;postfix[i]!='\0';i++)
 {
	symb=postfix[i];
  if(isdigit(symb))
  {
   	push(symb-'0');
   }
  else
  {
  	op2=pop();
  	op1=pop();
  	switch(symb)
  	{
  	  case'+':push(op1+op2);
  	          break;
  	  case'-':push(op1-op2);
  	          break;
  	  case'*':push(op1*op2);
	          break;
	  case'/':push(op1/op2);
	          break;
	  case'%':push(op1%op2);
	          break;
	  case'^':push(pow(op1,op2));
	          break;
	  default:push(0);
	  }
	 }
	}
res=pop();
printf("\n Result =%d",res);
}

