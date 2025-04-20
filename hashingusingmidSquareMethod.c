#include<stdio.h>
#include<stdlib.h>
int   hash;
int hash1;
int key;
int hash_mid_square(int key){
    int square=key*key;
    int mid;

    if(key<10){ mid=square;}
    else if (key<100){ mid=(square%100)/10;}
    else{ mid=(square%10000)/100;}
    hash=mid;
    int i=0;
    while(mid>=10)
    {
        hash=hash*10+(mid%10);
        mid/=10;
    }
    return hash;

}
int hash_mod_method(int key,int hashtablesize){
    hash1=(key)%(hashtablesize);
    return hash1;

}

int main()
{int choice;
   
    printf("1.Division method\n2.Mid-Square Method\n3.Exit\nEnter your choice\n*********\n");
    scanf("%d",&choice);
   
      switch (choice)
{
case 1:
    /* mod code in main */
    printf("Enter value of key:\n");
    scanf("%d",&key);
    printf("Enter hash table size:\n");
    int hashtablesize;
    scanf("%d",&hashtablesize);
    hash1=hash_mod_method( key,hashtablesize);
    printf("%d is indexed at %d\n",key ,hash1);
   
    break;
    
case 2:
    /* mid square code */
   printf("\nEnter value of key:\n");
    scanf("%d",&key);
    hash=hash_mid_square( key);
    printf("%d is indexed at %d\n",key ,hash);

    break;


default:
printf("exiting...\n");
    break;
}
    
    
}