#include<stdio.h>
#include<stdlib.h>
#define N 5
int s1[N],s2[N];
int top1=-1,top2=-1;
int count=0;
void enqueue(int x)
{
    push1(x);
    count++;
}
void push1(int x)
{
    if(top1=N-1)
    {
        printf("overflow\n");
    }
    else{
        top1++;
        s1[top1]=x;
    }
}
void dequeue()
{
    int i,a,b;
    if((top1=-1) && (top2=-1))
    {
        printf("Underflow\n");
    }
    else{
        for (i = 0; i < count; i++)
        {
            /* code */
            push2(pop1());
        }
        b=pop2();
        count--;
        for (i = 0; i < count; i++)
        {
            push1(pop2());
        }
    }
}
int pop1()
{
    return s1[top1--];
}
int pop2()
{
    return s2[top2--];
}
void push2(int x)
{
    if(top2==N-1)
    {
        printf("Overflow\n");
    }
    else{
        top2++;
        s2[top2]=x;
    }
}

void display()
{
    int i;
    for (i = 0; i < top1; i++)
    {
        /* code */
         printf("%d\t",s1[i]);
    } 
}
void main()
{
    int exp,n;

    printf("\n1.Enqueue\n2.Dequeue\n3.for display\n::");
    scanf("%d",&exp);
    switch (exp)
    {
    case /* constant-expression */1:
        /* code */
        printf("Enter num=\n");
        scanf("%d",&n);
        enqueue(n);
        break;

        case 2:
        dequeue();
         break;
        case 3:
        display();
         break;
        case 4:
        exit(0);
         break;
    default:
    printf("Invalid choice\n");
        break;
    }


}