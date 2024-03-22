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
void insertion_sort()
{
    for(int i=0;i<n;i++)
    {
        int temp=a[i];
        int j=i;
        while(j>0 && temp<a[j-1])
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
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
    insertion_sort();
    output();
}
