//C program to solve tower of hanoi
#include<stdio.h>
int m=0;
void tower(int n,char s,char t,char d){
    if(n==0)
        return;
    tower(n-1,s,d,t);
    printf("Move disc %d from %c to %c\n",n,s,d);
    m++;
    tower(n-1,t,s,d);
}
void main(){
    int n;
    printf("Enter number of disks\n");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("\nTotal number of steps = %d\n",m);
}
