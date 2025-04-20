#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *newnode,*temp,*top=0;
int push (int x)
{ struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
int pop()
{
if(top==0){
printf("underflow:\n");
}
else{
    top=top->next;
}
}
int peek()
{
    printf("THE %d is element at top of stack \n",top->data);
}
void display()
{ temp=top;  
 while(temp!=0){  
 printf("%d\n ",temp->data);
 temp=temp->next;}
    
}
int main()
{ while(1){
    int choice;
    int x;
    printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.Exit\nEnter your choice:\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case /* constant-expression */1:
        /* PUSH KA CODE  */  
        printf("ENTER NUMBER TO BE PUSHED\n");  
       scanf("%d",&x);
       push(x);
        break;
    
    case /* constant-expression */2:
        /*  pop ka code */
        pop();
        break;
    
    case /* constant-expression */3:
        /*  display ka code */
        peek();
        break;
    case /* constant-expression */4:
        /*  display ka code */
        display();
        break;
    
    case /* constant-expression */5:
        /*  exit case code */
        exit(0);
        break;
    
    default:
    printf("Invalid choice\n");
        break;
    } 
    }
}




