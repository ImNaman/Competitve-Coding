#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define pp pair<ll,ll>
#define inf 1e9
using namespace std;
const int N=10005,M=20;
 
int ChainHead[N],ChainId[N],ChainSz[N];           //chainhead-chain head,ChainId-ind of the node in that chain,chainlen-length of chain
int depth[N],subsz[N],dp[N][M],p[N],posinbase[N],basarr[N];       //basarr- segment tree built on,posinbase- holds pos of hash in posinbase 
int ptr,chainNo,n;                                    //chainno-global numbering of each chain,ptr-global ind of each node
 
vector<int> a[N];
vector<int> cost[N],ind[N];int otherend[N];       // to represent edge in form of vertex
int tree[6*N];
 
void build(int s,int e,int node)
{
    if(s==e)
    {
        tree[node]=basarr[s];
        return;
    }
    int mid=(s+e)/2;
    build(s,mid,2*node+1);
    build(mid+1,e,2*node+2);
    
    tree[node]=max(tree[2*node+1],tree[2*node+2]);
}
 
void dfs(int u,int par)
{
    depth[u]=(u!=0)? depth[par]+1 : 0;
    p[u]=dp[u][0]=par;subsz[u]=1;
  
    for(int i=0;i<a[u].size();i++)
    {
        if(a[u][i]!=par)
        {
            otherend[ind[u][i]]=a[u][i];
            dfs(a[u][i],u);
            subsz[u]+=subsz[a[u][i]];
        }
    }
    
      //cout<<u<<" "<<par<<" "<<subsz[u]<<"\n";
}
 
int LCA(int u,int v)
{
    if(depth[u]<depth[v])
    swap(u,v);
    
    int diff=depth[u]-depth[v];
    
    for(int i=0;i<M;i++)
    {
        if(diff&(1<<i))
        u=dp[u][i];
    }
    
  
    
    if(u==v)
    return u;
    
    for(int i=M-1;i>=0;i--)
    {
        if(dp[u][i]!=dp[v][i])
        {
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    
    return p[u];
}
 
void hld(int u,int c,int par)
{
   
    if(ChainHead[chainNo]==-1)
        ChainHead[chainNo]=u;
    
 
    ChainId[u]=chainNo;
    posinbase[u]=ptr;
    basarr[ptr++]=c;
 
    int sc=-1,in=-1;
    for(int i=0;i<a[u].size();i++)
    {
        if(a[u][i]!=par)
        {
            if(subsz[a[u][i]]>sc)
            {
                sc=subsz[a[u][i]];
                in=i;
            }
        }
    }
    
    if(in!=-1)
        hld(a[u][in],cost[u][in],u);       //special node
    
    for(int i=0;i<a[u].size();i++)
    {
        if(i!=in&&a[u][i]!=par)
        {
            chainNo++;
            hld(a[u][i],cost[u][i],u);            //normal node
        }
    }
    
}
 
void update(int s,int e,int l,int node,int val)     //point update
{
    if(s==e)
    {
        tree[node]=val;
        basarr[l]=val;
        return;
    }
    
    int mid=(s+e)/2;
    if(l<=mid)
    update(s,mid,l,2*node+1,val);
    else
    update(mid+1,e,l,2*node+2,val);
    
    tree[node]=max(tree[2*node+1],tree[2*node+2]);
}
 
int query_range(int s,int e,int l,int r,int node)
{
   if(s>e||s>r||e<l)
   return -1;
   
   if(s>=l&&e<=r)
   return tree[node];
   
   int mid=(s+e)/2;
   int x=query_range(s,mid,l,r,2*node+1);
   int y=query_range(mid+1,e,l,r,2*node+2);
   
   return max(x,y);
}
 
int query_up(int u,int v)
{
    int uchain,vchain=ChainId[v],ans=-1;
    //cout<<vchain<<" "<<ChainId[u]<<" "<<posinbase[ChainHead[ChainId[u]]]<<" "<<posinbase[u]<<"\n";
    while(1)
    {
        if(u==v)
        break;
        
        uchain=ChainId[u];
        if(uchain==vchain)
        {
            if(u==v)
            break;
          
            int x=query_range(0,ptr,posinbase[v]+1,posinbase[u],0);
            if(x>ans)
            ans=x;
            break;
        }
        
        int x=query_range(0,ptr,posinbase[ChainHead[uchain]],posinbase[u],0);
        if(x>ans)
        ans=x;
            
        u=ChainHead[uchain];
        u=p[u];
    }
    
    return ans;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int t;
    scanf("%d",&t);
    
  
        
    for(int l=0;l<t;l++)    
        {
        ptr=0;chainNo=0;
        scanf("%d",&n);
        
        for(int i=0;i<n;i++)
        {
         a[i].clear();
         ind[i].clear();
         cost[i].clear();
        }
       
        memset(dp,-1,sizeof(dp));
        memset(ChainHead,-1,sizeof(ChainHead));
        memset(tree,-1,sizeof(tree)); 
        
        for(int i=0;i<n-1;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            
            u--;v--;
            a[u].pb(v);
            cost[u].pb(c);
            ind[u].pb(i);
            
            a[v].pb(u);
            cost[v].pb(c);
            ind[v].pb(i);
        }
      
    
     
     
        
    dfs(0,0);
    hld(0,-1,0);
    
    
   
    
    build(0,ptr,0);
    
    for(int i=1;i<M;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[j][i-1]!=-1)
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    
    /*cout<<chainNo<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<otherend[i]<<" "<<posinbase[otherend[i]]<<"\n";
    }*/
    
    while(1)
    {
        char s[100];
        scanf("%s",s);
        
        if(s[0]=='D')
        break;
        
        if(s[0]=='Q')
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;v--;
            int lca=LCA(u,v);
            printf("%d\n",max(query_up(u,lca),query_up(v,lca)));
            //cout<<max(query_up(u,lca),query_up(v,lca))<<"\n";
        }
        else
        {
            int i,val;
            scanf("%d%d",&i,&val);
            i--;
            int u=otherend[i];
            update(0,n,posinbase[u],0,val);
        }
        
    }
        
    
    
    }
    return 0;
}  