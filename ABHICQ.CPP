#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NILL -1
#define MAX 5
typedef struct circulerq{
int front,rear;
int a[MAX];
}queue;
void main()
{
int a,n,data;
queue q;
clrscr();
q.front=q.rear=NILL;
int is_full(queue);
int is_empty(queue);
void insert_in_queue(queue *,int);
void delete_from_queue(queue *);
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
a=is_full(q);

if(a==1)
{
printf("queue is full\n");
}
else
{
printf("queue is not full\n");
}
break;
case 2:
a=is_empty(q);
if(a==1)
{
printf("queue is empty\n");
}
else
printf("queue is not empty\n");
break;
case 3:
a=is_full(q);
if(a==1)
{
printf("queue is full\n");
}
else
{
printf("enter the data\n");
scanf("%d",&data);
insert_in_queue(&q,data);
}
break;
case 4:
a=is_empty(q);
if(a==1)
{
printf("queue is empty\n");
}
else
{
delete_from_queue(&q);
}
break;
case 5:
exit(1);
}
}
getch();
}
int is_full(queue q)
{
if(q.front==0&&q.rear==MAX-1)
{
return 1;
}
else if((q.front)-1==q.rear)
{
return 1;
}
else
{
return 0;
}
}
int is_empty(queue q)
{
if(q.front==NILL&&q.rear==NILL)
{
return 1;
}
else if(q.front==q.rear)
{
return 1;
}
else
{
return 0;
}
}
void insert_in_queue(queue *q,int data)
{
if(q->rear==NILL&&q->front==NILL)
{
(*q).rear=0;
q->front=0;
}
else if(q->rear==MAX-1&&q->front!=0)
{
q->rear=NILL;
}
q->rear++;
q->a[q->rear]=data;
printf("entered data is %d",q->a[q->rear]);
}
void delete_from_queue(queue *q)
{
if((q->rear)<(q->front)&&q->front==MAX-1)
{
q->front=0;
printf("deleted element is %d",q->a[q->front]);
}
else
{
q->front++;
printf("deleted element is %d",q->a[q->front]);

}
}