#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct dlist{
struct dlist *prev;
int info;
struct dlist *next;
}node;
int main()
{
 int n,data,pos;

 node *head=NULL,*tail=NULL;

 void insert_at_beg(node **,node **,int);
 void traverse(node *);
 void traverse_rev(node *);
 void insert_at_end(node **,node **,int);
 void insert_after_pos(node **,node **,int,int);
 void insert_before_pos(node **,node **,int,int);
 void delete_from_beg(node **,node**);
 void delete_from_end(node **,node **);
 clrscr();
 while(1)
 {
 printf("\n1.insert at beginning\n");
 printf("2. traversing\n");
 printf("3. traverseing in reverse order\n");
 printf("4. insert at the end\n");
 printf("5. insert after a position\n");
 printf("6. insert before a position\n");
 printf("7. delete from begiining\n");
 printf("8. delte from end\n");
 printf("9. exit\n");
 scanf("%d",&n);
 switch(n)
 {
 case 1:
 printf("enter the data\n");
 scanf("%d",&data);
 insert_at_beg(&head,&tail,data);
 break;
 case 2:
 traverse(head);
 break;
 case 3:
 traverse_rev(tail);
 break;
 case 4:
 printf("enter the data\n");
 scanf("%d",&data);
 insert_at_end(&head,&tail,data);
 break;
 case 5:
 printf("enter the position\n");
 scanf("%d",&pos);
 printf("enter the data\n");
 scanf("%d",&data);
 insert_after_pos(&head,&tail,pos,data);
 break;
 case 6:
  printf("enter the position\n");
 scanf("%d",&pos);
 printf("enter the data\n");
 scanf("%d",&data);
 insert_before_pos(&head,&tail,pos,data);
 break;
 case 7:
 delete_from_beg(&head,&tail);
 break;
 case 8:
 delete_from_end(&head,&tail);
 break;
 case 9:
 exit(1);
 }

 }
getch();
}
void insert_at_beg(node **head,node **tail,int data)
{
node *temp;
temp=(node *)malloc(sizeof(node));
temp->info=data;
temp->prev=NULL;
temp->next=NULL;
if(*head==NULL)
{
*head=*tail=temp;
}
else
{
temp->next=*head;
(*head)->prev=temp;
*head=temp;
}
}
void traverse(node  *head)
{
while(head!=NULL)
{
printf("%d->",head->info);
head=head->next;
}

}
void traverse_rev(node *tail)
{
while(tail!=NULL)
{
printf("%d<-",tail->info);
tail=tail->prev;

}

}

void insert_at_end(node **head,node **tail,int data)
{
node *temp;
temp=(node *)malloc(sizeof(node));
temp->info=data;
temp->prev=NULL;
temp->next=NULL;
if(*head==NULL)
{
*head=*tail=temp;
}
else
{
temp->next=NULL;
(*tail)->next=temp;
temp->prev=*tail;
*tail=temp;
}
}
void insert_after_pos(node **head,node **tail,int pos,int data)
{
int count=0,i;
node *temp,*ptr;
temp=(node*)malloc(sizeof(node));
ptr=(node*)malloc(sizeof(node));
temp=*head;
ptr->info=data;
ptr->next=NULL;
ptr->prev=NULL;
while(temp!=NULL)
{
count++;
temp=temp->next;
}
if(count<pos)
{
printf("enter correct positin\n");
}
else if(pos==count)
{
ptr->next=NULL;
(*tail)->next=ptr;
ptr->prev=*tail;
*tail=ptr;
}
else
{
temp=*head;
while(pos>1)
{
temp=temp->next;
pos--;
}
ptr->next=temp->next;

ptr->prev=temp;
temp->next->prev=ptr;
temp->next=ptr;

}
}
void insert_before_pos(node **head,node **tail,int pos,int data)
{
int count=0,i;
node *temp,*ptr;
temp=(node*)malloc(sizeof(node));
ptr=(node*)malloc(sizeof(node));
temp=*head;
ptr->info=data;
ptr->next=NULL;
ptr->prev=NULL;
while(temp!=NULL)
{
count++;
temp=temp->next;
}
if(count<pos)
{
printf("enter correct positin\n");
}
else if(*head==NULL)
{
ptr=*head=*tail;
}
else if(pos==count)

{
ptr->next=*tail;
ptr->prev=(*tail)->prev;
(*tail)->prev->next=ptr;
(*tail)->prev=ptr;
}
else
{
temp=*head;
while(pos>1)
{
temp=temp->next;
pos--;
}
ptr->next=temp;

ptr->prev=temp->prev;
temp->prev->next=ptr;
temp->prev=ptr;
}
}
void delete_from_beg(node **head,node **tail)
{

if(*head==NULL)
{
printf("no element to delete....\n");
}
if((*head)->next==NULL)
{
*head=NULL;
*tail=NULL;
}
if((*head)!=NULL)
{
node *ptr;
ptr=(node *)malloc(sizeof(node));
ptr=*head;
*head=(*head)->next;
(*head)->prev=NULL;
free(ptr);
}
}
void delete_from_end(node **head,node **tail)
{
node *temp;
temp=*head;
if((*head)==NULL)
{
printf("no element to delete.....\n");
}
if((*head)->next==NULL)
{
  *head=NULL;
  *tail=NULL;
}
else
{
temp=*tail;
*tail=(*tail)->prev;
(*tail)->prev->next=*tail;
(*tail)->next=NULL;

free(temp);
}
}