#include<stdio.h>
#include<stdlib.h>

void push();
int pop();
void display();
int overflow();
int underflow();
void palindrome();

#define MAX 10

int ch,s1[MAX],s2[MAX],t1=-1,t2=-1,ele,n,i;

int main()
{
	while(1)
	{
		printf("\n1=push to stack 1\n2=pop from stack 1\n3=display the stack\n4=check the palindrome\n5=exit\n");
		printf("Enter the choice:\n");
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
			       		printf("Stack is empty.\n");
			       else
			       {
					ele=pop(s1,&t1);
					printf("The poped element is %d.\n",ele);
			       }
			       break;

			case 3:if(underflow(s1,&t1))
			       		printf("Stack is empty.\n");
			       else
					display(s1,&t1);
			       break;

			case 4:palindrome();
			       break;

			case 5:exit(0);
		}
	}
}

void push(int ele,int s[],int *t)
{ 
		(*t)++; 
		s[*t]=ele;
}

int pop(int s[],int *t)
{
	ele=s[*t];
	(*t)--;
	return ele;
}

void display(int s[],int *t)
{
		printf("The stack is:\n");
		for(i=*t;i>=0;i--)
			printf("%d\t",s[i]);
		printf("\n");
}

int overflow(int s[],int *t)
{
	if(*t>=MAX-1)
		return 1;
	else
		return 0;
}

int underflow(int s[],int *t)
{
	if(*t==-1)
		return 1;
	else
		return 0;
}

void palindrome()
{
	int s1[MAX],s2[MAX],t1=-1,t2=-1,x,z,i,n,a,b,flag=0;
	printf("Enter the value of n :\n");
	scanf("%d",&n);
	printf("Enter the elements of stack:\n");
	for(t1=0;t1<n;t1++)
		scanf("%d",&s1[t1]);
	t1--;
	x=t1;
	z=x/2;
	for(i=x;i>z;i--)
	{
		a=pop(s1,&t1);
		push(a,s2,&t2); 
        }
	if((n%2)!=0)
		a=pop(s1,&t1);  
	while((t1>=0) && (t2>=0))
	{ 
		a=pop(s1,&t1);
		b=pop(s2,&t2);  
		if(a!=b)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("The stack is not a palindrome.\n");
	else
		printf("The stack is a palindrome.\n");
}
