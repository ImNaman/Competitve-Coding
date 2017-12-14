// Naman Shukla

#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define pb push_back
#define Max 100005
vector<ll> Graph[Max];
ll vis[Max];


void bfs(int start)
{
	queue<ll> Q;
	vis[start] = 1;
	Q.push(start);

	while(!Q.empty())
	{
		ll cur = Q.front();
		Q.pop();
		cout<<cur<<" ";
		for(ll i=0;i<Graph[cur].size();i++)
		{
			ll neigh = Graph[cur][i];
			if(vis[neigh]==0)
			{
				vis[neigh] = 1;
				Q.push(neigh);
			}
		}
	}

}


int main()
{
	ll v,e;
	// cout<<"Enter the number of vertices and edges";
	cin>>v>>e;
	// cout<<"Enter all edges";
	for(ll i=0;i<e;i++)
	{
		ll v1,v2;
		cin>>v1>>v2;
		Graph[v1].pb(v2);
		Graph[v2].pb(v1);
	}
	// cout<<"Enter the start vertex";
	ll start;cin>>start;
	bfs(start);

	return 0;
}