#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int parent[100];
int rank[100];

int find_path(int x){
    while (x!=parent[x])
    {
        parent[x]=find_path(parent[x]);
    }
    return x;
}

int find_set(int x){
    while (x!=parent[x])
    {
        x=parent[x];
    }
    return x;
}

int munion(int x, int y){
    int r=find_path(x);
    int s=find_path(y);
    if (r==s)
    {
        return r;
    }
    else
    {
        if (rank[r]>=rank[s])
        {
            parent[s]=r;
            if (rank[s]==rank[r])
            {
                rank[r]+=1;
            }
            return r;
        }
        else
        {
            parent[r]=s;
            return s;
        }
    }
}

void make_set(int n){
    for (int i = 1; i <= n; i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int main()
{
    int n,i,j,t;
    printf("How many disjoint set you want to create?\n");
    scanf("%d",&n);
    make_set(n);
    printf("%d number of makeset operations are executed\n",n);
    printf("To stop Union operation, press -1\n");
    while(t!=-1)
    {
        printf("Enter the value of t");
        scanf("%d", &t);
        if(t!=-1)
        {
            printf("Enter i and j to perform Union(i,j) operation\n");
            printf("I = ");
            scanf("%d", &i);
            printf("J = ");
            scanf("%d", &j);
            munion(i,j);
            printf("UNION(%d,%d) is finished\n", i,j);
        }
    }
    int flag,count=0;
    printf("Do you want to find the connected components\n");
    printf("Press '1' for YES or, '0' for NO\n");
    scanf("%d", &flag);
    if(flag==1)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d\t",find_set(i));
            if(find_set(i)==i)
            count+=1;
        }
        printf("The number of connected component is %d\n", count);
    }
    else
    {
        printf("We do not want to find the connected components\n");
    }
    return 0;
}