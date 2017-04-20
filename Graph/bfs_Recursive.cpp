#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define pb push_back
#define Max 100005
vector<ll> Graph[Max];
ll vis[Max];


void bfs(queue<ll> cur)
{
	queue<ll> next;
	
	while(!cur.empty())
	{
		ll node = cur.front();
		cur.pop();
		cout<<node<<" ";
		for(ll i=0;i<Graph[node].size();i++)
		{
			ll neigh = Graph[node][i];
			if(vis[neigh]==0)
			{
				vis[neigh] = 1;
				next.push(neigh);
			}
		}
	}

	if(next.size())
	bfs(next);

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
	vis[start] = 1;
	queue<ll> Q;
	Q.push(start);
	bfs(Q);

	return 0;
}