#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}Node;
Node *root = NULL;
Node *newNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->right = temp->left = NULL;
	return temp;
}
Node *insert(Node *node,int data)
{
	if(node == NULL)
		return newNode(data);
	if(data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right,data);
	return node;
}
void inorder(Node *root)
{
	if(root!= NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void preorder(Node *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
int main()
{
	int choice, value;
	while(1)
	{
		printf("\n 1. Insert \n 2. Inorder \n 3. Preorder \n 4. Postorder \n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter value");
				scanf("%d", &value);
				root = insert(root, value);
				break;
			case 2:
				printf("\n Inorder: \n");
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				exit(1);
			default:
				printf("Wrong choice\n");
		}
	}
}

