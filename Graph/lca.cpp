// Naman Shukla


#include <bits/stdc++.h>
using namespace std;

#define MAXN 112345
#define LOGN 20

int parent[MAXN], depth[MAXN], f[MAXN][LOGN + 1];
vector <int> adj[MAXN];


void dfs(int u) {

    if (u != 1) {
        f[u][0] = parent[u];
        for (int i = 1; i <= LOGN; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
    }

     for (int i = 0; i < (int) adj[u].size(); i++) 
     {
        int v = adj[u][i];

        if (parent[v] == 0) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
            
        }
    }

}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = LOGN; i >= 0; i--)
        if (depth[f[u][i]] >= depth[v]) u = f[u][i];

    if (u == v) return v;

    for (int i = LOGN; i >= 0; i--)
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }

    return f[u][0];
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	return 0;
}