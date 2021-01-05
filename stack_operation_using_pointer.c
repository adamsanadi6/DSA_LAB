#include<stdio.h>
#include<stdlib.h>

void push();
int pop();
void display();
int overflow();
int underflow();

#define MAX 10

int ch,s1[MAX],s2[MAX],t1=-1,t2=-1,ele,n,i,item;

int main()
{
	while(1)
	{
		printf("\n1=push to stack 1\n2=pop from stack 1\n3=display the stack 1\n4=push to stack 2\n5=pop from stack 2\n6=display the stack 2\n7=exit\n");
		printf("\nenter the choice:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(overflow(s1,&t1))
			      		printf("Stack is Full.\n");
			       else
			       {
					printf("Enter the element to be pushed :\n");
			      		scanf("%d",&ele);
		 	       		push(ele,s1,&t1);
			       }
			       break;
			case 2:if(underflow(s1,&t1))
			       {
			       		printf("Stack is empty.\n");
			       }
			       else
			       {
					ele=pop(s1,&t1);
					printf("The poped element is %d.\n",ele);
			       }
			       break;
			case 3:if(underflow(s1,&t1))
			       {
			       		printf("Stack is empty.\n");
			       }
			       else
					display(s1,&t1);
			       break;
			case 4:if(overflow(s2,&t2))
			      		printf("Stack is Full.\n");
			       else
			       {
					printf("Enter the element to be pushed :\n");
			      		scanf("%d",&ele);
		 	       		push(ele,s2,&t2);
			       }
			       break;
			case 5:if(underflow(s2,&t2))
			       {
			       		printf("Stack is empty.\n");
			       }
			       else
			       {
					ele=pop(s2,&t2);
					printf("The poped element is %d.\n",ele);
			       }
			       break;
			case 6:if(underflow(s2,&t2))
			       {
			       		printf("Stack is empty.\n");
			       }
			       else
					display(s2,&t2);
			       break;
			case 7:exit(0);
		}
	}
}

void push(int ele,int s[],int *t)
{
	{
		(*t)++;
		s[*t]=ele;
	}
}

int pop(int s[],int *t)
{
	ele=s[*t];
	(*t)--;
	return ele;
}

void display(int s[],int *t)
{
		printf("The stack is:  ");
		for(i=*t;i>=0;i--)
		{
			printf("%d\t",s[i]);
		}
		printf("\n");
}

int overflow(int s[],int *t)
{
	if(*t>=MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int underflow(int s[],int *t)
{
	if(*t==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
