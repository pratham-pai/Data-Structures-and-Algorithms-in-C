#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;
NODE *head=NULL;
NODE* create_node()
{
    NODE *temp;
    temp=malloc(sizeof(NODE*));
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    //temp->link=NULL; no need here
    return temp;
}
void C_insert_front()
{
    NODE *temp1=head, *temp;
    temp=create_node();
    if(head==NULL)
    {
        head=temp;
        temp->link=temp;
        return;
    }
    while(temp1->link!=head)
        temp1=temp1->link;
    temp->link=head;
    head=temp;
    temp1->link=head;
}
void C_insert_end()
{
    NODE *temp1=head, *temp;
    temp=create_node();
    if(head==NULL)
    {
        head=temp;
        temp->link=temp;
        return;
    }
    while(temp1->link!=head)
        temp1=temp1->link;
    temp1->link=temp;
    temp->link=head;
}
void C_delete_front()
{
    NODE *temp=head, *temp1=head;
    if(head==NULL)
    {
        printf("Circular linked list is already empty\n");
        return;
    }
    if(head==head->link)
    {
        printf("Data of deleted node is = %d\n",head->data);
        head=NULL;
        return;
    }
    while(temp1->link!=head)
        temp1=temp1->link;
    head=head->link;
    temp1->link=head;
    printf("Data of deleted node = %d\n",temp->data);
    free(temp);
}
void C_delete_end()
{
    NODE *temp, *temp1=head;
    if(head==NULL)
    {
        printf("Circular linked list is already empty\n");
        return;
    }
    if(head==head->link)
    {
        printf("Data of deleted node is = %d\n",head->data);
        head=NULL;
        return;
    }
    while(temp1->link->link!=head)
        temp1=temp1->link;
    temp=temp1->link;
    temp1->link=head;
    printf("Data of deleted node = %d\n",temp->data);
    free(temp);
}
void C_display()
{
    NODE *temp=head;
    if(head==NULL)
    {
        printf("Circular linked list is empty\n");
        return;
    }
    if(head==head->link)
    {
        printf("%d\n",head->data);
        return;
    }
    while(temp->link!=head)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("%d\n",temp->data);
}
int main()
{
    int ch;
    while(1)
    {
        printf("Enter the choice\n");
        printf("1)Insert-front 3)Delete-front 5)Display-list\n");
        printf("2)Insert-end   4)Delete-end   6)Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: C_insert_front();
                    break;
            case 2: C_insert_end();
                    break;
            case 3: C_delete_front();
                    break;
            case 4: C_delete_end();
                    break;
            case 5: C_display();
                    break;
            case 6: exit(0);
           default: printf("Wrong choice, try again\n");
        }
    }
}
