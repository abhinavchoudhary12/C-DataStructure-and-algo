#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NILL -1
#define MAX 10
typedef struct lqueue{
int front,rear;
int a[MAX];
}queue;
void main()
{
queue Q;
int n,data;
clrscr();
Q.front=Q.rear=NILL;
while(1)
{
printf("\n1. queue is full\n");
printf("2. queue is empty\n");
printf("3. insert in queue\n");
printf("4. delete from queue\n");
printf("5. exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
if(Q.front==NILL&&Q.rear==MAX-1)
{
printf("Queue is full\n");
}
else
{
printf("Queue is not full\n");
}
break;
case 2:
if(Q.front==Q.rear)
{
printf("Queue is empty\n");
}
else
{
printf("Queue is not empty\n");
}
break;
case 3:
if(Q.front==Q.rear==NILL)
{
Q.front=0;
Q.rear=0;
}
else if(Q.front==0&&Q.rear==MAX-1)
{
printf("Queue is full\n");
}
else if(Q.rear==MAX-1)
{
printf("Queue is full\n");
}
else
{
printf("insert data\n");
scanf("%d",&data);
Q.rear++;
Q.a[Q.rear]=data;
printf("your insereted data is %d\n",Q.a[Q.rear]);
}
break;
case 4:
if(Q.front==Q.rear)
{
printf("Queue is empty\n");
Q.front=Q.rear=NILL;
}
else
{
 Q.front++;
 printf("your deleted data is %d\n",Q.a[Q.front]);

}
break;
case 5:
exit(1);
}

}

getch();
}