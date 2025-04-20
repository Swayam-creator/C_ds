#include<stdio.h>

#include<stdlib.h>
#include<string.h>
char min[10],max[10];
struct node
{
char name[100];
int salary;
struct node *left,*right;
};
struct node *create()
{
char x[100];
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter name or (1 for newnode)=");
scanf("%s",x);
if(x[0]=='1')
{
return 0;
}
else
{
printf("Enter salary=");
scanf("%d",&newnode->salary);
strcpy(newnode->name,x);
printf("Enter left child of ");
puts(x);
newnode->left=create();
printf("Enter right child of ");
puts(x);
newnode->right=create();
return newnode;
}
}
void inorder(struct node *root)
{
if(root==0)
{
return;
}
else
{
inorder(root->left);
printf("%s\t%d\n",root->name,root->salary);
inorder(root->right);
}
}
void minimum(struct node *root)
{
while(root->left!=0)
root=root->left;
printf("%s\t%d\n",root->name,root->salary);
}
void maximum(struct node *root)
{
while(root->right!=0)
root=root->right;
printf("%s\t%d\n",root->name,root->salary);
}
struct node *root=0;
void main()
{

//struct node *root=0;
int ch;
do
{
printf("\n1 to create BST\n2 for inorder\n3 for MINIMUM\n4 for MAXIMUM\n0 for exit=");
scanf("%d",&ch);
switch(ch)
{
case 1:
root=create();
break;
case 3:
printf("MINIMUM IS=\n");
minimum(root);
break;
case 2:
printf("INORDER IS=\n");
inorder(root);
printf("\n");
break;
case 4:
printf("MAXIMUM IS=\n");
maximum(root);
break;
case 0:
exit(0);
default:
printf("INVALID CHOICE");
}
}while(ch!=0);
}