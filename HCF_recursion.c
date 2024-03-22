//C Program to find HCF or GCD of two numbers
#include<stdio.h>
int hcf(int m,int n){
    if(n==0)
        return m;
    return hcf(n,m%n);
}
void main(){
    int m,n,res;
    printf("Enter the values of m and n\n");
    printf("m = ");
    scanf("%d",&m);
    printf("n = ");
    scanf("%d",&n);
    res=hcf(m,n);
    printf("HCF(m,n) = %d\n",res);
}
