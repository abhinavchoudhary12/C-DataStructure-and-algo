#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct lklist{
int info;
struct lklist * next;
}node;
void main()
{
int n,data,pos;
clrscr();
node * head=NULL,*temp,*ptr;



while(1)
{
printf("enter operation\n");
printf("1. insert at beginning\n");
printf("2. traversing\n");
printf("3. insert at the end\n");
printf("4. insert after a position\n");
printf("5. search an element\n");
printf("6. delete at beginning\n");
printf("7. delete at the end\n");
printf("8. delete after a given position\n");
printf("9. exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
printf("enter the element\n");
scanf("%d",&data);
temp=(node *)malloc(sizeof(node));
if(temp==NULL)
{
printf("memory not allocated");
}
temp->info=data;
if(head!=NULL)
{
temp->next=head;
}
else
{
temp->next=NULL;
}

head=temp;
break;
case 2:
temp=head;
while(temp!=NULL)
{
printf("%d\n",temp->info);
temp=temp->next;
}
break;
case 3:
printf("enter the element\n");
scanf("%d",&data);
temp=head;
ptr=(node*)malloc(sizeof(node));
if(ptr==NULL)
{
printf("memory not allocated");
}
ptr->info=data;
ptr->next=NULL;
if(temp==NULL)
{
head=ptr;
}
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
break;
case 4:
printf("enter the position\n");
scanf("%d",&pos);
int i=1,count=0;
temp=head;
while(temp!=NULL)
{
temp=temp->next;
count++;
}
if(pos>count || pos<1)
{
printf("enter correct position\n");
}
else
{
temp=head;
while(pos>i)
{
temp=temp->next;
pos--;
}
printf("enter the element");
scanf("%d",&data);
ptr=(node*)malloc(sizeof(node));
ptr->info=data;
ptr->next=temp->next;
temp->next=ptr;
}
break;
case 5:
printf("enter the element you want to search\n");
scanf("%d",&data);
temp=head;
while(temp!=NULL)
{
if(temp->info==data)
{
printf("element found....\n");
break;
}
temp=temp->next;
}
if(temp==NULL)
{
printf("element not found....\n");
}
break;
case 6:
if(head==NULL)
{
printf("no element to delete....\n");
}
if(head->next==NULL)
{
head=NULL;
}
if(head!=NULL)
{
ptr=(node *)malloc(sizeof(node));
ptr=head;
head=head->next;
free(ptr);
}
break;
case 7:
temp=head;
if(head==NULL)
{
printf("no element to delete.....\n");
}
if(head->next==NULL)
{
  head=NULL;
}
ptr=(node *)malloc(sizeof(node));
while(temp->next!=NULL)
{
  ptr=temp;
  temp=temp->next;

}
ptr->next=NULL;
free(temp);
break;
case 8:
printf("enter the position\n");
scanf("%d",&pos);
int i1=1,count1=0;
temp=head;
while(temp!=NULL)
{
temp=temp->next;
count1++;
}
if(pos>count1 || pos<1)
{
printf("enter correct position\n");
}
else
{
temp=head;
while(pos>i1)
{
temp=temp->next;
pos--;
}
ptr=(node *)malloc(sizeof(node));
ptr=temp->next;
temp->next=ptr->next;
free(ptr);
}
break;
case 9:
exit(1);
}
}
getch();
}
