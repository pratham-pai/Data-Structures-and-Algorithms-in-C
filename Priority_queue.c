#include<stdio.h>
#define SIZE 10
int rear=-1,front=-1,queue[SIZE];
int ch,i,j,item,choice;
void insert()
{
    int ele;
    printf("Enter the element\n");
    scanf("%d",&item);
    if(front==-1)
        front++;
    j=rear;
    while(j>=0 && item<queue[j])
    {
        queue[j+1]=queue[j];
        j--;
    }
    queue[j+1]=item;
    rear++;
}
int Q_full()
{
    if(rear==SIZE-1)
        return 1;
    else
        return 0;
}
void delet()
{
    printf("The item deleted is %d",queue[front]);
    front++;
}
int Q_Empty()
{
    if((front==-1) || (front>rear))
        return 1;
    else
        return 0;
}
void display()
{
    printf("Elements of priority queue:\n");
    for(i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
}
int main()
{
    printf("1.Insert\t2.Delete\t3.Display\t4.Exit");
    while(1)
    {
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(Q_full())
                        printf("Priority Queue is Full\n");
                    else
                        insert();
                    break;
            case 2: if(Q_Empty())
                        printf("Priority queue is empty\n");
                    else
                        delet();
                    break;
            case 3: if(Q_Empty())
                        printf("Priority Queue is Empty\n");
                    else
                        display();
                    break;
            case 4: exit(0);
        }
    }
}
