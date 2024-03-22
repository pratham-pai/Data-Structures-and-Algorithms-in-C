//C program to solve ackermann function
#include<stdio.h>
int ack(int m,int n){
    if(m==0)
        return n+1;
    if(n==0)
        return ack(m-1,1);
    return ack(m-1,ack(m,n-1));
}
void main(){
    int m,n;
    long double ans;
    printf("Enter values of m and n\n");
    scanf("%d%d",&m,&n);
    int x=m,y=n;
    ans=ack(m,n);
    printf("ackermann function M(%d,%d) = %ld",x,y,ans);
}
