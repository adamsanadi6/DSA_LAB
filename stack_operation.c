#include<stdio.h>
#include<stdlib.h>

void push();
int pop();
void display();
int overflow();
int underflow();

#define MAX 10

int ch,stack[MAX],top=-1,ele,n,i;

int main()
{
	while(1)
	{
		printf("\n1=push\n2=pop\n3=display\n4=exit\n");
		printf("\nenter the choice:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(overflow())
			       printf("Stack is Full.\n");
			       else
			       {
					printf("Enter the element to be pushed :\n");
			      		scanf("%d",&ele);
		 	       		push();
			       }
			       break;
			case 2:if(underflow())
			       {
			       		printf("Stack is empty.\n");
			       }
			       else
			       {
					ele=pop();
					printf("The poped element is %d.\n",ele);
			       }
			       pop();
			       break;
			case 3:display();
			       break;
			case 4:exit(0);
		}
	}
}

void push(int ele)
{
	if(overflow())
	{
		printf("Stack is full.\n");
	}
	else
	{
		stack[++top]=ele;
	}
}

int pop()
{
	if(underflow())
	{
		printf("Stack is empty.\n");
	}
	else
	{
		ele=stack[top];
		top--;
		return ele;
	}
}

void display()
{
	if(underflow())
	{
		printf("Stack is empty.\n");
	}
	else
	{
		printf("The stack is:  ");
		for(i=top;i>=0;i--)
		{
			printf("%d\t",stack[i]);
		}
		printf("\n");
	}
}

int overflow()
{
	if(top==MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int underflow()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
