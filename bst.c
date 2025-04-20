#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};

struct node*create(){
    int x;
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value or -1 for newnode:\n");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    printf("Enter value of left child of %d\n",x);
   newnode->left=create();
    printf("Enter value of right child of %d\n",x);
    newnode->right=create();
return newnode;
}
void preorder(struct node *root)
{
if(root==0)
{
return;
}
else{
   printf("%d\t",root->data);
   preorder(root->left);
   preorder(root->right);}
}
void inorder(struct node *root)
{if(root==0)
{
return;
}
    
else{
inorder(root->left);
printf("%d\t",root->data);
inorder(root->right);}
}
void postorder(struct node *root)
{
if(root==0)
{
return;
}
else{
postorder(root->left);
postorder(root->right);
printf("%d\t",root->data);}
}
struct node*root=0;
int main()
{
    int choice;
do{ printf("\n1.create Bst\n2.inorder\n3.preorder\n4.postorder\n5.Exit\nEnter your choice:=\n");
    scanf("%d",&choice);

   switch (choice)
   {
case 1:

        root=create();
        break;
    
    case 2:
        /* code */
        printf("INORDER TREE:\n");
        inorder(root);
        break;
    
   
    case 3:
        /* code */
        printf("PREORDER TREE:\n");
        preorder(root);
        break;
    
    case 4:
        /* code */
        printf("POSTORDER TREE:\n");
        postorder(root);
        break;
    
    default:
    printf("Invalid choice\n");
        break;
    }

}while (choice!=0);


}