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
void push_st()//insert_front of linked list
{
    struct node *temp;
    temp=create_node();
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->link=head;
    head=temp;
}
void pop_st()//delete_front of linked list
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Cannot delete, linked list is already empty\n");
        return;
    }
    temp=head;
    head=head->link;
    printf("Data of deleted node is = %d\n",temp->data);
    free(temp);
}

void display_st()
{
    struct node *temp1=head;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    while(temp1!=NULL)
    {
        printf("%d\t",temp1->data);
        temp1=temp1->link;
    }
    printf("\n");
}

void main()
{
    int ch;
    while(1)
    {
        printf("Enter the choice:\n1)Push  2)Pop  3)Display  4)Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push_st();
                    break;
            case 2: pop_st();
                    break;
            case 3: display_st();
                    break;
            case 4: exit(0);
           default: printf("Wrong choice entered, try again\n");
        }
    }
}
