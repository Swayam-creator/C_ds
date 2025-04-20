#include<stdio.h>
#include<stdlib.h>
struct node
{
    /* data */
    int data;
    struct node*next;
};
struct node*head=0,*temp,*newnode;

int count=0;

void create()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter number :\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
    {
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    count++;
}

void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
   
    }
}



 void insertionat_beg()
 {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter number :\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
 }
 void insertionat_end()
 {
    struct node*prevnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter number :\n");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    temp=newnode;
 }
 void pos()
 { int i=0;
 
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter number :\n");
    scanf("%d",&newnode->data);
    printf("Enter any position:\n");
    int pos;
    scanf("%d",&pos);
    if(pos>count)
{
    printf("invalid position");
}    
else{
    temp=head;
    while(i<pos-1)
    {
  temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
 }
void main()
{
    int choice;
 while(1)
 {
   printf("\nEnter your choice\n1.create\n2.display\n3.at start\n4.at end\n5.at pos\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
    create();

    break;
    case 2:
    display();

    break;
    case 3:
    insertionat_beg();
    break;
    case 4:
    insertionat_end();
    break;
    case 5:
    pos();
    break;

  
    default:
    printf("Invalid position");
    break;
   }
 
}

}

 