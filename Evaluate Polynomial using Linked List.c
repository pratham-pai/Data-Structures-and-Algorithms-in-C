#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int cof;
    int ex[3];
    struct node *next;
};
struct node *createnode()
{
    struct node *temp=malloc(sizeof(struct node));
    temp->cof=-1;
    temp->ex[0]=-1;
    temp->ex[1]=-1;
    temp->ex[2]=-1;
    temp->next=temp;
    return temp;
}
void read(struct node *p,int n,int x)
{
    struct node *temp;
    int i;
    for(i=1;i<=n;i++)
    {
        printf("Enter the coefficient and powers of x, y and z of the %dth term: ",i);
        scanf("%d%d%d%d",&temp->cof,&temp->ex[0],&temp->ex[1],&temp->ex[2]);
        addterm(p,temp->cof,temp->ex[0],temp->ex[1],temp->ex[2]);
    }
    print_poly(p,x);
}
void addterm(struct node *p,int c,int i,int j,int k)
{
    struct node *temp=malloc(sizeof(struct node)),*po=p->next;
    temp->cof=c;
    temp->ex[0]=i;
    temp->ex[1]=j;
    temp->ex[2]=k;
    while(po->next!=p)
        po=po->next;
    po->next=temp;
    temp->next=p;
}
void print_poly(struct node *p,int x)
{
    struct node *temp=p->next;
    if(x==1)
        printf("The first polynomial is: ");
    else if(x==2)
        printf("The second polynomial is: ");
    else if(x==3)
        printf("The polynomial sum is: ");
    while(temp!=p)
    {
        printf("%dx^%dy^%dz^%d",temp->cof,temp->ex[0],temp->ex[1],temp->ex[2]);
        if(temp->next!=p)
            printf(" + ");
        temp=temp->next;
    }
    printf("\n");
}
double evaluate(struct node *p,int x,int y,int z)
{
    int sum=0;
    struct node *temp=p->next;
    while(temp!=p)
    {
        sum+=temp->cof*(pow(x,temp->ex[0]))*(pow(y,temp->ex[1]))*(pow(z,temp->ex[2]));
        temp=temp->next;
    }
    return sum;
}
struct node *add(struct node *p1,struct node *p2)
{
    struct node *temp=createnode();
    struct node *t1=p1->next,*t3=p1->next;
    struct node *t2=p2->next,*t4=p2->next;
    int flag,i;
    while(t1!=p1)
    {
        t2=p2->next;
        while(t2!=p2)
        {
            flag=0;
            for(i=0;i<3;i++)
                if(t1->ex[i]!=t2->ex[i])
                {
                    flag=1;
                    break;
                }
            if(flag==0)
            {
                addterm(temp,t1->cof+t2->cof,t1->ex[0],t1->ex[1],t1->ex[2]);
                break;
            }
            t2=t2->next;
        }
        if(flag==1)
            addterm(temp,t1->cof,t1->ex[0],t1->ex[1],t1->ex[2]);
        t1=t1->next;
    }
    while(t4!=p2)
    {
        t3=p1->next;
        while(t3!=p1)
        {
            flag=0;
            for(i=0;i<3;i++)
                if(t4->ex[i]!=t3->ex[i])
                {
                    flag=1;
                    break;
                }
            if(flag==0)
                break;
            t3=t3->next;
        }
        if(flag==1)
            addterm(temp,t4->cof,t4->ex[0],t4->ex[1],t4->ex[2]);
        t4=t4->next;
    }
    return temp;
}
int main()
{
    int x,y,z,ch,n;
    struct node *p1=createnode(),*p2=createnode(),*ps;
    while(1)
    {
        printf(" 1:Evaluate Polynomial\n 2:Add\n 3:Exit\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of terms in the first polynomial: ");
                    scanf("%d",&n);
                    read(p1,n,1);
                    printf("Enter the values of x, y and z for evaluation: ");
                    scanf("%d%d%d",&x,&y,&z);
                    printf("%.2f\n",evaluate(p1,x,y,z));
                    break;
            case 2: printf("Enter the number of terms in the second polynomial: ");
                    scanf("%d",&n);
                    read(p2,n,2);
                    ps=add(p1,p2);
                    print_poly(ps,3);
                    break;
            case 3: exit(0);
        }
    }
}
