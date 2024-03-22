#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL;
struct node* create_node()
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    return temp;
}
void insertq()//insert_end of linked list
{
    struct node *temp1=head, *temp;
    temp=create_node();
    if(head==NULL)
    {
        head=temp;
        return;
    }
    while(temp1->link!=NULL)
        temp1=temp1->link;
    temp1->link=temp;
}
void deleteq()//delete_front of linked list
{
    if(head==NULL)
    {
        printf("Cannot delete, linked list is already empty\n");
        return;
    }
    struct node *temp=head;
    printf("Data of deleted node = %d\n",temp->data);//or head->data
    head=head->link;//or head=temp->link;
    free(temp);
}

void displayq()
{
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    struct node *temp1=head;
    while(temp1!=NULL)
    {
        printf("%d\t",temp1->data);
        temp1=temp1->link;
    }
    printf("\n");
}

void main()
{
    int ch,n;
    printf("Queue by Linked list:\n");
    while(1)
    {
        printf("Enter the choice\n");
        printf("1)Insert-q  2)Delete-q  3)Display-q  4)Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insertq();
                    break;
            case 2: deleteq();
                    break;
            case 3: displayq();
                    break;
            case 4: exit(0);
           default: printf("Wrong choice, try again\n");
        }
    }
}
