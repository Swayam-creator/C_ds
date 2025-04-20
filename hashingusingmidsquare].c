#include<stdio.h>
#define N 100
int a[N-1];
void mid_square(int x)
{
int square,key;
square=x*x;
if(square<100)
{
key=square;
printf("%d\t%d\n",x,key);
}
else if(square<1000)
{
square=square%100;
key=square/10;
printf("%d\t%d\n",x,key);
}
else if(square<10000)
{
square=square%1000;
key=square/10;
printf("%d\t%d\n",x,key);
}
a[key]=x;
}
void main()
{
int b[10];
printf("Enter any 10 numbers=");
int i;
for(i=0;i<10;i++)
{
scanf("%d",&b[i]);
}
printf("Hash value  Index\n");
for(i=0;i<10;i++)
{
mid_square(b[i]);
}

};
