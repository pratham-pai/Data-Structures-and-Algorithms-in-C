//Program 7 FINAL
#include<stdio.h>
#include<stdlib.h>
struct node
{
    char usn[4];
    char name[10];
    char sem[2];
    char branch[5];
    char phone[11];
    struct node *link;
};
struct node *head=NULL;
struct node * createnode()
{
    struct node *temp=NULL;
    temp=malloc(sizeof(struct node));
    printf("\nEnter the usn(last three num):");
    fflush(stdin);
    gets(temp->usn);
    printf("\nEnter the name:");
    gets(temp->name);
    printf("\nEnter the sem:");
    gets(temp->sem);
    printf("\nEnter the branch:");
    gets(temp->branch);
    printf("\nEnter the phone num:");
    gets(temp->phone);
    temp->link=NULL;
    return temp;
}
void insertFront()
{
    struct node *SLL=NULL;
    SLL=createnode();
    if(head!=NULL)
        SLL->link=head;
    head=SLL;
}
void deleteFront()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("The deleted node is:\n");
    printf("Usn=%s\nName=%s\nSem=%s",temp->usn,temp->name,temp->sem);
    printf("\nBranch=%s\nPhone=%s\n",temp->branch,temp->phone);
    head=temp->link;//or head=head->link;
    free(temp);
}
void insertEnd()
{
    struct node *SLL=NULL,*temp=head;
    SLL=createnode();
    if(head==NULL)
    {
        head=SLL;
        return;
    }
    while(temp->link!=NULL)
        temp=temp->link;
    temp->link=SLL;
}
void deleteEnd()
{
    struct node *temp=head,*t;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    while(temp->link!=NULL)
    {
        t=temp;
        temp=temp->link;
    }
    printf("The deleted node is:\n");
    printf("Usn=%s\nName=%s\nSem=%s",temp->usn,temp->name,temp->sem);
    printf("\nBranch=%s\nPhone=%s\n",temp->branch,temp->phone);
    t->link=NULL;
    free(temp);
}
void create()
{
    int i,n;
    printf("Enter the number of students:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        insertFront();
}
void display()
{
    struct node *temp=head;
    int c=0;
    printf("\nThe contents are:\n");
    printf("Usn\tName\tSem\tBranch\tPhone\n");
    while(temp!=NULL)
    {
        printf("%s \t%s \t%s",temp->usn,temp->name,temp->sem);
        printf(" \t%s \t%s \n",temp->branch,temp->phone);
        temp=temp->link;
        c++;
    }
    printf("\nThe number of nodes are %d\n\n",c);
}
int main()
{
    int ch1,ch2,ch3;
    while(1)
    {
        printf("1:Create\n2:Display and count\n");
        printf("3:Insert and delete from front\n4:Insert and delete from end\n");
        printf("5:Exit\nEnter the choice:");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: printf("Operations from Front:\n1:Insert\t2:Delete\nEnter the choice:");
                    scanf("%d",&ch2);
                    ch2==1?insertFront():deleteFront();
                    break;
            case 4: printf("Operations from End:\n1:Insert\t2:Delete\nEnter the choice:");
                    scanf("%d",&ch3);
                    ch3==1?insertEnd():deleteEnd();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
                     break;
        }
    }
    return 0;
}
