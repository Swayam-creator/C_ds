#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *temp;*top=0;
void push(int x)
{
struct node *newnode,*top=0;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=x;
newnode->next=top;
top=newnode;
}
void pop()
{
if(top==0)
printf("Underflow\n");
else
{
top=top->next;
}
}
void peek()
{
printf("Peek value if %d",top->data);
}
void display()
{
temp=top;
if(top==0)
printf("Underflow\n");
else
{
while(temp!=0)
{
printf("%d\n",&temp->data);
temp=temp->next;
}
}
}
void main()
{
int ch;
int x;
do
{
printf("Enter choice\n1 for push()\n2 for pop()\n3 for peek()\n4 for display\n)for exit\n=");
scanf("%d",&ch);
switch(ch)
{
case 1:

printf("Enter data=");
scanf("%d",&x);
push(x);
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 0:
exit(0);
default:
printf("invalid choice");
}
}while(ch!=0);

}

