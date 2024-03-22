//C program for Singly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL;
int num=0;//number of nodes at any time

struct node* create_node()
{
    struct node *temp;
    num++;
    temp=malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    return temp;
}

void insert_front()
{
    struct node *temp;
    temp=create_node();
    if(head==NULL)
        head=temp;
    else
        temp->link=head;
        head=temp;
}

void insert_end()
{
    struct node *temp1=head, *temp;
    temp=create_node();
    if(head==NULL)
        head=temp;
    else
    {
        while(temp1->link!=NULL)
            temp1=temp1->link;
        temp1->link=temp;
    }
}

//insert after nth node
void insert_after(int n)
{
    if(n>num)
    {
        printf("Cannot insert, there are only %d nodes\n",num);
        return;
    }
    struct node *temp,*temp1=head;
    int i;
    temp=create_node();
    for(i=1;i<n;i++)
        temp1=temp1->link;
    temp->link=temp1->link;
    temp1->link=temp;
}

void delete_front()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Cannot delete, linked list is already empty\n");
        return;
    }
    printf("Data of deleted node = %d\n",temp->data);//or head->data
    head=head->link;//or head=temp->link;
    free(temp);
    num--;
}

void delete_end()
{
    struct node *temp1=head, *temp;
    if(head==NULL)
    {
        printf("Cannot delete, linked list is already empty\n");
        return;
    }
    while(temp1->link->link!=NULL)
        temp1=temp1->link;
    temp=temp1->link;
    temp1->link=NULL;
    printf("Data of deleted node = %d\n",temp->data);
    free(temp);
    num--;
}

void delete_after(int n)
{
    if(head==NULL)
    {
        printf("Cannot delete, linked list is already empty\n");
        return;
    }
    if(n>=num)
    {
        printf("Cannot delete, there are only %d nodes\n",num);
        return;
    }
    struct node *temp1=head,*temp;
    int i;
    for(i=1;i<n;i++)
        temp1=temp1->link;
    temp=temp1->link;
    temp1->link=temp->link;
    //or temp1=temp1->link->link;
    printf("Data of deleted node = %d\n",temp->data);
    free(temp);
    num--;
}

void display()
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

void search()
{
    struct node *temp=head;
    int key,count=0;
    printf("Enter the element to be searched\n");//element or key both are same
    scanf("%d",&key);
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("The element is found at position %d\n",count);
            return;
        }
        temp=temp->link;
        count++;
    }
    printf("The element is not found\n");
}

int main()
{
    int ch,n;
    printf("Singly Linked List:\n");
    while(1)
    {
        printf("Enter the choice\n");
        printf("1:Insert-front   \t4:Delete-front   \t7:Display list    \t10:Exit\n");
        printf("2:Insert-end     \t5:Delete-end     \t8:Number of nodes \n");
        printf("3:Insert-after   \t6:Delete-after   \t9:Search          \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert_front();
                    break;
            case 2: insert_end();
                    break;
            case 3: printf("Insert after which node:\n");
                    scanf("%d",&n);
                    insert_after(n);
                    break;
            case 4: delete_front();
                    break;
            case 5: delete_end();
                    break;
            case 6: printf("Delete after which node:\n");
                    scanf("%d",&n);
                    delete_after(n);
                    break;
            case 7: display();
                    break;
            case 8: printf("Number of nodes are = %d\n",num);
                    break;
            case 9: search();
                    break;
           case 10: exit(0);
          default: printf("Wrong choice, try again\n");
        }
    }
}
