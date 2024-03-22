#include<stdio.h>
int m=0;
void tower(int n,char a,char c,char b)
{
    if(n>=1)
    {
        tower(n-1,a,b,c);
        printf("Move disc %d from %c to %c\n",n,a,c);
        m++;
        tower(n-1,b,c,a);
    }
}
void main()
{
    int n;
    printf("Enter number of disks\n");
    scanf("%d",&n);
    tower(n,'A','C','B');
    printf("\nTotal number of steps = %d\n",m);
}
