//C program to find first n Fibonacci numbers
#include<stdio.h>
int fibo(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fibo(n-1)+fibo(n-2);
}
void main(){
    int n,f;
    printf("Enter n\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        f=fibo(i);
        printf("%d\t",f);
    }
}
