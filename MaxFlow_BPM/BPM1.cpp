// Bipartite matching

// template taken Zobayer Hasan's blog

#include <bits/stdc++.h>
using namespace std;

#define SET(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))
#define MAX 100

vector < int > edges[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];

bool dfs(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    int len = edges[u].size(), i, v;
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(Right[v]==-1) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(dfs(Right[v])) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int match() {
    SET(Left);
    SET(Right);
    int i, ret = 0;
    bool done;
    do {
        done = true;
        CLR(visited);
        for(i=0; i<MAX; i++) {
            if(Left[i]==-1 && dfs(i)) {
                done = false;
            }
        }
    } while(!done);
    for(i=0; i<MAX; i++) ret += (Left[i]!=-1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}