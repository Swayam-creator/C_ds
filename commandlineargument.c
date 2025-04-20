#include<stdio.h>
int main(int argc,char*argv[])
{ int n,a,b,i=1;
 a=0;
 b=1;
 n=atoi(argv[1]);
 
 printf("The fibbonacci series is :\n\t ");
 for(i=0; i<n; i++){
printf("%d\t",a);
int c=(a+b);
 a=b;
 b=c;

 }
   
        }
        
    
    
