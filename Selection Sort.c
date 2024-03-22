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
void selection_sort()
{
    int minimum,temp;
    for(int i=0;i<n-1;i++)
    {
        minimum=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minimum])
            {
                minimum=j ;
            }
        }
        temp=a[minimum];
        a[minimum]=a[i];
        a[i]=temp;
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
    selection_sort();
    output();
}
