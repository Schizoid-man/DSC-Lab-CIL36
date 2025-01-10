#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;
Node *top = NULL;
void push(int value);
int pop();
int peek();
void display();
int main()
{
	int choice, value;
	while(1){

		printf("\nEnter your choice \n 1. Push \n 2. Pop \n 3.Peek \n 4. Display \n 5. Exit \n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter value");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
				value = pop();
				if(value != -1)
					printf("Value = %d\n", value);
				break;
			case 3:
				value = peek();
				if(value != -1)
					printf("Value = %d \n", value);
				break;
			case 4:
				display();
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
}
void push(int value)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = value;
	temp->next = top;
	top = temp;
}
int pop()
{
	if(top == NULL)
	{
		printf("Stack empty!\n");
		return -1;
	}
	Node *temp = top;
	top = temp->next;
	int item = temp->data;
	free(temp);
	return item;
}
int peek()
{
	if(top == NULL)
	{
		printf("Stack empty\n");
		return -1;
	}
	return top->data;
}
void display()
{
	if(top == NULL)
	{
		printf("Stack is empty");
		return ;
	}
	Node *temp = top;
	printf("Stack : ");
	while(temp !=NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

