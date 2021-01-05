#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void Qinsert();
char Qdelete();
void Qdisplay();
int overflow();
int underflow();

char CQ[MAX],ele,item;
int front=0,rear=0,ch;

void main()
{
	while(1)
	{
		printf("\n1-Qinsert\n2-Qdelete\n3-Qdisplay\n4-Exit\nEnter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(overflow())
					printf("Queue overflow.\n");
			       else
			       {
					printf("Enter the element:\n");
					scanf(" %C",&ele);
					Qinsert();
			       }
			       break;
	
			case 2:if(underflow())
					printf("Queue underflow.\n");
			       else
			       {
					item=Qdelete();
					printf("The deleted Queue element is '%c'.\n",item);
			       }
			       break;
	
			case 3:if(front==rear)
					printf("Queue underflow.\n");
			       else
	        	       {
					printf("The Queue elements are:\n");
					Qdisplay();
					printf("\n");
			       }
			       break;

			case 4:exit(0);

			default:printf("Invalid choice.\n");
		}
	}
}

void Qinsert()
{
	rear=(rear+1)%MAX;
	CQ[rear]=ele;
}

char Qdelete()
{
	front=(front+1)%MAX;
	return CQ[front];
}

void Qdisplay()
{
	int i=(front+1)%MAX;
	while(i!=rear)
	{
		printf("%c\t",CQ[i]);
		i=(i+1)%MAX;
	}
	printf("%c\t",CQ[i]);
}

int overflow()
{
	if(front==(rear+1)%MAX)
		return 1;
	else
		return 0;
}

int underflow()
{
	if(front==rear)
		return 1;
	else
		return 0;
}
