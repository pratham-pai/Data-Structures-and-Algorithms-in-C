//C program to find nth Fibonacci number
#include<stdio.h>
int fibo(int n){
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fibo(n-1)+fibo(n-2);
}
void main(){
    int n,f;
    printf("Enter n\n");
    scanf("%d",&n);
    f=fibo(n);
    printf("%d",f);
}
