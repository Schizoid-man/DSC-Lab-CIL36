#include <stdio.h>
#include <stdlib.h>
#define MAX 3
void insert(int value);
int delete();
void display();
struct CircularQ
{
	int data;
};//; is important
struct CircularQ queue[MAX];
int front = -1, rear = -1; 
int main()
{
	int value;
	int choice;

	while(1)
	{
		printf("\nEnter your choice \n 1. Insert \n 2. Delete \n 3.Display \n 4. Exit \n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter value");
				scanf("%d", &value);
				insert(value);
				break;
			case 2:
				value = delete();
				if(value != -1)
					printf("Element deleted: %d", value);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid choice");
			
		}
	}
}
void insert(int value)
{
	if((front == 0 && rear == MAX-1) || (rear+1 == front))
	{
		printf("Circular Q is full!\n");
		return;
	}
	if(front == -1)//empty so make both 0
		front = rear=0;
	if (rear == MAX-1)//becos circular q
		rear = 0;
	else
		rear++;
	queue[rear].data = value;
}
int delete()
{
	int value;
	if(front == -1)
		return -1;//becos empty
	value = queue[front].data;
	if(front == rear)
		front = rear = -1;
	else if(front == MAX-1)
		front = 0;
	else
		front++;
	return value;
}
void display()
{
	if(front ==-1)
		printf("Empty Q\n");
	else
	{
		int i;//remember to put i here cos we need it after the loop
		printf("Front: %d \n", front);
		printf("Items: ");
		for( i = front;i !=rear;i=(i+1)%MAX)
			printf("%d ", queue[i].data);
	
		printf("%d ", queue[i].data);
		printf("\n Rear -> %d \n", rear);
	}
}


