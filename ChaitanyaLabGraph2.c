#include <stdlib.h>
#include<stdio.h>
long long int set[200000]={-1};
long long int t[2][200000];
long long int source[200000]={0};
long long int destination[200000]={0};
long long int weight[200000]={0};
void join(long long int u,long long int v)
{
    if((set[u]<set[v]))
    {
        set[u]=set[u]+set[v];
        set[v]=u;
    }
    else
    {
        set[v]=set[v]+set[u];
        set[u]=v;
    }
}
long long int find(long long int u)
{
    long long int x=u,v=0;
    while(set[x]>0)
    {
        x=set[x];
    }
    while(u!=x)
    {
        v=set[u];
        set[u]=x;
        u=v;
    }
    return x;
}
void merge(long long int A[],long long int B[],long long int C[],long long int low2,long long int mid2,long long int high2)
{
    long long int i,j;
    i=low2;
    j=mid2+1;
    long long int b[high2+1];long long int c[high2+1];
    long long int t=low2;long long int d[high2+1];long long int g=low2;long long int h=low2;
    while(i<=mid2 && j<=high2)
    {
        if(A[i]>A[j])
        {
            b[h++]=A[i];
            c[g++]=B[i];
            d[t++]=C[i++];
        }
        else
        {
            b[h++]=A[j];
            c[g++]=B[j];
            d[t++]=C[j++];
        }
    }
    for(;i<=mid2;i++)
    {
        b[h++]=A[i];
        c[g++]=B[i];
        d[t++]=C[i];
    }
    for(;j<=high2;j++)
    {
        b[h++]=A[j];
        c[g++]=B[j];
        d[t++]=C[j];
    }
    for(long long int i=low2;i<=high2;i++)
    {
        A[i]=b[i];
        B[i]=c[i];
        C[i]=d[i];
    }
}
void MergeSort(long long int A[],long long int B[],long long int C[],long long int low,long long int high)
{
    if(low<high)
    {
        long long int mid=(low+high)/2;
        MergeSort(A,B,C,low,mid);
        MergeSort(A,B,C,mid+1,high);
        merge(A,B,C,low,mid,high);
    }
}
int main()
{
    long long int k,u,v;
    long long int max;
    long long int i=0;
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    for(long long int i=0;i<m;i++)
    {
        long long int a,b;
        long long int c;
        scanf("%lld %lld %lld",&source[i],&destination[i],&weight[i]);
    }
    MergeSort(weight,destination,source,0,m-1);long long int maxcounter=0;long long int maxweight=0;
    while(i<n-1)
    {
        if(maxcounter<m)
        {
            max=weight[maxcounter];
            u=source[maxcounter];
            v=destination[maxcounter];
        }
        else
        break;
        if((find(u)!=find(v)))
        {
            t[0][i]=u;t[1][i++]=v;
            join(find(u),find(v));
            maxweight+=max;
        }
        maxcounter++;
    }
    if(i==(n-1))
    printf("%lld\n",maxweight);
    else
    printf("IMPOSSIBLE\n");
}