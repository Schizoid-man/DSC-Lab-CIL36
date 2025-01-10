#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int front = -1, rear = -1;
void insert(int value);
void delete();
void display();
int item[MAX];
int main()
{
	int value;
	int ch;
	int callerid;
	while(1)
	{
		printf("\nEnter option: \n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit \n");
			scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter callerid \n");
				scanf("%d", &callerid);
				insert(callerid);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
}
void insert(int value)
{
	if(rear == MAX-1)
		printf("Queue Overflow!");
	if(rear == -1 && front == -1)
		front = 0;
	rear++;
	item[rear] = value;
}
void delete()
{
	if(front == -1 )
		printf("Queue underflow");
	else
	{
		printf("\n Callerid deleted: %d", item[front]);
		front++;
		if(front>rear)
			front = rear = -1;
	}
}
void display()
{
	if(rear == -1)
		printf("Queue empty");
	else
	{
		printf("\n Calls held in queue: ");
		for(int i = front;i<=rear;i++)
		{
			printf("%d ", item[i]);
		}
	}
}


