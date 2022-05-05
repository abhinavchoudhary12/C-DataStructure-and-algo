#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NILL -1
#define MAX 5
typedef struct stack{
int tos;
int a[MAX];
}S;
void main()
{
int data,n,a;
S s;
clrscr();
int is_empty(S);
int is_full(S);
void push(S *,int);
void pop(S *);
s.tos=NILL;
while(1)
{
printf("\n1. stack is full\n");
printf("2. stack is empty\n");
printf("3. push in stack\n");
printf("4. pop from satck\n");
printf("5. exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
a=is_full(s);
if(a==1)
{
printf("stack is full\n");
}
else
{
 printf("stack is not full\n");
}
break;
case 2:
a=is_empty(s);
if(a==1)
{
printf("stack is empty\n");
}
else
{
 printf("stack is not empty\n");
}
break;
case 3:
a=is_full(s);
if(a==1)
{
printf("stack is full\n");
}
else
{
printf("enter the data\n");
scanf("%d",&data);
push(&s,data);
}
break;
case 4:
a=is_empty(s);
if(a==1)
{
printf("stack is empty\n");
}
else
{
 pop(&s);
}
break;
case 5:
exit(1);
}

}
getch();
}
int is_full(S s)
{
if(s.tos==MAX-1)
{
return 1;
}
else
{
return 0;
}
}
int is_empty(S s)
{
if(s.tos==0)
{
return 1;
}
else
{
return 0;
}
}
void push(S *s,int data)
{
 if(s->tos==NILL)
 {
 s->tos=0;
 }

s->a[s->tos]=data;
printf("entered data is %d",s->a[s->tos]);
s->tos++;

}
void pop(S *s)
{
s->tos--;
printf("poped element is %d",s->a[s->tos]);
}