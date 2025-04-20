#include"file1.c"
#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter any two numbers :\n");
    scanf("%d%d",&a,&b);
    int ans=addition(a,b);
    printf("****addition:%d\n****",ans);
    ans=subtraction(a,b);
    printf("****subtraction:%d\n****",ans);
    
    ans=division(a,b);
    printf("****division:%d\n****",ans);
    ans=multiplication(a,b);
    printf("*****multiplication:%d\n****",ans);

}