#include <stdio.h>
#define N 10
int a[N],key,n;
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
int ternary_search(int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(a[mid1] == x)
            return mid1;
        if(a[mid2] == x)
            return mid2;
        if(x<a[mid1])
            return ternary_search(l,mid1-1,x);
        else if(x>a[mid2])
            return ternary_search(mid2+1,r,x);
        else
            return ternary_search(mid1+1,mid2-1,x);
    }
    return -1;
}

int main(void)
{
	data();
	int result = ternary_search(0,n-1,key);
	(result == -1) ? printf("Element is not present in array")
				: printf("Element is present at index %d",result);
	return 0;
}
