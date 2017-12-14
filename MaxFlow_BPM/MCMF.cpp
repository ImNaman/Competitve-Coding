//Naman Shukla

#include <bits/stdc++.h>
using namespace std;
#define ND 500
#define ED 100000
#define INF 1000000000

int eg_no,st,en,rs,fl,mx;
int to[ED],from[ED],nx[ED],cap[ED],cst[ED],last[ND],ds[ND],pr[ND],pr_i[ND];

void init()
{
    eg_no=0;
    memset(last,-1,sizeof(last));
}

void add_edge(int u,int v,int cp,int cs)
{
    to[eg_no]=v;cap[eg_no]=cp;cst[eg_no]=cs;nx[eg_no]=last[u];last[u]=eg_no++;
    to[eg_no]=u;cap[eg_no]=0;cst[eg_no]=-cs;nx[eg_no]=last[v];last[v]=eg_no++;
}

int bellman()
{
    for(int i=0;i<ND;i++) ds[i]=INF;
    memset(pr,-1,sizeof(pr));
    memset(pr_i,-1,sizeof(pr_i));
    queue<int>q;
    int mrk[ND];
    memset(mrk,0,sizeof(mrk));
    q.push(st);mrk[st]=1;ds[st]=0;
    while(!q.empty())
    {
        int p=q.front();q.pop();
        mrk[p]=0;
        for(int i=last[p];i>=0;i=nx[i])
        {
            int t=to[i];
            if(cap[i]<=0) continue;
            if(ds[t]>ds[p]+cst[i])
            {
                ds[t]=ds[p]+cst[i];
                pr[t]=p;pr_i[t]=i;
                if(mrk[t]==0){ mrk[t]=1;q.push(t); }
            }
        }
    }
    
    if(ds[en]==INF) return 0;
    int x=en,mn=10000;
    while(pr[x]!=-1){ mn=min(mn,cap[pr_i[x]]);x=pr[x]; }
    
    x=en;
    while(pr[x]!=-1)
    {
        int z=pr_i[x];
        cap[z]-=mn;cap[z^1]+=mn;
        x=pr[x];
    }
    rs+=ds[en];
    return mn;
}    
int maxflow()
{
    rs=0;
    int ans=0;
    while(1)
    {
        int res=bellman();
        if(res==0) break;
        ans+=res;
    }
    return rs;
}   

int main()
{
	return 0;
}