#include<stdio.h>
#include<stdlib.h>
#define MAX 2
char queue[MAX];
int front=-1,rear=-1;
int isFull()
{
  return ((rear+1)%MAX==front);
}
int isEmpty()
{
  return (front==-1);
}
void insert()
{
  char ch;
  if(isFull())
  {
    printf("Queue Overflow!Cannot insert.\n");
    return;
  }
  printf("Enter the character to insert:");
  scanf(" %c",&ch);
  if(isEmpty())
  {
    front=rear=0;
  }
  else
  {
    rear=(rear+1)%MAX;
  }
  queue[rear]=ch;
  printf("Inserted '%c' into the queue.\n",ch);
}
void delete()
{
  if(isEmpty())
  {
    printf("Queue Underflow!Nothing to delete.\n");
    return;
  }
  char deleted =queue[front];
  if(front==rear)
  {
    front=rear=-1;
  }
  else
  {
    front=(front+1)%MAX;
  }
  printf("Deleted '%c' from the queue.\n",deleted);
}
void display()
{
  if(isEmpty())
  {
    printf("Queue is empty.\n");
    return ;
  }
  printf("Queue contents:");
  int i=front;
  while(1)
  {
    printf("%c",queue[i]);
    if(i==rear)
      break;
    i=(i+1)%MAX;
  }
  printf("\n");
}
void queueStatus()
{
  if(isEmpty())
  { 
    printf("Queue is Empty.\n");
  }
  else if(isFull())
  {
    printf("Queue is Full.\n");
  }
  else
  {
    int count=(rear>=front)?(rear-front+1):(MAX-front+rear+1);
    printf("Queue has%d element(s),space left:%d\n",count,MAX-count);
  }
}
int main()
{
  int choice;
  while(1)
  {
    printf("\n---CIRCULAR QUEUE MENU---\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display Queue\n");
    printf("4.Queue Status\n");
    printf("5.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:insert();break;
      case 2:delete();break;
      case 3:display();break;
      case 4:queueStatus();break;
      case 5:printf("Exiting Program.\n");exit(0);
      default:printf("Invalid choice!Try again.\n");
    }
   }
   return 0;
}
  
