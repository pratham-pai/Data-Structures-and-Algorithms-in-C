#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *llink;
    int data;
    struct node *rlink;
};
struct node *head=NULL;
int num=0;
struct node* create()
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;
    num++;
    return temp;
}

void D_insert_front()
{
    struct node *temp;
    temp=create();
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->rlink=head;
    head->llink=temp;
    head=temp;
}

void D_insert_end()
{
    struct node *temp, *temp1=head;
    temp=create();
    if(head==NULL)
    {
        head=temp;
        return;
    }
    while(temp1->rlink!=NULL)
        temp1=temp1->rlink;
    temp1->rlink=temp;
    temp->llink=temp1;
}

void D_insert_after(int n)//for insert_spec(), just make i<n-1 in for loop,(and ofcourse change function name here and in main())
{
    struct node *temp, *temp1=head;
    int i;
    temp=create();
    for(i=1;i<n;i++)
        temp1=temp1->rlink;
    temp->rlink=temp1->rlink;
    temp->llink=temp1;
    temp1->rlink=temp;
    temp->rlink->llink=temp;
}

void D_delete_front()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Doubly linked list is already empty\n");
        return;
    }
    head=head->rlink;
    head->llink=NULL;
    num--;
    printf("Data of deleted node is = %d\n",temp->data);
    free(temp);
}

void D_delete_end()
{
    struct node *temp1=head, *temp;
    if(head==NULL)
    {
        printf("Doubly linked list is already empty\n");
        return;
    }
    while(temp1->rlink->rlink!=NULL)
        temp1=temp1->rlink;
    temp=temp1->rlink;
    temp1->rlink=NULL;
    num--;
    printf("Data of deleted node is = %d\n",temp->data);
    free(temp);
}

void D_delete_spec(int n)//for delete_after(), just make i<n in for loop,(and ofcourse change function name here and in main())
{
    struct node *temp1=head, *temp;
    int i;
    if(head==NULL)
    {
        printf("Doubly linked list is already empty\n");
        return;
    }
    for(i=1;i<n-1;i++)
        temp1=temp1->rlink;
    temp=temp1->rlink;
    temp1->rlink=temp->rlink;
    temp->rlink->llink=temp1;
    num--;
    printf("Data of deleted node is = %d\n",temp->data);
    free(temp);
}

void D_display()
{
    int c=0;//count of nodes;
    struct node *temp1=head, *temp;
    if(head==NULL)
    {
        printf("Doubly linked list is empty\n");
        return;
    }
    printf("The values are :\n");
    while(temp1!=NULL)
    {
        printf("%d\t",temp1->data);
        c++;
        temp1=temp1->rlink;
    }
    printf("\nThe number of nodes = %d\n",c);//or num
}

int main()
{
    int ch,n;
    printf("Doubly Linked list:\n");
    while(1)
    {
        printf("Enter the choice\n");
        printf("1:Insert-front   \t4:Delete-front   \t7:Display list    \n");
        printf("2:Insert-end     \t5:Delete-end     \t8:Number of nodes \n");
        printf("3:Insert-after   \t6:Delete-specf   \t9:Exit            \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: D_insert_front();
                    break;
            case 2: D_insert_end();
                    break;
            case 3: printf("Enter after which node:");
                    scanf("%d",&n);
                    D_insert_after(n);
                    break;
            case 4: D_delete_front();
                    break;
            case 5: D_delete_end();
                    break;
            case 6: printf("Delete which node:");
                    scanf("%d",&n);
                    D_delete_spec(n);
                    break;
            case 7: D_display();
                    break;
            case 8: printf("The number of nodes are = %d\n",num);
                    break;
            case 9: exit(0);
           default: printf("Wrong choice entered, try again\n");
        }
    }
    return 0;
}
