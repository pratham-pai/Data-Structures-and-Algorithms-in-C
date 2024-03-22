//Program 1
#include<stdio.h>
//#include<conio.h>
int n,a[10];
void read()
{
    int i;
    printf("Enter the %d elements: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void print()
{
    int i;
    printf("The elements of the array are: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void insert(int ele, int pos)
{
    int i;
    for(i=n-1;i>=pos-1;i--)
        a[i+1]=a[i];
    a[pos-1]=ele;
    n++;
}
int delete(int pos)
{
    int i,ele;
    ele=a[pos-1];
    for(i=pos-1;i<n;i++)
        a[i]=a[i+1];
    n--;
    return ele;
}
int main()
{
    int ch,ele,pos;
    while(1)
    {
        printf("1.Read\t2.Print\t3.Insert\t4.Delete\t5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of elements: ");
                    scanf("%d",&n);
                    read();
                    break;
            case 2: print();
                    break;
            case 3: printf("Enter the element to be inserted: ");
                    scanf("%d",&ele);
                    printf("Enter position of the element to insert: ");
                    scanf("%d",&pos);
                    insert(ele,pos);
                    break;
            case 4: printf("Enter position of the element to be deleted: ");
                    scanf("%d",&pos);
                    ele=delete(pos);
                    printf("The deleted element is: %d\n",ele);
                    break;
            //case 5: exit(0);
        }
    }
}
