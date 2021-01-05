#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int top=-1;
char stack[100];

void infix_to_postfix(char *infix,char *postfix);
int precedence(char);
void push(char);
char pop();

void main()
{
	char infix[100],postfix[100];
	printf("Enter the infix expression:\n");
	scanf("%s",infix);
	printf("The entered infix expression is:\n%s\n", infix);
	infix_to_postfix(infix,postfix);
	printf("The postfix expression is:\n%s\n",postfix);
}

int precedence(char sym)
{
	switch(sym)
	{
		case '#': return 0;
		case '(': return 1;
		case ')': return 1;
		case '-': return 2;
		case '+': return 2;
		case '*': return 3;
		case '/': return 3;
		case '%': return 3;
		case '^': return 4;
		case '$': return 4;
		
		default:printf("'%c' is a invalid operator.\n",sym);
			exit(0);
	}
}

void infix_to_postfix(char *infix,char *postfix)
{
	int i=0,j=0;
	char sym,ele;
	push('#');
	while(infix[i]!='\0')
	{
		sym=infix[i];
		if(sym=='(')
			push(sym);
		else if(isalnum(sym))
			postfix[j++]=sym;
		else if(sym==')')
		{
			while(stack[top]!='(')
				postfix[j++]=pop();
			ele=pop();
		}
		else
		{
			while(precedence(stack[top])>=precedence(sym))
				postfix[j++]=pop();
			push(sym);
		}
		i++;
	}
	while(stack[top]!='#')
		postfix[j++]=pop();
	postfix[j]='\0';
}

void push(char ele)
{
	stack[++top]=ele;
}

char pop()
{
	return stack[top--];
}
