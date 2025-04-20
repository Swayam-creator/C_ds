#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct node{
        int amt,id;
        struct node*next;
    };
    struct node*newnode,*temp,*head;
    head=0;
    int choice,rate,num,n;
    printf("Enter rate of coffee:\n");
    scanf("%d",&rate);
    do{
    printf("\n1.Place order\n2.View Bill\n3.Maximum Bill\n4.Minimum\n5.Exit\nEnter your choice:-\t");
    scanf("%d",&choice);
    switch (choice)
    {
    case /* constant-expression */1:
     newnode=(struct node*)malloc(sizeof(struct node));
     printf("ENTER YOUR ID :\n");
     scanf("%d",&newnode->id);
     printf("Enter the number of coffees:\n");
     scanf("%d",&num);
     newnode->amt=(num*rate);
     newnode->next=0;
     if(head==0)
     {
        head=temp=newnode;
     }  
     else{
        temp->next=newnode;
        temp=newnode;
     }       
        break;
    case 2:
       temp=head;
       while(temp!=0)
       {
        printf("%d-->%d\n",temp->id,temp->amt);
        temp=temp->next;
       } 
       break;
    case 3:
    temp=head;
    int max,id1;
    max=temp->amt;
    id1=temp->id;
    while(temp!=0)
    {
        if(temp->amt>max)
        {
           max=temp->amt;
           id1=temp->id;
        }
        temp=temp->next;   
    }
    printf("Maximum Bill:id-->amt\n");
    printf("%d-->%d\n",id1,max);
     break;
    case 4:
   temp=head;
   int min,id2;
   min=temp->amt;
   id2=temp->id;
   while(temp!=0)
   {
    if(temp->amt<min)
    {
        min=temp->amt;
        id2=temp->id;
    }
    temp=temp->next;
   }
   printf("Minimum Bill:\tId-->amt\n");
   printf("%d-->%d\n",id2,min);
 break;
 case 5:
 exit(0);
 break;
   default:
   printf("Invalid choice!!!");
        break;
    }
}while(n!=0);
free(temp);
return 0;
}
