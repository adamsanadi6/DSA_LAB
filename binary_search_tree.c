#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
    	struct Node *left,*right;
};

typedef struct Node *Nodeptr;

Nodeptr root=NULL,temp;
int  n,i,ele,key;
char ch;

Nodeptr getnode(int ele)
{
    	temp=(Nodeptr)malloc(sizeof(struct Node));
    	temp->data=ele;
    	temp->left=NULL;
    	temp->right=NULL;
    	return temp;
}

Nodeptr create(Nodeptr ptr,int ele)
{
    	if(ptr==NULL)
    	{
        	temp=getnode(ele);
        	ptr=temp;
    	}
    	else
    	{
        	if(ptr->data==ele)
            		return ptr;
        	else if(ptr->data<ele)
            		ptr->right=create(ptr->right,ele);
        	else if(ptr->data>ele)
            		ptr->left=create(ptr->left,ele);
    	}
    	return ptr;
}

void inorder(Nodeptr temp)
{
    	if(temp!=NULL)
    	{
        	inorder(temp->left);
        	printf("%d\t",temp->data);
        	inorder(temp->right);
    	}
}

void preorder(Nodeptr temp)
{
    	if(temp!=NULL)
   	{
		printf("%d\t",temp->data);
		preorder(temp->left);
        	preorder(temp->right);
	}
}

void postorder(Nodeptr temp)
{
    	if(temp!=NULL)
    	{
        	postorder(temp->left);
        	postorder(temp->right);
       	 	printf("%d\t",temp->data);
    	}	
}

void search(int key)
{
   	temp=root;
    	while(temp!=NULL)
        {
            	if(temp->data==key)
            	{
                	printf("The KEY element's search is SUCCESSFUL!\n");
                	return;
            	}
            	else if(temp->data>key)
                	temp=temp->left;
            	else
                	temp=temp->right;
        }
        printf("The KEY element's search is UNSUCCESSFUL!\n");
}

void main()
{
    	while(1)
	{
		printf("\n<-:Binary Search Tree (BST) Operation Menu:->\n1. Create a BST of N Integers\n2. Traverse the BST in InOrder, PreOrder and Post Order\n3. Search the BST for a given KEY element\n4. Exit\nEnter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
            		case 1: printf("Enter the number of Nodes:\n");
                    		scanf("%d",&n);
                    		printf("Enter %d Nodes:\n",n);
                    		for(i=0;i<n;i++)
                   		{
                        		scanf("%d",&ele);
                        		root=create(root,ele);
                    		}
                    		break;

            		case 2: printf("\nThe INORDER traversal for given BST is:\n");
                    		inorder(root);
                    		printf("\nThe PREORDER traversal for given BST is:\n");
                    		preorder(root);
                    		printf("\nThe POSTORDER traversal for given BST is:\n");
                    		postorder(root);
				printf("\n");
                   		break;

            		case 3: printf("Enter the KEY value to search\n");
                    		scanf("%d",&key);
                    		search(key);
                    		break;

            		case 4: exit(0);

            		default: printf("Enter a Valid Choice.\n");
		}
	}
}
