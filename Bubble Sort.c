#include<stdio.h>
#define N 10
int a[N],n;
void input()
{
    int i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void bubble_sort()
{
    int temp;
    for(int k=0;k<n-1;k++)
        for(int i=0;i<n-k-1;i++)
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
}
void output()
{
    int i;
    printf("The sorted elements are:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void main()
{
    input();
    bubble_sort();
    output();

}
