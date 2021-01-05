#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE             
{
    char name[100],dept[100],ssn[100],desgn[100],phno[100],sal[100];
    struct NODE *llink;
    struct NODE *rlink;
};

typedef struct NODE *Nodeptr; 
Nodeptr first=NULL,temp,ptr,prev,newnode;
int  n,ch,i,count;     


Nodeptr create_node()
{
    newnode=(Nodeptr)malloc(sizeof(struct NODE)); 
    printf("\nEnter the Employee SSN:\n");
    scanf("%s",newnode->ssn);
    printf("Enter the Employee Name:\n");
    scanf("%s",newnode->name);
    printf("Enter the Employee Department:\n");
    scanf("%s",newnode->dept);
    printf("Enter the Employee Designation:\n");
    scanf("%s",newnode->desgn);
    printf("Enter the Employee Salary:\n");
    scanf("%s",newnode->sal);
    printf("Enter the Employee Phone No:\n");
    scanf("%s",newnode->phno);
    newnode->rlink=NULL;  
    newnode->llink=NULL;  
    return newnode;        
}

void insert_front() 
{
    temp=create_node();
    if(first==NULL)
    	first=temp;
    temp->rlink=first;
    first->llink=temp;
    first=temp;
}

void delete_front()
{
    ptr=first;
    if(first==NULL)
        printf("List is Empty.\n");
    else if(first->rlink==NULL)
    {
        first=NULL;
        free(ptr);
        printf("Front node deleted successfully.\n");
    }
    else
    {
        first=ptr->rlink;
        ptr->rlink=NULL;
        first->llink=NULL;
        free(ptr);
        printf("Front node deleted successfully.\n");
    }
}

void insert_end()
{
    temp=create_node();
    ptr=first;
    if(first==NULL)
        first=temp;
    else
    {
        while(ptr->rlink!=NULL)
            ptr=ptr->rlink;     
        ptr->rlink=temp;
        temp->llink=ptr;
    }
}

void delete_end()
{
    ptr=first;
    if(first==NULL)
        printf("List is Empty.\n");
    else if(first->rlink==NULL)
    {
        first=NULL;
        free(ptr);
        printf("End node deleted successfully.\n");
    }
    else
    {
   	while(ptr->rlink!=NULL)
	{
		prev=ptr;
	ptr=ptr->rlink;
	}	
	prev->rlink=NULL;
	ptr->llink=NULL;
	free(ptr); 
        printf("End node deleted successfully.\n");
    }
}

void display()
{
    count=0;
    ptr=first;
    if(first==NULL)
        printf("List is Empty.\n");
    else
    {
        printf("\n<-:The DDL values are:->");
        while(ptr!=NULL)
        {
            printf("\nSSN:%s\nName:%s\nDepartment:%s\nDesignation:%s\nSalary:%s\nPh NO:%s\n",ptr->ssn,ptr->name,ptr->dept,ptr->desgn,ptr->sal,ptr->phno);
            ptr=ptr->rlink;
	    count++;
        }
        printf("\nNODE COUNT='%d'.\n",count);
    }

}

int main()
{
	while(1)
	{
		printf("\n<-:Doubly Linked List Operations Menu:->\n");
		printf("1. Create a DLL of N Students Data by using front insertion\n2. Display the status of DLL\n3. Insertion / Deletion at End of DLL\n4. Insertion / Deletion at Front of DLL\n5. Exit\nEnter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value of N to create DLL:\n");
                		scanf("%d",&n);
                		for(i=1;i<=n;i++)
                		{
                    			printf("Enter a %d node to insert towards end of DLL:\n",i);
                    			insert_end();
                		}
                		break;

			case 2: display();
				break;

			case 3: printf("Press 1 to Insert End or 2 to Delete End:\n");
                		scanf("%d",&ch);
                		if(ch==1)
				{
                    				printf("Enter a node to insert towards end of DLL:\n");
                    				insert_end();
				}
                		else if(ch==2)
                   			delete_end();
               			else
                    			printf("Invalid Entry.\n");
                		break;
		
			case 4: printf("Press 1 to Insert Front or 2 to Delete Front:\n");
	                	scanf("%d",&ch);
	                	if(ch==1)
	                	{
       	                		printf("Enter a node to insert to Front of DLL:\n");
                    			insert_front();
                		}
                		else if(ch==2)
                    			delete_front();        
                		else
                    			printf("Invalid Entry.\n");
                		break;

	        	case 5: exit(0);

			default: printf("Enter the valid choice.\n\n");
				 break;
		}
	}
	return 0;
}
