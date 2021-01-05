#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int stack[100],top=-1;
char postfix[100],sym;

void postfix_eval();
void push(int);
int pop();
void tower_of_hanoi(int, char, char, char);

void main()
{
	int ch,n;
	while(1)
	{
		printf("\n1-postfix evaluation\n2-tower of hanoi\n3-exit\n");
		printf("Enter the choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			 case 1:printf("Enter the postfix expression:\n");
				scanf("%s",postfix);
				printf("The entered postfix expresiion is:\n%s\n",postfix);
				postfix_eval();
				printf("The result is:\n%d\n",stack[top]);
				break;

			 case 2:printf("Enter the number of disks:\n");
				scanf("%d",&n);
				printf("The sequence of moves involved in tower of hanoi are:\n");
				tower_of_hanoi(n,'A','B','C');
				break;

			 case 3:exit(0);

			 default:printf("Invalid choice.\n");
				 break;
		}
	}
	
}

void postfix_eval()
{
	int op1,op2,i=0;
	while(postfix[i]!='\0')
	{
		sym=postfix[i];
		if(isdigit(sym))
			push(sym-'0');
		else
		{
			op2=pop();
			op1=pop();
			switch(sym)
			{
				case '+':push(op1+op2);
					 break;

				case '-':push(op1-op2);
					 break;

				case '*':push(op1*op2);
					 break;

				case '/':push(op1/op2);
					 break;

				case '%':push(op1%op2);
					 break;

				case '^':push(pow(op1,op2));
					 break;
			
				case '$':push(pow(op1,op2));
					 break;

			  	default:printf("'%c' is a invalid operator.\n",sym);
					exit(0);
			}
		}
		i++;
	}
}

void push(int ele)
{
	stack[++top]=ele;
}

int pop()
{
	return stack[top--];
}

void tower_of_hanoi(int N, char PEGA, char PEGB, char PEGC)
{
	if(N==1)
		printf("\nMove disk 1 from PEG %c to PEG %c.\n",PEGA,PEGB);
	else
	{
		tower_of_hanoi(N-1, PEGA, PEGC, PEGB);
		printf("\nMove disk %d from PEG %c to PEG %c.\n",N,PEGA,PEGB);
		tower_of_hanoi(N-1, PEGC, PEGB, PEGA);
	}
}
		


