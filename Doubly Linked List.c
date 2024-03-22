//Program 8 FINAL
#include<stdio.h>
#include<stdlib.h>
struct node
{
    char ssn[10];
    char name[10];
    char branch[10];
    char des[10];
    char sal[10];
    char phone[10];
    struct node *llink;
    struct node *rlink;
};
struct node *head=NULL;
struct node * createnode()
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    printf("\nEnter the SSN: ");
    fflush(stdin);
    gets(temp->ssn);
    printf("Enter the name: ");
    gets(temp->name);
    printf("Enter the branch: ");
    gets(temp->branch);
    printf("Enter the designation: ");
    gets(temp->des);
    printf("Enter the salary: ");
    gets(temp->sal);
    printf("Enter the phone number: ");
    gets(temp->phone);
    temp->rlink=NULL;
    temp->llink=NULL;
    return temp;
}
void insertFront()
{
    struct node *DLL;
    DLL=createnode();
    if(head!=NULL)
    {
        DLL->rlink=head;
        head->llink=DLL;
    }
    head=DLL;
}
void deleteFront()
{
    struct node *DLL=head;
    if(head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    head=DLL->rlink;
    head->llink=NULL;
    printf("\nData of deleted node is:\n");
    printf("SSN = %s\n",DLL->ssn);
    printf("Name = %s\n",DLL->name);
    printf("Branch = %s\n",DLL->branch);
    printf("Designation = %s\n",DLL->des);
    printf("Salary = %s\n",DLL->sal);
    printf("Phone = %s\n\n",DLL->phone);
    free(DLL);
}
void insertEnd()
{
    struct node *SLL,*temp=head;
    SLL=createnode();
    if(head==NULL)
        head=SLL;
    else
    {
        while(temp->rlink!=NULL)
            temp=temp->rlink;
        temp->rlink=SLL;
        SLL->llink=temp;
    }
}
void deleteEnd()
{
    struct node *temp=head,*DLL;
    if(head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while(temp->rlink->rlink!=NULL)
        temp=temp->rlink;
    DLL=temp->rlink;
    temp->rlink=NULL;
    printf("\nData of deleted node is:\n");
    printf("SSN = %s\n",DLL->ssn);
    printf("Name = %s\n",DLL->name);
    printf("Branch = %s\n",DLL->branch);
    printf("Designation = %s\n",DLL->des);
    printf("Salary = %s\n",DLL->sal);
    printf("Phone = %s\n\n",DLL->phone);
    free(DLL);
}
void create()
{
    int i,n;
    printf("Enter how many members: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        insertEnd();
}
void display()
{
    struct node *temp=head;
    int c=0;
    printf("The contents are:\n");
    fflush(stdout);
    while(temp!=NULL)
    {
        printf("%s\t",temp->ssn);
        printf("%s\t",temp->name);
        printf("%s\t",temp->branch);
        printf("%s\t",temp->des);
        printf("%s\t",temp->sal);
        printf("%s\n",temp->phone);
        temp=temp->rlink;
        c++;
    }
    printf("\nThe number of nodes are = %d\n\n",c);
}
void dequeue()
{
    int ch;
    while(1)
    {
        printf("1:Insert front\n2:Delete front\n");
        printf("3:Insert end\n4:Delete end\n");
        printf("5:Display\n6:Exit\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insertFront();
                    break;
            case 2: deleteFront();
                    break;
            case 3: insertEnd();
                    break;
            case 4: deleteEnd();
                    break;
            case 5: display();
                    break;
            case 6: return;
        }
    }
}
int main()
{
    int ch1,ch2,ch3;
    while(1)
    {
        printf("1:Create\n2:Insert or Delete from front\n");
        printf("3:Insert or Delete from end\n4:Display\n");
        printf("5:Dequeue\n6:Exit\nEnter the choice: ");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1: create();
                    break;
            case 2: printf("1:Insert\t2:Delete\nEnter the choice: ");
                    scanf("%d",&ch2);
                    ch2==1?insertFront():deleteFront();
                    break;
            case 3: printf("1:Insert\t2:Delete\nEnter the choice: ");
                    scanf("%d",&ch3);
                    ch3==1?insertEnd():deleteEnd();
                    break;
            case 4: display();
                    break;
            case 5: dequeue();
                    break;
            case 6: exit(0);
        }
    }
}
