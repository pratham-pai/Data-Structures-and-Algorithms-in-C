//Program 6
#include<stdio.h>
#define MAX 5
char CQ[MAX];
int f=-1,r=-1;
void CQinsert(char elem)
{
    if(CQfull())
        printf("\nOverflow\n");
    else
    {
        if(f==-1)
            f=0;
        r=(r+1)%MAX;
        CQ[r]=elem;
    }
}
char CQdelete()
{
    char elem;
    if(CQempty())
    {
        printf("\nUnderflow\n");
        return('0');
    }
    else
    {
        elem=CQ[f];
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else
            f=(f+1)%MAX;
        return(elem);
    }
}
int CQfull()
{
    if((f==r+1)||(f==0&&r==MAX-1))
        return 1;
    return 0;
}
int CQempty()
{
    if(f==-1)
        return 1;
    return 0;
}
void display()
{
    int i;
    if(CQempty())
        printf("\n Empty Queue\n");
    else
    {
        printf("Front[%d]->",f);
        for(i=f;i!=r;i=(i+1)%MAX)
            printf("%c ",CQ[i]);
        printf("%c ",CQ[i]);
        printf("<-[%d]Rear",r);
    }
}
int main()
{
    int opn;
    char elem,ch;
    while(1)
    {
        printf("Enter your choice :\n 1:Insert\n2:Delete\n3:Display\n4:Exit\nChoose an option ");
        scanf("%d",&opn);
        ch=getchar();
        switch(opn)
        {
            case 1: printf("\nEnter the element to be Inserted:");
                    scanf("%c",&elem);
                    ch=getchar();
                    CQinsert(elem);
                    break;
            case 2: elem=CQdelete();
                    if(elem!='0')
                        printf("\n\nDeleted Element is %c \n",elem);
                    break;
            case 3: printf("\n\nThe Circular Queue is\n");
                    display();
                    break;
            case 4: exit(0);
        }
    }
    return 0;
}
