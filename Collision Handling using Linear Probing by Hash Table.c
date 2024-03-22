//Program 12
#include<stdio.h>
#define max 100
int hash_func(int num)
{
    return num%100;
}
void linear_prob(int a[max],int key,int num)
{
    int i;
    if(a[key]==-1)
    {
        a[key]=num;
        return;
    }
    for(i=key+1; i<max; i++)
        if(a[i]==-1)
        {
            a[i]=num;
            return;
        }
    for(i=0; i<key; i++)
        if(a[i]==-1)
        {
            a[i]=num;
            return;
        }
    printf("\n hash table is full\n");
}
void display(int a[max])
{
    int i;
    printf("\n the hash table is…\n");
    printf("key/index\t employee id\n");
    printf("………………………………………\n");
    for(i=0; i<max; i++)
        printf("\n %d  %d\n", i, a[i]);
}
int main()
{
    int a[max]={-1},num,key,i,ans=0;
    printf("collision handling by linear probing\n");
    do
    {
        printf("\n enter the four digit number:");
        scanf("%d",&num);
        key=hash_func(num);//or key=num%100;
        linear_prob(a,key,num);
        printf("do you want to continue? 1-yes/0-no\n");
        scanf("%d",&ans);
    }while(ans==1);
    display(a);
    return 0;
}
