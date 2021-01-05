#include<stdio.h>
#include<stdlib.h>

int ch,i,n;

struct node
{
	char usn[100],name[100],branch[100],phone[100],sem[100];
	struct node *link;
};

typedef struct node Nodeptr;
Nodeptr *first=NULL, *ptr, *newnode, *temp, *prev;

Nodeptr *create()
{
	newnode=(Nodeptr*)malloc(sizeof(Nodeptr));
	printf("Enter the USN, NAME, BRANCH, SEM, PHONE NO:\n");
	scanf("%s%s%s%s%s",newnode->usn,newnode->name,newnode->branch,newnode->sem,newnode->phone);
	newnode->link=NULL;
	return newnode;
}

Nodeptr *insert_front(Nodeptr *first)
{
	temp=create();
	if(first==NULL)
	{
		first=temp;
	}
	else
	{
		temp->link=first;
		first=temp;
	}
	return first;
}

Nodeptr *insert_end(Nodeptr *first)
{	
	temp=create();
	if(first==NULL)
	{
		first=temp;
	}
	else
	{
		ptr=first;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=temp;
	}
	return first;
}

Nodeptr *delete_front(Nodeptr *first)
{
	if(first==NULL)
		printf("Linked list is empty.\n");
	else
	{
		ptr=first;
		first=first->link;
		ptr->link=NULL;
		free(ptr);
	}
	return first;
}

Nodeptr *delete_end(Nodeptr *first)
{
	if(first==NULL)
	{
		printf("Linked list is empty.\n");
	}
	else if(first->link==NULL)
	{
		first=NULL;
		free(ptr);
	}
	else
	{
		ptr=first;
		while(ptr->link!=NULL)
		{
			prev=ptr;
			ptr=ptr->link;
		}	
		free(ptr);
		prev->link=NULL;
	}
	return first;
}

Nodeptr *display(Nodeptr *first)
{
	if(first==NULL)
	{
		printf("Linked list is empty.\n");
	}
	else
	{
		ptr=first;
		while(ptr->link!=NULL)
		{
			printf("USN:%s\nNAME:%s\nBRANCH:%s\nSEM:%s\nPHONE:%s\n\n",ptr->usn,ptr->name,ptr->branch,ptr->sem,ptr->phone);
			ptr=ptr->link;
		}
		printf("USN:%s\nNAME:%s\nBRANCH:%s\nSEM:%s\nPHONE:%s\n\n",ptr->usn,ptr->name,ptr->branch,ptr->sem,ptr->phone);
	}
}

void main()
{
	first=NULL;
	printf("STUDENT DATABASE\n");
	printf("Number of students data you want to create:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		first=insert_front(first);
	while(1)
	{
		printf("\n1-Insert from the front\n2-Delete from the front\n3-Insert from the end\n4-Delete from the end\n5-Stack insertion\n6-Stack deletion\n7-Display\n8-Exit\nEnter the choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:first=insert_front(first);
			       break;
	
			case 2:first=delete_front(first);
			       break;

			case 3:first=insert_end(first);
			       break;

			case 4:first=delete_end(first);
			       break;

			case 5:first=insert_front(first);
			       break;

			case 6:first=delete_front(first);
			       break;

			case 7:display(first);
    			       break;

			case 8:exit(0);
			       break;

			default:printf("Invalid choice.\n");
		}
	}
}
