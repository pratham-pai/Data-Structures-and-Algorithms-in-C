#include<stdio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void insertq(int ele)
{
    if(rear==MAX-1)
        queueFull();
    queue[++rear]=ele;
}
int deleteq()
{
    if(front==rear)
        queueEmpty();
    return queue[++front];
}
void queueFull()
{
    fprintf(stderr,"Queue is full");
    exit(1);
}
void queueEmpty()
{
    fprintf(stderr,"Queue is empty");
    exit(1);
}
void display()
{
    int i=front+1;
    printf("\nElements are:\n");
    while(i<=rear)
        printf("%d\t",queue[i++]);
    printf("\n");
}
int main()
{
    int ch,key,k;
    printf("Implementation of Double Queue\n");
    while(1)
    {
        printf("\n1Insertq\t2.Deleteq\t3.Display\t4.Exit\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter value to be inserted\n");
                    scanf("%d",&key);
                    insertq(key);
                    break;
            case 2: k=deleteq();
                    printf("%d deleted\n",k);
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Wrong selection,try again\n");
        }
    }
}
