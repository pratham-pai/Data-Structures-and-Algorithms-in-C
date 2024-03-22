#include<stdio.h>
#include<math.h>
#define N 10
int a[N],key,n,j,l,r;
void data()
{
    int i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to search: ");
    scanf("%d",&key);
}
void jump_search()
{
    int i;
    for(i=0;i<n;i+=j)
        if(a[i]>key)
        {
            r=i;
            l=i-j;
            return;
        }
}
void linear_search()
{
    int i;
    for(i=l;i<r;i++)
        if(a[i]==key)
        {
            printf("Element found at location %d",i+1);
            return;
        }
    printf("Element not found");
}
void main()
{
    data();
    j=sqrt(n);
    jump_search();
    linear_search();
}
