#include<stdio.h>

#include<math.h>
int main()
{ 
    float a,b,c,x,d;
    printf("This is a quadratic equation :ax^2+bx+c\n");
    printf("Enter values of a,b,c\n");
    scanf("%f%f%f",&a,&b,&c);
    d=((b*b)-(4*a*c));
    int z=pow(d,0.5);
   int  x1=(-b+z)/(2*a);
   
   int  x2=((-b)-z)/(2*a);
   printf("%d %d are roots of equation",x1,x2);
return 0;

}