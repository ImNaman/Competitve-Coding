// Naman Shukla
// Dijkstras Algo 
 
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair 
typedef long long ll; 
typedef pair< ll ,ll > pii;
 
const ll MAX = 100001;
const ll INF = 10000000000000001;
 
vector< pii > G[MAX];
ll d[MAX];
 
void dijk(ll S) 
{
     
    ll u, v, i, c, w;     
    priority_queue< pii, vector< pii >, greater< pii > > Q;
    memset(d, INF, sizeof(d));
    Q.push(mp(0, S));
    d[S] = 0;     
    while(!Q.empty()) 
    {
        u = Q.top().second;c = Q.top().first; 
        Q.pop();         
        if(d[u] < c) continue;
        for(i = 0; i < G[u].size(); i++) 
        {
            v = G[u][i].first; 
            w = G[u][i].second;
            if(d[v] > d[u] + w) 
            {
                d[v] = d[u] + w;
                Q.push(mp(d[v], v));
            }
        }
    }
}
 
int main() 
{
    //    G[v].push_back(mp(u, w));
    //dijk(S);
    return 0;
} 