//Program 11
#include<stdio.h>
#include<conio.h>
int count=0;
void creategraph(int n,int a[10][10])
{
    int i,j;
    printf("enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
}
void dfs(int a[10][10],int n,int vis[],int v)//depth first search
{
    int i;
    count++;
    vis[v]=count;
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0 && a[v][i]==1)
            dfs(a,n,vis,i);
    }
}
void main()
{
    int a[10][10],n,source,vis[10]={0};
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    creategraph(n,a);
    printf("enter the source vertex\n");
    scanf("%d",&source);
    dfs(a,n,vis,source);
    if(count==n)
        printf("the graph is connected(all the nodes are reacheable)\n");
    else
        printf("the graph is not connected(some nodes are unreacheable)\n");
}
