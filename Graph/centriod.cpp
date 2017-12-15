#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<ll,ll> 
#define mk make_pair
#define inf 1e9
#define eps 1e-9
#define mod 1000000007 
using namespace std;
const int N=100005;

set<int> a[N];
vector<int> g[N];
int sz[N],p[N],m,root;

char s[N]="";

void subtreesize(int u,int par)
{
	sz[u]=1;
	m++;
	for(set<int>::iterator it=a[u].begin();it!=a[u].end();it++)
	{
		if(*it!=par)
		{
			subtreesize(*it,u);
			sz[u]+=sz[*it];
		}
	}
}

int centroid(int u,int par)
{
	for(set<int>::iterator it=a[u].begin();it!=a[u].end();it++)
	{
		if(*it!=par)
		{
			if(sz[*it]>m/2)
				return centroid(*it,u);
		}
	}
	return u;
}


void decompose(int u,int par)
{
	m=0;
	subtreesize(u,u);
	int c=centroid(u,u);

	
	if(par==0)
		root=c;
	else
	{
		g[par].pb(c);
		g[c].pb(par);
	}
	
	

	for(set<int>::iterator it=a[c].begin();it!=a[c].end();it++)
	{
		a[*it].erase(c);
		decompose(*it,c);
	}

	a[c].clear();
}

void dfs(int u,int par,char ch)
{
	s[u]=ch;ch++;
	for(int i=0;i<g[u].size();i++)
	{
		if(g[u][i]!=par)
			dfs(g[u][i],u,ch);
	}
}



int main()
{
	int n;
	scanf("%d",&n);

	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);

		a[u].insert(v);
		a[v].insert(u);
	}

	decompose(1,0);
	dfs(root,root,'A');

	for(int i=1;i<=n;i++)
		printf("%c ",s[i]);

}