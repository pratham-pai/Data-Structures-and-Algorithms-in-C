#include<stdio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void insert_rear(int ele)
{
    if(rear==MAX-1)
        queueFull();
    queue[++rear]=ele;
}
int delete_front()
{
    if(front==rear)
        queueEmpty();
    return queue[++front];
}
void insert_front(int ele)
{
    if(front==0 || (front==-1 && rear!=-1))
        queueFull();
    else if(front==rear)
        rear=front=MAX-1;
    queue[front--]=ele;
}
int delete_rear()
{
    if(front==rear)
        queueEmpty();
    return queue[rear--];
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
        printf("\n1.Insert_front\t2.Delete_front\t3.Insert_rear\t4.Delete_rear\t5.Display\t6.Exit\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter value to be inserted\n");
                    scanf("%d",&key);
                    insert_front(key);
                    break;
            case 2: k=delete_front();
                    printf("%d deleted\n",k);
                    break;
            case 3: printf("Enter value to be inserted\n");
                    scanf("%d",&key);
                    insert_rear(key);
                    break;
            case 4: k=delete_rear();
                    printf("%d deleted\n",k);
                    break;
            case 5: display();
                    break;
            case 6: exit(0);
            default: printf("Wrong selection,try again\n");
        }
    }
}
